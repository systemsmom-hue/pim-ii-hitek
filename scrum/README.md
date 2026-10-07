# Scrum

Esta seção reúne os artefatos relacionados à aplicação do **Scrum** no desenvolvimento do projeto **Sistema de Gestão de Comissões — Hitek Informática**.

O objetivo é documentar a organização da equipe, o planejamento do produto, as funcionalidades priorizadas e o acompanhamento das atividades realizadas durante o desenvolvimento do PIM.

---

## Equipe Scrum

| Integrante | Papel |
|---|---|
| Kawan Felipe | Product Owner |
| Júlio Poleto | Scrum Master |
| João Martins | Dev Team |
| Paulo Nambu | Dev Team |
| Victor Andrade | Dev Team |
| Ícaro Marcelo | Dev Team |

---

## Papéis

### Product Owner

Responsável por representar as necessidades do produto e auxiliar na definição, priorização e refinamento das funcionalidades.

No projeto, essa função é exercida por:

**Kawan Felipe**

As decisões e refinamentos definidos pelo Product Owner deverão ser refletidos nos artefatos relacionados do projeto.

---

### Scrum Master

Responsável por auxiliar a equipe na aplicação do Scrum e na organização do processo de desenvolvimento.

No projeto, essa função é exercida por:

**Júlio Poleto**

---

### Dev Team

Responsável pela execução das atividades necessárias para o desenvolvimento dos artefatos e funcionalidades do projeto.

Integrantes:

- João Martins;
- Paulo Nambu;
- Victor Andrade;
- Ícaro Marcelo.

---

## Artefatos

### Product Backlog

O Product Backlog reúne as funcionalidades e atividades previstas para o desenvolvimento do sistema.

Ele deverá ser atualizado sempre que houver refinamentos ou novas decisões relacionadas ao produto.

[Ver Product Backlog](product-backlog.md)

### User Stories

As User Stories representam funcionalidades do sistema sob a perspectiva dos usuários.

As histórias deverão permanecer coerentes com os requisitos, regras de negócio e decisões mais recentes do Product Owner.

[Ver User Stories](user-stories.md)

### Definition of Done

A Definition of Done estabelece os critérios utilizados para considerar uma atividade concluída.

[Ver Definition of Done](definition-of-done.md)

### Sprints

As atividades desenvolvidas ao longo do projeto são organizadas em Sprints para registrar a evolução real do trabalho.

[Ver Sprints](sprints/)

---

## Refinamento atual do produto

Durante a evolução do projeto, o Product Owner definiu novas permissões para o perfil Vendedor.

O Vendedor poderá:

- atualizar a situação da venda;
- atualizar informações de pagamento/faturamento;
- atualizar a situação de retirada quando aplicável;
- alterar o valor da venda.

O Vendedor não poderá:

- alterar o valor de custo;
- confirmar a baixa da venda.

A confirmação da baixa continuará sob responsabilidade do Financeiro.

Esse refinamento deverá permanecer refletido em:

- requisitos funcionais;
- regras de negócio;
- casos de uso;
- diagramas;
- Product Backlog;
- User Stories;
- arquitetura;
- modelagem de dados;
- implementação.

---

## Organização

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

## Relação com o projeto

O planejamento Scrum deverá acompanhar os principais entregáveis do PIM, incluindo:

- levantamento e revisão dos requisitos;
- regras de negócio;
- casos de uso;
- diagramas;
- refinamentos solicitados pelo Product Owner;
- modelagem do banco de dados;
- implementação em C;
- documentação das demais disciplinas;
- revisão da documentação final.

---

## Situação atual

| Artefato | Status |
|---|---|
| Definição dos papéis Scrum | ✅ Concluído |
| Product Backlog | ✅ Atualizado |
| User Stories | ✅ Atualizado |
| Definition of Done | ✅ Definida |
| Planejamento das Sprints | 🟡 Em desenvolvimento |

---

## Atualização dos artefatos

Os artefatos Scrum deverão ser atualizados conforme o andamento real do projeto.

Quando uma decisão alterar uma funcionalidade, deverá ser verificada a coerência entre:

```text
Decisão do Product Owner
        ↓
Product Backlog
        ↓
User Stories
        ↓
Requisitos
        ↓
Regras de negócio
        ↓
Casos de uso
        ↓
Diagramas
        ↓
Implementação
```

Alterações não deverão ser aplicadas apenas em um único documento se afetarem outras partes do sistema.

---

## Histórico

As Sprints anteriores devem preservar o histórico real do projeto.

Por esse motivo, uma decisão tomada posteriormente não deverá ser inserida retroativamente em uma Sprint antiga como se já existisse naquela etapa.

Novos refinamentos deverão ser registrados na Sprint correspondente ao momento em que foram definidos.

---

## Observação

Os artefatos Scrum devem permanecer coerentes com o estado atual do desenvolvimento e com a documentação presente no repositório.

O histórico das Sprints deverá representar a evolução do projeto, enquanto os artefatos atuais deverão representar a versão mais recente do produto.

---

[← Voltar ao README principal](../README.md)
