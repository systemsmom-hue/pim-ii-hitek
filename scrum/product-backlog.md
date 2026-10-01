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
| RF02 — Gerenciar vendas | PB04, PB05, PB06, PB09, PB10 |
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
Verificação financeira
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

---

## Atualização do backlog

O Product Backlog deverá ser atualizado ao longo do desenvolvimento.

Quando uma funcionalidade avançar, seu status poderá ser alterado para:

- Planejado;
- Em desenvolvimento;
- Concluído.

Alterações de prioridade também poderão ser realizadas conforme as necessidades identificadas pela equipe.

---

## Documentação relacionada

- [Requisitos Funcionais](../docs/02-engenharia-de-software/requisitos-funcionais.md)
- [Regras de Negócio](../docs/01-visao-geral/regras-de-negocio.md)
- [Casos de Uso](../docs/02-engenharia-de-software/casos-de-uso.md)
- [User Stories](user-stories.md)

---

[← Voltar para Scrum](README.md)
