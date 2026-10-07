# Sprint 06 — Organização do GitHub e Formalização do Scrum

A Sprint 06 representa a etapa de organização, versionamento e formalização da documentação do **Sistema de Gestão de Comissões — Hitek Informática**.

Nesta etapa, os artefatos desenvolvidos anteriormente começaram a ser centralizados em um repositório GitHub estruturado, permitindo melhor organização, rastreabilidade e acompanhamento da evolução do PIM.

Também foi iniciada a formalização da utilização do Scrum, organizando Product Backlog, User Stories, Definition of Done e o histórico das Sprints.

Durante esta Sprint também foram realizados refinamentos no produto a partir de novas definições do Product Owner.

> Esta Sprint corresponde à etapa atual de desenvolvimento do projeto.

---

## Status

**Em andamento**

---

## Objetivo da Sprint

Organizar os artefatos já desenvolvidos em um repositório GitHub, formalizar a documentação relacionada ao Scrum e manter os artefatos do projeto atualizados conforme os refinamentos realizados durante o desenvolvimento.

---

## Atividades da Sprint

| ID | Atividade | Status |
|---|---|---|
| SP06-01 | Criar o repositório do PIM no GitHub | ✅ Concluído |
| SP06-02 | Definir a estrutura de pastas do repositório | ✅ Concluído |
| SP06-03 | Criar o README principal do projeto | ✅ Concluído |
| SP06-04 | Criar a seção de Visão Geral | ✅ Concluído |
| SP06-05 | Documentar problema e solução | ✅ Concluído |
| SP06-06 | Documentar objetivos | ✅ Concluído |
| SP06-07 | Documentar escopo | ✅ Concluído |
| SP06-08 | Documentar perfis de usuário | ✅ Concluído |
| SP06-09 | Documentar regras de negócio | ✅ Concluído |
| SP06-10 | Criar a seção de Engenharia de Software | ✅ Concluído |
| SP06-11 | Documentar requisitos funcionais | ✅ Concluído |
| SP06-12 | Documentar requisitos não funcionais | ✅ Concluído |
| SP06-13 | Documentar casos de uso | ✅ Concluído |
| SP06-14 | Documentar a arquitetura lógica inicial | ✅ Concluído |
| SP06-15 | Criar a seção de Diagramas | ✅ Concluído |
| SP06-16 | Criar a seção de Banco de Dados | ✅ Concluído |
| SP06-17 | Criar a seção de Pesquisa e Inovação | ✅ Concluído |
| SP06-18 | Criar a seção de Redes | ✅ Concluído |
| SP06-19 | Criar a seção de Direitos Humanos e Inclusão | ✅ Concluído |
| SP06-20 | Criar a seção de Documentação Final | ✅ Concluído |
| SP06-21 | Estruturar a área Scrum | ✅ Concluído |
| SP06-22 | Revisar e organizar o Product Backlog | ✅ Concluído |
| SP06-23 | Criar as User Stories | ✅ Concluído |
| SP06-24 | Definir a Definition of Done | ✅ Concluído |
| SP06-25 | Reconstruir o histórico das Sprints com base na evolução real do projeto | 🟡 Em andamento |
| SP06-26 | Preparar a área de implementação em C | 🟡 Em andamento |
| SP06-27 | Preparar a estrutura de scripts do banco de dados | ⚪ Pendente |
| SP06-28 | Revisar todos os links internos do repositório | ⚪ Pendente |
| SP06-29 | Realizar revisão geral da estrutura do GitHub | ⚪ Pendente |
| SP06-30 | Registrar refinamento solicitado pelo Product Owner em 06/10/2026 | ✅ Concluído |
| SP06-31 | Atualizar os artefatos afetados pelo refinamento do Product Owner | 🟡 Em andamento |
| SP06-32 | Atualizar os diagramas finais no repositório | 🟡 Em andamento |

---

## Estrutura do repositório

A estrutura principal definida para o projeto é:

```text
pim-ii-hitek/
├── README.md
├── assets/
├── database/
├── docs/
│   ├── 01-visao-geral/
│   ├── 02-engenharia-de-software/
│   ├── 03-diagramas/
│   ├── 04-banco-de-dados/
│   ├── 05-pesquisa-e-inovacao/
│   ├── 06-redes/
│   ├── 07-direitos-humanos/
│   └── 08-documentacao-final/
├── scrum/
│   ├── README.md
│   ├── product-backlog.md
│   ├── user-stories.md
│   ├── definition-of-done.md
│   └── sprints/
└── src/
    └── c/
```

Essa organização separa os diferentes tipos de artefatos e facilita a navegação pelo projeto.

---

## README principal

Foi criado um README principal para funcionar como página inicial do repositório.

O documento apresenta:

- identificação do projeto;
- descrição da solução;
- objetivo;
- principais funcionalidades;
- perfis do sistema;
- andamento do projeto;
- equipe;
- diagramas;
- estrutura do repositório;
- navegação rápida;
- tecnologias e ferramentas utilizadas.

---

## Organização da documentação

A documentação foi dividida em áreas específicas.

### 01 — Visão Geral

Reúne:

- problema e solução;
- objetivos;
- escopo;
- perfis de usuário;
- regras de negócio.

### 02 — Engenharia de Software

Reúne:

- requisitos funcionais;
- requisitos não funcionais;
- casos de uso;
- arquitetura lógica.

### 03 — Diagramas

Área destinada ao armazenamento de:

- Diagrama de Casos de Uso;
- Diagrama Estendido;
- arquivos editáveis relacionados.

### 04 — Banco de Dados

Área destinada a:

- modelo conceitual;
- DER;
- modelo lógico;
- normalização;
- modelo físico.

### 05 — Pesquisa e Inovação

Área destinada à futura documentação de:

- metodologia;
- fundamentação teórica;
- análise da inovação.

### 06 — Redes

Área destinada à documentação de:

- topologia;
- equipamentos;
- endereçamento;
- infraestrutura;
- acesso remoto;
- segurança;
- sistemas distribuídos.

### 07 — Direitos Humanos e Inclusão

Área destinada à documentação relacionada a:

- acessibilidade;
- inclusão;
- uso responsável da tecnologia.

### 08 — Documentação Final

Área destinada a:

- backups;
- versões de revisão;
- documento final;
- arquivos destinados à entrega.

---

# Formalização do Scrum

Nesta etapa, o Scrum começou a ser formalizado documentalmente no repositório.

Embora o projeto já tivesse sido desenvolvido em diferentes etapas de trabalho, a divisão formal dessas etapas em Sprints foi estruturada posteriormente com base no histórico real registrado durante o desenvolvimento.

---

## Product Backlog

O Product Backlog foi revisado para refletir as funcionalidades atualmente definidas para o sistema.

Entre os itens registrados estão:

- autenticação;
- usuários;
- colaboradores;
- vendas;
- margem;
- comissões;
- baixa;
- venda faturada;
- retirada do equipamento;
- pagamentos;
- quitação;
- ajustes;
- relatórios;
- atualização da situação da venda pelo Vendedor;
- alteração do valor da venda pelo Vendedor.

Os itens ainda não implementados permanecem com status de planejamento.

---

## User Stories

Foram criadas User Stories para os três perfis do sistema:

```text
Vendedor
Financeiro
Administrador
```

As histórias foram relacionadas aos itens correspondentes do Product Backlog.

Durante o refinamento desta Sprint, também foram incluídas histórias relacionadas a:

- atualização da situação da venda pelo Vendedor;
- alteração do valor da venda pelo Vendedor.

---

## Refinamento solicitado pelo Product Owner — 06/10/2026

Durante a evolução do projeto, o Product Owner solicitou uma alteração nas permissões relacionadas ao perfil **Vendedor**.

Foi definido que o Vendedor poderá:

- atualizar a situação da venda;
- informar ou atualizar a situação de pagamento/faturamento;
- informar ou atualizar a situação de retirada do equipamento quando aplicável;
- alterar o valor da venda.

Também foi definido que o perfil Vendedor **não poderá alterar o valor de custo da venda**.

---

## Separação das responsabilidades

A alteração não transfere ao Vendedor a responsabilidade de confirmação da baixa.

O fluxo deverá permanecer com a seguinte separação:

```text
Vendedor atualiza a situação da venda
        ↓
Financeiro verifica as informações
        ↓
Financeiro confirma a baixa
        ↓
Sistema calcula e libera a comissão
```

Portanto:

### Vendedor

Poderá:

- atualizar a situação da venda;
- alterar o valor da venda.

Não poderá:

- alterar o valor de custo;
- confirmar a baixa.

### Financeiro

Continuará responsável por:

- verificar pagamento ou faturamento;
- verificar retirada do equipamento quando aplicável;
- confirmar a baixa da venda.

---

## Impacto do refinamento

A decisão do Product Owner exige revisão de diferentes artefatos para manter a consistência do projeto.

Os principais artefatos afetados são:

```text
Perfis de usuário
        ↓
Escopo
        ↓
Objetivos
        ↓
Regras de negócio
        ↓
Requisitos funcionais
        ↓
Casos de uso
        ↓
Diagramas
        ↓
Arquitetura
        ↓
Product Backlog
        ↓
User Stories
        ↓
Banco de dados
        ↓
Implementação
```

As alterações deverão representar a mesma regra em todos esses artefatos.

---

## Definition of Done

Foi definida uma Definition of Done para estabelecer os critérios utilizados para considerar uma atividade realmente concluída.

Foram definidos critérios específicos para:

- documentação;
- requisitos;
- casos de uso;
- diagramas;
- banco de dados;
- programação em C;
- Scrum.

---

## Reconstrução das Sprints

O histórico do projeto começou a ser organizado de acordo com a sequência real das atividades desenvolvidas.

A estrutura definida é:

```text
Sprint 01 — Definição Inicial do Projeto

Sprint 02 — Requisitos e Planejamento Inicial

Sprint 03 — Modelagem Inicial do Sistema

Sprint 04 — Refinamento das Regras e do Fluxo

Sprint 05 — Consolidação da Modelagem Funcional

Sprint 06 — Organização do GitHub e Formalização do Scrum

Sprint 07 — Banco de Dados

Sprint 08 — Programação Estruturada em C

Sprint 09 — Disciplinas Complementares

Sprint 10 — Integração e Entrega Final
```

As Sprints anteriores preservam o histórico do que havia sido definido em cada etapa.

Novas decisões não deverão ser inseridas retroativamente nas Sprints antigas como se já existissem naquele momento.

---

## Evolução das Sprints

O histórico estruturado até esta etapa pode ser resumido como:

```text
Definição do projeto
        ↓
Requisitos e planejamento
        ↓
Modelagem inicial
        ↓
Refinamento das regras
        ↓
Consolidação da modelagem funcional
        ↓
Organização e versionamento no GitHub
        ↓
Refinamentos atuais do produto
```

---

## Versionamento

O GitHub passou a ser utilizado como repositório central do projeto.

Os commits deverão representar alterações específicas e identificáveis.

Exemplos:

```text
docs: atualiza regras de negócio

docs: atualiza casos de uso

docs: atualiza diagrama de casos de uso

scrum: atualiza product backlog

scrum: adiciona novas user stories

scrum: registra refinamento do product owner

db: adiciona modelo lógico

feat: implementa cálculo de comissão

fix: corrige fluxo de pagamento
```

---

## Benefícios da organização

A utilização do repositório permite:

- centralizar os artefatos;
- acompanhar alterações;
- organizar os documentos por disciplina;
- preservar versões;
- facilitar a colaboração da equipe;
- relacionar documentação e implementação;
- acompanhar o andamento do PIM;
- manter histórico das decisões do projeto.

---

## Situação ao final da etapa atual

O repositório possui uma base documental organizada.

Estão estruturadas as áreas de:

- visão geral;
- Engenharia de Software;
- diagramas;
- banco de dados;
- Pesquisa e Inovação;
- Redes;
- Direitos Humanos e Inclusão;
- documentação final;
- Scrum;
- implementação em C.

Entretanto, nem todas essas áreas possuem seus artefatos finais.

A criação da estrutura não significa que as disciplinas correspondentes estejam concluídas.

---

## Principais pendências

As principais etapas restantes incluem:

- concluir a atualização dos artefatos afetados pelo refinamento do Product Owner;
- garantir que os diagramas atuais estejam no repositório;
- revisar e concluir o banco de dados;
- desenvolver o modelo conceitual;
- finalizar o DER;
- desenvolver o modelo lógico;
- realizar a normalização;
- desenvolver o modelo físico;
- criar os scripts SQL;
- selecionar as funcionalidades para implementação em C;
- implementar e testar as funcionalidades em C;
- concluir Pesquisa e Inovação;
- concluir Redes;
- desenvolver Direitos Humanos e Inclusão;
- integrar todos os conteúdos ao documento final;
- revisar a entrega completa.

---

## Resultado esperado da Sprint

Ao final desta Sprint, o projeto deverá possuir:

- repositório GitHub estruturado;
- documentação existente organizada;
- navegação entre os artefatos;
- Product Backlog atualizado;
- User Stories atualizadas;
- Definition of Done definida;
- histórico das Sprints organizado;
- refinamentos atuais documentados;
- áreas preparadas para as próximas etapas;
- situação real do projeto claramente identificada.

---

## Documentação relacionada

- [README principal](../../README.md)
- [Visão Geral](../../docs/01-visao-geral/)
- [Engenharia de Software](../../docs/02-engenharia-de-software/)
- [Diagramas](../../docs/03-diagramas/)
- [Product Backlog](../product-backlog.md)
- [User Stories](../user-stories.md)
- [Definition of Done](../definition-of-done.md)

---

[← Voltar para Scrum](../README.md)
