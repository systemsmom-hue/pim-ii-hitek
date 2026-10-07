# Requisitos Funcionais

Os requisitos funcionais descrevem as funcionalidades que o **Sistema de Gestão de Comissões — Hitek Informática** deverá disponibilizar aos seus usuários.

---

## RF01 — Gerenciar colaboradores

O sistema deverá permitir o gerenciamento dos colaboradores envolvidos no processo de vendas e comissões.

Entre as operações previstas estão:

- cadastrar colaborador;
- editar dados do colaborador;
- consultar colaborador.

Os colaboradores poderão ser associados às vendas para identificação do responsável pela comissão.

---

## RF02 — Gerenciar vendas

O sistema deverá permitir o registro, consulta e gerenciamento das vendas.

O gerenciamento das vendas deverá possibilitar:

- registrar uma venda;
- consultar vendas;
- associar a venda ao colaborador responsável;
- registrar o valor da venda;
- registrar o valor de custo;
- calcular a margem da venda;
- alertar quando a margem for inferior a 30%;
- permitir ao Vendedor atualizar a situação da venda;
- permitir ao Vendedor alterar o valor da venda;
- impedir que o perfil Vendedor altere o valor de custo;
- registrar e acompanhar a situação de pagamento ou faturamento;
- registrar e acompanhar a situação de retirada do equipamento, quando aplicável;
- registrar informações relacionadas à baixa da venda.

A atualização da situação da venda pelo Vendedor não substitui a validação do Financeiro.

A confirmação da baixa deverá permanecer sob responsabilidade do perfil Financeiro.

---

## RF03 — Gerenciar comissões

O sistema deverá permitir o gerenciamento das comissões relacionadas às vendas.

O gerenciamento deverá contemplar:

- calcular a comissão;
- consultar comissões;
- controlar o status da comissão;
- registrar ajustes de comissão;
- utilizar o percentual de comissão configurado no sistema.

Os principais estados utilizados serão:

```text
Pendente → Liberada → Paga
```

Uma comissão deverá permanecer como **Liberada** enquanto houver saldo pendente de pagamento.

---

## RF04 — Gerar relatórios

O sistema deverá permitir a geração e visualização de relatórios relacionados ao processo de vendas e comissões.

Os relatórios deverão permitir o acompanhamento das informações registradas no sistema, incluindo dados relacionados a:

- vendas;
- comissões.

---

## RF05 — Gerenciar pagamentos

O sistema deverá permitir o gerenciamento dos pagamentos das comissões.

O gerenciamento deverá possibilitar:

- registrar pagamentos de comissão;
- consultar pagamentos realizados;
- atualizar o valor pago;
- atualizar o saldo restante da comissão;
- verificar se a comissão foi totalmente quitada.

O sistema deverá permitir mais de um pagamento para a mesma comissão quando houver pagamentos parciais.

Quando o valor total da comissão for quitado, seu status deverá ser alterado para **Paga**.

---

## RF06 — Autenticar usuário

O sistema deverá exigir autenticação para permitir o acesso às suas funcionalidades.

A autenticação deverá identificar o usuário e seu respectivo perfil de acesso.

Os perfis definidos são:

- Vendedor;
- Financeiro;
- Administrador.

Após a autenticação, o usuário deverá ter acesso somente às funcionalidades correspondentes ao seu perfil.

---

## Resumo dos requisitos

| Código | Requisito |
|---|---|
| RF01 | Gerenciar colaboradores |
| RF02 | Gerenciar vendas |
| RF03 | Gerenciar comissões |
| RF04 | Gerar relatórios |
| RF05 | Gerenciar pagamentos |
| RF06 | Autenticar usuário |

---

## Relação com as permissões dos perfis

### Vendedor

No gerenciamento de vendas, o Vendedor poderá:

- registrar venda;
- consultar suas vendas;
- atualizar a situação da venda;
- alterar o valor da venda.

O Vendedor não poderá:

- alterar o valor de custo;
- confirmar a baixa da venda.

### Financeiro

O Financeiro poderá:

- consultar vendas;
- verificar pagamento ou faturamento;
- verificar retirada do equipamento quando aplicável;
- confirmar a baixa;
- registrar pagamentos das comissões.

### Administrador

O Administrador poderá realizar as operações administrativas e de gerenciamento previstas para seu perfil.

---

[← Voltar para Engenharia de Software](README.md)
