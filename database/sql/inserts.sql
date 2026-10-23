-- ============================================================
-- SISTEMA DE GESTÃO DE COMISSÕES - HITEK INFORMÁTICA
-- Arquivo: inserts.sql (DML - Data Manipulation Language)
-- ============================================================

USE db_hitek_comissoes;

-- 1. Inserção de Colaboradores (com credenciais integradas)
INSERT INTO colaborador (id_colaborador, nome, cpf, email, telefone, cargo, data_admissao, login, senha, perfil, status) VALUES
(2, 'Carlos Souza', '222.222.222-22', 'carlos@hitek.com', '11922222222', 'Vendedor', '2022-05-15', 'carlos', '1234', 'VENDEDOR', 'ATIVO'),
(3, 'Joao Martin', '000.000.000-00', 'joao@hitek.com', '12933333333', 'Financeiro', '2024-01-15', 'joao', '1234', 'FINANCEIRO', 'ATIVO'),
(4, 'Marina Costa', '444.444.444-44', 'marina@hitek.com', '11944444444', 'Vendedor', '2026-10-12', 'marina', '1234', 'VENDEDOR', 'ATIVO');

-- 2. Inserção de Vendas
INSERT INTO venda (id_venda, numero_os, id_colaborador, data_venda, nome_cliente, valor_venda, custo, margem, forma_pagamento, faturada, venda_paga, data_retirada, descricao, status, data_baixa, id_financeiro_baixa) VALUES
(1, 'OS-2026-001', 2, '2026-10-01', 'Empresa Alfa Ltda', 15000.00, 12000.00, 20.00, 'PIX', 1, 1, '2026-10-02', 'Venda realizada com sucesso', 'ATIVA', '2026-10-03 10:00:00', 3),
(2, 'OS-2026-002', 2, '2026-10-05', 'Beta Tecnologias', 8500.00, 6800.00, 20.00, 'BOLETO', 1, 1, '2026-10-06', 'Aguardando confirmação', 'ATIVA', NULL, NULL),
(3, 'OS-2026-003', 4, '2026-10-10', 'Gamma Comércio', 22000.00, 17600.00, 20.00, 'CARTAO', 0, 1, '2026-10-11', 'Equipamento entregue', 'ATIVA', NULL, NULL),
(4, 'OS-2026-004', 4, '2026-10-12', 'Delta Serviços', 5000.00, 4000.00, 20.00, 'DINHEIRO', 0, 0, NULL, 'Em andamento', 'ATIVA', NULL, NULL);

-- 3. Inserção de Comissões Geradas
INSERT INTO comissao (id_comissao, id_venda, percentual_aplicado, valor_comissao, status, data_calculo, data_conferencia) VALUES
(1, 1, 1.00, 150.00, 'PAGA', '2026-10-01 10:35:00', '2026-10-03 10:00:00'),
(2, 2, 1.00, 85.00, 'LIBERADA', '2026-10-05 14:20:00', NULL),
(3, 3, 1.00, 220.00, 'PENDENTE', '2026-10-10 09:05:00', NULL);

-- 4. Inserção de Pagamento de Comissão Registrado
INSERT INTO pagamento_comissao (id_pagamento, id_comissao, data_pagamento, valor_pago, forma_pagamento, status, observacao, id_responsavel) VALUES
(1, 1, '2026-10-15', 150.00, 'PIX', 'PAGO', 'Pagamento efetuado via PIX', 3);

-- 5. Inserção de Desconto
INSERT INTO desconto (id_desconto, id_comissao_origem, valor_desconto, motivo, data_registro, aplicado, data_aplicacao, id_pagamento_aplicacao) VALUES
(1, 2, 10.00, 'Ajuste de taxa operacional', '2026-10-16', 0, NULL, NULL);
