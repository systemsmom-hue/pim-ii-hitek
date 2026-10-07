# Arquitetura do Sistema

Esta seção apresenta a organização lógica do **Sistema de Gestão de Comissões — Hitek Informática**.

A arquitetura detalhada de implementação ainda será refinada durante o desenvolvimento. Neste momento, a solução está organizada com base nos módulos funcionais já definidos no projeto.

---

## Visão geral

O sistema será responsável por receber as ações dos usuários, aplicar as regras de negócio, registrar as informações e permitir consultas relacionadas ao processo de vendas e comissões.

A organização lógica pode ser representada da seguinte forma:

```text
Usuários
   ↓
Funcionalidades do sistema
   ↓
Regras de negócio
   ↓
Dados do sistema
```

---

## Usuários do sistema

O sistema possui três perfis principais:

- Vendedor;
- Financeiro;
- Administrador.

Cada perfil terá acesso às funcionalidades correspondentes às suas responsabilidades.

Antes de utilizar as funcionalidades protegidas, o usuário deverá ser autenticado.

---

## Módulos funcionais

O sistema foi organizado em oito módulos principais.

### Vendas

Responsável pelas operações relacionadas às vendas.

Principais funções:

- registrar venda;
- consultar venda;
- atualizar situação da venda;
- alterar valor da venda;
- calcular margem;
- verificar margem;
- alertar margem baixa.

A alteração do valor de custo não estará disponível para o perfil Vendedor.

A atualização da situação da venda pelo Vendedor também não substitui a validação realizada pelo Financeiro.

---

### Financeiro

Responsável pelas verificações financeiras necessárias para liberação das comissões.

Principais funções:

- consultar vendas;
- verificar pagamento ou faturamento;
- confirmar baixa;
- verificar retirada do equipamento.

O Financeiro continuará responsável pela confirmação da baixa, mesmo quando as informações da situação da venda forem atualizadas pelo Vendedor.

---

### Comissões

Responsável pelo cálculo e controle das comissões.

Principais funções:

- calcular comissão;
- consultar comissão;
- alterar status da comissão;
- registrar ajuste de comissão.

---

### Usuários

Responsável pelo gerenciamento e autenticação dos usuários do sistema.

Principais funções:

- cadastrar usuário;
- editar usuário;
- bloquear usuário;
- consultar usuário;
- autenticar usuário.

---

### Colaboradores

Responsável pelo gerenciamento dos colaboradores relacionados às vendas.

Principais funções:

- cadastrar colaborador;
- editar colaborador;
- consultar colaborador.

---

### Pagamentos

Responsável pelo registro e acompanhamento dos pagamentos das comissões.

Principais funções:

- registrar pagamento da comissão;
- consultar pagamentos;
- atualizar saldo da comissão;
- verificar quitação da comissão.

---

### Relatórios

Responsável pela geração e visualização das informações consolidadas do sistema.

Principais funções:

- gerar relatório de vendas;
- gerar relatório de comissões;
- visualizar relatório.

---

### Configurações

Responsável pelos parâmetros utilizados pelo sistema.

Principais funções:

- consultar percentual de comissão;
- configurar percentual de comissão.

---

## Dependências entre os módulos

Os módulos possuem dependências funcionais entre si.

As principais relações definidas são:

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

Essas relações representam a necessidade de um módulo utilizar informações ou funcionalidades disponibilizadas por outro módulo.

---

## Fluxo principal

De forma simplificada, o fluxo principal da solução é:

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

Quando a venda for faturada, a retirada do equipamento deverá ser confirmada antes da liberação da comissão.

A informação de retirada poderá ser atualizada pelo Vendedor, mas deverá ser verificada pelo Financeiro antes da confirmação da baixa.

---

## Alteração das informações da venda

O módulo de Vendas deverá respeitar as permissões definidas para cada perfil.

### Vendedor

Poderá:

```text
registrarVenda()
consultarVenda()
alterarSituacaoVenda()
alterarValorVenda()
```

Não poderá alterar o valor de custo nem confirmar a baixa.

### Financeiro

Será responsável pelas verificações necessárias para a confirmação da baixa:

```text
consultarVendas()
verificarPagamentoFaturamento()
verificarRetiradaEquipamento()
confirmarBaixa()
```

Essa separação mantém a atualização operacional da venda e a validação financeira como responsabilidades distintas.

---

## Dados

Os dados necessários ao funcionamento do sistema serão armazenados em banco de dados.

O modelo de dados deverá contemplar as informações necessárias para representar:

- usuários;
- colaboradores;
- vendas;
- valor da venda;
- valor de custo;
- situação de pagamento ou faturamento;
- situação de retirada;
- comissões;
- pagamentos;
- configurações;
- ajustes.

O modelo de dados será detalhado na seção específica de Banco de Dados do projeto.

[Ver documentação de Banco de Dados](../04-banco-de-dados/)

---

## Implementação

A disciplina de Programação Estruturada utilizará a linguagem **C** para implementação das funcionalidades selecionadas do projeto.

Os arquivos de código-fonte serão organizados em:

```text
src/c/
```

[Ver Programação em C](../../src/c/)

---

## Modelagem relacionada

A organização funcional do sistema também está representada pelos diagramas desenvolvidos no projeto:

- Diagrama de Casos de Uso;
- Diagrama Estendido.

[Ver Diagramas](../03-diagramas/)

---

## Observação

Esta documentação representa a arquitetura lógica atualmente definida para o projeto.

Detalhes adicionais de implementação, banco de dados e infraestrutura poderão ser refinados conforme o desenvolvimento do PIM avançar.

---

[← Voltar para Engenharia de Software](README.md)
