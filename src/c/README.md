# Programação Estruturada em C

Esta pasta será utilizada para armazenar a implementação em linguagem **C** das funcionalidades selecionadas do **Sistema de Gestão de Comissões — Hitek Informática**.

A implementação fará parte da disciplina de Programação Estruturada e deverá permanecer coerente com os requisitos, regras de negócio, diagramas e demais artefatos do projeto.

---

## Status

**Planejado**

A implementação em C ainda não foi iniciada.

Antes da criação do código-fonte, serão selecionadas as funcionalidades mais adequadas para representação utilizando Programação Estruturada.

---

## Objetivo

Representar em linguagem C algumas das principais funcionalidades do sistema, demonstrando a utilização dos conceitos estudados na disciplina.

A implementação deverá aplicar, quando apropriado:

- estruturas condicionais;
- estruturas de repetição;
- funções;
- vetores;
- matrizes;
- manipulação de arquivos.

---

## Processo de desenvolvimento

Para cada funcionalidade selecionada, deverá ser seguido o processo:

```text
Funcionalidade
      ↓
Algoritmo
      ↓
Fluxograma
      ↓
Pseudocódigo
      ↓
Código em C
      ↓
Testes
      ↓
Resultado
```

Todas as etapas deverão representar a mesma lógica.

---

## Seleção das funcionalidades

As funcionalidades que serão implementadas ainda serão definidas.

A escolha deverá considerar:

- importância para o sistema;
- relação com as regras de negócio;
- possibilidade de representação utilizando Programação Estruturada;
- conceitos exigidos pela disciplina;
- facilidade de demonstração e teste.

O **Diagrama Estendido** poderá ser utilizado como referência para essa seleção.

---

## Módulos disponíveis como referência

O sistema atualmente possui os seguintes módulos funcionais:

```text
VENDAS
FINANCEIRO
COMISSÕES
USUÁRIOS
COLABORADORES
PAGAMENTOS
RELATÓRIOS
CONFIGURAÇÕES
```

Esses módulos não significam que todos serão implementados em C.

A equipe deverá selecionar somente as funcionalidades necessárias para atender às exigências do PIM.

---

## Funções previstas no Diagrama Estendido

As seguintes funções já aparecem na modelagem funcional e poderão servir como referência durante a seleção.

### Vendas

```text
registrarVenda()
consultarVenda()
alterarSituacaoVenda()
alterarValorVenda()
calcularMargem()
verificarMargem()
alertarMargemBaixa()
```

As funções:

```text
alterarSituacaoVenda()
alterarValorVenda()
```

representam o refinamento que permite ao perfil Vendedor atualizar a situação da venda e alterar seu valor.

O perfil Vendedor não poderá alterar o valor de custo da venda.

---

### Financeiro

```text
consultarVendas()
verificarPagamentoFaturamento()
confirmarBaixa()
verificarRetiradaEquipamento()
```

Mesmo quando a situação da venda for atualizada pelo Vendedor, a confirmação da baixa continuará sendo responsabilidade do Financeiro.

---

### Comissões

```text
calcularComissao()
consultarComissao()
alterarStatusComissao()
registrarAjusteComissao()
```

---

### Usuários

```text
cadastrarUsuario()
editarUsuario()
bloquearUsuario()
consultarUsuario()
autenticarUsuario()
```

---

### Colaboradores

```text
cadastrarColaborador()
editarColaborador()
consultarColaborador()
```

---

### Pagamentos

```text
registrarPagamentoComissao()
consultarPagamentos()
atualizarSaldoComissao()
verificarQuitacaoComissao()
```

---

### Relatórios

```text
gerarRelatorioVendas()
gerarRelatorioComissoes()
visualizarRelatorio()
```

---

### Configurações

```text
consultarPercentualComissao()
configurarPercentualComissao()
```

---

## Permissões relacionadas às vendas

Caso as funcionalidades de alteração da venda sejam selecionadas para implementação em C, deverão respeitar as mesmas regras definidas na documentação.

### Vendedor

Poderá:

```text
registrarVenda()
consultarVenda()
alterarSituacaoVenda()
alterarValorVenda()
```

Não poderá:

- alterar o valor de custo;
- confirmar a baixa.

### Financeiro

Poderá executar as funções relacionadas à validação financeira:

```text
consultarVendas()
verificarPagamentoFaturamento()
verificarRetiradaEquipamento()
confirmarBaixa()
```

A atualização realizada pelo Vendedor não deverá substituir a validação do Financeiro.

---

## Estruturas condicionais

As estruturas condicionais poderão ser utilizadas para representar decisões presentes nas regras do sistema.

Exemplos:

```c
if
else
switch
```

Possíveis situações de decisão incluem:

```text
Margem inferior a 30%?
Venda paga ou faturada?
Venda faturada?
Equipamento retirado?
Comissão quitada?
Usuário possui permissão para executar a operação?
```

A utilização definitiva dependerá das funcionalidades escolhidas.

---

## Estruturas de repetição

Quando houver necessidade de executar operações repetidamente, poderão ser utilizadas estruturas como:

```c
for
while
do while
```

A repetição deverá possuir uma finalidade real dentro do programa.

---

## Funções

O programa deverá utilizar funções para separar responsabilidades.

Estrutura geral:

```c
tipo nomeFuncao(parametros) {
    // processamento
}
```

A divisão em funções deverá facilitar:

- organização;
- leitura;
- manutenção;
- reutilização da lógica.

---

## Vetores e matrizes

A utilização de vetores e matrizes será definida conforme as funcionalidades escolhidas.

Essas estruturas poderão ser utilizadas para representar conjuntos de informações durante a execução do programa.

Não deverão ser adicionadas apenas para cumprir uma exigência sem relação com a lógica do sistema.

---

## Manipulação de arquivos

Também será avaliada a utilização de arquivos.

Caso seja necessária, poderá ser utilizada para armazenar informações entre diferentes execuções do programa.

Exemplo de declaração em C:

```c
FILE *arquivo;
```

A decisão será tomada durante o desenvolvimento.

---

## Regras que deverão ser preservadas

Caso as funcionalidades correspondentes sejam implementadas em C, deverão ser respeitadas regras como:

- uma venda possuir apenas um colaborador responsável pela comissão;
- a comissão iniciar como Pendente enquanto não atender às condições de liberação;
- margem inferior a 30% gerar alerta sem bloquear a venda;
- venda faturada depender da retirada do equipamento para liberação da comissão;
- pagamentos parciais manterem a comissão como Liberada enquanto houver saldo;
- quitação total alterar a comissão para Paga;
- Vendedor poder atualizar a situação da venda;
- Vendedor poder alterar o valor da venda;
- Vendedor não poder alterar o valor de custo;
- Vendedor não poder confirmar a baixa;
- Financeiro permanecer responsável pela confirmação da baixa.

---

## Testes

As funcionalidades implementadas deverão ser testadas.

Os testes deverão verificar:

- entradas válidas;
- comportamento das decisões;
- resultados dos cálculos;
- funcionamento das repetições;
- resultados esperados;
- situações previstas pelas regras de negócio;
- permissões dos perfis quando aplicável;
- alteração do valor da venda quando implementada;
- proteção do valor de custo contra alteração pelo Vendedor;
- manutenção da responsabilidade do Financeiro pela baixa.

---

## Estrutura futura

A organização dos arquivos será definida após a seleção das funcionalidades.

Uma possível estrutura poderá ser:

```text
src/
└── c/
    ├── README.md
    └── arquivos de implementação
```

Os nomes definitivos dos arquivos somente serão definidos quando a implementação começar.

---

## Critérios de conclusão

A parte de Programação Estruturada somente deverá ser considerada concluída quando:

- as funcionalidades estiverem selecionadas;
- os algoritmos estiverem definidos;
- os fluxogramas estiverem desenvolvidos;
- os pseudocódigos estiverem desenvolvidos;
- o código estiver implementado;
- o código compilar sem erros;
- as funcionalidades estiverem testadas;
- os resultados estiverem documentados;
- houver coerência entre algoritmo, fluxograma, pseudocódigo e código C;
- as regras de negócio relacionadas às funcionalidades escolhidas estiverem respeitadas.

---

## Observação

As funções listadas nesta documentação representam a **modelagem funcional atual** do sistema.

Isso não significa que todas serão obrigatoriamente implementadas em C.

A seleção definitiva deverá considerar as exigências da disciplina e o escopo definido pela equipe.

---

## Documentação relacionada

- [Diagrama Estendido](../../docs/03-diagramas/estendido.png)
- [Requisitos Funcionais](../../docs/02-engenharia-de-software/requisitos-funcionais.md)
- [Regras de Negócio](../../docs/01-visao-geral/regras-de-negocio.md)
- [Arquitetura](../../docs/02-engenharia-de-software/arquitetura.md)
- [Sprint 08 — Programação Estruturada em C](../../scrum/sprints/sprint-08.md)

---

[← Voltar ao README principal](../../README.md)
