# Sprint 03 — Modelagem Inicial do Sistema

A Sprint 03 representa o início da modelagem visual e estrutural do **Sistema de Gestão de Comissões — Hitek Informática**.

Após a definição inicial dos requisitos, regras de negócio e casos de uso, o projeto avançou para a representação gráfica das funcionalidades e para os primeiros trabalhos relacionados à estrutura de dados.

> Esta divisão em Sprints foi organizada posteriormente com base na sequência real de desenvolvimento registrada durante o projeto.

---

## Período

O período desta Sprint não foi formalizado no início do projeto.

---

## Objetivo da Sprint

Transformar os requisitos e casos de uso definidos anteriormente em modelos visuais e iniciar a estruturação dos dados necessários ao funcionamento do sistema.

---

## Atividades realizadas

| ID | Atividade | Status |
|---|---|---|
| SP03-01 | Criar a primeira versão do Diagrama de Casos de Uso | ✅ Concluído |
| SP03-02 | Relacionar os atores às principais funcionalidades | ✅ Concluído |
| SP03-03 | Analisar os relacionamentos entre vendas, colaboradores e comissões | ✅ Concluído |
| SP03-04 | Iniciar a modelagem do banco de dados | ✅ Concluído |
| SP03-05 | Receber e analisar uma versão inicial do MER desenvolvida pelo grupo | ✅ Concluído |
| SP03-06 | Identificar pontos da modelagem que ainda dependiam de revisão | ✅ Concluído |

---

## Diagrama de Casos de Uso inicial

Foi criada uma primeira representação visual dos casos de uso do sistema.

O objetivo do diagrama era representar:

```text
Atores
   ↓
Interação
   ↓
Funcionalidades do sistema
```

Essa primeira versão serviu como base para compreender de forma visual quais funcionalidades estavam relacionadas a cada tipo de usuário.

---

## Atores e funcionalidades

A modelagem começou a representar as responsabilidades dos diferentes usuários envolvidos no processo.

As funcionalidades estavam relacionadas principalmente a:

- vendas;
- consultas;
- comissões;
- pagamentos;
- usuários;
- colaboradores;
- relatórios;
- configurações.

Essa estrutura ainda passaria por revisões conforme o fluxo real de comissões fosse melhor compreendido.

---

## Início da modelagem de dados

Durante esta etapa, o grupo também iniciou os trabalhos relacionados ao banco de dados.

Uma primeira versão do **Modelo Entidade-Relacionamento — MER** foi desenvolvida pelo grupo.

Essa versão ainda não era considerada definitiva.

---

## Elementos analisados na modelagem

A modelagem começou a considerar informações relacionadas a:

- usuários;
- colaboradores;
- vendas;
- comissões;
- pagamentos.

Também passou a ser necessário compreender corretamente os relacionamentos entre essas informações.

Um dos pontos centrais da análise era:

```text
Venda
  ↓
Colaborador
  ↓
Comissão
```

A forma definitiva desses relacionamentos ainda dependeria das regras de negócio que estavam sendo levantadas.

---

## Questões identificadas

Durante a modelagem, foram identificados pontos que ainda precisavam ser esclarecidos ou revisados.

Entre eles:

- relacionamento entre venda e comissão;
- relacionamento entre colaborador e comissão;
- quantidade de colaboradores que poderiam receber comissão por venda;
- percentual aplicado às comissões;
- forma de armazenar o percentual utilizado;
- processo de pagamento das comissões;
- possibilidade de pagamentos parciais;
- tratamento de ajustes referentes a comissões anteriores;
- separação entre usuário do sistema e colaborador.

---

## Necessidade de revisão

A modelagem inicial mostrou que algumas decisões não poderiam ser fechadas antes da confirmação das regras reais do processo.

Por esse motivo, os modelos desenvolvidos nesta etapa foram tratados como versões iniciais.

O fluxo de trabalho passou a seguir:

```text
Requisitos iniciais
        ↓
Modelagem inicial
        ↓
Identificação de dúvidas
        ↓
Levantamento de novas regras
        ↓
Revisão dos modelos
```

---

## Banco de Dados

Ao final desta Sprint, o banco de dados estava apenas em sua fase inicial.

Já havia:

- início da modelagem;
- primeira versão do MER;
- identificação de entidades importantes;
- análise inicial dos relacionamentos.

Ainda precisavam ser definidos ou revisados:

- entidades definitivas;
- atributos;
- chaves primárias;
- chaves estrangeiras;
- cardinalidades;
- modelo conceitual final;
- DER final;
- modelo lógico;
- normalização;
- modelo físico;
- scripts SQL.

---

## Artefatos ainda não finalizados

Nesta etapa ainda não estavam concluídos:

- versão final do Diagrama de Casos de Uso;
- Diagrama de Atividade;
- Diagrama Estendido;
- arquitetura definitiva;
- MER revisado;
- DER final;
- modelo lógico;
- modelo físico;
- implementação em C;
- formalização das Sprints.

---

## Resultado da Sprint

Ao final desta etapa, o projeto já possuía uma primeira representação visual e estrutural do sistema.

Foram obtidos:

- primeira versão do Diagrama de Casos de Uso;
- representação inicial das interações dos usuários;
- início da modelagem do banco de dados;
- primeira versão do MER;
- identificação de dúvidas importantes sobre as regras de comissão;
- identificação de pontos que precisariam ser revisados antes da modelagem definitiva.

Essa etapa foi importante porque revelou quais regras ainda precisavam ser esclarecidas antes de consolidar os diagramas e o banco de dados.

---

## Próxima etapa

A etapa seguinte seria dedicada ao refinamento das regras e do fluxo do sistema.

Entre os principais pontos estavam:

- revisar as regras de comissão;
- revisar os perfis e permissões;
- revisar o fluxo principal;
- atualizar requisitos;
- atualizar casos de uso;
- revisar o Diagrama de Casos de Uso;
- representar corretamente baixa, faturamento, liberação e pagamento das comissões.

---

## Documentação relacionada

- [Casos de Uso](../../docs/02-engenharia-de-software/casos-de-uso.md)
- [Diagramas](../../docs/03-diagramas/)
- [Banco de Dados](../../docs/04-banco-de-dados/)
- [Regras de Negócio](../../docs/01-visao-geral/regras-de-negocio.md)
- [Product Backlog](../product-backlog.md)

---

[← Voltar para Scrum](../README.md)
