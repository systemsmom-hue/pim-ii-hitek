 # 🗄️ Scripts SQL do Banco de Dados

Esta pasta reúne os scripts SQL necessários para criação, povoamento e consulta do banco de dados relacional **`db_hitek_comissoes`**, utilizado no **Sistema de Gestão de Comissões — Hitek Informática**.

---

## 📁 Arquivos da Pasta

| Arquivo | Categoria | Descrição |
| :--- | :--- | :--- |
| **[`schema.sql`](schema.sql)** | **DDL** (*Data Definition Language*) | Script de criação da base de dados, tabelas, chaves primárias/estrangeiras, restrições e índices de otimização. |
| **[`inserts.sql`](inserts.sql)** | **DML** (*Data Manipulation Language*) | Carga inicial de dados para testes, incluindo usuários, colaboradores, parâmetros do sistema, vendas e comissões. |
| **[`consultas.sql`](consultas.sql)** | **DQL** (*Data Query Language*) | Conjunto de consultas complexas (`JOIN`, `GROUP BY`, somatórios) para relatórios gerenciais e extratos de vendedores. |

---

## 🚀 Ordem de Execução Recomendada

Para garantir a integridade referencial das chaves estrangeiras, execute os scripts exatamente na seguinte ordem:

```bash
1. schema.sql    # Cria a base de dados e a estrutura de tabelas
2. inserts.sql   # Popula o banco com os dados iniciais e simulação
3. consultas.sql # Executa relatórios de teste para validação
```

---

## 🛠️ Como Executar os Scripts

### Opção 1: Via Linha de Comando (Terminal / CMD)

Acesse o terminal no diretório `database/sql/` e execute o comando abaixo (substituindo `root` pelo seu usuário do MySQL, se necessário):

```bash
# Execute os 3 passos em sequência:
mysql -u root -p < schema.sql
mysql -u root -p < inserts.sql
mysql -u root -p < consultas.sql
```

### Opção 2: Via MySQL Workbench ou DBeaver

1. Abra o seu cliente MySQL de preferência.
2. Conecte-se ao servidor local ou remoto.
3. Abra e execute o conteúdo do arquivo **`schema.sql`** (pressione `Ctrl + Shift + Enter` ou clique no raio verde).
4. Abra e execute o arquivo **`inserts.sql`**.
5. Abra o arquivo **`consultas.sql`** para visualizar as consultas e relatórios gerados.

---

## 🔗 Documentação Relacionada

- [Modelo Conceitual](../../docs/04-banco-de-dados/modelo-conceitual.md)
- [Modelo Lógico](../../docs/04-banco-de-dados/modelo-logico.md)
- [Modelo Físico](../../docs/04-banco-de-dados/modelo-fisico.md)
- [Normalização de Banco de Dados](../../docs/04-banco-de-dados/normalizacao.md)

---

[← Voltar à documentação de Banco de Dados](../../docs/04-banco-de-dados/)
