# Product Backlog

O Product Backlog reúne as principais funcionalidades previstas para o desenvolvimento do **Sistema de Gestão de Comissões — Hitek Informática**.

Os itens abaixo foram definidos com base nos requisitos funcionais e nas regras de negócio atualmente estabelecidas para o projeto.

---

## Backlog do Produto

| ID | Item | Descrição | Prioridade | Status |
|---|---|---|---|---|
| PB01 | Autenticação de usuários | Permitir que Vendedor, Financeiro e Administrador realizem autenticação no sistema e tenham acesso conforme seu perfil. | Alta | Planejado |
| PB02 | Gerenciamento de usuários | Permitir cadastrar, editar, consultar e bloquear usuários do sistema. | Alta | Planejado |
| PB03 | Gerenciamento de colaboradores | Permitir cadastrar, editar e consultar colaboradores responsáveis pelas vendas e comissões. | Alta | Planejado |
| PB04 | Registro de vendas | Permitir registrar uma venda e associá-la ao colaborador responsável. | Alta | Planejado |
| PB05 | Consulta de vendas | Permitir consultar as vendas registradas conforme as permissões de cada perfil. | Alta | Planejado |
| PB06 | Cálculo e verificação de margem | Calcular a margem da venda e alertar quando o valor for inferior a 30%, sem impedir o registro. | Alta | Planejado |
| PB07 | Controle de comissões | Calcular a comissão e controlar seus estados: Pendente, Liberada e Paga. | Alta | Planejado |
| PB08 | Configuração do percentual de comissão | Permitir que o Administrador consulte e altere o percentual utilizado no cálculo das comissões. | Média | Planejado |
| PB09 | Confirmação da baixa | Permitir ao Financeiro verificar pagamento ou faturamento e confirmar a baixa da venda. | Alta | Planejado |
| PB10 | Controle de venda faturada | Exigir a confirmação da retirada do equipamento antes da liberação da comissão em vendas faturadas. | Alta | Planejado |
| PB11 | Registro de pagamentos | Permitir registrar pagamentos das comissões e atualizar o valor pago e o saldo restante. | Alta | Planejado |
| PB12 | Pagamentos parciais | Permitir múltiplos pagamentos para uma mesma comissão, mantendo-a como Liberada enquanto existir saldo. | Alta | Planejado |
| PB13 | Verificação de quitação | Verificar se a comissão foi totalmente quitada e alterar seu status para Paga quando necessário. | Alta | Planejado |
| PB14 | Ajustes de comissão | Permitir o registro de ajustes relacionados às comissões quando necessário. | Média | Planejado |
| PB15 | Relatórios de vendas | Permitir ao Administrador gerar e visualizar relatórios relacionados às vendas. | Média | Planejado |
| PB16 | Relatórios de comissões | Permitir ao Administrador gerar e visualizar relatórios relacionados às comissões. | Média | Planejado |
| PB17 | Atualização da situação da venda | Permitir ao Vendedor atualizar informações da situação da venda, incluindo pagamento/faturamento e retirada quando aplicável. | Alta | Planejado |
| PB18 | Alteração do valor da venda | Permitir ao Vendedor alterar o valor da venda, sem permitir a alteração do valor de custo. | Alta | Planejado |

---

## Regras relacionadas aos novos itens

### PB17 — Atualização da situação da venda

O Vendedor poderá atualizar informações relacionadas à situação da venda.

Entre as informações previstas estão:

- situação de pagamento;
- situação de faturamento;
- situação de retirada do equipamento, quando aplicável.

A atualização realizada pelo Vendedor não substitui a validação do Financeiro.

O Financeiro continuará responsável pela verificação das informações e pela confirmação da baixa.

---

### PB18 — Alteração do valor da venda

O Vendedor poderá alterar o **valor da venda** quando necessário.

O perfil Vendedor **não poderá alterar o valor de custo**.

A alteração do valor da venda deverá ser considerada nos cálculos relacionados à margem e à comissão conforme as regras do sistema.

---

## Prioridades

As prioridades utilizadas no backlog são:

| Prioridade | Significado |
|---|---|
| Alta | Funcionalidade essencial para o funcionamento do fluxo principal do sistema |
| Média | Funcionalidade importante, mas que depende ou complementa funcionalidades principais |
| Baixa | Funcionalidade complementar que pode ser desenvolvida posteriormente |

As prioridades poderão ser revistas conforme o andamento do projeto e as decisões da equipe.

---

## Relação com os Requisitos Funcionais

| Requisito | Itens relacionados |
|---|---|
| RF01 — Gerenciar colaboradores | PB03 |
| RF02 — Gerenciar vendas | PB04, PB05, PB06, PB09, PB10, PB17, PB18 |
| RF03 — Gerenciar comissões | PB07, PB08, PB14 |
| RF04 — Gerar relatórios | PB15, PB16 |
| RF05 — Gerenciar pagamentos | PB11, PB12, PB13 |
| RF06 — Autenticar usuário | PB01, PB02 |

---

## Fluxo principal relacionado ao backlog

```text
Autenticação
      ↓
Registro da venda
      ↓
Cálculo e verificação da margem
      ↓
Comissão Pendente
      ↓
Vendedor pode atualizar a situação da venda
      ↓
Financeiro verifica as informações
      ↓
Confirmação da baixa
      ↓
Comissão Liberada
      ↓
Registro de pagamento
      ↓
Verificação de quitação
      ↓
Comissão Paga
```

Em vendas faturadas, deverá ser confirmada a retirada do equipamento antes da liberação da comissão.

A situação de retirada poderá ser atualizada pelo Vendedor, mas deverá ser verificada pelo Financeiro antes da confirmação da baixa.

---

## Separação de responsabilidades

### Vendedor

Relaciona-se principalmente aos itens:

```text
PB04
PB05
PB06
PB07
PB17
PB18
```

O Vendedor poderá:

- registrar vendas;
- consultar suas vendas;
- consultar suas comissões;
- atualizar a situação da venda;
- alterar o valor da venda.

Não poderá:

- alterar o valor de custo;
- confirmar a baixa.

### Financeiro

Relaciona-se principalmente aos itens:

```text
PB05
PB09
PB10
PB11
PB12
PB13
```

O Financeiro continuará responsável por:

- verificar pagamento ou faturamento;
- verificar retirada do equipamento quando aplicável;
- confirmar a baixa;
- registrar pagamentos das comissões;
- acompanhar a quitação.

---

## Atualização do backlog

O Product Backlog deverá ser atualizado ao longo do desenvolvimento.

Quando uma funcionalidade avançar, seu status poderá ser alterado para:

- Planejado;
- Em desenvolvimento;
- Concluído.

Alterações de prioridade também poderão ser realizadas conforme as necessidades identificadas pela equipe e as decisões do Product Owner.

---

## Documentação relacionada

- [Requisitos Funcionais](../docs/02-engenharia-de-software/requisitos-funcionais.md)
- [Regras de Negócio](../docs/01-visao-geral/regras-de-negocio.md)
- [Casos de Uso](../docs/02-engenharia-de-software/casos-de-uso.md)
- [User Stories](user-stories.md)

---

[← Voltar para Scrum](README.md)
