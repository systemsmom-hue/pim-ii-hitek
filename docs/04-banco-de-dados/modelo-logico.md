# 📐 Modelo Lógico de Banco de Dados

Este documento descreve o **Modelo Lógico de Banco de Dados** para o **Sistema de Gestão de Comissões — Hitek Informática**. Ele converte as entidades e relacionamentos identificados no Modelo Conceitual em uma estrutura de tabelas relacionais com definições formais de chaves primárias (PK), chaves estrangeiras (FK) e regras de integridade.

---

## 1. Esquema Relacional de Tabelas

Abaixo está o esquema textual das tabelas mapeadas para o modelo relacional:

* **`usuarios`** (**`id_usuario`**, `nome`, `email`, `senha_hash`, `perfil`, `ativo`, `data_cadastro`)
* **`colaboradores`** (**`id_colaborador`**, *`id_usuario`*, `cpf`, `cargo`, `percentual_padrao`, `chave_pix`, `ativo`)
* **`vendas`** (**`id_venda`**, *`id_colaborador`*, `numero_nf`, `valor_total`, `data_venda`, `observacao`)
* **`comissoes`** (**`id_comissao`**, *`id_venda`*, *`id_colaborador`*, `percentual_aplicado`, `valor_bruto`, `valor_liquido`, `status`, `data_geracao`)
* **`pagamentos`** (**`id_pagamento`**, *`id_comissao`*, *`id_usuario_financeiro`*, `data_pagamento`, `valor_pago`, `comprovante_ref`)
* **`descontos`** (**`id_desconto`**, *`id_comissao`*, `tipo_desconto`, `valor_desconto`, `motivo`, `data_registro`)
* **`configuracoes`** (**`id_configuracao`**, `chave`, `valor`, `descricao`, `data_atualizacao`)

---

## 2. Dicionário da Estrutura Lógica

### 2.1. Tabela `usuarios`
Armazena os dados de autenticação e permissão dos usuários da plataforma.

| Atributo | Tipo Lógico | Restrições / Regras | Descrição |
| :--- | :--- | :--- | :--- |
| `id_usuario` | Inteiro | **PK**, Autoincremento | Identificador único do usuário |
| `nome` | Texto (100) | Não Nulo | Nome completo do usuário |
| `email` | Texto (100) | Não Nulo, Único | E-mail de login do usuário |
| `senha_hash` | Texto (255) | Não Nulo | Hash seguro da senha de acesso |
| `perfil` | Enumeração | Não Nulo | Perfil (`ADMINISTRADOR`, `FINANCEIRO`, `COLABORADOR`) |
| `ativo` | Booleano | Padrão: Verdadeiro | Indica se a conta está ativa |
| `data_cadastro` | Data/Hora | Padrão: Atual | Data/Hora do cadastro |

---

### 2.2. Tabela `colaboradores`
Contém as informações cadastrais e financeiras dos vendedores da Hitek Informática.

| Atributo | Tipo Lógico | Restrições / Regras | Descrição |
| :--- | :--- | :--- | :--- |
| `id_colaborador` | Inteiro | **PK**, Autoincremento | Identificador único do colaborador |
| `id_usuario` | Inteiro | **FK** (`usuarios.id_usuario`), Único, Opcional | Vínculo com a conta de usuário |
| `cpf` | Texto (11) | Não Nulo, Único | CPF do colaborador |
| `cargo` | Texto (50) | Não Nulo | Cargo ou função na empresa |
| `percentual_padrao` | Decimal (5,2) | Não Nulo, Padrão: 5.00 | Porcentagem base de comissão (%) |
| `chave_pix` | Texto (100) | Opcional | Chave PIX para pagamento de comissões |
| `ativo` | Booleano | Padrão: Verdadeiro | Status de atividade do colaborador |

---

### 2.3. Tabela `vendas`
Registra cada nota fiscal e operação de venda efetuada por um colaborador.

| Atributo | Tipo Lógico | Restrições / Regras | Descrição |
| :--- | :--- | :--- | :--- |
| `id_venda` | Inteiro | **PK**, Autoincremento | Identificador único da venda |
| `id_colaborador` | Inteiro | **FK** (`colaboradores.id_colaborador`), Não Nulo | Vendedor responsável |
| `numero_nf` | Texto (20) | Não Nulo, Único | Número da Nota Fiscal ou Pedido |
| `valor_total` | Decimal (10,2) | Não Nulo, Valor > 0 | Valor total bruto da venda (R$) |
| `data_venda` | Data/Hora | Não Nulo | Data e hora de emissão da venda |
| `observacao` | Texto (255) | Opcional | Observações sobre a venda |

---

### 2.4. Tabela `comissoes`
Mapeia o direito de comissão calculado a partir de cada venda efetuada.

| Atributo | Tipo Lógico | Restrições / Regras | Descrição |
| :--- | :--- | :--- | :--- |
| `id_comissao` | Inteiro | **PK**, Autoincremento | Identificador único da comissão |
| `id_venda` | Inteiro | **FK** (`vendas.id_venda`), Único, Não Nulo | Venda de origem |
| `id_colaborador` | Inteiro | **FK** (`colaboradores.id_colaborador`), Não Nulo | Colaborador beneficiário |
| `percentual_aplicado` | Decimal (5,2) | Não Nulo | Percentual final de comissão (%) |
| `valor_bruto` | Decimal (10,2) | Não Nulo | Valor bruto da comissão (R$) |
| `valor_liquido` | Decimal (10,2) | Não Nulo | Valor líquido após descontos (R$) |
| `status` | Enumeração | Padrão: `PENDENTE` | Estado (`PENDENTE`, `LIBERADA`, `PAGA`, `CANCELADA`) |
| `data_geracao` | Data/Hora | Padrão: Atual | Data de geração do registro |

---

### 2.5. Tabela `pagamentos`
Guarda o histórico de quitação das comissões autorizadas pelo setor financeiro.

| Atributo | Tipo Lógico | Restrições / Regras | Descrição |
| :--- | :--- | :--- | :--- |
| `id_pagamento` | Inteiro | **PK**, Autoincremento | Identificador único do pagamento |
| `id_comissao` | Inteiro | **FK** (`comissoes.id_comissao`), Único, Não Nulo | Comissão quitada |
| `id_usuario_financeiro` | Inteiro | **FK** (`usuarios.id_usuario`), Não Nulo | Operador do financeiro que deu a baixa |
| `data_pagamento` | Data/Hora | Padrão: Atual | Data e hora da efetivação |
| `valor_pago` | Decimal (10,2) | Não Nulo, Valor > 0 | Valor final pago (R$) |
| `comprovante_ref` | Texto (100) | Opcional | Identificador ou link do comprovante |

---

### 2.6. Tabela `descontos`
Registra eventuais abatimentos ou estornos incidentes sobre uma comissão.

| Atributo | Tipo Lógico | Restrições / Regras | Descrição |
| :--- | :--- | :--- | :--- |
| `id_desconto` | Inteiro | **PK**, Autoincremento | Identificador único do desconto |
| `id_comissao` | Inteiro | **FK** (`comissoes.id_comissao`), Não Nulo | Comissão associada |
| `tipo_desconto` | Texto (50) | Não Nulo | Categoria do desconto (ex.: Estorno, Taxa) |
| `valor_desconto` | Decimal (10,2) | Não Nulo, Valor > 0 | Valor deduzido (R$) |
| `motivo` | Texto (255) | Não Nulo | Justificativa detalhada do desconto |
| `data_registro` | Data/Hora | Padrão: Atual | Data do registro do desconto |

---

### 2.7. Tabela `configuracoes`
Armazena parâmetros gerais de funcionamento do sistema.

| Atributo | Tipo Lógico | Restrições / Regras | Descrição |
| :--- | :--- | :--- | :--- |
| `id_configuracao` | Inteiro | **PK**, Autoincremento | Identificador do parâmetro |
| `chave` | Texto (50) | Não Nulo, Único | Chave identificadora (ex.: `PERCENTUAL_PADRAO`) |
| `valor` | Texto (100) | Não Nulo | Valor atribuído à chave |
| `descricao` | Texto (255) | Opcional | Descrição da utilidade do parâmetro |
| `data_atualizacao` | Data/Hora | Padrão: Atual | Última modificação |

---

## 3. Regras de Integridade Referencial

1. **Exclusão/Atualização de Colaboradores (`colaboradores` $\rightarrow$ `vendas` / `comissoes`):**
   * Não é permitida a exclusão física (`RESTRICT`) de colaboradores com vendas ou comissões cadastradas. O sistema utiliza exclusão lógica através da flag `ativo = FALSE`.

2. **Integridade das Vendas e Comissões (`vendas` $\rightarrow$ `comissoes`):**
   * Cada venda possui no máximo uma comissão associada. A alteração no ID da venda se propaga em cascata (`ON UPDATE CASCADE`).

3. **Restrições de Pagamento (`comissoes` $\rightarrow$ `pagamentos`):**
   * Somente comissões com status `LIBERADA` podem receber registro na tabela `pagamentos`. Uma vez registrado o pagamento, o status da comissão é atualizado para `PAGA`.

---

## 📜 Documentação Relacionada

* [Modelo Conceitual](modelo-conceitual.md)
* [Modelo Físico](modelo-fisico.md)
* [Normalização](normalizacao.md)
