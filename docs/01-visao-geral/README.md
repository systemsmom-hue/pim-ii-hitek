# Visão Geral do Projeto

Esta seção reúne as informações fundamentais do **Sistema de Gestão de Comissões — Hitek Informática**.

Aqui estão documentados:

- o problema identificado;
- a solução proposta;
- os objetivos do projeto;
- o escopo do sistema;
- os perfis de usuário;
- as principais regras de negócio.

---

## Conteúdo

### Problema e solução

Apresenta o problema identificado no processo atual da Hitek Informática e a solução computacional proposta.

[Ver problema e solução](problema-e-solucao.md)

---

### Objetivos

Apresenta o objetivo geral e os objetivos específicos do projeto.

[Ver objetivos](objetivos.md)

---

### Escopo

Define o que faz parte do sistema e o que está fora do escopo do projeto.

[Ver escopo](escopo.md)

---

### Perfis de usuário

Apresenta os três perfis de acesso do sistema:

- Vendedor;
- Financeiro;
- Administrador.

Também define as responsabilidades e limitações de cada perfil.

Entre as permissões atualmente definidas, o Vendedor poderá:

- registrar e consultar suas vendas;
- atualizar a situação da venda;
- alterar o valor da venda;
- consultar suas comissões.

O Vendedor não poderá:

- alterar o valor de custo;
- confirmar a baixa da venda.

A confirmação da baixa permanece sob responsabilidade do Financeiro.

[Ver perfis de usuário](perfis-de-usuario.md)

---

### Regras de negócio

Apresenta as regras que controlam o funcionamento do sistema, incluindo:

- percentual de comissão;
- margem da venda;
- atualização da situação da venda;
- alteração do valor da venda;
- restrição de alteração do valor de custo;
- confirmação da baixa;
- venda faturada;
- retirada do equipamento;
- estados da comissão;
- pagamentos parciais;
- quitação da comissão.

[Ver regras de negócio](regras-de-negocio.md)

---

## Resumo do sistema

O projeto propõe o desenvolvimento de um sistema para centralizar e organizar o processo de controle de vendas e comissões da Hitek Informática.

O fluxo principal pode ser representado da seguinte forma:

```text
Vendedor registra a venda
        ↓
Comissão Pendente
        ↓
Vendedor pode atualizar a situação da venda
        ↓
Financeiro verifica as informações
        ↓
Financeiro confirma a baixa
        ↓
Sistema calcula a comissão
        ↓
Comissão Liberada
        ↓
Pagamentos
        ↓
Comissão totalmente quitada
        ↓
Comissão Paga
```

---

## Venda faturada

Quando uma venda estiver faturada, a comissão somente poderá ser liberada após a confirmação da retirada do equipamento pelo cliente.

Fluxo simplificado:

```text
Venda faturada
      ↓
Equipamento retirado?
      ↓
Não → Comissão permanece Pendente
Sim → Financeiro pode prosseguir com a baixa
```

O Vendedor poderá informar ou atualizar a situação de retirada, mas a validação continuará sob responsabilidade do Financeiro.

---

## Separação de responsabilidades

### Vendedor

Responsável principalmente por:

- registrar vendas;
- consultar suas vendas;
- atualizar a situação da venda;
- alterar o valor da venda;
- consultar suas comissões.

Não poderá alterar o valor de custo nem confirmar a baixa.

### Financeiro

Responsável principalmente por:

- consultar vendas;
- verificar pagamento ou faturamento;
- verificar retirada do equipamento quando aplicável;
- confirmar a baixa;
- registrar pagamentos das comissões.

### Administrador

Responsável pelas funções administrativas e de gerenciamento geral previstas no sistema.

---

## Relação entre os documentos

Os documentos desta seção devem permanecer coerentes entre si.

```text
Problema e Solução
        ↓
Objetivos
        ↓
Escopo
        ↓
Perfis de Usuário
        ↓
Regras de Negócio
```

Alterações realizadas no funcionamento do sistema deverão ser refletidas nos documentos correspondentes.

---

[← Voltar ao README principal](../../README.md)
