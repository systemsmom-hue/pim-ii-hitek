# ⚙️ Modelo Físico de Banco de Dados

Este documento apresenta a especificação técnica e o detalhamento de implementação física do banco de dados do **Sistema de Gestão de Comissões — Hitek Informática**, utilizando o SGBD **MySQL 8.0+** com a engine **InnoDB**.

---

## 1. Especificações Técnicas de Infraestrutura

- **SGBD:** MySQL 8.0 / MariaDB 10.5+
- **Storage Engine:** `InnoDB` (suporte a transações ACID, chaves estrangeiras e *row-level locking*)
- **Charset por Padrão:** `utf8mb4`
- **Collate:** `utf8mb4_unicode_ci`
- **Nome do Banco de Dados:** `hitek_comissoes`

---

## 2. Dicionário do Modelo Físico e Tipagem

### 2.1. Tabela `usuarios`
Armazena credenciais e permissões operacionais do sistema.

```sql
CREATE TABLE usuarios (
    id_usuario INT AUTO_INCREMENT,
    nome VARCHAR(100) NOT NULL,
    email VARCHAR(100) NOT NULL,
    senha_hash VARCHAR(255) NOT NULL,
    perfil ENUM('ADMINISTRADOR', 'FINANCEIRO', 'COLABORADOR') NOT NULL,
    ativo BOOLEAN NOT NULL DEFAULT TRUE,
    data_cadastro DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    CONSTRAINT pk_usuarios PRIMARY KEY (id_usuario),
    CONSTRAINT uk_usuarios_email UNIQUE (email)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
```

---

### 2.2. Tabela `colaboradores`
Contém as informações cadastrais e financeiras dos colaboradores e vendedores.

```sql
CREATE TABLE colaboradores (
    id_colaborador INT AUTO_INCREMENT,
    id_usuario INT NULL UNIQUE,
    cpf VARCHAR(11) NOT NULL,
    cargo VARCHAR(50) NOT NULL,
    percentual_padrao DECIMAL(5,2) NOT NULL DEFAULT 5.00,
    chave_pix VARCHAR(100) NULL,
    ativo BOOLEAN NOT NULL DEFAULT TRUE,
    CONSTRAINT pk_colaboradores PRIMARY KEY (id_colaborador),
    CONSTRAINT uk_colaboradores_cpf UNIQUE (cpf),
    CONSTRAINT fk_colaboradores_usuarios FOREIGN KEY (id_usuario)
        REFERENCES usuarios (id_usuario)
        ON DELETE SET NULL
        ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
```

---

### 2.3. Tabela `vendas`
Registra notas fiscais e vendas realizadas.

```sql
CREATE TABLE vendas (
    id_venda INT AUTO_INCREMENT,
    id_colaborador INT NOT NULL,
    numero_nf VARCHAR(20) NOT NULL,
    valor_total DECIMAL(10,2) NOT NULL,
    data_venda DATETIME NOT NULL,
    observacao VARCHAR(255) NULL,
    CONSTRAINT pk_vendas PRIMARY KEY (id_venda),
    CONSTRAINT uk_vendas_numero_nf UNIQUE (numero_nf),
    CONSTRAINT chk_vendas_valor CHECK (valor_total > 0),
    CONSTRAINT fk_vendas_colaboradores FOREIGN KEY (id_colaborador)
        REFERENCES colaboradores (id_colaborador)
        ON DELETE RESTRICT
        ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
```

---

### 2.4. Tabela `comissoes`
Mapeia os valores apurados e estados do fluxo de cada comissão.

```sql
CREATE TABLE comissoes (
    id_comissao INT AUTO_INCREMENT,
    id_venda INT NOT NULL UNIQUE,
    id_colaborador INT NOT NULL,
    percentual_aplicado DECIMAL(5,2) NOT NULL,
    valor_bruto DECIMAL(10,2) NOT NULL,
    valor_liquido DECIMAL(10,2) NOT NULL,
    status ENUM('PENDENTE', 'LIBERADA', 'PAGA', 'CANCELADA') NOT NULL DEFAULT 'PENDENTE',
    data_geracao DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    CONSTRAINT pk_comissoes PRIMARY KEY (id_comissao),
    CONSTRAINT chk_comissoes_valores CHECK (valor_bruto >= 0 AND valor_liquido >= 0),
    CONSTRAINT fk_comissoes_vendas FOREIGN KEY (id_venda)
        REFERENCES vendas (id_venda)
        ON DELETE RESTRICT
        ON UPDATE CASCADE,
    CONSTRAINT fk_comissoes_colaboradores FOREIGN KEY (id_colaborador)
        REFERENCES colaboradores (id_colaborador)
        ON DELETE RESTRICT
        ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
```

---

### 2.5. Tabela `pagamentos`
Histórico de pagamentos efetivados pelo setor financeiro.

```sql
CREATE TABLE pagamentos (
    id_pagamento INT AUTO_INCREMENT,
    id_comissao INT NOT NULL UNIQUE,
    id_usuario_financeiro INT NOT NULL,
    data_pagamento DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    valor_pago DECIMAL(10,2) NOT NULL,
    comprovante_ref VARCHAR(100) NULL,
    CONSTRAINT pk_pagamentos PRIMARY KEY (id_pagamento),
    CONSTRAINT chk_pagamentos_valor CHECK (valor_pago > 0),
    CONSTRAINT fk_pagamentos_comissoes FOREIGN KEY (id_comissao)
        REFERENCES comissoes (id_comissao)
        ON DELETE RESTRICT
        ON UPDATE CASCADE,
    CONSTRAINT fk_pagamentos_usuarios FOREIGN KEY (id_usuario_financeiro)
        REFERENCES usuarios (id_usuario)
        ON DELETE RESTRICT
        ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
```

---

### 2.6. Tabela `descontos`
Abatimentos aplicados às comissões apuradas.

```sql
CREATE TABLE descontos (
    id_desconto INT AUTO_INCREMENT,
    id_comissao INT NOT NULL,
    tipo_desconto VARCHAR(50) NOT NULL,
    valor_desconto DECIMAL(10,2) NOT NULL,
    motivo VARCHAR(255) NOT NULL,
    data_registro DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    CONSTRAINT pk_descontos PRIMARY KEY (id_desconto),
    CONSTRAINT chk_descontos_valor CHECK (valor_desconto > 0),
    CONSTRAINT fk_descontos_comissoes FOREIGN KEY (id_comissao)
        REFERENCES comissoes (id_comissao)
        ON DELETE CASCADE
        ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
```

---

### 2.7. Tabela `configuracoes`
Parâmetros do sistema.

```sql
CREATE TABLE configuracoes (
    id_configuracao INT AUTO_INCREMENT,
    chave VARCHAR(50) NOT NULL UNIQUE,
    valor VARCHAR(100) NOT NULL,
    descricao VARCHAR(255) NULL,
    data_atualizacao DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    CONSTRAINT pk_configuracoes PRIMARY KEY (id_configuracao)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
```

---

## 3. Índices de Desempenho (Otimização de Consultas)

Para garantir respostas rápidas nas telas do sistema em Linguagem C e relatórios gerenciais, foram definidos os seguintes índices:

```sql
-- Otimização de busca de vendas por período e colaborador
CREATE INDEX idx_vendas_colaborador_data ON vendas (id_colaborador, data_venda);

-- Otimização de filtragem de comissões por status
CREATE INDEX idx_comissoes_status ON comissoes (status);

-- Otimização de busca de pagamentos por data
CREATE INDEX idx_pagamentos_data ON pagamentos (data_pagamento);
```

---

## 📜 Documentação Relacionada

- [Modelo Conceitual](modelo-conceitual.md)
- [Modelo Lógico](modelo-logico.md)
- [Normalização](normalizacao.md)
