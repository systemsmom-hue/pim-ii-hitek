# 📚 Fundamentação Teórica

Este documento reúne a sustentação teórica e bibliográfica que embasa o projeto do **Sistema de Gestão de Comissões — Hitek Informática**, desenvolvido no âmbito do Projeto Integrado Multidisciplinar (PIM II). 

A fundamentação abrange os conceitos essenciais de Gestão por Processos de Negócio (BPM), Sistemas de Informação Gerencial, Engenharia de Software, Programação Estruturada e Modelagem de Bancos de Dados Relacionais.

---

## 1. Gestão por Processos de Negócio (BPM)

A **Gestão por Processos de Negócio** (*Business Process Management* — BPM) é uma abordagem disciplinada para identificar, desenhar, executar, documentar, medir, monitorar e controlar processos de negócios automatizados e não automatizados, com o intuito de alcançar resultados consistentes e alinhados com os objetivos estratégicos da organização (ABPMP, 2013).

### 1.1. Mapeamento de Processos: AS-IS e TO-BE

De acordo com **Gonçalves (2000)**, um processo de negócio é um conjunto de atividades estruturadas e mensuráveis destinadas a produzir um resultado específico para um determinado cliente ou mercado. A eficácia da automação depende diretamente da compreensão do fluxo atual de trabalho:

* **Estágio *AS-IS* (Como é):** Representa o mapeamento da situação atual do processo de fechamento de comissões na Hitek Informática, caracterizado por planilhas manuais, alto tempo de execução e vulnerabilidade a equívocos de digitação ou cálculo.
* **Estágio *TO-BE* (Como será):** Corresponde ao estado futuro otimizado, onde o fluxo de dados é padronizado, automatizado por software e persistido centralizadamente em banco de dados.

**Iritani et al. (2015)** destacam que a transição do estado *AS-IS* para o *TO-BE*, quando apoiada por sistemas computacionais, promove a eliminação de retrabalhos, reduz drasticamente os tempos de ciclo e amplia a transparência nas relações de trabalho.

---

## 2. Sistemas de Informação Gerencial (SIG) e Automação

Os **Sistemas de Informação Gerencial (SIG)** fornecem informações necessárias para gerenciar com eficácia as organizações, automatizando rotinas operacionais e consolidando dados para apoio à tomada de decisão (STAIR; REYNOLDS, 2011).

### 2.1. Redução de Erros Operacionais e Tempo de Ciclo

A automação de processos financeiros e remuneratórios substitui tarefas repetitivas propensas à falha humana por algoritmos determinísticos. Conforme aponta **Laudon e Laudon (2014)**:

> *"Os sistemas de informação transformam dados brutos em informações úteis, eliminando discrepâncias operacionais e permitindo que as empresas operem com maior precisão e agilidade em suas rotinas contábeis e administrativas."*

 No contexto da Hitek Informática, a aplicação do SIG assegura a aplicação exata de taxas, margens e descontos sem dependência da intervenção manual do operador.

---

## 3. Engenharia de Software e Programação Estruturada

O desenvolvimento da camada de aplicação fundamenta-se nos princípios da **Programação Estruturada** e da **Modularização**, conforme consolidados por **Kernighan e Ritchie (1988)** e **Deitel e Deitel (2011)**.

### 3.1. Paradigma da Programação Estruturada em C

A Linguagem C provê alto desempenho e controle rigoroso de recursos de memória através de:

1. **Modularidade:** Divisão do código em submódulos independentes e coesos (`vendas.c`, `financeiro.c`, `administrador.c`, `banco.c`), facilitando a manutenção e os testes unitários.
2. **Estruturas de Controle Formais:** Uso exclusivo de sequências, seleções (`if/else`, `switch`) e repetições (`for`, `while`) para controle claro do fluxo sintático.
3. **Abstração de Dados via Structs:** Agrupamento de propriedades complexas (ex.: vendedor, venda, comissão) em estruturas de dados bem personalizadas.

---

## 4. Modelagem e Gerenciamento de Bancos de Dados Relacionais

Para assegurar a consistência, integridade e perenidade das informações, a solução utiliza um **Sistema Gerenciador de Banco de Dados Relacional (SGBDR)** fundamentado nos postulados de **Codd (1970)** e **Elmasri e Navathe (2011)**.

### 4.1. Normalização de Dados

A **Normalização** é o processo formal de análise dos esquemas de relatas com base em suas dependências funcionais e chaves primárias, visando eliminar redundâncias e anomalias de inserção, atualização e exclusão (DATE, 2004).

* **Primeira Forma Normal (1FN):** Eliminação de grupos repetidos e garantia de que todos os atributos contêm apenas valores atômicos (indivisíveis).
* **Segunda Forma Normal (2FN):** Garantia de que todos os atributos não-chave sejam totalmente dependentes da chave primária (eliminação da dependência parcial).
* **Terceira Forma Normal (3FN):** Remoção de dependências transitivas, garantindo que nenhum atributo não-chave dependa de outro atributo não-chave.

### 4.2. Integridade Referencial e ACID

A implementação no **MySQL** assegura as propriedades **ACID** (Atomicidade, Consistência, Isolamento e Durabilidade) através do uso de chaves estrangeiras (*Foreign Keys*), garantindo que pagamentos de comissão estejam obrigatoriamente vinculados a vendas válidas e colaboradores cadastrados.

---

## 5. Referências Bibliográficas

* **ABPMP.** *BPM CBOK: Guia para o Gerenciamento de Processos de Negócio*. Corpo Comum de Conhecimento, Versão 3.0, 2013.
* **CODD, E. F.** *A Relational Model of Data for Large Shared Data Banks*. Communications of the ACM, v. 13, n. 6, p. 377-387, 1970.
* **DATE, C. J.** *Introdução a Sistemas de Bancos de Dados*. 8. ed. Rio de Janeiro: Elsevier, 2004.
* **DEITEL, P.; DEITEL, H.** *C: Como Programar*. 6. ed. São Paulo: Pearson Hall, 2011.
* **ELMASRI, R.; NAVATHE, S. B.** *Sistemas de Banco de Dados*. 6. ed. São Paulo: Pearson Addison Wesley, 2011.
* **GONÇALVES, J. E. L.** *As empresas são grandes coleções de processos*. RAE - Revista de Administração de Empresas, v. 40, n. 1, p. 6-19, 2000.
* **IRITANI, D. A. et al.** *Análise da Gestão por Processos de Negócio (BPM) aplicados em ambientes organizacionais*. Revista de Gestão e Projetos (GeP), v. 6, n. 2, p. 45-59, 2015.
* **KERNIGHAN, B. W.; RITCHIE, D. M.** *The C Programming Language*. 2. ed. Englewood Cliffs: Prentice Hall, 1988.
* **LAUDON, K. C.; LAUDON, J. P.** *Sistemas de Informação Gerenciais*. 11. ed. São Paulo: Pearson Education, 2014.
* **STAIR, R. M.; REYNOLDS, G. W.** *Princípios de Sistemas de Informação*. 9. ed. São Paulo: Cengage Learning, 2011.

---

## 📜 Documentação Relacionada

* [Visão Geral da Pesquisa e Inovação](README.md)
* [Metodologia](metodologia.md)
* [Análise da Inovação](inovacao.md)
