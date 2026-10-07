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

Eles serão criados após a validação do modelo conceitual, DER, modelo lógico, normalização e modelo físico.

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
- situações das vendas;
- situações das comissões;
- pagamentos;
- pagamentos parciais;
- regras relacionadas à liberação das comissões.

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
- clientes;
- vendas;
- comissões;
- pagamentos;
- configurações;
- ajustes;
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

Os nomes definitivos das tabelas e atributos serão definidos somente após a conclusão da modelagem.

---

## Informações relacionadas à venda

A futura estrutura relacionada às vendas deverá permitir representar as informações necessárias às regras de negócio atualmente definidas.

Entre elas estão:

- colaborador responsável;
- valor da venda;
- valor de custo;
- situação de pagamento ou faturamento;
- situação de retirada do equipamento, quando aplicável;
- informações relacionadas à confirmação da baixa;
- usuário responsável pela baixa;
- data da baixa.

As situações de pagamento/faturamento e de retirada deverão poder ser acompanhadas separadamente quando necessário.

Exemplo conceitual:

```text
VENDA

valor da venda
valor de custo

situação de pagamento/faturamento
+
situação de retirada
```

Isso permite representar, por exemplo, uma venda faturada cujo equipamento ainda não tenha sido retirado.

---

## Permissões relacionadas à venda

As permissões de alteração serão controladas pela aplicação conforme o perfil autenticado.

### Vendedor

O sistema permitirá ao Vendedor:

- atualizar a situação da venda;
- alterar o valor da venda.

O Vendedor não poderá:

- alterar o valor de custo;
- confirmar a baixa da venda.

### Financeiro

O Financeiro continuará responsável por:

- verificar pagamento ou faturamento;
- verificar retirada do equipamento quando aplicável;
- confirmar a baixa da venda.

A informação registrada ou atualizada pelo Vendedor não substitui a validação realizada pelo Financeiro.

---

## Relações principais previstas

Entre os relacionamentos que deverão ser analisados estão:

```text
COLABORADOR → VENDA

VENDA → COMISSAO

COMISSAO → PAGAMENTO

COMISSAO → AJUSTE

USUARIO → operações registradas

CONFIGURACAO → percentual de comissão
```

Uma venda deverá possuir um colaborador responsável pela comissão.

Uma comissão deverá estar relacionada à respectiva venda.

Uma comissão poderá possuir mais de um pagamento.

As cardinalidades definitivas serão estabelecidas durante a modelagem.

---

## Comissão

A estrutura do banco deverá permitir representar os estados definidos para a comissão:

```text
Pendente
   ↓
Liberada
   ↓
Paga
```

Também deverá ser possível armazenar as informações necessárias para:

- cálculo da comissão;
- percentual utilizado no cálculo;
- acompanhamento do status;
- registro de ajustes;
- acompanhamento dos pagamentos;
- verificação da quitação.

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

Enquanto houver saldo pendente, a comissão deverá permanecer como:

```text
Liberada
```

Após a quitação total:

```text
Liberada → Paga
```

---

## Venda faturada

Quando uma venda estiver faturada, a estrutura deverá permitir acompanhar também a situação de retirada do equipamento.

O fluxo conceitual é:

```text
Venda faturada
      ↓
Equipamento retirado?
      ↓
Sim → Financeiro pode prosseguir com a confirmação da baixa
Não → Comissão permanece Pendente
```

O Vendedor poderá informar ou atualizar a situação de retirada, mas a validação continuará sendo responsabilidade do Financeiro.

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

## Alteração do valor da venda

O sistema deverá permitir que o valor da venda seja atualizado pelo perfil Vendedor.

O valor de custo deverá permanecer protegido contra alterações realizadas por esse perfil.

Os dados armazenados deverão permitir que os cálculos que dependem do valor da venda utilizem as informações válidas registradas no sistema.

A forma definitiva de implementação será estabelecida após a conclusão da modelagem e das regras de implementação.

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
- atualização das informações da venda;
- pagamentos parciais;
- preservação do histórico do percentual;
- situações das comissões;
- exclusão ou atualização quando aplicável.

---

## Observação

Esta documentação não define ainda:

- nomes definitivos das tabelas;
- nomes definitivos dos atributos;
- tipos de dados;
- cardinalidades finais;
- restrições SQL específicas;
- comandos de atualização definitivos.

Esses elementos deverão ser definidos a partir da modelagem aprovada antes da criação dos scripts.

---

## Documentação relacionada

- [Banco de Dados — Documentação](../docs/04-banco-de-dados/)
- [Regras de Negócio](../docs/01-visao-geral/regras-de-negocio.md)
- [Requisitos Funcionais](../docs/02-engenharia-de-software/requisitos-funcionais.md)
- [Casos de Uso](../docs/02-engenharia-de-software/casos-de-uso.md)
- [Sprint 07 — Banco de Dados](../scrum/sprints/sprint-07.md)

---

[← Voltar ao README principal](../README.md)
