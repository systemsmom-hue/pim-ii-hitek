# Sprint 05 — Consolidação da Modelagem Funcional

A Sprint 05 representa a etapa de consolidação dos principais artefatos de modelagem do **Sistema de Gestão de Comissões — Hitek Informática**.

Nesta etapa, os diagramas e regras já desenvolvidos foram revisados para garantir maior coerência entre requisitos, casos de uso, regras de negócio e fluxo operacional.

Também foi desenvolvido o **Diagrama Estendido**, utilizado para representar a organização funcional do sistema em módulos e funções.

> Esta divisão em Sprints foi organizada posteriormente com base na sequência real de desenvolvimento registrada durante o projeto.

---

## Período

O período desta Sprint não foi formalizado no início do projeto.

---

## Objetivo da Sprint

Consolidar a modelagem funcional do sistema, revisando os artefatos já desenvolvidos e representando de forma mais precisa:

- autenticação dos usuários;
- responsabilidades dos atores;
- relacionamentos entre casos de uso;
- confirmação da baixa;
- cálculo e liberação das comissões;
- pagamentos e quitação;
- organização dos módulos e funções do sistema.

---

## Atividades realizadas

| ID | Atividade | Status |
|---|---|---|
| SP05-01 | Revisar o Diagrama de Casos de Uso | ✅ Concluído |
| SP05-02 | Incluir autenticação obrigatória no sistema | ✅ Concluído |
| SP05-03 | Revisar os relacionamentos `<<include>>` e `<<extend>>` | ✅ Concluído |
| SP05-04 | Refinar o caso de uso Registrar Venda | ✅ Concluído |
| SP05-05 | Refinar o caso de uso Confirmar Baixa da Venda | ✅ Concluído |
| SP05-06 | Refinar o caso de uso Registrar Pagamento da Comissão | ✅ Concluído |
| SP05-07 | Refinar o fluxo de pagamento e quitação da comissão | ✅ Concluído |
| SP05-08 | Revisar o Diagrama de Atividade | ✅ Concluído |
| SP05-09 | Desenvolver o Diagrama Estendido | ✅ Concluído |
| SP05-10 | Definir os módulos funcionais do sistema | ✅ Concluído |
| SP05-11 | Definir as principais funções de cada módulo | ✅ Concluído |
| SP05-12 | Revisar as dependências entre os módulos | ✅ Concluído |
| SP05-13 | Revisar a coerência entre requisitos, regras, casos de uso e diagramas | ✅ Concluído |

---

## Autenticação obrigatória

Durante esta etapa foi consolidada a necessidade de autenticação dos usuários.

O sistema deverá permitir o acesso somente após a identificação do usuário.

Os três perfis considerados são:

- Vendedor;
- Financeiro;
- Administrador.

A autenticação passou a ser representada no Diagrama de Casos de Uso por meio do caso:

**Autenticar Usuário**

Após a autenticação, o sistema deverá disponibilizar somente as funcionalidades correspondentes ao perfil do usuário.

---

## Revisão do Diagrama de Casos de Uso

O Diagrama de Casos de Uso foi revisado para representar de forma mais precisa as responsabilidades dos três atores.

### Vendedor

Principais casos de uso:

- Registrar Venda;
- Consultar Vendas;
- Consultar Comissão;
- Autenticar Usuário.

### Financeiro

Principais casos de uso:

- Consultar Vendas;
- Confirmar Baixa da Venda;
- Registrar Pagamento da Comissão;
- Autenticar Usuário.

### Administrador

Principais casos de uso:

- Gerenciar Usuários;
- Gerenciar Colaboradores;
- Gerenciar Vendas;
- Gerenciar Comissões;
- Gerenciar Pagamentos;
- Gerar Relatórios;
- Configurar Percentual de Comissão;
- Autenticar Usuário.

---

## Relacionamentos `<<include>>` e `<<extend>>`

Os relacionamentos do Diagrama de Casos de Uso foram revisados de acordo com o comportamento das funcionalidades.

### Registro da venda

O registro de uma venda inclui obrigatoriamente a verificação da margem.

```text
Registrar Venda
      |
      | <<include>>
      ↓
Verificar Margem
```

Quando a margem for inferior a 30%, ocorre uma extensão condicional:

```text
Alertar Margem Inferior a 30%
              |
              | <<extend>>
              ↓
        Verificar Margem
```

---

## Confirmação da baixa

O caso de uso **Confirmar Baixa da Venda** passou a representar as operações necessárias para liberação da comissão.

Inclui:

- verificar pagamento ou faturamento;
- registrar data e usuário responsável pela baixa;
- calcular comissão;
- alterar o status para Liberada.

Representação:

```text
Confirmar Baixa da Venda
        |
        | <<include>>
        ├── Verificar Pagamento/Faturamento
        ├── Registrar Data e Usuário da Baixa
        ├── Calcular Comissão
        └── Alterar Status para Liberada
```

---

## Retirada do equipamento

Nas vendas faturadas, a retirada do equipamento representa uma condição específica.

Por esse motivo, foi tratada como comportamento condicional relacionado à confirmação da baixa.

```text
Verificar Retirada do Equipamento
              |
              | <<extend>>
              ↓
     Confirmar Baixa da Venda
```

Caso a retirada ainda não tenha ocorrido, a comissão permanece como:

**Pendente**

---

## Pagamento da comissão

O processo de pagamento também foi refinado.

Após registrar um pagamento, o sistema deverá verificar se a comissão foi totalmente quitada.

```text
Registrar Pagamento da Comissão
              |
              | <<include>>
              ↓
     Verificar Quitação da Comissão
```

Caso a comissão esteja totalmente quitada:

```text
Alterar Status para Paga
            |
            | <<extend>>
            ↓
Verificar Quitação da Comissão
```

Caso ainda exista saldo pendente, a comissão continuará com o status:

**Liberada**

---

## Pagamentos parciais

O fluxo passou a considerar a possibilidade de mais de um pagamento para uma mesma comissão.

Após cada pagamento, o sistema deverá:

1. registrar o valor pago;
2. atualizar o valor total já pago;
3. atualizar o saldo restante;
4. verificar a quitação da comissão.

Enquanto existir saldo:

```text
Liberada
   ↓
Pagamento parcial
   ↓
Atualização do saldo
   ↓
Liberada
```

Quando não houver mais saldo:

```text
Liberada
   ↓
Quitação
   ↓
Paga
```

---

## Revisão do Diagrama de Atividade

O Diagrama de Atividade também foi revisado para acompanhar as regras consolidadas.

O fluxo principal passou a representar:

```text
Registrar venda
        ↓
Comissão Pendente
        ↓
Verificar pagamento/faturamento
        ↓
Verificar retirada quando necessário
        ↓
Confirmar baixa
        ↓
Registrar data e usuário da baixa
        ↓
Calcular comissão
        ↓
Comissão Liberada
        ↓
Registrar pagamento
        ↓
Atualizar saldo
        ↓
Verificar quitação
        ↓
Quitada?
   ↙          ↘
Não            Sim
 ↓              ↓
Liberada       Paga
```

---

# Diagrama Estendido

Nesta Sprint foi desenvolvido o **Diagrama Estendido — Sistema de Gestão de Comissões**.

O diagrama foi utilizado para representar a organização funcional da solução em módulos e funções.

Diferentemente de um diagrama de classes tradicional, o foco está nas funções previstas para a implementação estruturada do sistema.

---

## Módulos funcionais

Foram definidos oito módulos principais:

```text
VENDAS
FINANCEIRO
COMISSÕES
USUÁRIOS
COLABORADORES
PAGAMENTOS
RELATÓRIOS
CONFIGURAÇÕES
```

---

## Módulo Vendas

Principais funções:

```text
registrarVenda(): void
consultarVenda(): void
calcularMargem(): void
verificarMargem(): void
alertarMargemBaixa(): void
```

---

## Módulo Financeiro

Principais funções:

```text
consultarVendas(): void
verificarPagamentoFaturamento(): void
confirmarBaixa(): void
verificarRetiradaEquipamento(): void
```

---

## Módulo Comissões

Principais funções:

```text
calcularComissao(): void
consultarComissao(): void
alterarStatusComissao(): void
registrarAjusteComissao(): void
```

---

## Módulo Usuários

Principais funções:

```text
cadastrarUsuario(): void
editarUsuario(): void
bloquearUsuario(): void
consultarUsuario(): void
autenticarUsuario(): void
```

---

## Módulo Colaboradores

Principais funções:

```text
cadastrarColaborador(): void
editarColaborador(): void
consultarColaborador(): void
```

---

## Módulo Pagamentos

Principais funções:

```text
registrarPagamentoComissao(): void
consultarPagamentos(): void
atualizarSaldoComissao(): void
verificarQuitacaoComissao(): void
```

---

## Módulo Relatórios

Principais funções:

```text
gerarRelatorioVendas(): void
gerarRelatorioComissoes(): void
visualizarRelatorio(): void
```

---

## Módulo Configurações

Principais funções:

```text
consultarPercentualComissao(): void
configurarPercentualComissao(): void
```

---

## Dependências entre módulos

As principais dependências funcionais definidas foram:

```text
VENDAS → COLABORADORES
VENDAS → COMISSÕES

FINANCEIRO → VENDAS
FINANCEIRO → COMISSÕES
FINANCEIRO → PAGAMENTOS

COMISSÕES → CONFIGURAÇÕES

PAGAMENTOS → COMISSÕES

RELATÓRIOS → VENDAS
RELATÓRIOS → COMISSÕES
```

Essas relações indicam quais módulos utilizam informações ou funcionalidades disponibilizadas por outros módulos.

---

## Coerência entre os diagramas

Ao final desta Sprint, os três principais diagramas passaram a representar diferentes perspectivas do mesmo sistema.

### Diagrama de Casos de Uso

Responde:

```text
Quem utiliza o sistema e o que pode fazer?
```

### Diagrama de Atividade

Responde:

```text
Como o processo acontece e em qual ordem?
```

### Diagrama Estendido

Responde:

```text
Como o sistema está organizado em módulos e funções?
```

---

## Resultado da Sprint

Ao final desta etapa, estavam consolidados:

- atores principais;
- autenticação;
- casos de uso principais;
- relacionamentos `<<include>>`;
- relacionamentos `<<extend>>`;
- fluxo de baixa;
- fluxo de venda faturada;
- retirada do equipamento;
- pagamento da comissão;
- verificação de quitação;
- fluxo de pagamentos parciais;
- Diagrama de Casos de Uso revisado;
- Diagrama de Atividade revisado;
- Diagrama Estendido;
- módulos funcionais;
- principais funções;
- dependências entre módulos.

Essa etapa consolidou a base de Engenharia de Software necessária para avançar para as etapas de banco de dados e implementação.

---

## Itens ainda pendentes

Ao final desta Sprint, ainda permaneciam como próximos trabalhos:

- revisão definitiva do banco de dados;
- modelo conceitual;
- DER final;
- modelo lógico;
- normalização;
- modelo físico;
- scripts SQL;
- seleção das funções que serão implementadas em C;
- implementação em C;
- documentação de Redes;
- documentação de Pesquisa e Inovação;
- documentação de Direitos Humanos e Inclusão;
- integração final do projeto.

---

## Documentação relacionada

- [Casos de Uso](../../docs/02-engenharia-de-software/casos-de-uso.md)
- [Arquitetura](../../docs/02-engenharia-de-software/arquitetura.md)
- [Regras de Negócio](../../docs/01-visao-geral/regras-de-negocio.md)
- [Diagrama de Casos de Uso](../../docs/03-diagramas/casos-de-uso.png)
- [Diagrama de Atividade](../../docs/03-diagramas/atividade.png)
- [Diagrama Estendido](../../docs/03-diagramas/estendido.png)

---

[← Voltar para Scrum](../README.md)
