CREATE DATABASE IF NOT EXISTS hitek_db 
DEFAULT CHARACTER SET utf8mb4 
COLLATE utf8mb4_unicode_ci;

USE hitek_db;

-- 1. Tabela Colaborador
CREATE TABLE IF NOT EXISTS colaborador (
    id_colaborador INT AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    cpf VARCHAR(14) NOT NULL UNIQUE,
    email VARCHAR(100) NOT NULL,
    telefone VARCHAR(20),
    cargo VARCHAR(45) NOT NULL,
    data_admissao DATE NOT NULL,
    login VARCHAR(50) NOT NULL UNIQUE,
    senha VARCHAR(100) NOT NULL,
    perfil ENUM('VENDEDOR', 'FINANCEIRO', 'ADMINISTRADOR') NOT NULL,
    status ENUM('ATIVO', 'INATIVO') DEFAULT 'ATIVO'
) ENGINE=InnoDB;

-- 2. Tabela Venda
CREATE TABLE IF NOT EXISTS venda (
    id_venda INT AUTO_INCREMENT PRIMARY KEY,
    id_colaborador INT NOT NULL,
    numero_os VARCHAR(50) NOT NULL,
    valor_venda DECIMAL(10,2) NOT NULL,
    custo DECIMAL(10,2) NOT NULL DEFAULT 0.00,
    margem DECIMAL(5,2) DEFAULT 0.00,
    forma_pagamento VARCHAR(50),
    faturada TINYINT(1) DEFAULT 0,
    venda_paga TINYINT(1) DEFAULT 0,
    equipamento_retirado TINYINT(1) DEFAULT 0,
    data_venda DATETIME DEFAULT CURRENT_TIMESTAMP,
    data_retirada DATETIME NULL,
    data_baixa DATETIME NULL,
    status ENUM('ATIVA', 'CANCELADA') DEFAULT 'ATIVA',
    CONSTRAINT fk_venda_colaborador FOREIGN KEY (id_colaborador) 
        REFERENCES colaborador(id_colaborador) ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE=InnoDB;

-- 3. Tabela Comissão
CREATE TABLE IF NOT EXISTS comissao (
    id_comissao INT AUTO_INCREMENT PRIMARY KEY,
    id_venda INT NOT NULL,
    percentual_aplicado DECIMAL(5,2) NOT NULL,
    valor_comissao DECIMAL(10,2) NOT NULL,
    status ENUM('PENDENTE', 'LIBERADA', 'PAGA', 'CANCELADA') DEFAULT 'PENDENTE',
    data_calculo DATETIME DEFAULT CURRENT_TIMESTAMP,
    data_conferencia DATETIME NULL,
    CONSTRAINT fk_comissao_venda FOREIGN KEY (id_venda) 
        REFERENCES venda(id_venda) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB;

-- 4. Tabela Configuração
CREATE TABLE IF NOT EXISTS configuracao (
    id_configuracao INT AUTO_INCREMENT PRIMARY KEY,
    percentual_atual DECIMAL(5,2) NOT NULL DEFAULT 1.00,
    data_alteracao DATETIME DEFAULT CURRENT_TIMESTAMP,
    id_administrador INT NOT NULL,
    CONSTRAINT fk_configuracao_administrador FOREIGN KEY (id_administrador) 
        REFERENCES colaborador(id_colaborador) ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE=InnoDB;

-- 5. Tabela Pagamento de Comissão
CREATE TABLE IF NOT EXISTS pagamento_comissao (
    id_pagamento INT AUTO_INCREMENT PRIMARY KEY,
    id_colaborador INT NOT NULL,
    valor_pago DECIMAL(10,2) NOT NULL,
    data_pagamento DATETIME DEFAULT CURRENT_TIMESTAMP,
    status ENUM('PAGO', 'CANCELADO') DEFAULT 'PAGO',
    CONSTRAINT fk_pagamento_colaborador FOREIGN KEY (id_colaborador) 
        REFERENCES colaborador(id_colaborador) ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE=InnoDB;

-- 6. Tabela Desconto (Ajustes de Comissão)
CREATE TABLE IF NOT EXISTS desconto (
    id_desconto INT AUTO_INCREMENT PRIMARY KEY,
    id_comissao_origem INT NOT NULL,
    valor_desconto DECIMAL(10,2) NOT NULL,
    motivo VARCHAR(255) NOT NULL,
    data_registro DATETIME DEFAULT CURRENT_TIMESTAMP,
    aplicado TINYINT(1) DEFAULT 0,
    data_aplicacao DATETIME NULL,
    id_pagamento_aplicacao INT NULL,
    CONSTRAINT fk_desconto_comissao FOREIGN KEY (id_comissao_origem) 
        REFERENCES comissao(id_comissao) ON DELETE CASCADE ON UPDATE CASCADE,
    CONSTRAINT fk_desconto_pagamento FOREIGN KEY (id_pagamento_aplicacao) 
        REFERENCES pagamento_comissao(id_pagamento) ON DELETE SET NULL ON UPDATE CASCADE
) ENGINE=InnoDB;

-- Inserção do usuário Administrador inicial e configuração padrão (1.00%)
INSERT INTO colaborador (nome, cpf, email, telefone, cargo, data_admissao, login, senha, perfil, status) 
VALUES ('Administrador Sistema', '000.000.000-00', 'admin@hitek.com', '12999999999', 'Administrador', CURDATE(), 'admin', 'admin123', 'ADMINISTRADOR', 'ATIVO');

INSERT INTO configuracao (percentual_atual, id_administrador) 
VALUES (1.00, 1);
