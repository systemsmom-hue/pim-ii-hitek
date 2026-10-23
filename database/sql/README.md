# Banco de Dados – Scripts SQL

Esta pasta é utilizada para armazenar a modelagem e os scripts SQL do **Sistema de Gestão de Comissões – Hitek Informática**.

## Status
**Concluído**

Os scripts SQL foram desenvolvidos e sincronizados com a modelagem relacional, DER e protótipo em linguagem C.

## Organização da Estrutura

```text
database/
├── BD-hitek-comissoes.sql
├── der-hitek-comissoes.png
├── modelo-relacional.mwb
├── README.md
└── sql/
    ├── schema.sql
    ├── inserts.sql
    ├── consultas.sql
    └── README.md
```

## Descrição dos Arquivos

### 1. `sql/schema.sql` (DDL)
Responsável pela criação da estrutura física da base de dados `db_hitek_comissoes`, incluindo:
- Definição das tabelas (`colaborador`, `venda`, `comissao`, `configuracao`, `pagamento_comissao`, `desconto`);
- Chaves primárias e estrangeiras;
- Restrições de unicidade (`UNIQUE`), valores padrão (`DEFAULT`) e regras de exclusão/atualização (`CASCADE`/`RESTRICT`);
- Inserção inicial do usuário administrador padrão e da configuração do percentual de comissão.

### 2. `sql/inserts.sql` (DML)
Popula o banco de dados com massa de dados de teste para validação dos fluxos do sistema:
- Cadastro de colaboradores e perfis de acesso;
- Registro de vendas (com valores, custos e regras de faturamento/retirada);
- Cálculo e geração automática de comissões;
- Histórico de pagamentos e ajustes/descontos.

### 3. `sql/consultas.sql` (DQL)
Contém consultas preparadas e relatórios gerenciais:
- Extrato detalhado de comissões por vendedor;
- Acompanhamento de vendas e status de retirada do equipamento;
- Filtragem de comissões pendentes para conferência do setor financeiro;
- Auditoria e histórico de pagamentos efetuados.

## Ordem de Execução Recomendada

Para garantir a integridade referencial, os scripts devem ser executados na seguinte ordem:

```bash
1. sql/schema.sql    # Cria o banco e as tabelas
2. sql/inserts.sql   # Popula com dados de teste
3. sql/consultas.sql # Executa os relatórios e validações
```

## Documentação Relacionada
- [Visão Geral e Regras de Negócio](../docs/01-visao-geral/regras-de-negocio.md)
- [Requisitos Funcionais](../docs/02-engenharia-de-software/requisitos-funcionais.md)
- [Sprint 07 – Banco de Dados](../scrum/sprints/sprint-07.md)
