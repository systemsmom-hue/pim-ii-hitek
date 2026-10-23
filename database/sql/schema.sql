CREATE DATABASE IF NOT EXISTS db_hitek_comissoes
DEFAULT CHARACTER SET utf8mb4
COLLATE utf8mb4_unicode_ci;

USE db_hitek_comissoes;

-- 1. Tabela Colaborador
CREATE TABLE IF NOT EXISTS colaborador (
id_colaborador INT AUTO_INCREMENT PRIMARY KEY,
nome VARCHAR(100) NOT NULL,
cpf VARCHAR(14) NOT NULL UNIQUE,
email VARCHAR(100) NOT NULL UNIQUE,
telefone VARCHAR(20) DEFAULT NULL,
cargo VARCHAR(45) NOT NULL,
data_admissao DATE NOT NULL,
login VARCHAR(50) NOT NULL UNIQUE,
senha VARCHAR(255) NOT NULL,
perfil ENUM('USUARIO', 'VENDEDOR', 'FINANCEIRO', 'ADMINISTRADOR') NOT NULL,
status ENUM('ATIVO', 'INATIVO') NOT NULL DEFAULT 'ATIVO'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- 2. Tabela Venda
CREATE TABLE IF NOT EXISTS venda (
id_venda INT AUTO_INCREMENT PRIMARY KEY,
numero_os VARCHAR(30) NOT NULL UNIQUE,
id_colaborador INT NOT NULL,
data_venda DATE NOT NULL,
nome_cliente VARCHAR(100) NOT NULL,
valor_venda DECIMAL(10,2) NOT NULL,
custo DECIMAL(10,2) NOT NULL DEFAULT 0.00,
margem DECIMAL(5,2) NOT NULL DEFAULT 0.00,
forma_pagamento ENUM('PIX', 'CARTAO', 'BOLETO', 'DINHEIRO') NOT NULL,
faturada TINYINT(1) NOT NULL DEFAULT 0,
venda_paga TINYINT(1) NOT NULL DEFAULT 0,
data_retirada DATE DEFAULT NULL,
descricao VARCHAR(255) DEFAULT NULL,
status ENUM('ATIVA', 'CANCELADA') NOT NULL DEFAULT 'ATIVA',
data_baixa DATETIME DEFAULT NULL,
id_financeiro_baixa INT DEFAULT NULL,
CONSTRAINT fk_venda_colaborador FOREIGN KEY (id_colaborador)
REFERENCES colaborador(id_colaborador) ON DELETE RESTRICT ON UPDATE CASCADE,
CONSTRAINT fk_venda_financeiro_baixa FOREIGN KEY (id_financeiro_baixa)
REFERENCES colaborador(id_colaborador) ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- 3. Tabela Comissão
CREATE TABLE IF NOT EXISTS comissao (
id_comissao INT AUTO_INCREMENT PRIMARY KEY,
id_venda INT NOT NULL UNIQUE,
percentual_aplicado DECIMAL(10,2) NOT NULL,
valor_comissao DECIMAL(10,2) NOT NULL,
status ENUM('PENDENTE', 'LIBERADA', 'PAGA', 'CANCELADA') NOT NULL DEFAULT 'PENDENTE',
data_calculo DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
data_conferencia DATETIME DEFAULT NULL,
CONSTRAINT fk_comissao_venda FOREIGN KEY (id_venda)
REFERENCES venda(id_venda) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- 4. Tabela Configuração
CREATE TABLE IF NOT EXISTS configuracao (
id_configuracao INT AUTO_INCREMENT PRIMARY KEY,
percentual_atual DECIMAL(5,2) NOT NULL DEFAULT 1.00,
data_alteracao DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
id_administrador INT NOT NULL,
CONSTRAINT fk_configuracao_administrador FOREIGN KEY (id_administrador)
REFERENCES colaborador(id_colaborador) ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- 5. Tabela Pagamento de Comissão
CREATE TABLE IF NOT EXISTS pagamento_comissao (
id_pagamento INT AUTO_INCREMENT PRIMARY KEY,
id_comissao INT NOT NULL,
data_pagamento DATE DEFAULT NULL,
valor_pago DECIMAL(10,2) NOT NULL,
forma_pagamento ENUM('PIX', 'TRANSFERENCIA', 'DINHEIRO') NOT NULL,
status ENUM('PENDENTE', 'PAGO', 'CANCELADO') NOT NULL DEFAULT 'PENDENTE',
observacao VARCHAR(255) DEFAULT NULL,
id_responsavel INT DEFAULT NULL,
CONSTRAINT fk_pagamento_comissao FOREIGN KEY (id_comissao)
REFERENCES comissao(id_comissao) ON DELETE CASCADE ON UPDATE CASCADE,
CONSTRAINT fk_pagamento_responsavel FOREIGN KEY (id_responsavel)
REFERENCES colaborador(id_colaborador) ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- 6. Tabela Desconto (Ajustes de Comissão)
CREATE TABLE IF NOT EXISTS desconto (
id_desconto INT AUTO_INCREMENT PRIMARY KEY,
id_comissao_origem INT NOT NULL,
valor_desconto DECIMAL(10,2) NOT NULL,
motivo VARCHAR(255) NOT NULL,
data_registro DATE NOT NULL,
aplicado TINYINT(1) NOT NULL DEFAULT 0,
data_aplicacao DATE DEFAULT NULL,
id_pagamento_aplicacao INT DEFAULT NULL,
CONSTRAINT fk_desconto_comissao FOREIGN KEY (id_comissao_origem)
REFERENCES comissao(id_comissao) ON DELETE CASCADE ON UPDATE CASCADE,
CONSTRAINT fk_desconto_pagamento FOREIGN KEY (id_pagamento_aplicacao)
REFERENCES pagamento_comissao(id_pagamento) ON DELETE SET NULL ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- Inserção do colaborador Administrador inicial e configuração padrão (1.00%)
INSERT INTO colaborador (nome, cpf, email, telefone, cargo, data_admissao, login, senha, perfil, status)
VALUES ('Jonas Silva', '111.111.111-11', 'jonas@hitek.com', '11911111111', 'Administrador', '2020-01-10', 'jonas', '1234', 'ADMINISTRADOR', 'ATIVO');

INSERT INTO configuracao (percentual_atual, id_administrador)
VALUES (1.00, 1);
