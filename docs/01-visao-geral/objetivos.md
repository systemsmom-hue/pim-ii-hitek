# Escopo do Sistema

## Dentro do escopo

O Sistema de Gestão de Comissões deverá contemplar:

- gerenciamento de colaboradores;
- cadastro de vendas;
- consulta de vendas;
- associação entre venda e colaborador responsável;
- atualização da situação da venda pelo Vendedor;
- alteração do valor da venda pelo Vendedor;
- restrição da alteração do valor de custo para o perfil Vendedor;
- cálculo automático de comissão;
- configuração do percentual de comissão;
- cálculo da margem da venda;
- alerta para margem inferior a 30%;
- visualização e atualização da situação de pagamento/faturamento;
- visualização e atualização da situação de retirada do equipamento, quando aplicável;
- confirmação da baixa pelo Financeiro;
- controle dos estados das comissões;
- registro e acompanhamento dos pagamentos das comissões;
- autenticação de usuários;
- controle de usuários e permissões;
- geração de relatórios;
- histórico de pagamentos;
- registro de ajustes de comissões;
- verificação da retirada do equipamento quando aplicável ao fluxo de venda faturada.

---

## Fora do escopo

Não fazem parte deste projeto:

- gerenciamento completo de Ordens de Serviço;
- controle de laboratório;
- controle de estoque;
- controle de compras;
- controle de peças;
- gestão completa da recepção;
- gestão completa do setor financeiro;
- substituição de todo o sistema operacional utilizado pela empresa.

---

## Limite da solução

O projeto concentra-se especificamente no processo de gestão de vendas e comissões da Hitek Informática.

O sistema deverá apoiar as atividades necessárias para:

- registrar vendas;
- consultar vendas;
- permitir ao Vendedor atualizar a situação da venda;
- permitir ao Vendedor alterar o valor da venda;
- impedir que o Vendedor altere o valor de custo;
- acompanhar a situação financeira da venda;
- permitir ao Financeiro validar as informações necessárias e confirmar a baixa;
- calcular e controlar comissões;
- registrar pagamentos;
- acompanhar a quitação das comissões;
- disponibilizar informações para consulta e geração de relatórios.

A atualização das informações da venda pelo Vendedor não substitui as responsabilidades do Financeiro no processo de verificação e confirmação da baixa.

---

## Responsabilidades principais por perfil

### Vendedor

Responsável por:

- registrar vendas;
- consultar suas vendas;
- atualizar a situação da venda;
- alterar o valor da venda;
- consultar suas comissões.

O Vendedor não poderá alterar o valor de custo nem confirmar a baixa da venda.

### Financeiro

Responsável por:

- consultar vendas;
- verificar pagamento ou faturamento;
- verificar retirada do equipamento quando aplicável;
- confirmar a baixa da venda;
- registrar pagamentos das comissões.

### Administrador

Responsável pelas funções gerais de gerenciamento, configuração e relatórios do sistema.

---

[← Voltar para Visão Geral](README.md)
