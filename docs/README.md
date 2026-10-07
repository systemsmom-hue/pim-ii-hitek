# Documentação do Projeto

Esta pasta reúne a documentação acadêmica e técnica do **Sistema de Gestão de Comissões — Hitek Informática**.

O conteúdo está organizado por área para facilitar a navegação, revisão, manutenção e rastreabilidade dos artefatos desenvolvidos ao longo do PIM II.

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

Essa seção também registra as responsabilidades e permissões atualmente definidas para os perfis:

- Vendedor;
- Financeiro;
- Administrador.

[Ver Visão Geral](01-visao-geral/)

---

## 02 — Engenharia de Software

Reúne os principais artefatos relacionados à definição, organização e modelagem do sistema.

Conteúdo:

- requisitos funcionais;
- requisitos não funcionais;
- casos de uso;
- arquitetura lógica.

Os artefatos dessa seção deverão permanecer coerentes com as regras de negócio e com os refinamentos definidos ao longo do projeto.

[Ver Engenharia de Software](02-engenharia-de-software/)

---

## 03 — Diagramas

Reúne os diagramas atualmente utilizados para representar o sistema.

Diagramas atuais:

- Diagrama de Casos de Uso;
- Diagrama Estendido.

O Diagrama de Casos de Uso representa os atores e suas interações com o sistema.

O Diagrama Estendido representa os módulos funcionais, suas funções e dependências.

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

A modelagem deverá contemplar as informações necessárias ao funcionamento do sistema, incluindo vendas, comissões, pagamentos, usuários, configurações e demais dados definidos pelas regras de negócio.

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

Além da documentação acadêmica presente em `docs/`, o projeto possui áreas específicas para outros artefatos.

### Scrum

```text
/scrum/
```

Contém:

- Product Backlog;
- User Stories;
- Definition of Done;
- Sprints.

A documentação Scrum registra tanto o planejamento atual quanto a evolução histórica do projeto.

[Ver Scrum](../scrum/)

---

### Programação Estruturada em C

```text
/src/c/
```

Será utilizada para armazenar as funcionalidades selecionadas para implementação em linguagem C.

A implementação deverá permanecer coerente com os requisitos, regras de negócio e modelagem funcional do sistema.

[Ver Programação em C](../src/c/)

---

### Banco de Dados — SQL

```text
/database/
```

Será utilizada para armazenar os scripts SQL após a conclusão e validação da modelagem de dados.

[Ver Scripts de Banco de Dados](../database/)

---

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

## Coerência entre os artefatos

As alterações realizadas no produto deverão ser refletidas nos documentos relacionados.

Fluxo de referência:

```text
Regras de Negócio
       ↓
Requisitos
       ↓
Casos de Uso
       ↓
Diagramas
       ↓
Arquitetura
       ↓
Banco de Dados
       ↓
Implementação
```

Os artefatos Scrum também deverão acompanhar essas alterações quando houver impacto no planejamento ou nas funcionalidades do produto.

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

Os status deverão ser atualizados conforme os artefatos forem efetivamente desenvolvidos, revisados e validados pela equipe.

Os documentos atuais devem representar a versão mais recente do sistema, enquanto os registros históricos das Sprints devem preservar a evolução real do projeto.

---

[← Voltar ao README principal](../README.md)
