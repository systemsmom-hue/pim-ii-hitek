# Sprint 04 — Refinamento das Regras e do Fluxo

A Sprint 04 representa a etapa de refinamento das regras de negócio e do fluxo operacional do **Sistema de Gestão de Comissões — Hitek Informática**.

Após a modelagem inicial, tornou-se necessário revisar algumas definições e representar com maior precisão como uma venda evolui até a liberação e o pagamento da comissão.

> Esta divisão em Sprints foi organizada posteriormente com base na sequência real de desenvolvimento registrada durante o projeto.

---

## Período

O período desta Sprint não foi formalizado no início do projeto.

---

## Objetivo da Sprint

Refinar o funcionamento do sistema com base nas regras levantadas, estabelecendo de maneira mais clara:

- responsabilidades dos usuários;
- situação da venda;
- confirmação da baixa;
- liberação da comissão;
- venda faturada;
- retirada do equipamento;
- estados da comissão;
- fluxo de pagamento.

---

## Atividades realizadas

| ID | Atividade | Status |
|---|---|---|
| SP04-01 | Revisar as regras de negócio relacionadas às comissões | ✅ Concluído |
| SP04-02 | Revisar os perfis e responsabilidades dos usuários | ✅ Concluído |
| SP04-03 | Refinar o fluxo principal da gestão de comissões | ✅ Concluído |
| SP04-04 | Definir os estados da comissão | ✅ Concluído |
| SP04-05 | Detalhar o processo de confirmação da baixa | ✅ Concluído |
| SP04-06 | Definir o tratamento da venda faturada | ✅ Concluído |
| SP04-07 | Definir a necessidade de retirada do equipamento | ✅ Concluído |
| SP04-08 | Revisar os casos de uso conforme o novo fluxo | ✅ Concluído |
| SP04-09 | Desenvolver e revisar o Diagrama de Atividade | ✅ Concluído |

---

## Perfis consolidados

Nesta etapa, o sistema passou a trabalhar com três perfis principais.

### Vendedor

Responsável principalmente por:

- registrar vendas;
- consultar suas vendas;
- consultar suas comissões;
- acompanhar o status das comissões.

### Financeiro

Responsável principalmente por:

- consultar vendas;
- verificar pagamento ou faturamento;
- confirmar a baixa;
- verificar a retirada do equipamento quando necessário;
- registrar pagamentos de comissão;
- consultar pagamentos.

### Administrador

Responsável principalmente por:

- gerenciar usuários;
- gerenciar colaboradores;
- gerenciar vendas;
- gerenciar comissões;
- gerenciar pagamentos;
- configurar o percentual de comissão;
- gerar relatórios.

O perfil Técnico não foi adotado no sistema.

---

## Estados da comissão

Nesta etapa foi consolidado o fluxo de estados utilizado pelo sistema:

```text
Pendente → Liberada → Paga
```

### Pendente

A comissão ainda não atende às condições necessárias para ser liberada.

### Liberada

As condições necessárias foram confirmadas e a comissão está disponível para pagamento.

### Paga

A comissão foi quitada e o pagamento correspondente foi registrado.

A etapa anteriormente considerada como **Conferida** deixou de fazer parte do fluxo.

---

## Fluxo principal refinado

O fluxo passou a considerar de forma explícita as responsabilidades do Vendedor, do Financeiro e do Sistema.

```text
Vendedor registra a venda
        ↓
Sistema registra a venda
        ↓
Comissão = Pendente
        ↓
Financeiro consulta a venda
        ↓
Financeiro verifica pagamento/faturamento
        ↓
Financeiro confirma a baixa
        ↓
Sistema registra data e usuário responsável
        ↓
Sistema calcula a comissão
        ↓
Comissão = Liberada
        ↓
Pagamento da comissão
        ↓
Comissão = Paga
```

Esse fluxo serviu como base para o desenvolvimento do Diagrama de Atividade.

---

## Confirmação da baixa

A confirmação da baixa passou a representar uma etapa central do processo.

Ao confirmar a baixa, o processo deverá permitir o registro de informações como:

- data da baixa;
- usuário responsável pela operação.

Após as verificações necessárias, o sistema poderá calcular e liberar a comissão.

---

## Venda faturada

Foi definida uma regra específica para vendas faturadas.

Em uma venda faturada:

- o vendedor possui direito à comissão;
- a comissão não deverá ser liberada imediatamente;
- a retirada do equipamento pelo cliente deverá ser confirmada;
- somente após essa condição a baixa poderá prosseguir;
- posteriormente, a comissão poderá ser liberada.

Fluxo:

```text
Venda faturada
      ↓
Cliente retira o equipamento
      ↓
Financeiro confirma a baixa
      ↓
Sistema calcula e libera a comissão
      ↓
Pagamento da comissão
```

Caso a retirada ainda não tenha ocorrido, a comissão deverá permanecer como:

**Pendente**

---

## Margem da venda

O sistema também deverá calcular a margem correspondente à venda.

Quando a margem for inferior a:

**30%**

o sistema deverá apresentar um alerta.

Esse alerta possui caráter informativo e não deverá impedir o registro da venda.

---

## Ajustes

Também foi mantida a necessidade de permitir ajustes relacionados a diferenças ou erros identificados posteriormente nas comissões.

Esses ajustes deverão permanecer registrados para controle do processo.

---

## Diagrama de Atividade

Com o fluxo mais detalhado, foi possível desenvolver o Diagrama de Atividade representando o processo principal da gestão de comissões.

O diagrama passou a distinguir responsabilidades em raias para:

```text
Vendedor
Sistema
Financeiro
Administrador
```

Entre os elementos representados estavam:

- registro da venda;
- criação da comissão pendente;
- consulta da venda;
- verificação de pagamento ou faturamento;
- condição de venda faturada;
- retirada do equipamento;
- confirmação da baixa;
- cálculo da comissão;
- mudança para Liberada;
- pagamento da comissão;
- disponibilização de informações para relatórios.

---

## Evolução em relação à Sprint anterior

Na Sprint anterior, a modelagem havia revelado dúvidas sobre o funcionamento real do processo.

Nesta etapa, essas informações começaram a ser transformadas em regras mais concretas.

A evolução pode ser resumida como:

```text
Modelagem inicial
        ↓
Identificação de dúvidas
        ↓
Revisão das regras
        ↓
Refinamento do fluxo
        ↓
Diagrama de Atividade
```

---

## Resultado da Sprint

Ao final desta etapa, o projeto possuía um fluxo de negócio significativamente mais definido.

Foram consolidados:

- perfis principais do sistema;
- responsabilidades do Financeiro;
- estados da comissão;
- confirmação da baixa;
- tratamento da venda faturada;
- necessidade de retirada do equipamento;
- cálculo e alerta de margem;
- fluxo principal da comissão;
- Diagrama de Atividade.

Essas definições permitiram revisar posteriormente o Diagrama de Casos de Uso e desenvolver a organização funcional do sistema.

---

## Itens que ainda seriam refinados posteriormente

Ao final desta Sprint, ainda seriam trabalhados:

- versão final do Diagrama de Casos de Uso;
- autenticação obrigatória conforme orientação do professor;
- revisão de `<<include>>` e `<<extend>>`;
- tratamento detalhado de pagamentos e quitação;
- Diagrama Estendido;
- arquitetura lógica;
- revisão final da coerência entre os artefatos;
- banco de dados definitivo;
- implementação em C.

---

## Documentação relacionada

- [Regras de Negócio](../../docs/01-visao-geral/regras-de-negocio.md)
- [Perfis de Usuário](../../docs/01-visao-geral/perfis-de-usuario.md)
- [Casos de Uso](../../docs/02-engenharia-de-software/casos-de-uso.md)
- [Diagramas](../../docs/03-diagramas/)

---

[← Voltar para Scrum](../README.md)
