# Documentação do Projeto

Esta pasta reúne a documentação acadêmica e técnica do **Sistema de Gestão de Comissões — Hitek Informática (PIM II)**.

O conteúdo está organizado por área para facilitar a navegação, revisão, manutenção e rastreabilidade de todos os artefatos desenvolvidos ao longo do projeto.

---

## Estrutura da Documentação

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

Reúne as informações fundamentais e o alinhamento estratégico do projeto.

**Conteúdo:**
- Problema e solução
- Objetivos gerais e específicos
- Escopo do sistema
- Perfis de usuário (RBAC)
- Regras de negócio

**Perfis e Permissões:**
- **Vendedor:** Registro e consulta de vendas próprias.
- **Financeiro:** Validação, liberação e quitação de comissões.
- **Administrador:** Gestão global de usuários, parâmetros e relatórios.

[👉 Ver Visão Geral](01-visao-geral/)

---

## 02 — Engenharia de Software

Reúne os artefatos de especificação, organização e arquitetura do sistema.

**Conteúdo:**
- Requisitos funcionais (RFs)
- Requisitos não funcionais (RNFs)
- Casos de uso estendidos
- Arquitetura lógica Cliente-Servidor (CLI + MySQL)

[👉 Ver Engenharia de Software](02-engenharia-de-software/)

---

## 03 — Diagramas

Reúne as representações visuais e estruturais da aplicação.

**Diagramas Documentados:**
- **Diagrama de Casos de Uso:** Mapeamento de atores e suas interações com o sistema.
- **Diagrama Estendido:** Representação dos módulos funcionais, funções em C e dependências.

[👉 Ver Diagramas](03-diagramas/)

---

## 04 — Banco de Dados

Reúne a documentação completa da modelagem relacional do sistema.

**Conteúdo:**
- Modelo conceitual e DER
- Modelo lógico e esquemas relacionais
- Normalização até a 3ª Forma Normal (3FN)
- Modelo físico (MySQL 8.0 / InnoDB, `utf8mb4`)

*Os scripts SQL DDL/DML estão centralizados na pasta [`/database/`](../database/).*

[👉 Ver Banco de Dados](04-banco-de-dados/)

---

## 05 — Pesquisa e Inovação

Reúne a fundamentação científica, metodológica e o estudo de impacto da solução.

**Conteúdo:**
- Metodologia de pesquisa aplicada (Estudo de Caso e BPM)
- Fundamentação teórica
- Análise de soluções relacionadas
- Inovação (*AS-IS* vs. *TO-BE*): Redução do tempo de fechamento de 2 dias úteis para < 2 horas com 0% de erro manual.

[👉 Ver Pesquisa e Inovação](05-pesquisa-e-inovacao/)

---

## 06 — Redes e Infraestrutura

Reúne a especificação de infraestrutura de rede e topologia para suporte ao sistema.

**Conteúdo:**
- Topologia física/lógica em estrela (Ethernet Gigabit Cat6)
- Dimensionamento de equipamentos e endereçamento IP
- Segmentação em VLANs (`VLAN_VENDAS`, `VLAN_FINANCEIRO`, `VLAN_SERVIDORES`)
- Servidor MySQL no IP fixo `192.168.30.10:3306`
- Comunicação segura e políticas de segurança

[👉 Ver Redes](06-redes/)

---

## 07 — Direitos Humanos e Inclusão

Reúne a análise do impacto humano, acessibilidade, ética e conformidade legal.

**Conteúdo:**
- Acessibilidade na CLI (alto contraste, navegação por teclado/números, leitores NVDA/Orca)
- Inclusão digital e usabilidade simplificada
- Privacidade, segurança de dados e logs de auditoria
- Conformidade com a LGPD (Artigos 6º e 18) e sanitização contra SQL Injection (`mysql_real_escape_string()`)

[👉 Ver Direitos Humanos e Inclusão](07-direitos-humanos/)

---

## 08 — Documentação Final

Reúne as versões consolidadas para revisão e entrega acadêmica do PIM II.

**Estrutura da Pasta:**
```text
08-documentacao-final/
├── backups/    # Versões intermediárias e revisões
└── entrega/    # Artefatos finais em DOCX e PDF (Normas ABNT)
```

[👉 Ver Documentação Final](08-documentacao-final/)

---

## Relação com Outras Áreas do Repositório

| Módulo | Caminho | Descrição |
|---|---|---|
| **Scrum** | [`/scrum/`](../scrum/) | Backlog, User Stories, DoD e histórico de Sprints |
| **Código C** | [`/src/c/`](../src/c/) | Código-fonte da aplicação CLI em Linguagem C |
| **Banco de Dados** | [`/database/`](../database/) | Scripts SQL DDL/DML, views e procedimentos |
| **Assets Visuais** | [`/assets/`](../assets/) | Imagens, diagramas exportados e recursos gráficos |

---

## Fluxo de Coerência entre Artefatos

```text
Regras de Negócio ──► Requisitos ──► Casos de Uso ──► Diagramas ──► Arquitetura ──► Banco de Dados ──► Implementação em C
```

---

## Status Geral da Documentação

| Área | Status | Detalhes / Entregáveis |
|---|:---:|---|
| **01 — Visão Geral** | 🟢 Concluído | Problema, objetivos, regras de negócio e perfis RBAC |
| **02 — Engenharia de Software** | 🟢 Concluído | RFs, RNFs, casos de uso e arquitetura lógica em C |
| **03 — Diagramas** | 🟢 Concluído | Casos de uso e diagrama estendido de módulos |
| **04 — Banco de Dados** | 🟢 Concluído | Conceitual, Lógico, Físico, 3FN e DDL no `/database/` |
| **05 — Pesquisa e Inovação** | 🟢 Concluído | Metodologia BPM, fundamentação e análise *AS-IS / TO-BE* |
| **06 — Redes** | 🟢 Concluído | Topologia, endereçamento, VLANs e MySQL no IP `192.168.30.10` |
| **07 — Direitos Humanos e Inclusão** | 🟢 Concluído | Acessibilidade CLI (NVDA), LGPD e segurança sanitizada |
| **08 — Documentação Final** | 🟡 Em desenvolvimento | Compilação e formatação ABNT dos arquivos DOCX e PDF |

---

## Observações de Manutenção

- **Sincronismo de Artefatos:** Qualquer alteração no escopo ou código em C/SQL deve ser refletida na respectiva documentação.
- **Preservação Histórica:** Os registros de Sprints na pasta `/scrum/` mantêm o histórico evolutivo, enquanto os arquivos em `docs/` refletem a versão atual do sistema.

---

[← Voltar ao README principal](../README.md)
