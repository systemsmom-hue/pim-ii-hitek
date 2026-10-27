# Histórico e Planejamento das Sprints

Esta seção reúne o histórico completo e o acompanhamento das Sprints do **Sistema de Gestão de Comissões — Hitek Informática (PIM II)**.

A organização reflete o desenvolvimento real e incremental do projeto, desde a concepção inicial até a implementação do banco de dados, aplicação executada no terminal em C e disciplinas complementares.

---

## Visão Geral do Ciclo de Vida

| Sprint | Título / Foco Principal | Status | Entregáveis Principais |
|---|---|:---:|---|
| **Sprint 01** | Definição Inicial do Projeto | ✅ Concluída | Escopo, problema, solução Hitek e objetivos do PIM II |
| **Sprint 02** | Requisitos e Planejamento | ✅ Concluída | Requisitos (RF/RNF), Regras de Negócio e Product Backlog |
| **Sprint 03** | Modelagem Inicial do Sistema | ✅ Concluída | 1ª versão do Casos de Uso e Modelo Entidade-Relacionamento |
| **Sprint 04** | Refinamento de Regras e Fluxo | ✅ Concluída | Estados da comissão, faturamento, retirada e Diagrama de Atividade |
| **Sprint 05** | Consolidação Funcional | ✅ Concluída | Diagrama Estendido, módulos C, tratamento de pagamentos parciais |
| **Sprint 06** | Gestão Scrum e GitHub | ✅ Concluída | Estruturação do repositório, User Stories, DoD e refinamento do PO |
| **Sprint 07** | Banco de Dados Relacional | ✅ Concluída | Conceitual, Lógico, Físico, 3FN e scripts DDL/DML MySQL (`schema.sql`) |
| **Sprint 08** | Programação Estruturada em C | ✅ Concluída | Aplicação no Terminal (C11 + MySQL API), RBAC, sanitização e transações |
| **Sprint 09** | Disciplinas Complementares | ✅ Concluída | Pesquisa/Inovação (BPM), Redes (VLANs/IPs) e Direitos Humanos/LGPD |
| **Sprint 10** | Diagramas de Sequência e Documentação | 🟢 Concluída | 4 Diagramas de Sequência UML, integração final e formatação ABNT |

---

# Sprint 01 — Definição Inicial do Projeto

Nesta etapa foram estabelecidas as bases estratégicas e operacionais do projeto.

**Principais Atividades:**
- Definição do cenário organizacional da Hitek Informática.
- Mapeamento do problema de controle manual de comissões.
- Proposta da solução computacional automatizada.
- Definição do escopo, justificativa e objetivos gerais/específicos.
- Mapeamento dos perfis iniciais e fluxo operacional de vendas.

📄 [Ver Detalhes da Sprint 01](sprint-01.md)

---

# Sprint 02 — Requisitos e Planejamento Inicial

Definição dos primeiros artefatos formais de Engenharia de Software.

**Principais Atividades:**
- Levantamento de Requisitos Funcionais (RFs) e Não Funcionais (RNFs).
- Formalização das Regras de Negócio iniciais.
- Definição da matriz de perfis e permissões (RBAC).
- Especificação textual dos primeiros Casos de Uso.
- Elaboração da versão inicial do Product Backlog.

📄 [Ver Detalhes da Sprint 02](sprint-02.md)

---

# Sprint 03 — Modelagem Inicial do Sistema

Estruturação visual e concepção do modelo de dados.

**Principais Atividades:**
- Primeira versão do Diagrama de Casos de Uso UML.
- Mapeamento das interações entre atores e sistema.
- Concepção inicial do Modelo Entidade-Relacionamento (MER).
- Levantamento de dúvidas técnicas e pontos de revisão funcional.

📄 [Ver Detalhes da Sprint 03](sprint-03.md)

---

# Sprint 04 — Refinamento das Regras e do Fluxo

Refinamento detalhado das regras operacionais e de cálculo de comissões.

**Principais Atividades:**
- Ciclo de vida da comissão (`PENDENTE`, `LIBERADA`, `PAGA`, `CANCELADA`).
- Condições de liberação: Venda faturada E equipamento retirado.
- Separação de responsabilidades: Confirmação da baixa mantida com o Financeiro.
- Desenvolvimento do Diagrama de Atividade para mapeamento do fluxo de processo.

> *Nota Histórica:* O Diagrama de Atividade fez parte da modelagem nesta etapa do projeto, sendo posteriormente substituído pelos Diagramas de Sequência e Estendido.

📄 [Ver Detalhes da Sprint 04](sprint-04.md)

---

# Sprint 05 — Consolidação da Modelagem Funcional

Mapeamento arquitetural das funções em C e tratamento de exceções financeiras.

**Principais Atividades:**
- Evolução do Diagrama de Casos de Uso (`<<include>>` de autenticação).
- Regra de abates e pagamentos parciais de comissões.
- Concepção do **Diagrama Estendido**, conectando os módulos funcionais às rotinas executáveis do sistema.

📄 [Ver Detalhes da Sprint 05](sprint-05.md)

---

# Sprint 06 — Organização do GitHub e Formalização do Scrum

Estruturação profissional do repositório e refinamentos solicitados pelo PO.

**Principais Atividades:**
- Padronização do repositório no GitHub e documentação em Markdown.
- Elaboração das User Stories, Product Backlog e Definition of Done (DoD).
- Incorporação do refinamento do PO para o perfil **Vendedor**:
  - Permissão para atualizar situação da venda e alterar o valor final da venda.
  - Bloqueio estrito de alteração do valor de custo e de confirmação de baixa.

📄 [Ver Detalhes da Sprint 06](sprint-06.md)

---

# Sprint 07 — Modelagem e Implementação do Banco de Dados

Concepção e implementação física do banco relacional.

**Principais Atividades:**
- Elaboração dos Modelos Conceitual, Lógico e Físico no MySQL 8.0.
- Aplicação das regras de normalização até a 3ª Forma Normal (3FN).
- Construção dos scripts SQL DDL (`schema.sql`) e DML na pasta `/database/`.
- Garantia de integridade referencial, chaves estrangeiras e índices.

📄 [Ver Detalhes da Sprint 07](sprint-07.md)

---

# Sprint 08 — Programação Estruturada em C

Desenvolvimento do software executável no terminal.

**Principais Atividades:**
- Construção da aplicação em Linguagem C11 para execução no terminal, integrada ao MySQL via `mysql.h`.
- Implementação dos módulos `vendas`, `financeiro`, `administrador`, `autenticacao` e `calculos`.
- Implementação de segurança com `mysql_real_escape_string()` contra SQL Injection.
- Controle transacional com `mysql_autocommit()`, `commit`, `rollback` e `FOR UPDATE`.
- Operações de precisão financeira em cêntimos (`long long`) para evitar erros de arredondamento.

📄 [Ver Detalhes da Sprint 08](sprint-08.md)

---

# Sprint 09 — Disciplinas Complementares

Documentação técnica das disciplinas integradas do PIM II.

**Principais Atividades:**
- **Pesquisa e Inovação:** Análise BPM do processo *AS-IS* vs. *TO-BE* (redução do tempo de fechamento de 2 dias para < 2 horas).
- **Redes e Infraestrutura:** Topologia em estrela, endereçamento IP, segmentação em VLANs (`VLAN_SERVIDORES` no IP `192.168.30.10:3306`).
- **Direitos Humanos e Inclusão:** Acessibilidade no terminal (compatibilidade com leitores NVDA/Orca) e conformidade com a LGPD.

📄 [Ver Detalhes da Sprint 09](sprint-09.md)

---

# Sprint 10 — Diagramas de Sequência, Integração e Entrega Final

Consolidação da modelagem UML dinâmica e compilação final do PIM II.

**Principais Atividades:**
- Elaboração e inclusão dos **4 Diagramas de Sequência UML**:
  1. *Autenticação e Login*
  2. *Cadastro de Venda e Cálculo de Comissão*
  3. *Conferência e Baixa Financeira*
  4. *Pagamento e Quitação de Comissão*
- Auditoria de rastreabilidade entre Código C, Scripts SQL e Documentação.
- Compilação dos arquivos consolidados em DOCX e PDF nas normas ABNT.

📄 [Ver Detalhes da Sprint 10](sprint-10.md)

---

## Evolução Temporal do Projeto

```text
Sprint 01: Definição do Projeto (Hitek)
   │
   ├──► Sprint 02: Requisitos e Backlog
   │
   ├──► Sprint 03: Modelagem Inicial (Casos de Uso / MER)
   │
   ├──► Sprint 04: Refinamento de Regras & Diagrama de Atividade
   │
   ├──► Sprint 05: Diagrama Estendido & Módulos Funcionais
   │
   ├──► Sprint 06: Padronização Scrum, GitHub & Permissões do PO
   │
   ├──► Sprint 07: Banco de Dados Relacional MySQL (3FN)
   │
   ├──► Sprint 08: Aplicação Executável no Terminal em C
   │
   ├──► Sprint 09: Pesquisa BPM, Infraestrutura de Redes & LGPD
   │
   └──► Sprint 10: 4 Diagramas de Sequência & Entrega Final ABNT
```

---

## Conjunto Atual de Diagramas de Engenharia de Software

Atualmente, o repositório mantém o conjunto completo de diagramas UML atualizados:

1. **Diagrama de Casos de Uso:** Mapeamento de atores e escopo por perfil (RBAC).
2. **Diagrama Estendido:** Mapeamento de módulos e funções em Linguagem C.
3. **Diagramas de Sequência (4 fluxos):**
   - *Autenticação e Login*
   - *Cadastro de Venda e Comissão*
   - *Baixa Financeira*
   - *Pagamento e Quitação*

> *Nota:* O Diagrama de Atividade utilizado nas Sprints 04 e 05 permanece registrado unicamente no histórico das respectivas Sprints, tendo sido descontinuado do conjunto principal de diagramas em favor dos Diagramas de Sequência.

---

## Preservação do Histórico

As Sprints concluídas preservam o registro fiel das decisões tomadas em cada momento do projeto. Alterações posteriores solicitadas pelo PO (como as novas permissões do perfil Vendedor na Sprint 06) são registradas a partir da Sprint em que foram introduzidas, mantendo a rastreabilidade histórica do produto.

---

[← Voltar para a pasta Scrum](../README.md)
