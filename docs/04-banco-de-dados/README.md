# Banco de Dados

Esta seção reúne a documentação relacionada ao banco de dados do **Sistema de Gestão de Comissões — Hitek Informática**.

O banco de dados será responsável por armazenar as informações necessárias para o funcionamento do sistema, incluindo dados relacionados a usuários, colaboradores, vendas, comissões e pagamentos.

---

## Objetivo

O objetivo da modelagem de dados é estruturar as informações do sistema de forma organizada, permitindo:

- armazenamento consistente dos dados;
- relacionamento entre as principais entidades;
- redução de redundâncias;
- realização de consultas;
- acompanhamento das vendas e comissões;
- registro dos pagamentos;
- manutenção do histórico necessário ao sistema.

---

## Etapas da modelagem

A documentação do banco de dados será organizada nas seguintes etapas:

### Modelo Conceitual

Representa as principais entidades do sistema e seus relacionamentos, sem depender diretamente de um SGBD específico.

[Ver modelo conceitual](modelo-conceitual.md)

### Modelo Lógico

Apresenta a transformação do modelo conceitual em uma estrutura baseada em tabelas, atributos, chaves primárias e chaves estrangeiras.

[Ver modelo lógico](modelo-logico.md)

### Modelo Físico

Apresenta a estrutura que será utilizada para implementação do banco de dados no SGBD escolhido.

[Ver modelo físico](modelo-fisico.md)

### Normalização

Documenta a análise das tabelas de acordo com as formas normais utilizadas no projeto.

[Ver normalização](normalizacao.md)

---

## Principais informações do sistema

A modelagem deverá contemplar informações relacionadas a:

- usuários;
- perfis de acesso;
- colaboradores;
- vendas;
- comissões;
- pagamentos;
- configurações do sistema;
- histórico necessário ao controle das operações.

---

## Relacionamentos importantes

Entre os relacionamentos previstos no sistema estão:

```text
Colaborador → Venda
Venda → Comissão
Comissão → Pagamento
Usuário → Operações registradas
Configuração → Percentual de comissão
```

Uma venda deverá possuir um colaborador responsável pela comissão.

Uma comissão estará relacionada a uma venda e poderá possuir mais de um pagamento, permitindo o controle de pagamentos parciais.

---

## DER

O Diagrama Entidade-Relacionamento será armazenado nesta seção quando sua versão final estiver concluída.

Arquivo previsto:

```text
der.png
```

---

## Scripts SQL

Os scripts utilizados para implementação do banco de dados serão armazenados separadamente na pasta:

```text
/database/sql/
```

Arquivos previstos:

```text
schema.sql
inserts.sql
consultas.sql
```

---

## Situação atual

| Artefato | Status |
|---|---|
| Modelo Conceitual | 🟡 Em desenvolvimento |
| Modelo Lógico | 🟡 Em desenvolvimento |
| Modelo Físico | ⚪ Pendente |
| Normalização | 🟡 Em desenvolvimento |
| DER | 🟡 Em desenvolvimento |
| Scripts SQL | ⚪ Pendente |

---

## Documentação relacionada

- [Regras de Negócio](../01-visao-geral/regras-de-negocio.md)
- [Requisitos Funcionais](../02-engenharia-de-software/requisitos-funcionais.md)
- [Arquitetura do Sistema](../02-engenharia-de-software/arquitetura.md)

---

[← Voltar ao README principal](../../README.md)
