-- ============================================================
-- SISTEMA DE GESTÃO DE COMISSÕES — HITEK INFORMÁTICA
-- Arquivo: schema.sql (DDL - Data Definition Language)
-- ============================================================

CREATE DATABASE IF NOT EXISTS `db_hitek_comissoes`
DEFAULT CHARACTER SET utf8mb4
DEFAULT COLLATE utf8mb4_unicode_ci;

USE `db_hitek_comissoes`;

-- Limpeza preventiva de tabelas existentes na ordem correta das FKs
DROP TABLE IF EXISTS `desconto`;
DROP TABLE IF EXISTS `pagamento`;
DROP TABLE IF EXISTS `comissao`;
DROP TABLE IF EXISTS `venda`;
DROP TABLE IF EXISTS `colaborador`;
DROP TABLE IF EXISTS `usuario`;
DROP TABLE IF EXISTS `configuracao`;

-- Tabela: USUARIO
CREATE TABLE `usuario` (
  `id_usuario` INT AUTO_INCREMENT PRIMARY KEY,
  `login` VARCHAR(50) NOT NULL UNIQUE,
  `senha_hash` VARCHAR(255) NOT NULL,
  `perfil` ENUM('ADMINISTRADOR', 'FINANCEIRO', 'VENDEDOR') NOT NULL,
  `status` ENUM('ATIVO', 'INATIVO') NOT NULL DEFAULT 'ATIVO',
  `criado_em` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `ultimo_acesso` DATETIME NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- Tabela: COLABORADOR
CREATE TABLE `colaborador` (
  `id_colaborador` INT AUTO_INCREMENT PRIMARY KEY,
  `id_usuario` INT NULL UNIQUE,
  `nome` VARCHAR(100) NOT NULL,
  `cpf` VARCHAR(14) NOT NULL UNIQUE,
  `email` VARCHAR(100) NOT NULL UNIQUE,
  `cargo` VARCHAR(50) NOT NULL,
  `percentual_comissao` DECIMAL(5,2) NOT NULL DEFAULT 3.00,
  `status` ENUM('ATIVO', 'INATIVO') NOT NULL DEFAULT 'ATIVO',
  `criado_em` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
  CONSTRAINT `fk_colaborador_usuario` FOREIGN KEY (`id_usuario`)
    REFERENCES `usuario` (`id_usuario`) ON DELETE SET NULL ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- Tabela: VENDA
CREATE TABLE `venda` (
  `id_venda` INT AUTO_INCREMENT PRIMARY KEY,
  `id_colaborador` INT NOT NULL,
  `numero_nf` VARCHAR(30) NOT NULL UNIQUE,
  `cliente` VARCHAR(100) NOT NULL,
  `valor_total` DECIMAL(10,2) NOT NULL,
  `margem_lucro` DECIMAL(5,2) NOT NULL DEFAULT 15.00,
  `data_venda` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `status_comissao` ENUM('PENDENTE', 'GERADA', 'CANCELADA') NOT NULL DEFAULT 'PENDENTE',
  CONSTRAINT `fk_venda_colaborador` FOREIGN KEY (`id_colaborador`)
    REFERENCES `colaborador` (`id_colaborador`) ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- Tabela: COMISSAO
CREATE TABLE `comissao` (
  `id_comissao` INT AUTO_INCREMENT PRIMARY KEY,
  `id_venda` INT NOT NULL UNIQUE,
  `id_colaborador` INT NOT NULL,
  `valor_base` DECIMAL(10,2) NOT NULL,
  `percentual_aplicado` DECIMAL(5,2) NOT NULL,
  `valor_comissao` DECIMAL(10,2) NOT NULL,
  `data_calculo` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `status` ENUM('PENDENTE', 'LIBERADA', 'PAGA', 'CANCELADA') NOT NULL DEFAULT 'PENDENTE',
  CONSTRAINT `fk_comissao_venda` FOREIGN KEY (`id_venda`)
    REFERENCES `venda` (`id_venda`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `fk_comissao_colaborador` FOREIGN KEY (`id_colaborador`)
    REFERENCES `colaborador` (`id_colaborador`) ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- Tabela: PAGAMENTO
CREATE TABLE `pagamento` (
  `id_pagamento` INT AUTO_INCREMENT PRIMARY KEY,
  `id_comissao` INT NOT NULL,
  `valor_pago` DECIMAL(10,2) NOT NULL,
  `data_pagamento` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `meio_pagamento` ENUM('PIX', 'TRANSFERENCIA', 'BOLETO', 'OUTRO') NOT NULL DEFAULT 'PIX',
  `comprovante_ref` VARCHAR(100) NULL,
  CONSTRAINT `fk_pagamento_comissao` FOREIGN KEY (`id_comissao`)
    REFERENCES `comissao` (`id_comissao`) ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- Tabela: DESCONTO
CREATE TABLE `desconto` (
  `id_desconto` INT AUTO_INCREMENT PRIMARY KEY,
  `id_comissao` INT NOT NULL,
  `motivo` VARCHAR(255) NOT NULL,
  `valor_desconto` DECIMAL(10,2) NOT NULL,
  `data_desconto` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
  CONSTRAINT `fk_desconto_comissao` FOREIGN KEY (`id_comissao`)
    REFERENCES `comissao` (`id_comissao`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- Tabela: CONFIGURACAO
CREATE TABLE `configuracao` (
  `id_config` INT AUTO_INCREMENT PRIMARY KEY,
  `chave` VARCHAR(50) NOT NULL UNIQUE,
  `valor` VARCHAR(255) NOT NULL,
  `descricao` VARCHAR(255) NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- Índices de Otimização de Busca
CREATE INDEX `idx_venda_data` ON `venda` (`data_venda`);
CREATE INDEX `idx_venda_colaborador` ON `venda` (`id_colaborador`);
CREATE INDEX `idx_comissao_status` ON `comissao` (`status`);
CREATE INDEX `idx_comissao_colaborador` ON `comissao` (`id_colaborador`);
