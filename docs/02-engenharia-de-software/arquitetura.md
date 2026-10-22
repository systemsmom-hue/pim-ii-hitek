# Arquitetura do Sistema

Esta seção apresenta a organização arquitetural e estrutural do **Sistema de Gestão de Comissões — Hitek Informática**.

A solução adota a **Arquitetura em Camadas (3-Tier Architecture)**, separando a interface do usuário, as regras de negócio e a persistência de dados em níveis independentes para garantir desacoplamento, segurança e facilidade de manutenção.

## Índice

- [Visão Geral](#visão-geral)
- [Arquitetura em Camadas (3-Tier)](#arquitetura-em-camadas-3-tier)
- [Usuários do Sistema e Autenticação](#usuários-do-sistema-e-autenticação)
- [Módulos Funcionais](#módulos-funcionais)
- [Dependências Arquiteturais Entre Módulos](#dependências-arquiteturais-entre-módulos)
- [Fluxo de Processo e Ciclo de Vida da Comissão](#fluxo-de-processo-e-ciclo-de-vida-da-comissão)
- [Controle de Acesso e Permissões por Perfil](#controle-de-acesso-e-permissões-por-perfil)
- [Camada de Persistência e Dados](#camada-de-persistência-e-dados)
- [Mapeamento da Implementação em C](#mapeamento-da-implementação-em-c)
- [Modelagem Relacionada](#modelagem-relacionada)
- [Observação](#observação)

---

## Visão Geral

O sistema é responsável por capturar as interações dos usuários, processar as regras de negócio de vendas e comissões, gerenciar permissões por perfil e persistir as informações na base de dados relacional.

A estrutura lógica do sistema organiza-se no seguinte fluxo de camadas:

```text
+-------------------------------------------------------+
|             CAMADA DE APRESENTAÇÃO (UI)               |
|      Interface em Consola C (printf / scanf)          |
+-------------------------------------------------------+
                           │
                           ▼
+-------------------------------------------------------+
|         CAMADA DE LÓGICA DE NEGÓCIO (DOMÍNIO)         |
|     Cálculos, Validações, Regras e Autenticação       |
+-------------------------------------------------------+
                           │
                           ▼
+-------------------------------------------------------+
|        CAMADA DE ACESSO A DADOS (PERSISTÊNCIA)        |
|          MySQL C API / Instruções SQL (CRUD)          |
+-------------------------------------------------------+
```

---

## Arquitetura em Camadas (3-Tier)

A aplicação divide-se em três camadas horizontais com responsabilidades bem definidas.

### 1. Camada de Apresentação (Interface do Usuário)

- **Responsabilidade:** Capturar dados digitados pelo usuário, exibir menus do sistema, formatar tabelas de consulta e apresentar alertas na tela.
- **Tecnologia / Implementação:** Desenvolvida em **Linguagem C**, utilizando chamadas de entrada e saída padrão (`printf`, `scanf`, tratamento de buffers) via terminal/console.
- **Componentes:** Módulos de telas e menus (`vendas.c`, `financeiro.c`, `administrador.c`).

### 2. Camada de Lógica de Negócio (Domínio e Aplicação)

- **Responsabilidade:** Processar as regras de negócio, realizar cálculos financeiros, validar permissões de usuários e gerenciar as transições de estado das comissões. Esta camada não possui conhecimento de como os dados são exibidos ou armazenados fisicamente.
- **Regras Principais:**
  - Cálculo de margem de lucro e emissão de alerta para margens inferiores a 30%.
  - Cálculo da comissão baseado na taxa configurada (padrão 1%).
  - Controle do ciclo de vida da comissão (`PENDENTE` → `LIBERADA` → `PAGA`).
  - Bloqueio de alteração do valor de custo por usuários do perfil Vendedor.
- **Componentes:** Funções de cálculo e validação (`calcularComissao()`, `calcularMargem()`, `verificarMargem()`, `autenticarUsuario()`).

### 3. Camada de Acesso a Dados (Persistência)

- **Responsabilidade:** Estabelecer a conexão com o banco de dados, executar comandos SQL e traduzir os registros da base de dados para as estruturas de dados (`structs`) do programa em C.
- **Tecnologia / Implementação:** Driver de conexão **MySQL C API** (`mysql.h`).
- **Componentes:** Instruções SQL parametrizadas (`INSERT`, `SELECT`, `UPDATE`) enviadas ao banco de dados relacional MySQL.

---

## Usuários do Sistema e Autenticação

O sistema possui três perfis de acesso distintos:

| Perfil | Responsabilidades |
|--------|-------------------|
| **Vendedor** | Registro e acompanhamento de suas vendas e comissões. |
| **Financeiro** | Validação de faturamento, confirmação de baixa e liquidação de pagamentos. |
| **Administrador** | Gestão global de usuários, colaboradores, parâmetros do sistema e relatórios. |

O acesso a qualquer funcionalidade do sistema exige autenticação prévia na camada de negócio via `autenticarUsuario()`, garantindo o controle de acesso baseado em perfil (RBAC — *Role-Based Access Control*).

---

## Módulos Funcionais

A aplicação é dividida em oito módulos funcionais organizados na camada de negócio.

### Vendas

Responsável pelas operações relacionadas ao registro e acompanhamento de vendas.

- `registrarVenda()`
- `consultarVenda()`
- `alterarSituacaoVenda()`
- `alterarValorVenda()`
- `calcularMargem()`
- `verificarMargem()`
- `alertarMargemBaixa()`

### Financeiro

Responsável pela conferência financeira e confirmação de baixa das vendas.

- `consultarVendas()`
- `verificarPagamentoFaturamento()`
- `verificarRetiradaEquipamento()`
- `confirmarBaixa()`

### Comissões

Responsável pelo cálculo e controle dos estados das comissões.

- `calcularComissao()`
- `consultarComissao()`
- `alterarStatusComissao()`
- `registrarAjusteComissao()`

### Usuários

Responsável pelo gerenciamento de credenciais e autenticação.

- `cadastrarUsuario()`
- `editarUsuario()`
- `bloquearUsuario()`
- `consultarUsuario()`
- `autenticarUsuario()`

### Colaboradores

Responsável pelo cadastro do corpo de vendedores.

- `cadastrarColaborador()`
- `editarColaborador()`
- `consultarColaborador()`

### Pagamentos

Responsável pelo registro de quitação e acompanhamento de saldos.

- `registrarPagamentoComissao()`
- `consultarPagamentos()`
- `atualizarSaldoComissao()`
- `verificarQuitacaoComissao()`

### Relatórios

Responsável pelo agrupamento e exibição de dados consolidados.

- `gerarRelatorioVendas()`
- `gerarRelatorioComissoes()`
- `visualizarRelatorio()`

### Configurações

Responsável pela parametrização das alíquotas do sistema.

- `consultarPercentualComissao()`
- `configurarPercentualComissao()`

---

## Dependências Arquiteturais Entre Módulos

As dependências funcionais entre os módulos do sistema são organizadas da seguinte forma:

```text
VENDAS ───────► COLABORADORES

FINANCEIRO ───► VENDAS
FINANCEIRO ───► COMISSÕES
FINANCEIRO ───► PAGAMENTOS

COMISSÕES ────► CONFIGURAÇÕES
COMISSÕES ────► VENDAS

PAGAMENTOS ───► COMISSÕES

RELATÓRIOS ───► VENDAS
RELATÓRIOS ───► COMISSÕES
```

---

## Fluxo de Processo e Ciclo de Vida da Comissão

A sequência operacional das regras de negócio executada entre as camadas é descrita a seguir:

```text
Vendedor registra a venda
        ↓
Sistema registra comissão como Pendente
        ↓
Vendedor pode atualizar a situação da venda
        ↓
Financeiro verifica pagamento ou faturamento
        ↓
Condições para baixa são confirmadas
        ↓
Sistema calcula a comissão
        ↓
Comissão passa para Liberada
        ↓
Financeiro registra pagamento
        ↓
Sistema atualiza valor pago e saldo
        ↓
Comissão totalmente quitada?
        ↓
Sim → Status Paga
Não → Permanece Liberada
```

> **Importante:** Quando a venda for faturada, a retirada do equipamento deverá ser confirmada antes da liberação da comissão.

A informação de retirada poderá ser atualizada pelo Vendedor, mas deverá ser verificada pelo Financeiro antes da confirmação da baixa.

---

## Controle de Acesso e Permissões por Perfil

O módulo de Vendas aplica restrições de permissão diretamente na camada de negócio.

### Vendedor

**Permissões ativas:**

```text
registrarVenda()
consultarVenda()
alterarSituacaoVenda()
alterarValorVenda()
```

**Restrições:** Não possui permissão para alterar o valor de custo nem confirmar a baixa de vendas.

### Financeiro

**Permissões ativas:**

```text
consultarVendas()
verificarPagamentoFaturamento()
verificarRetiradaEquipamento()
confirmarBaixa()
```

**Restrições:** A validação e a confirmação de baixa são responsabilidades exclusivas deste perfil.

---

## Camada de Persistência e Dados

Os dados necessários ao funcionamento do sistema serão armazenados em um banco de dados MySQL.

O modelo de dados contempla as seguintes estruturas principais:

| Tabela | Descrição |
|--------|-----------|
| `USUARIO` | Usuários e credenciais |
| `COLABORADOR` | Colaboradores e vendedores |
| `CLIENTE` | Clientes |
| `VENDA` | Vendas, valores, custos e situações |
| `COMISSAO` | Cálculos e parcelas de comissão |
| `PAGAMENTO` | Registros de quitação de pagamentos |
| `CONFIGURACAO` | Alíquotas e parâmetros do sistema |
| `AJUSTE` | Histórico de acertos e ajustes |

[Ver documentação de Banco de Dados](../04-banco-de-dados/)

---

## Mapeamento da Implementação em C

A disciplina de Programação Estruturada utilizará a linguagem C para a implementação física da arquitetura.

Os arquivos de código-fonte estão organizados no diretório:

```text
src/c/
├── main.c              # Ponto de entrada e menu principal (Apresentação)
├── autenticacao.c      # Controle de acesso e sessões (Negócio)
├── vendas.c            # Módulo de vendas e cálculo de margem (Apresentação/Negócio)
├── financeiro.c        # Módulo financeiro e confirmação de baixa (Apresentação/Negócio)
├── comissoes.c         # Módulo de regras e cálculo de comissões (Negócio)
├── relatorios.c        # Geração de relatórios (Apresentação)
└── database.c          # Conexão e rotinas MySQL C API (Persistência)
```

[Ver código-fonte](../../src/c/)

---

## Modelagem Relacionada

A arquitetura do sistema é suportada pelos seguintes diagramas UML:

- **Diagrama de Casos de Uso:** Mapeamento dos atores e funcionalidades.
- **Diagrama Estendido / Funcional:** Mapeamento das funções e dependências de módulos.
- **Modelo Entidade-Relacionamento (DER):** Modelagem lógica e física de dados.

[Ver Diagramas](../03-diagramas/)

---

## Observação

Esta documentação representa a arquitetura lógica e física atualmente definida para o projeto. Detalhes adicionais de implementação, banco de dados e infraestrutura poderão ser refinados conforme o desenvolvimento do PIM avançar.

[← Voltar para Engenharia de Software](../README.md)
