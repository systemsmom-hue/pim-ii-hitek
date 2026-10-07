# Perfis de Usuário

O Sistema de Gestão de Comissões possui três perfis principais de acesso:

- Vendedor
- Financeiro
- Administrador

Cada perfil possui responsabilidades específicas dentro do sistema.

---

## Vendedor

O Vendedor poderá:

- autenticar-se no sistema;
- registrar suas vendas;
- consultar suas vendas;
- atualizar a situação da venda;
- informar ou atualizar a situação de pagamento/faturamento;
- informar ou atualizar a situação de retirada do equipamento, quando aplicável;
- alterar o valor da venda;
- consultar suas comissões;
- acompanhar o status das comissões.

O Vendedor **não poderá alterar o valor de custo da venda**.

O Vendedor está diretamente relacionado ao início e à atualização do fluxo operacional da venda.

As informações de situação da venda atualizadas pelo Vendedor não substituem a validação realizada pelo Financeiro.

---

## Financeiro

O Financeiro poderá:

- autenticar-se no sistema;
- consultar vendas;
- verificar a situação de pagamento ou faturamento;
- verificar a retirada do equipamento quando aplicável;
- confirmar a baixa da venda;
- consultar comissões liberadas;
- registrar pagamentos das comissões;
- consultar pagamentos realizados.

O perfil Financeiro continua responsável pelas verificações necessárias antes da confirmação da baixa.

Mesmo que o Vendedor atualize a situação de pagamento, faturamento ou retirada da venda, a confirmação da baixa permanecerá sob responsabilidade do Financeiro.

---

## Administrador

O Administrador poderá:

- autenticar-se no sistema;
- gerenciar usuários;
- gerenciar colaboradores;
- gerenciar vendas;
- gerenciar comissões;
- gerenciar pagamentos;
- configurar o percentual de comissão;
- gerar e consultar relatórios;
- executar operações administrativas autorizadas.

O Administrador possui acesso às funcionalidades de configuração, gerenciamento e acompanhamento geral do sistema.

---

## Controle de acesso

As funcionalidades disponíveis para cada usuário serão determinadas pelo seu perfil.

Essa separação tem como objetivo impedir que usuários executem operações que não estejam relacionadas às suas responsabilidades dentro do processo de gestão de comissões.

No caso do Vendedor:

- poderá alterar o **valor da venda**;
- poderá atualizar a **situação da venda**;
- não poderá alterar o **valor de custo**;
- não poderá confirmar a **baixa da venda**.

A confirmação da baixa continuará sendo uma responsabilidade do perfil Financeiro.

---

[← Voltar para Visão Geral](README.md)
