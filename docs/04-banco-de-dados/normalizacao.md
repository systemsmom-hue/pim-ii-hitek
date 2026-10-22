
# 📐 Processo de Normalização de Banco de Dados

Este documento apresenta a demonstração prática da aplicação das **Formas Normais** (1FN, 2FN e 3FN) no modelo de banco de dados do **Sistema de Gestão de Comissões — Hitek Informática**.

O objetivo do processo de normalização é organizar as tabelas para eliminar redundâncias de dados, evitar anomalias de alteração, inserção e exclusão, além de assegurar a integridade relacional.

---

## 1. Primeira Forma Normal (1FN)

**Regra da 1FN:** Uma tabela está na 1FN se todos os seus atributos contiverem apenas valores atômicos (indivisíveis) e não existirem colunas repetidas ou vetores/grupos repetitivos.

### Análise e Adequação no Projeto

#### Cenário Não Normalizado (*Unnormalized Form*):
Em uma planilha inicial, os dados de uma comissão e seus eventuais descontos eram mantidos em uma única linha com campos compostos ou repetidos:

| Venda_ID | Vendedor | Descontos_Aplicados | Valores_Descontos |
| :---: | :---: | :---: | :---: |
| 101 | Carlos Silva | Taxa Cartão, Estorno Parcial | R$ 15,00, R$ 30,00 |

#### Solução Aplicada para a 1FN:
* **Atomicidade de Atributos:** Todos os campos possuem valores indivisíveis (por exemplo, `nome` é armazenado como string simples, `data_venda` possui tipo nativo `DATETIME`).
* **Eliminação de Grupos Repetidos:** Os descontos foram destacados da tabela principal e alocados em uma entidade própria (`descontos`), onde cada registro representa exatamente **um** abatimento vinculado ao `id_comissao`.

---

## 2. Segunda Forma Normal (2FN)

**Regra da 2FN:** A tabela precisa estar na 1FN e todos os atributos não-chave devem depender **totalmente** da chave primária (eliminação da dependência funcional parcial em chaves compostas).

### Análise e Adequação no Projeto

#### Aplicação de Chaves Primárias Simples:
Todas as tabelas do esquema (`usuarios`, `colaboradores`, `vendas`, `comissoes`, `pagamentos`, `descontos`, `configuracoes`) utilizam chaves primárias atômicas do tipo inteiro com autoincremento (`id_usuario`, `id_colaborador`, `id_venda`, etc.).

Por não existirem chaves primárias compostas no modelo físico, **não há risco de dependência funcional parcial**, garantindo automaticamente a conformidade com a 2FN.

---

## 3. Terceira Forma Normal (3FN)

**Regra da 3FN:** A tabela precisa estar na 2FN e nenhum atributo não-chave pode depender de outro atributo não-chave (eliminação da dependência transitiva).

### Análise e Adequação no Projeto

#### Cenário de Dependência Transitiva Identificado (*Violação de 3FN*):
Se a tabela `vendas` contivesse diretamente os dados cadastrais do vendedor (por exemplo, `nome_vendedor`, `cpf_vendedor`, `percentual_comissao`):

$$\text{id\_venda} \longrightarrow \text{id\_colaborador} \longrightarrow \text{cpf\_vendedor}$$

O campo `cpf_vendedor` dependeria de `id_colaborador`, que por sua vez não é a chave primária da tabela `vendas`.

#### Solução Aplicada para a 3FN:
1. **Separação de Entidades:** Criou-se a tabela `colaboradores` com `id_colaborador` como PK, isolando `cpf`, `cargo` e `percentual_padrao`.
2. **Referência por Chave Estrangeira:** A tabela `vendas` armazena apenas a chave estrangeira `id_colaborador`.
3. **Cálculo Deslocado:** O valor apurado da comissão fica restrito à tabela `comissoes`, evitando guardar valores calculados redundantes dentro da tabela de vendas.

---

## 4. Quadro Resumo de Conformidade

| Tabela | Chave Primária | 1FN | 2FN | 3FN | Estratégia de Normalização |
| :--- | :--- | :---: | :---: | :---: | :--- |
| **`usuarios`** | `id_usuario` |  |  |  | Atributos atômicos e login único. |
| **`colaboradores`** | `id_colaborador` |  |  |  | Isolamento dos dados do vendedor e chave PIX. |
| **`vendas`** | `id_venda` |  |  |  | Apontamento exclusivo para a FK `id_colaborador`. |
| **`comissoes`** | `id_comissao` |  |  |  | Separação do estado e do cálculo da venda. |
| **`pagamentos`** | `id_pagamento` |  |  |  | Registro financeiro independente por FK. |
| **`descontos`** | `id_desconto` |  |  |  | Coleção de descontos individualizados por ID. |
| **`configuracoes`** | `id_configuracao` |  |  |  | Parâmetros chave/valor únicos. |

---

## 📜 Documentação Relacionada

- [Modelo Conceitual](modelo-conceitual.md)
- [Modelo Lógico](modelo-logico.md)
- [Modelo Físico](modelo-fisico.md)
