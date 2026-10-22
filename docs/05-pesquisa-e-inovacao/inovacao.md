# 💡 Inovação e Melhorias Operacionais

Este documento detalha os aspectos de inovação tecnológica e operacional trazidos pelo **Sistema de Gestão de Comissões** para a **Hitek Informática**, contrastando a solução desenvolvida com o cenário operacional anterior.

---

## 1. Contexto do Problema e Necessidade de Inovação

A Hitek Informática enfrentava entraves decorrentes do uso de processos manuais e planilhas eletrônicas descentralizadas para o fechamento mensal das comissões de seus colaboradores. Esse formato gerava:

* **Inconsistência nos Dados:** Erros recorrentes em cálculos manuais de percentuais e margens.
* **Gargalo de Tempo:** Necessidade de aproximadamente **2 dias úteis** dedicados exclusivamente ao fecho de comissões.
* **Falta de Transparência:** Dificuldade em auditagem e acompanhamento em tempo real dos pagamentos e status das comissões.
* **Insegurança da Informação:** Dados sensíveis salvos em arquivos locais sem controle rigoroso de acesso.

A introdução de um sistema computacional estruturado em Linguagem C e banco de dados relacional MySQL constitui uma **inovação de processo** no ambiente organizacional da empresa.

---

## 2. Pilares da Inovação Proposta

### 2.1. Automação de Regras de Negócio e Cálculos
* **Cenário Anterior:** O cálculo do valor da comissão exigia digitação manual de taxas e aplicação pontual de descontos ou taxas adicionais.
* **Inovação Aplicada:** O sistema calcula de forma automática e determinística a margem de comissão com base em regras previamente parametrizadas no banco de dados (`CONFIGURACAO` e `DESCONTO`), garantindo **0% de margem de erro sintático/aritmético**.

### 2.2. Gestão por Estado de Comissão (*Workflow*)
* **Cenário Anterior:** As comissões eram marcadas de forma informal em planilhas sem rastreabilidade do histórico de alterações.
* **Inovação Aplicada:** Implementação de uma máquina de estados finitos controlada por software:
  
$$\text{Venda Registrada} \longrightarrow \text{Comissão Pendente} \longrightarrow \text{Comissão Liberada} \longrightarrow \text{Pagamento Efetivado}$$

A mudança de estado exige validações de perfil e confirmação no banco de dados, criando uma trilha de auditoria confiável.

### 2.3. Centralização e Integridade de Dados
* **Cenário Anterior:** Múltiplas versões da mesma planilha armazenadas em computadores diferentes.
* **Inovação Aplicada:** Persistência em Sistema Gerenciador de Banco de Dados Relacional (**MySQL**), assegurando integridade referencial (*Foreign Keys*), suporte a transações e backup padronizado.

### 2.4. Segurança e Controle de Acesso Baseado em Perfis (RBAC)
* **Cenário Anterior:** Acesso genérico aos arquivos por qualquer pessoa com permissão na pasta compartilhada.
* **Inovação Aplicada:** Autenticação individualizada com três níveis funcionais:
  1. **Administrador:** Gestão global, parâmetros e relatórios.
  2. **Financeiro:** Liberação de comissões e registro de pagamentos.
  3. **Vendedor/Colaborador:** Consulta restrita do próprio extrato de vendas e comissões.

---

## 3. Matriz Comparativa: *AS-IS* vs. *TO-BE*

| Dimensão | Processo Anterior (*AS-IS*) | Solução Inovadora (*TO-BE*) |
| :--- | :--- | :--- |
| **Meio de Registro** | Planilhas descentralizadas / Papel | Banco de Dados Relacional Centralizado (MySQL) |
| **Tempo de Processamento** | $\approx 2$ dias úteis | $< 2$ horas |
| **Cálculo de Margens** | Manual (Sujeito a falhas humanas) | Automatizado por rotinas em Linguagem C |
| **Auditoria** | Inexistente / Difícil verificação | Trilha de auditoria por perfil e ID de transação |
| **Segurança da Informação** | Sem controle de acesso por usuário | Autenticação RBAC com senhas e perfis |
| **Acompanhamento de Status** | Informal | Estados formais (*Pendente*, *Liberada*, *Paga*) |

---

## 4. Impactos Organizacionais e Ganhos de Produtividade

A automação trouxe benefícios diretos para os diferentes atores da empresa:

1. **Equipe de Vendas:** Aumento da confiança na exatidão dos valores recebidos e previsibilidade de recebimentos.
2. **Setor Financeiro:** Liberação do tempo de trabalho antes gasto em conferência manual para atividades estratégicas.
3. **Gestão / Diretoria:** Acesso a relatórios gerenciais consolidados para tomada de decisão fundamentada em dados reais.

---

## 📜 Documentação Relacionada

* [Visão Geral da Pesquisa e Inovação](README.md)
* [Metodologia](metodologia.md)
* [Fundamentação Teórica](fundamentacao-teorica.md)
