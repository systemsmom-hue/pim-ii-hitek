
# Documentação do Projeto

Esta pasta reúne a documentação acadêmica e técnica do **Sistema de Gestão de Comissões — Hitek Informática**.

O conteúdo está organizado por área para facilitar a navegação, revisão e manutenção dos artefatos desenvolvidos ao longo do PIM II.

---

## Estrutura da documentação

```text
docs/
├── README.md
├── 01-visao-geral/
├── 02-engenharia-de-software/
├── 03-diagramas/
├── 04-banco-de-dados/
├── 05-pesquisa-e-inovacao/
├── 06-redes/
├── 07-direitos-humanos/
└── 08-documentacao-final/
```

---

## 01 — Visão Geral

Reúne as informações fundamentais do projeto.

Conteúdo:

- problema e solução;
- objetivos;
- escopo;
- perfis de usuário;
- regras de negócio.

[Ver Visão Geral](01-visao-geral/)

---

## 02 — Engenharia de Software

Reúne os principais artefatos relacionados à definição e modelagem do sistema.

Conteúdo:

- requisitos funcionais;
- requisitos não funcionais;
- casos de uso;
- arquitetura lógica.

[Ver Engenharia de Software](02-engenharia-de-software/)

---

## 03 — Diagramas

Reúne os principais diagramas utilizados para representar o sistema.

Diagramas atuais:

- Diagrama de Casos de Uso;
- Diagrama de Atividade;
- Diagrama Estendido.

[Ver Diagramas](03-diagramas/)

---

## 04 — Banco de Dados

Reúne a documentação relacionada à modelagem do banco de dados.

Conteúdo previsto:

- modelo conceitual;
- DER;
- modelo lógico;
- normalização;
- modelo físico.

Os scripts SQL serão armazenados separadamente na pasta:

```text
/database/
```

[Ver Banco de Dados](04-banco-de-dados/)

---

## 05 — Pesquisa e Inovação

Reúne os conteúdos relacionados à fundamentação científica e à análise da solução proposta.

Conteúdo previsto:

- metodologia;
- fundamentação teórica;
- análise de soluções relacionadas;
- inovação.

[Ver Pesquisa e Inovação](05-pesquisa-e-inovacao/)

---

## 06 — Redes

Reúne a documentação relacionada à infraestrutura necessária para suportar a solução.

Conteúdo previsto:

- arquitetura da rede;
- topologia;
- equipamentos;
- endereçamento;
- VLANs;
- comunicação entre serviços;
- segurança;
- sistemas distribuídos.

[Ver Redes](06-redes/)

---

## 07 — Direitos Humanos e Inclusão

Reúne as análises relacionadas ao impacto humano e ao uso responsável da tecnologia.

Conteúdo previsto:

- acessibilidade;
- inclusão digital;
- privacidade;
- proteção dos dados;
- segurança das informações;
- aspectos éticos;
- LGPD, quando aplicável.

[Ver Direitos Humanos e Inclusão](07-direitos-humanos/)

---

## 08 — Documentação Final

Reúne as versões destinadas à revisão e entrega do PIM.

Organização prevista:

```text
08-documentacao-final/
├── backups/
└── entrega/
```

Essa seção será utilizada para armazenar:

- versões intermediárias;
- backups;
- DOCX final;
- PDF final.

[Ver Documentação Final](08-documentacao-final/)

---

## Relação com outras áreas do repositório

Além da documentação acadêmica presente em `docs/`, o projeto também possui áreas específicas para outros artefatos.

### Scrum

```text
/scrum/
```

Contém:

- Product Backlog;
- User Stories;
- Definition of Done;
- Sprints.

[Ver Scrum](../scrum/)

### Programação Estruturada em C

```text
/src/c/
```

Será utilizada para armazenar as funcionalidades implementadas em linguagem C.

[Ver Programação em C](../src/c/)

### Banco de Dados — SQL

```text
/database/
```

Será utilizada para armazenar os scripts SQL do projeto.

[Ver Scripts de Banco de Dados](../database/)

### Assets

```text
/assets/
```

Reúne recursos visuais gerais utilizados no repositório.

[Ver Assets](../assets/)

---

## Navegação

```text
Visão Geral
     ↓
Engenharia de Software
     ↓
Diagramas
     ↓
Banco de Dados
     ↓
Pesquisa e Inovação
     ↓
Redes
     ↓
Direitos Humanos e Inclusão
     ↓
Documentação Final
```

---

## Status geral

| Área | Status |
|---|---|
| Visão Geral | ✅ Estruturada |
| Engenharia de Software | ✅ Estruturada |
| Diagramas | ✅ Estruturada |
| Banco de Dados | 🟡 Em desenvolvimento |
| Pesquisa e Inovação | ⚪ Pendente |
| Redes | ⚪ Pendente |
| Direitos Humanos e Inclusão | ⚪ Pendente |
| Documentação Final | 🟡 Em desenvolvimento |

---

## Observação

A existência de uma pasta ou de um README não significa que a respectiva etapa esteja concluída.

Os status deverão ser atualizados conforme os artefatos forem efetivamente desenvolvidos e revisados.

---

[← Voltar ao README principal](../README.md)
