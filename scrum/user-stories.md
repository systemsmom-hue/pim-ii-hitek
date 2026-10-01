# User Stories

As User Stories representam as principais necessidades dos usuários do **Sistema de Gestão de Comissões — Hitek Informática** sob a perspectiva de cada perfil.

A estrutura utilizada é:

```text
Como [perfil],
quero [funcionalidade],
para [objetivo].
```

---

## Vendedor

### US01 — Autenticar-se no sistema

Como **Vendedor**,  
quero autenticar-me no sistema,  
para acessar somente as funcionalidades disponíveis para o meu perfil.

---

### US02 — Registrar uma venda

Como **Vendedor**,  
quero registrar uma venda,  
para que ela seja associada ao colaborador responsável e utilizada no cálculo da comissão.

---

### US03 — Consultar minhas vendas

Como **Vendedor**,  
quero consultar minhas vendas,  
para acompanhar os registros realizados no sistema.

---

### US04 — Consultar minhas comissões

Como **Vendedor**,  
quero consultar minhas comissões,  
para acompanhar seus valores e respectivos estados.

---

### US05 — Receber alerta de margem baixa

Como **Vendedor**,  
quero ser alertado quando a margem da venda for inferior a 30%,  
para ter conhecimento dessa condição durante o registro da venda.

O alerta não deverá impedir o registro.

---

## Financeiro

### US06 — Autenticar-se no sistema

Como **Financeiro**,  
quero autenticar-me no sistema,  
para acessar as funcionalidades relacionadas às minhas responsabilidades.

---

### US07 — Consultar vendas

Como **Financeiro**,  
quero consultar as vendas registradas,  
para realizar as verificações necessárias antes da confirmação da baixa.

---

### US08 — Verificar pagamento ou faturamento

Como **Financeiro**,  
quero verificar a situação de pagamento ou faturamento da venda,  
para identificar se ela atende às condições necessárias para continuidade do processo.

---

### US09 — Verificar retirada do equipamento

Como **Financeiro**,  
quero verificar a retirada do equipamento em vendas faturadas,  
para confirmar se a comissão pode ser liberada.

---

### US10 — Confirmar baixa da venda

Como **Financeiro**,  
quero confirmar a baixa da venda,  
para permitir que o sistema calcule e libere a comissão quando as condições necessárias forem atendidas.

---

### US11 — Registrar pagamento da comissão

Como **Financeiro**,  
quero registrar um pagamento de comissão,  
para manter atualizado o valor pago e o saldo restante.

---

### US12 — Registrar pagamentos parciais

Como **Financeiro**,  
quero registrar mais de um pagamento para uma mesma comissão,  
para permitir o controle de pagamentos realizados de forma parcial.

---

### US13 — Confirmar quitação da comissão

Como **Financeiro**,  
quero que o sistema verifique se a comissão foi totalmente quitada,  
para que seu status seja alterado para **Paga** quando não houver saldo restante.

---

## Administrador

### US14 — Autenticar-se no sistema

Como **Administrador**,  
quero autenticar-me no sistema,  
para acessar as funcionalidades administrativas autorizadas.

---

### US15 — Gerenciar usuários

Como **Administrador**,  
quero cadastrar, editar, consultar e bloquear usuários,  
para controlar quem possui acesso ao sistema.

---

### US16 — Gerenciar colaboradores

Como **Administrador**,  
quero cadastrar, editar e consultar colaboradores,  
para manter atualizadas as informações utilizadas no processo de vendas e comissões.

---

### US17 — Gerenciar vendas

Como **Administrador**,  
quero consultar e gerenciar as vendas registradas,  
para acompanhar as informações do processo comercial.

---

### US18 — Gerenciar comissões

Como **Administrador**,  
quero consultar e gerenciar as comissões,  
para acompanhar seus valores, estados e possíveis ajustes.

---

### US19 — Registrar ajustes de comissão

Como **Administrador**,  
quero registrar ajustes de comissão quando necessário,  
para manter o controle de diferenças identificadas posteriormente.

---

### US20 — Gerenciar pagamentos

Como **Administrador**,  
quero consultar e gerenciar informações relacionadas aos pagamentos das comissões,  
para acompanhar o processo de quitação.

---

### US21 — Configurar percentual de comissão

Como **Administrador**,  
quero consultar e alterar o percentual de comissão,  
para definir o valor utilizado nos cálculos realizados pelo sistema.

O percentual padrão considerado atualmente é de **1%**.

---

### US22 — Gerar relatório de vendas

Como **Administrador**,  
quero gerar e visualizar relatórios de vendas,  
para acompanhar as informações registradas no sistema.

---

### US23 — Gerar relatório de comissões

Como **Administrador**,  
quero gerar e visualizar relatórios de comissões,  
para acompanhar os valores e estados das comissões registradas.

---

## Relação com o Product Backlog

| User Story | Product Backlog relacionado |
|---|---|
| US01 | PB01 |
| US02 | PB04, PB06 |
| US03 | PB05 |
| US04 | PB07 |
| US05 | PB06 |
| US06 | PB01 |
| US07 | PB05 |
| US08 | PB09 |
| US09 | PB10 |
| US10 | PB09 |
| US11 | PB11 |
| US12 | PB12 |
| US13 | PB13 |
| US14 | PB01 |
| US15 | PB02 |
| US16 | PB03 |
| US17 | PB05 |
| US18 | PB07 |
| US19 | PB14 |
| US20 | PB11, PB12, PB13 |
| US21 | PB08 |
| US22 | PB15 |
| US23 | PB16 |

---

## Observação

As User Stories poderão ser revisadas conforme o desenvolvimento do projeto e a atualização do Product Backlog.

Elas devem permanecer coerentes com:

- requisitos funcionais;
- regras de negócio;
- casos de uso;
- Product Backlog;
- funcionalidades efetivamente desenvolvidas.

---

## Documentação relacionada

- [Product Backlog](product-backlog.md)
- [Requisitos Funcionais](../docs/02-engenharia-de-software/requisitos-funcionais.md)
- [Casos de Uso](../docs/02-engenharia-de-software/casos-de-uso.md)
- [Regras de Negócio](../docs/01-visao-geral/regras-de-negocio.md)

---

[← Voltar para Scrum](README.md)
