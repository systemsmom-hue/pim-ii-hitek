-- ============================================================
-- SISTEMA DE GESTÃO DE COMISSÕES - HITEK INFORMÁTICA
-- Arquivo: consultas.sql (DQL - Data Query Language & Relatórios)
-- ============================================================

USE db_hitek_comissoes;

-- Consulta 1: Relatório Consolidado de Comissões por Vendedor

SELECT
c.id_colaborador,
c.nome AS vendedor,
c.cargo,
COUNT(com.id_comissao) AS total_comissoes,
SUM(v.valor_venda) AS total_vendas_base,
SUM(com.valor_comissao) AS total_comissao_bruta,
SUM(CASE WHEN com.status = 'PAGA' THEN com.valor_comissao ELSE 0 END) AS total_pago,
SUM(CASE WHEN com.status = 'LIBERADA' THEN com.valor_comissao ELSE 0 END) AS total_a_pagar
FROM colaborador c
INNER JOIN venda v ON c.id_colaborador = v.id_colaborador
INNER JOIN comissao com ON v.id_venda = com.id_venda
GROUP BY c.id_colaborador, c.nome, c.cargo
ORDER BY total_comissao_bruta DESC;

-- Consulta 2: Extrato Detalhado de Vendas e Comissões

SELECT
v.numero_os,
v.nome_cliente,
v.data_venda,
v.valor_venda,
v.margem,
col.nome AS vendedor,
com.percentual_aplicado,
com.valor_comissao,
com.status AS status_comissao,
CASE
WHEN v.data_retirada IS NOT NULL THEN 'Retirada'
ELSE 'Não retirada'
END AS situacao_retirada
FROM venda v
INNER JOIN colaborador col ON v.id_colaborador = col.id_colaborador
LEFT JOIN comissao com ON v.id_venda = com.id_venda
ORDER BY v.data_venda DESC;

-- Consulta 3: Comissões Pendentes de Liberação / Pagamento

SELECT
com.id_comissao,
col.nome AS vendedor,
v.numero_os,
v.nome_cliente,
com.valor_comissao,
com.status,
com.data_calculo
FROM comissao com
INNER JOIN venda v ON com.id_venda = v.id_venda
INNER JOIN colaborador col ON v.id_colaborador = col.id_colaborador
WHERE com.status IN ('PENDENTE', 'LIBERADA')
ORDER BY com.data_calculo ASC;

-- Consulta 4: Histórico Auditoria de Pagamentos

SELECT
p.id_pagamento,
p.data_pagamento,
col.nome AS vendedor,
v.numero_os,
p.valor_pago,
p.forma_pagamento,
p.status,
p.observacao
FROM pagamento_comissao p
INNER JOIN comissao com ON p.id_comissao = com.id_comissao
INNER JOIN venda v ON com.id_venda = v.id_venda
INNER JOIN colaborador col ON v.id_colaborador = col.id_colaborador
ORDER BY p.data_pagamento DESC;
