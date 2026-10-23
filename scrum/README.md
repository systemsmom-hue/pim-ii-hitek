# Processo Ágil e Documentação Scrum

Esta seção reúne os artefatos de planejamento, execução e controle ágil do **Sistema de Gestão de Comissões — Hitek Informática (PIM II)**.

A metodologia **Scrum** foi adotada para estruturar o fluxo de trabalho da equipe, garantindo rastreabilidade, entregas incrementais e flexibilidade no alinhamento com as regras de negócio do produto.

---

## Equipe Scrum e Papéis

| Integrante | Papel Scrum | Responsabilidades Principais |
|---|---|---|
| **Kawan Felipe** | Product Owner (PO) | Definição de visão do produto, priorização do backlog, refinamento de regras de negócio e validação dos critérios de aceite. |
| **Júlio Poleto** | Scrum Master (SM) | Facilitação dos ritos, remoção de impedimentos, garantia da adesão à metodologia e alinhamento do time. |
| **João Martins** | Dev Team | Desenvolvimento de módulos funcionais em Linguagem C, integração com MySQL e modelagem de banco de dados. |
| **Paulo Nambu** | Dev Team | Análise de requisitos, modelagem relacional (3FN) e documentação técnica. |
| **Victor Andrade** | Dev Team | Infraestrutura de redes, segmentação de VLANs, segurança e acessibilidade CLI (LGPD). |
| **Ícaro Marcelo** | Dev Team | Testes unitários/integração, validação de regras de negócio e compilação de artefatos ABNT. |

---

## Artefatos Scrum

| Artefato | Descrição | Link de Acesso |
|---|---|:---:|
| **Product Backlog** | Lista priorizada de todas as funcionalidades, requisitos e melhorias técnicas do sistema. | [👉 Visualizar](product-backlog.md) |
| **User Stories** | Histórias de usuário com critérios de aceite focadas nos perfis Vendedor, Financeiro e Administrador. | [👉 Visualizar](user-stories.md) |
| **Definition of Done (DoD)** | Critérios de qualidade mínimos necessários para considerar uma tarefa/item concluído. | [👉 Visualizar](definition-of-done.md) |
| **Histórico de Sprints** | Registro detalhado do planejamento, execução, dailies, reviews e retrospectivas (Sprints 01 a 10). | [👉 Visualizar](sprints/) |

---

## Refinamento do Produto (Regras de Negócio RBAC)

Durante as Sprints de refinamento, o Product Owner estabeleceu atualização nas permissões funcionais do perfil **Vendedor**:

> ### 📝 Diretrizes do perfil Vendedor
>
> **O Vendedor possui permissão para:**
> - Atualizar a situação operacional da venda (ex.: *Em Processamento*, *Aguardando Faturamento*);
> - Informar/atualizar dados de faturamento e formas de pagamento;
> - Atualizar a situação de retirada/envio do produto (quando aplicável);
> - Ajustar o valor bruto de venda.
>
> **O Vendedor NÃO possui permissão para:**
> - Alterar o valor de custo dos produtos/serviços;
> - Confirmar a baixa financeira/quitação da venda (exclusivo do perfil **Financeiro**).

---

## Estrutura de Arquivos da Pasta

```text
scrum/
├── README.md
├── product-backlog.md
├── user-stories.md
├── definition-of-done.md
└── sprints/
    ├── README.md
    ├── sprint-01.md
    ├── sprint-02.md
    ├── sprint-03.md
    ├── sprint-04.md
    ├── sprint-05.md
    ├── sprint-06.md
    ├── sprint-07.md
    ├── sprint-08.md
    ├── sprint-09.md
    └── sprint-10.md
```

---

## Matriz de Rastreabilidade e Impacto

Toda mudança de escopo aprovada pelo PO deve propagar sequencialmente por todos os artefatos técnicos do projeto:

```text
Decisão do Product Owner
        │
        ▼
Product Backlog & User Stories
        │
        ▼
Requisitos Funcionais & Regras de Negócio
        │
        ▼
Casos de Uso & Diagramas de Arquitetura
        │
        ▼
Modelagem Relacional (SQL / DDL / DML)
        │
        ▼
Implementação em C & Testes de Integração
```

---

## Status dos Artefatos Scrum

| Artefato / Atividade | Status | Observações |
|---|:---:|---|
| Definição dos Papéis Scrum | 🟢 Concluído | PO, SM e Dev Team definidos e atuantes |
| Product Backlog | 🟢 Concluído | Totalmente refinado com RFs e RNFs |
| User Stories | 🟢 Concluído | Mapeadas para os 3 perfis funcionais com DoD |
| Definition of Done (DoD) | 🟢 Concluído | Padrões de código C, SQL e ABNT estabelecidos |
| Execução e Registro das Sprints | 🟢 Concluído | Sprints 01 a 10 documentadas em `/sprints/` |

---

## Diretrizes de Governança e Histórico

1. **Imutabilidade do Histórico:** Decisões tomadas em Sprints avançadas não alteram retroativamente os registros de Sprints anteriores. O histórico de Sprints preserva a linha do tempo real do projeto.
2. **Consistência Ativa:** O estado atual do sistema refletido em `/docs/` e `/src/c/` deve coincidir rigorosamente com a versão mais recente do Product Backlog e das User Stories.

---

[← Voltar ao README principal](../README.md)
