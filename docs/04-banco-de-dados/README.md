# Banco de Dados

Esta seção reúne a documentação relacionada ao banco de dados do **Sistema de Gestão de Comissões — Hitek Informática**.

O banco de dados será responsável por armazenar as informações necessárias para o funcionamento do sistema, incluindo dados relacionados a usuários, colaboradores, vendas, comissões, pagamentos, configurações e ajustes.

---

## Objetivo

O objetivo da modelagem de dados é estruturar as informações do sistema de forma organizada, permitindo:

- armazenamento consistente dos dados;
- relacionamento entre as principais entidades;
- redução de redundâncias;
- realização de consultas;
- acompanhamento das vendas e comissões;
- registro dos pagamentos;
- controle das situações relacionadas às vendas;
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
- valor da venda;
- valor de custo;
- situação de pagamento ou faturamento;
- situação de retirada do equipamento;
- confirmação da baixa;
- usuário responsável pela baixa;
- data da baixa;
- comissões;
- status das comissões;
- pagamentos;
- saldo das comissões;
- configurações do sistema;
- percentual de comissão;
- ajustes de comissão;
- histórico necessário ao controle das operações.

---

## Informações relacionadas à venda

A estrutura de dados utilizada para representar uma venda deverá permitir armazenar as informações necessárias ao fluxo definido pelo sistema.

Entre elas estão:

- colaborador responsável;
- valor da venda;
- valor de custo;
- situação de pagamento ou faturamento;
- situação de retirada do equipamento, quando aplicável;
- informações relacionadas à baixa.

As informações de pagamento/faturamento e retirada deverão permitir representar diferentes condições da venda durante seu processamento.

Por exemplo:

```text
Situação de pagamento/faturamento
        +
Situação de retirada
```

Essa separação permite acompanhar situações como uma venda faturada cujo equipamento ainda não tenha sido retirado.

---

## Permissões e integridade dos dados

O banco de dados deverá armazenar os dados necessários ao funcionamento das regras de acesso definidas pelo sistema.

As permissões serão controladas pela aplicação de acordo com o perfil do usuário.

### Vendedor

O sistema permitirá ao Vendedor:

- atualizar a situação da venda;
- alterar o valor da venda.

O Vendedor não poderá:

- alterar o valor de custo;
- confirmar a baixa da venda.

### Financeiro

O Financeiro continuará responsável por:

- verificar as informações de pagamento ou faturamento;
- verificar a retirada do equipamento quando aplicável;
- confirmar a baixa da venda.

A atualização de informações pelo Vendedor não substitui a validação realizada pelo Financeiro.

---

## Informações relacionadas à comissão

Cada comissão estará relacionada à respectiva venda.

A modelagem deverá permitir representar os estados:

```text
Pendente
   ↓
Liberada
   ↓
Paga
```

Também deverá ser possível armazenar os dados necessários para:

- cálculo da comissão;
- acompanhamento do status;
- registro de ajustes;
- acompanhamento dos pagamentos;
- verificação da quitação.

---

## Pagamentos parciais

Uma comissão poderá possuir mais de um pagamento.

A modelagem deverá permitir representar:

```text
Comissão
   ↓
Pagamento 1
Pagamento 2
Pagamento 3
...
```

Enquanto existir saldo pendente, a comissão deverá permanecer como **Liberada**.

Quando sua quitação for confirmada, o status poderá ser alterado para **Paga**.

---

## Relacionamentos importantes

Entre os relacionamentos previstos no sistema estão:

```text
Colaborador → Venda
Venda → Comissão
Comissão → Pagamento
Usuário → Operações registradas
Configuração → Percentual de comissão
Comissão → Ajuste
```

Uma venda deverá possuir um colaborador responsável pela comissão.

Uma comissão estará relacionada a uma venda e poderá possuir mais de um pagamento, permitindo o controle de pagamentos parciais.

As operações que exigem identificação do usuário responsável, como a confirmação da baixa, deverão permitir o registro dessa informação.

---

## Impacto do refinamento do Vendedor

O refinamento das permissões do Vendedor afeta a futura modelagem de dados porque o sistema deverá permitir armazenar e atualizar:

```text
valor da venda
situação de pagamento/faturamento
situação de retirada
```

Ao mesmo tempo, o sistema deverá respeitar a restrição de que o perfil Vendedor não poderá alterar:

```text
valor de custo
```

Essa restrição deverá ser aplicada pela lógica de acesso da aplicação.

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

## Observação

Os nomes definitivos das tabelas, atributos, tipos de dados, chaves e restrições serão estabelecidos durante a conclusão dos modelos conceitual, lógico e físico.

Esta seção define apenas as necessidades de informação que deverão ser contempladas pela modelagem.

---

## Documentação relacionada

- [Regras de Negócio](../01-visao-geral/regras-de-negocio.md)
- [Requisitos Funcionais](../02-engenharia-de-software/requisitos-funcionais.md)
- [Arquitetura do Sistema](../02-engenharia-de-software/arquitetura.md)
- [Casos de Uso](../02-engenharia-de-software/casos-de-uso.md)

---

[← Voltar ao README principal](../../README.md)
