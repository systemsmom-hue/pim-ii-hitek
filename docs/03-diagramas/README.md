# Diagramas do Sistema

Esta seção reúne os principais diagramas desenvolvidos para o **Sistema de Gestão de Comissões — Hitek Informática**.

Os diagramas representam diferentes perspectivas do sistema:

- interação entre usuários e funcionalidades;
- organização dos módulos e funções do sistema.

---

## Diagrama de Casos de Uso

O Diagrama de Casos de Uso apresenta os atores do sistema e as funcionalidades com as quais cada perfil interage.

Os atores definidos são:

- Vendedor;
- Financeiro;
- Administrador.

Entre as principais funcionalidades representadas estão:

- autenticação de usuário;
- registro e consulta de vendas;
- atualização da situação da venda pelo Vendedor;
- alteração do valor da venda pelo Vendedor;
- consulta de comissões;
- confirmação de baixa pelo Financeiro;
- registro de pagamento da comissão;
- gerenciamento de usuários;
- gerenciamento de colaboradores;
- gerenciamento de vendas;
- gerenciamento de comissões;
- gerenciamento de pagamentos;
- geração de relatórios;
- configuração do percentual de comissão.

O Vendedor poderá atualizar a situação da venda e alterar o valor da venda, mas não poderá alterar o valor de custo.

A atualização da situação da venda não substitui a validação realizada pelo Financeiro, que continua responsável pela confirmação da baixa.

O diagrama também utiliza os relacionamentos `<<include>>` e `<<extend>>` quando aplicáveis.

### Visualização

![Diagrama de Casos de Uso](casos-de-uso.png)

[Ver imagem em tamanho original](casos-de-uso.png)

---

## Diagrama Estendido

O Diagrama Estendido apresenta a organização funcional do sistema por meio de módulos e suas respectivas funções.

Os módulos definidos são:

- Vendas;
- Financeiro;
- Comissões;
- Usuários;
- Colaboradores;
- Pagamentos;
- Relatórios;
- Configurações.

O objetivo desse diagrama é representar como as principais funcionalidades do sistema estão organizadas e relacionadas.

### Módulo Vendas

Entre as funções representadas no módulo de Vendas estão:

```text
registrarVenda(): void
consultarVenda(): void
alterarSituacaoVenda(): void
alterarValorVenda(): void
calcularMargem(): void
verificarMargem(): void
alertarMargemBaixa(): void
```

As funções:

```text
alterarSituacaoVenda()
alterarValorVenda()
```

foram incluídas para representar as novas permissões definidas para o perfil Vendedor.

A alteração do valor de custo não está disponível para esse perfil.

### Principais dependências

As principais dependências entre os módulos são:

```text
VENDAS → COLABORADORES
VENDAS → COMISSÕES

FINANCEIRO → VENDAS
FINANCEIRO → COMISSÕES
FINANCEIRO → PAGAMENTOS

COMISSÕES → CONFIGURAÇÕES

PAGAMENTOS → COMISSÕES

RELATÓRIOS → VENDAS
RELATÓRIOS → COMISSÕES
```

### Visualização

![Diagrama Estendido](estendido.png)

[Ver imagem em tamanho original](estendido.png)

---

## Arquivo editável

O arquivo editável dos diagramas desenvolvidos no Astah também poderá ser armazenado nesta pasta.

Arquivo previsto:

```text
sistema-comissoes.asta
```

Esse arquivo permite abrir e editar os diagramas diretamente no Astah UML.

---

## Arquivos da seção

```text
03-diagramas/
├── README.md
├── casos-de-uso.png
├── estendido.png
└── sistema-comissoes.asta
```

---

## Relação entre os diagramas

Cada diagrama apresenta uma visão diferente do sistema:

| Diagrama | Objetivo |
|---|---|
| Casos de Uso | Mostrar quem utiliza o sistema e quais funcionalidades cada ator pode executar |
| Estendido | Mostrar como o sistema está organizado em módulos, funções e dependências |

---

## Documentação relacionada

- [Casos de Uso](../02-engenharia-de-software/casos-de-uso.md)
- [Arquitetura do Sistema](../02-engenharia-de-software/arquitetura.md)
- [Regras de Negócio](../01-visao-geral/regras-de-negocio.md)

---

[← Voltar ao README principal](../../README.md)
