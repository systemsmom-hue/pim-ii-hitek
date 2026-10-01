# Banco de Dados — Scripts SQL

Esta pasta será utilizada para armazenar os scripts SQL do **Sistema de Gestão de Comissões — Hitek Informática**.

A documentação conceitual e lógica do banco ficará separada em:

```text
docs/04-banco-de-dados/
```

Já os arquivos executáveis relacionados à implementação do banco serão armazenados nesta pasta.

---

## Status

**Planejado**

Os scripts SQL ainda não foram desenvolvidos.

Eles serão criados após a validação do modelo conceitual, DER, modelo lógico e normalização.

---

## Organização prevista

A estrutura planejada é:

```text
database/
├── README.md
└── sql/
    ├── schema.sql
    ├── inserts.sql
    └── consultas.sql
```

---

## schema.sql

O arquivo:

```text
sql/schema.sql
```

será responsável pela criação da estrutura do banco de dados.

Deverá conter comandos relacionados a:

- criação do banco quando aplicável;
- criação das tabelas;
- definição das chaves primárias;
- definição das chaves estrangeiras;
- restrições;
- relacionamentos entre as tabelas.

Exemplos de comandos que poderão ser utilizados:

```sql
CREATE DATABASE
CREATE TABLE
PRIMARY KEY
FOREIGN KEY
UNIQUE
NOT NULL
```

A estrutura definitiva somente será criada após a conclusão da modelagem.

---

## inserts.sql

O arquivo:

```text
sql/inserts.sql
```

será utilizado para armazenar dados de teste.

Esses dados poderão ser utilizados para verificar:

- funcionamento dos relacionamentos;
- inserção de registros;
- consultas;
- cálculos;
- situações de comissão;
- pagamentos.

Os dados utilizados deverão ser fictícios ou adequados ao contexto acadêmico do projeto.

---

## consultas.sql

O arquivo:

```text
sql/consultas.sql
```

será utilizado para armazenar consultas relevantes para o funcionamento e demonstração do sistema.

As consultas poderão envolver informações relacionadas a:

- usuários;
- colaboradores;
- vendas;
- comissões;
- pagamentos;
- relatórios.

Exemplo de operações que poderão ser utilizadas:

```sql
SELECT
JOIN
WHERE
GROUP BY
ORDER BY
```

As consultas definitivas serão definidas conforme a estrutura final do banco.

---

## Entidades previstas

A modelagem atual considera entidades relacionadas a:

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

Essa estrutura ainda deverá ser validada na etapa de Banco de Dados.

---

## Relações principais previstas

Entre os relacionamentos que deverão ser analisados estão:

```text
COLABORADOR → VENDA

VENDA → COMISSAO

COMISSAO → PAGAMENTO

COMISSAO → AJUSTE

USUARIO → operações registradas
```

As cardinalidades definitivas serão estabelecidas durante a modelagem.

---

## Pagamentos parciais

O banco deverá permitir que uma comissão possua mais de um pagamento.

Estrutura conceitual:

```text
COMISSAO
   |
   ├── PAGAMENTO 01
   ├── PAGAMENTO 02
   └── PAGAMENTO 03
```

Essa estrutura permitirá controlar:

- valor total da comissão;
- valor já pago;
- saldo restante;
- quitação da comissão.

---

## Histórico do percentual

O percentual utilizado no cálculo de uma comissão deverá ser preservado.

Uma alteração posterior no percentual configurado não deverá modificar comissões calculadas anteriormente.

Exemplo:

```text
Percentual atual do sistema: 1,5%

Comissão antiga:
percentual utilizado = 1%

Nova comissão:
percentual utilizado = 1,5%
```

A estrutura do banco deverá permitir esse histórico.

---

## Ordem de desenvolvimento

Os scripts SQL somente deverão ser produzidos após a conclusão das etapas:

```text
Modelo Conceitual
        ↓
DER
        ↓
Modelo Lógico
        ↓
Normalização
        ↓
Modelo Físico
        ↓
Scripts SQL
```

Isso evita implementar uma estrutura que ainda esteja sujeita a alterações.

---

## Validação

Antes de considerar os scripts concluídos, deverão ser realizados testes de:

- criação das tabelas;
- inserção de registros;
- integridade das chaves;
- relacionamentos;
- consultas;
- pagamentos parciais;
- preservação do histórico;
- exclusão ou atualização quando aplicável.

---

## Documentação relacionada

- [Banco de Dados — Documentação](../docs/04-banco-de-dados/)
- [Regras de Negócio](../docs/01-visao-geral/regras-de-negocio.md)
- [Requisitos Funcionais](../docs/02-engenharia-de-software/requisitos-funcionais.md)
- [Sprint 07 — Banco de Dados](../scrum/sprints/sprint-07.md)

---

[← Voltar ao README principal](../README.md)
