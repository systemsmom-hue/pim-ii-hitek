# Engenharia de Software

Esta seção reúne os principais artefatos de Engenharia de Software desenvolvidos para o **Sistema de Gestão de Comissões — Hitek Informática**.

A documentação apresenta os requisitos do sistema, os casos de uso, a arquitetura lógica e a modelagem funcional utilizada para representar as responsabilidades dos usuários e as funcionalidades do sistema.

---

## Conteúdo

### Requisitos Funcionais

Descrevem as funcionalidades que o sistema deverá oferecer aos usuários.

Entre as funcionalidades atualmente definidas estão:

- gerenciamento de colaboradores;
- gerenciamento de vendas;
- gerenciamento de comissões;
- geração de relatórios;
- gerenciamento de pagamentos;
- autenticação de usuários.

No gerenciamento de vendas, o Vendedor poderá atualizar a situação da venda e alterar o valor da venda, sem permissão para alterar o valor de custo ou confirmar a baixa.

[Ver requisitos funcionais](requisitos-funcionais.md)

---

### Requisitos Não Funcionais

Definem características de qualidade e restrições do sistema, como:

- segurança;
- usabilidade;
- desempenho;
- disponibilidade;
- escalabilidade;
- acessibilidade.

[Ver requisitos não funcionais](requisitos-nao-funcionais.md)

---

### Casos de Uso

Apresentam os atores do sistema e as principais funcionalidades com as quais cada ator interage.

Os três atores definidos são:

- Vendedor;
- Financeiro;
- Administrador.

Entre os casos de uso relacionados ao Vendedor estão:

- Registrar Venda;
- Consultar Vendas;
- Consultar Comissão;
- Atualizar Situação da Venda;
- Alterar Valor da Venda.

A atualização da situação da venda pelo Vendedor não substitui a validação realizada pelo Financeiro.

[Ver casos de uso](casos-de-uso.md)

---

### Arquitetura

Apresenta a organização lógica do sistema, seus módulos funcionais e as principais dependências entre eles.

Os módulos atualmente definidos são:

- Vendas;
- Financeiro;
- Comissões;
- Usuários;
- Colaboradores;
- Pagamentos;
- Relatórios;
- Configurações.

[Ver arquitetura](arquitetura.md)

---

## Modelagem do sistema

A modelagem atual utiliza dois diagramas principais:

- **Diagrama de Casos de Uso:** mostra quem utiliza o sistema e quais funcionalidades cada ator pode executar;
- **Diagrama Estendido:** apresenta os módulos funcionais, suas funções e as dependências entre eles.

Os diagramas estão disponíveis em:

[Ver diagramas](../03-diagramas/)

---

## Diagrama de Casos de Uso

O Diagrama de Casos de Uso representa as interações entre:

```text
Vendedor
Financeiro
Administrador
```

Entre as alterações mais recentes estão os casos de uso:

```text
Atualizar Situação da Venda
Alterar Valor da Venda
```

Essas funcionalidades pertencem ao perfil Vendedor.

O Vendedor não poderá:

```text
alterar o valor de custo
confirmar a baixa da venda
```

---

## Diagrama Estendido

O Diagrama Estendido representa a organização funcional do sistema.

No módulo **VENDAS**, estão previstas as funções:

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

representam o refinamento mais recente das permissões relacionadas ao Vendedor.

---

## Separação de responsabilidades

A modelagem deverá preservar a seguinte divisão:

### Vendedor

Poderá:

- registrar venda;
- consultar suas vendas;
- consultar suas comissões;
- atualizar a situação da venda;
- alterar o valor da venda.

Não poderá:

- alterar o valor de custo;
- confirmar a baixa.

### Financeiro

Continuará responsável por:

- consultar vendas;
- verificar pagamento ou faturamento;
- verificar retirada do equipamento quando aplicável;
- confirmar a baixa;
- registrar pagamentos das comissões.

### Administrador

Será responsável pelas funcionalidades administrativas e de gerenciamento geral previstas no sistema.

---

## Relação entre os artefatos

Os artefatos de Engenharia de Software deverão permanecer coerentes entre si.

```text
Requisitos Funcionais
        ↓
Casos de Uso
        ↓
Diagramas
        ↓
Arquitetura
```

Esses artefatos também deverão respeitar as regras de negócio definidas na Visão Geral do projeto.

---

## Situação atual

| Artefato | Status |
|---|---|
| Requisitos Funcionais | ✅ Atualizado |
| Requisitos Não Funcionais | ✅ Concluído |
| Casos de Uso | ✅ Atualizado |
| Diagrama de Casos de Uso | ✅ Atualizado |
| Diagrama Estendido | ✅ Atualizado |
| Arquitetura | ✅ Atualizada |

---

## Documentação relacionada

- [Regras de Negócio](../01-visao-geral/regras-de-negocio.md)
- [Perfis de Usuário](../01-visao-geral/perfis-de-usuario.md)
- [Diagramas](../03-diagramas/)
- [Banco de Dados](../04-banco-de-dados/)

---

[← Voltar ao README principal](../../README.md)
