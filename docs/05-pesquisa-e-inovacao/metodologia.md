# 📑 Metodologia de Pesquisa e Desenvolvimento

Este documento descreve a metodologia aplicada no mapeamento, diagnóstico e desenvolvimento do **Sistema de Gestão de Comissões** para a empresa **Hitek Informática**, como parte do Projeto Integrado Multidisciplinar (PIM II).

---

## 1. Caracterização da Pesquisa

O estudo classifica-se como uma **pesquisa aplicada**, com abordagem **qualitativa** e caráter **exploratório-descritivo**, utilizando como procedimento o **estudo de caso** e a **pesquisa-ação** no ambiente operacional da Hitek Informática.

- **Natureza:** Aplicada, voltada para a solução prática de um problema real de gestão de comissões.
- **Abordagem:** Qualitativa no mapeamento de requisitos e quantitativa na mensuração do tempo de processamento e precisão dos cálculos.
- **Objetivo:** Explorar as falhas do processo manual existente e descrever a arquitetura do novo sistema automatizado.

---

## 2. Diagnóstico da Situação Atual (*AS-IS*)

A etapa inicial consistiu na análise crítica do processo de fechamento de comissões da empresa, onde foram identificados os seguintes gargalos:

- **Processo Manual e Descentralizado:** Utilização de planilhas eletrônicas avulsas e anotações físicas.
- **Elevado Tempo de Processamento:** O fechamento mensal das comissões demandava aproximadamente **2 dias úteis** do setor financeiro.
- **Vulnerabilidade a Erros:** Riscos contínuos de incoerência em percentuais de comissão, cálculo de margens e aplicação de descontos.
- **Falta de Rastreabilidade:** Ausência de controle claro sobre o ciclo de vida da comissão (*Pendente*, *Liberada*, *Paga*).

---

## 3. Coleta de Dados e Levantamento de Requisitos

Para fundamentar o desenvolvimento da solução, foram empregados quatro procedimentos principais:

1. **Observação Direta:** Acompanhamento presencial da rotina de registro de vendas e conciliação de pagamentos.
2. **Entrevistas Semiestruturadas:** Diálogos com gestores, vendedores e equipe financeira para extração de requisitos funcionais e não funcionais.
3. **Mapeamento de Processos (BPM):** Modelação dos fluxos de trabalho para eliminação de etapas redundantes e estruturação do estado ideal (*TO-BE*).
4. **Pesquisa Bibliográfica:** Levantamento teórico fundamentado em literatura técnica sobre Gestão por Processos de Negócio (BPM), Engenharia de Software e Modelagem de Bancos de Dados Relacionais.

---

## 4. Metodologia de Desenvolvimento da Solução

O desenvolvimento do software seguiu uma abordagem iterativa baseada nos princípios do framework **Scrum**, estruturada nas seguintes fases:

```text
[ Levantamento ] ➔ [ Modelação BD ] ➔ [ Desenvolvimento C ] ➔ [ Validação & Testes ]
```

### 4.1. Modelação do Banco de Dados
- Construção dos modelos Conceitual (DER), Lógico e Físico.
- Aplicação das Três Primeiras Formas Normais (1FN, 2FN e 3FN) para eliminação de redundâncias.
- Implementação em **MySQL** garantindo integridade referencial via chaves estrangeiras e restrições.

### 4.2. Implementação do Software
- Desenvolvimento da lógica do sistema em **Linguagem C** modularizada (`vendas.c`, `financeiro.c`, `administrador.c`, `banco.c`).
- Integração com o banco MySQL via API nativa do cliente C (`mysql.h`).
- Implementação de controle de acesso baseado em perfis (RBAC).

---

## 5. Métrica de Sucesso e Resultados Esperados

A eficácia da metodologia e da solução proposta é avaliada pelo alcance dos seguintes indicadores operacionais:

| Indicador | Situação Anterior (*AS-IS*) | Meta com o Sistema (*TO-BE*) |
| :--- | :---: | :---: |
| **Tempo de Fechamento** | ~2 dias úteis | **< 2 horas** |
| **Margem de Erro nos Cálculos** | Suscetível a falhas humanas | **0% (automação via SQL/C)** |
| **Rastreabilidade de Status** | Inexistente / Manual | **100% auditável** |
| **Centralização dos Dados** | Planilhas dispersas | **Banco MySQL centralizado** |

---

## 📜 Documentação Relacionada

- [Visão Geral da Pesquisa e Inovação](README.md)
- [Fundamentação Teórica](fundamentacao-teorica.md)
- [Análise da Inovação](inovacao.md)
