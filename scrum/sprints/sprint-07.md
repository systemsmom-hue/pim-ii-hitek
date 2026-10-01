# Sprint 07 — Modelagem e Implementação do Banco de Dados

A Sprint 07 representa a etapa planejada para desenvolvimento e consolidação do banco de dados do **Sistema de Gestão de Comissões — Hitek Informática**.

Nesta Sprint, a modelagem iniciada anteriormente deverá ser revisada e transformada em uma estrutura de banco de dados coerente com os requisitos, regras de negócio, casos de uso e diagramas já definidos.

> Esta Sprint ainda não foi concluída. As atividades abaixo representam o planejamento da próxima etapa do projeto.

---

## Status

**Planejada**

---

## Objetivo da Sprint

Desenvolver e validar a modelagem completa do banco de dados do sistema, garantindo coerência entre os dados armazenados e o funcionamento definido nos demais artefatos do projeto.

---

## Atividades planejadas

| ID | Atividade | Status |
|---|---|---|
| SP07-01 | Revisar a modelagem inicial existente | ⚪ Pendente |
| SP07-02 | Definir as entidades definitivas | ⚪ Pendente |
| SP07-03 | Definir os atributos das entidades | ⚪ Pendente |
| SP07-04 | Definir as chaves primárias | ⚪ Pendente |
| SP07-05 | Definir as chaves estrangeiras | ⚪ Pendente |
| SP07-06 | Definir os relacionamentos | ⚪ Pendente |
| SP07-07 | Definir as cardinalidades | ⚪ Pendente |
| SP07-08 | Desenvolver e validar o modelo conceitual | ⚪ Pendente |
| SP07-09 | Desenvolver o DER | ⚪ Pendente |
| SP07-10 | Desenvolver o modelo lógico | ⚪ Pendente |
| SP07-11 | Realizar a normalização | ⚪ Pendente |
| SP07-12 | Documentar a normalização | ⚪ Pendente |
| SP07-13 | Desenvolver o modelo físico | ⚪ Pendente |
| SP07-14 | Criar os scripts SQL | ⚪ Pendente |
| SP07-15 | Criar comandos de inserção de dados para testes | ⚪ Pendente |
| SP07-16 | Criar consultas SQL relevantes | ⚪ Pendente |
| SP07-17 | Avaliar a utilização de NoSQL | ⚪ Pendente |
| SP07-18 | Justificar a utilização ou não de NoSQL | ⚪ Pendente |
| SP07-19 | Conferir coerência entre banco de dados e regras de negócio | ⚪ Pendente |
| SP07-20 | Conferir coerência entre banco de dados e diagramas | ⚪ Pendente |

---

## Entidades previstas

A modelagem deverá considerar as informações necessárias para o funcionamento do sistema.

Entre as entidades já identificadas estão:

```text
USUARIO
COLABORADOR
CLIENTE
VENDA
COMISSAO
PAGAMENTO
CONFIGURACAO
AJUSTE
```

A estrutura definitiva ainda deverá ser validada durante esta Sprint.

---

## Usuário

A entidade de usuário deverá armazenar informações relacionadas ao acesso ao sistema.

Informações previstas:

```text
id_usuario
nome
login
senha
perfil
status
```

Os perfis utilizados pelo sistema são:

- Vendedor;
- Financeiro;
- Administrador.

---

## Colaborador

A entidade de colaborador deverá representar as pessoas relacionadas às vendas e comissões.

Informações previstas:

```text
id_colaborador
nome
cargo
status
```

O colaborador é diferente do usuário do sistema.

Um colaborador poderá estar relacionado às vendas e às comissões independentemente das informações utilizadas para autenticação.

---

## Cliente

A entidade Cliente deverá armazenar somente as informações necessárias ao contexto das vendas utilizadas no sistema.

Informações inicialmente previstas:

```text
id_cliente
nome
documento
telefone
email
```

A necessidade definitiva de todos esses campos deverá ser validada antes da implementação.

---

## Venda

A entidade Venda deverá representar as informações necessárias para o acompanhamento do processo comercial e da liberação da comissão.

Entre os dados previstos estão:

```text
id_venda
numero_os
data_venda
cliente
colaborador_responsavel
valor_venda
custo
margem
forma_pagamento
situacao_pagamento
situacao_faturamento
data_retirada
data_baixa
usuario_responsavel_baixa
```

Essas informações deverão permitir verificar as condições necessárias para liberação da comissão.

---

## Comissão

A entidade Comissão deverá representar a comissão gerada a partir de uma venda.

Informações previstas:

```text
id_comissao
venda
colaborador
percentual
valor_comissao
data_calculo
situacao
```

Os estados utilizados são:

```text
Pendente
Liberada
Paga
```

O percentual utilizado no momento do cálculo deverá permanecer associado à comissão para preservar o histórico.

---

## Pagamento

A entidade Pagamento deverá armazenar os pagamentos realizados para uma comissão.

Informações previstas:

```text
id_pagamento
comissao
data_pagamento
valor_pago
usuario_responsavel
```

A estrutura deverá permitir registrar mais de um pagamento relacionado à mesma comissão.

Isso permitirá representar pagamentos parciais.

---

## Configuração

A entidade Configuração deverá armazenar parâmetros utilizados pelo sistema.

Entre eles:

```text
id_configuracao
percentual_comissao
data_alteracao
usuario_responsavel
```

O percentual padrão atualmente considerado no projeto é:

**1%**

Entretanto, o sistema deverá permitir sua alteração por usuário autorizado.

---

## Ajuste

A entidade Ajuste poderá ser utilizada para registrar diferenças ou correções relacionadas às comissões.

Informações previstas:

```text
id_ajuste
comissao
tipo_ajuste
valor
motivo
data
usuario_responsavel
```

Essa estrutura deverá permitir manter o histórico dos ajustes realizados.

---

## Relacionamentos principais

A modelagem deverá validar relacionamentos como:

```text
COLABORADOR 1 ─── N VENDA

VENDA 1 ─── 1 COMISSAO

COMISSAO 1 ─── N PAGAMENTO

COMISSAO 1 ─── N AJUSTE

USUARIO 1 ─── N operações registradas
```

As cardinalidades definitivas deverão ser confirmadas durante a modelagem.

---

## Pagamentos parciais

O banco deverá ser capaz de representar o fluxo de múltiplos pagamentos de uma comissão.

Exemplo:

```text
COMISSAO
   |
   ├── PAGAMENTO 01
   |
   ├── PAGAMENTO 02
   |
   └── PAGAMENTO 03
```

A existência de vários registros de pagamento permitirá calcular:

- valor total da comissão;
- valor total pago;
- saldo restante.

Enquanto houver saldo, a comissão permanecerá como:

**Liberada**

Quando o saldo chegar a zero:

**Paga**

---

## Preservação do histórico

Alterações futuras no percentual de comissão não deverão modificar comissões calculadas anteriormente.

Por isso, o percentual aplicado deverá ser armazenado na própria comissão.

Exemplo:

```text
CONFIGURACAO
percentual_atual = 1.5%

COMISSAO ANTIGA
percentual_aplicado = 1%

COMISSAO NOVA
percentual_aplicado = 1.5%
```

Dessa forma, o histórico permanece preservado.

---

## Modelo Conceitual

O modelo conceitual deverá apresentar:

- entidades;
- relacionamentos;
- cardinalidades.

Sem se preocupar inicialmente com tipos específicos de dados do SGBD.

Arquivo:

```text
docs/04-banco-de-dados/modelo-conceitual.md
```

---

## DER

O Diagrama Entidade-Relacionamento deverá representar visualmente a estrutura conceitual do banco.

Arquivo previsto:

```text
docs/04-banco-de-dados/der.png
```

---

## Modelo Lógico

O modelo lógico deverá transformar as entidades em estruturas de tabelas.

Deverá apresentar:

- tabelas;
- atributos;
- chaves primárias;
- chaves estrangeiras;
- relacionamentos.

Arquivo:

```text
docs/04-banco-de-dados/modelo-logico.md
```

---

## Normalização

A estrutura deverá ser analisada quanto às formas normais aplicáveis.

A documentação deverá abordar:

```text
1FN
2FN
3FN
```

O objetivo será reduzir redundâncias e manter a consistência dos dados.

Arquivo:

```text
docs/04-banco-de-dados/normalizacao.md
```

---

## Modelo Físico

O modelo físico deverá representar a implementação definitiva no SGBD escolhido.

Deverá apresentar elementos como:

```text
INT
VARCHAR
DECIMAL
DATE
DATETIME
PRIMARY KEY
FOREIGN KEY
UNIQUE
NOT NULL
```

Arquivo:

```text
docs/04-banco-de-dados/modelo-fisico.md
```

---

## Scripts SQL

Os scripts serão armazenados em:

```text
database/sql/
```

Estrutura prevista:

```text
database/
└── sql/
    ├── schema.sql
    ├── inserts.sql
    └── consultas.sql
```

### schema.sql

Responsável pela criação das estruturas do banco.

### inserts.sql

Responsável pelos dados utilizados durante testes.

### consultas.sql

Responsável por armazenar consultas relevantes utilizadas no projeto.

---

## NoSQL

A Sprint também deverá analisar a necessidade ou não da utilização de banco de dados NoSQL.

A decisão deverá ser justificada tecnicamente.

O objetivo não é utilizar NoSQL apenas por obrigação, mas avaliar se esse tipo de banco apresenta alguma vantagem real para o sistema proposto.

---

## Validação da modelagem

Antes de considerar a Sprint concluída, deverá ser verificada a coerência entre:

```text
Requisitos
    ↓
Regras de negócio
    ↓
Casos de uso
    ↓
Diagramas
    ↓
Banco de dados
```

A estrutura de dados deverá ser capaz de representar todas as informações necessárias ao fluxo do sistema.

---

## Critérios para conclusão da Sprint

A Sprint 07 somente deverá ser marcada como concluída quando:

- o modelo conceitual estiver validado;
- o DER estiver finalizado;
- o modelo lógico estiver definido;
- as chaves estiverem corretas;
- os relacionamentos estiverem corretos;
- as cardinalidades estiverem definidas;
- a normalização estiver documentada;
- o modelo físico estiver pronto;
- os principais scripts SQL estiverem criados;
- a decisão sobre NoSQL estiver justificada;
- a modelagem estiver coerente com as regras de negócio.

---

## Resultado esperado

Ao final desta Sprint, o projeto deverá possuir uma estrutura de banco de dados completa e documentada, preparada para armazenar as informações necessárias ao funcionamento do Sistema de Gestão de Comissões.

---

## Documentação relacionada

- [Banco de Dados](../../docs/04-banco-de-dados/)
- [Regras de Negócio](../../docs/01-visao-geral/regras-de-negocio.md)
- [Requisitos Funcionais](../../docs/02-engenharia-de-software/requisitos-funcionais.md)
- [Casos de Uso](../../docs/02-engenharia-de-software/casos-de-uso.md)
- [Diagramas](../../docs/03-diagramas/)

---

[← Voltar para Scrum](../README.md)
