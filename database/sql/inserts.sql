-- ============================================================
-- SISTEMA DE GESTÃO DE COMISSÕES — HITEK INFORMÁTICA
-- Arquivo: inserts.sql (DML - Data Manipulation Language)
-- ============================================================

USE `db_hitek_comissoes`;

-- Inserção de Usuários
INSERT INTO `usuario` (`id_usuario`, `login`, `senha_hash`, `perfil`, `status`) VALUES
(1, 'admin', 'e10adc3949ba59abbe56e057f20f883e', 'ADMINISTRADOR', 'ATIVO'),
(2, 'financeiro', 'e10adc3949ba59abbe56e057f20f883e', 'FINANCEIRO', 'ATIVO'),
(3, 'carlos.vendas', 'e10adc3949ba59abbe56e057f20f883e', 'VENDEDOR', 'ATIVO'),
(4, 'ana.vendas', 'e10adc3949ba59abbe56e057f20f883e', 'VENDEDOR', 'ATIVO');

-- Inserção de Colaboradores
INSERT INTO `colaborador` (`id_colaborador`, `id_usuario`, `nome`, `cpf`, `email`, `cargo`, `percentual_comissao`, `status`) VALUES
(1, 1, 'Roberto Gerente', '111.222.333-01', 'roberto@hitek.com.br', 'Gerente Geral', 5.00, 'ATIVO'),
(2, 2, 'Fernanda Silva', '222.333.444-02', 'fernanda@hitek.com.br', 'Analista Financeiro', 0.00, 'ATIVO'),
(3, 3, 'Carlos Eduardo', '333.444.555-03', 'carlos@hitek.com.br', 'Consultor de Vendas', 3.50, 'ATIVO'),
(4, 4, 'Ana Paula', '444.555.666-04', 'ana@hitek.com.br', 'Consultora de Vendas', 4.00, 'ATIVO');

-- Inserção de Configurações
INSERT INTO `configuracao` (`chave`, `valor`, `descricao`) VALUES
('MARGEM_MINIMA_COMISSAO', '10.00', 'Margem de lucro mínima (%) para direito à comissão integral'),
('DIA_FECHAMENTO_MENSAL', '25', 'Dia limite do mês para consolidação das comissões'),
('VERSAO_SISTEMA', '1.0.0', 'Versão atual da aplicação C/MySQL');

-- Inserção de Vendas
INSERT INTO `venda` (`id_venda`, `id_colaborador`, `numero_nf`, `cliente`, `valor_total`, `margem_lucro`, `data_venda`, `status_comissao`) VALUES
(1, 3, 'NF-2026-001', 'Empresa Alfa Ltda', 15000.00, 18.50, '2026-10-01 10:30:00', 'GERADA'),
(2, 3, 'NF-2026-002', 'Beta Tecnologias', 8500.00, 12.00, '2026-10-05 14:15:00', 'GERADA'),
(3, 4, 'NF-2026-003', 'Gamma Comércio', 22000.00, 22.00, '2026-10-10 09:00:00', 'GERADA'),
(4, 4, 'NF-2026-004', 'Delta Serviços', 5000.00, 8.00, '2026-10-12 16:45:00', 'PENDENTE');

-- Inserção de Comissões Geradas
INSERT INTO `comissao` (`id_comissao`, `id_venda`, `id_colaborador`, `valor_base`, `percentual_aplicado`, `valor_comissao`, `data_calculo`, `status`) VALUES
(1, 1, 3, 15000.00, 3.50, 525.00, '2026-10-01 10:35:00', 'PAGA'),
(2, 2, 3, 8500.00, 3.50, 297.50, '2026-10-05 14:20:00', 'LIBERADA'),
(3, 3, 4, 22000.00, 4.00, 880.00, '2026-10-10 09:05:00', 'LIBERADA');

-- Inserção de Pagamento Registrado
INSERT INTO `pagamento` (`id_pagamento`, `id_comissao`, `valor_pago`, `data_pagamento`, `meio_pagamento`, `comprovante_ref`) VALUES
(1, 1, 525.00, '2026-10-15 11:00:00', 'PIX', 'PIX-HITEK-88239102');
