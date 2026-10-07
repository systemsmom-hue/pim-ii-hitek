# Regras de Negócio

As regras de negócio definem as condições e comportamentos que devem ser respeitados pelo Sistema de Gestão de Comissões.

---

## RN01 — Percentual de comissão

O percentual padrão de comissão considerado atualmente é de **1%**, podendo ser alterado por usuário autorizado.

---

## RN02 — Um responsável por venda

Cada venda deverá possuir apenas **um colaborador responsável pela comissão**.

---

## RN03 — Confirmação da situação da venda

A comissão dependerá da confirmação da situação da venda antes de ser liberada.

O Vendedor poderá atualizar as informações permitidas da situação da venda, mas a verificação e a confirmação da baixa permanecerão sob responsabilidade do Financeiro.

---

## RN04 — Registro da baixa

A confirmação da baixa deverá registrar:

- a data da baixa;
- o usuário responsável pela operação.

---

## RN05 — Comissão pendente

Enquanto as condições necessárias para liberação da comissão não forem confirmadas, a comissão permanecerá com o status:

**Pendente**

---

## RN06 — Comissão liberada

Após a confirmação necessária e o cálculo da comissão, o sistema deverá alterar seu status para:

**Liberada**

Nesse estado, a comissão estará disponível para receber pagamentos.

---

## RN07 — Comissão paga

A comissão somente deverá assumir o status:

**Paga**

quando sua quitação for confirmada.

Caso exista pagamento parcial, a comissão deverá permanecer como **Liberada** até que o valor total seja quitado.

---

## RN08 — Margem

O sistema deverá calcular e apresentar a margem correspondente à venda registrada.

---

## RN09 — Margem inferior a 30%

Quando a margem calculada for inferior a **30%**, o sistema deverá emitir um alerta ao usuário.

O alerta não deverá impedir o registro da venda.

---

## RN10 — Ajustes de comissão

Erros ou diferenças identificados posteriormente poderão gerar ajustes na comissão, conforme o procedimento utilizado pela empresa.

Esses ajustes poderão ser registrados para controle e acompanhamento.

---

## RN11 — Venda faturada

Em uma venda faturada, o vendedor terá direito à comissão, porém sua liberação dependerá da confirmação da retirada do equipamento pelo cliente.

Caso o equipamento ainda não tenha sido retirado, a comissão deverá permanecer como **Pendente**.

---

## RN12 — Atualização da situação da venda pelo Vendedor

O Vendedor poderá atualizar informações relacionadas à situação da venda.

Entre as informações que poderão ser atualizadas estão:

- situação de pagamento;
- situação de faturamento;
- situação de retirada do equipamento, quando aplicável.

A atualização realizada pelo Vendedor não substitui a validação realizada pelo Financeiro.

---

## RN13 — Alteração do valor da venda pelo Vendedor

O Vendedor poderá alterar o **valor da venda** quando necessário.

O perfil Vendedor **não poderá alterar o valor de custo da venda**.

O valor de custo deverá permanecer protegido contra alterações não autorizadas por esse perfil.

---

## RN14 — Validação financeira

A verificação das informações relacionadas ao pagamento, faturamento e retirada da venda deverá ser realizada pelo Financeiro antes da confirmação da baixa.

Mesmo quando essas informações forem atualizadas pelo Vendedor, a responsabilidade pela confirmação da baixa continuará sendo do Financeiro.

---

## Fluxo dos estados da comissão

O fluxo principal dos estados da comissão é:

```text
Pendente
   ↓
Liberada
   ↓
Paga
```

### Pendente

A comissão ainda não atende às condições necessárias para liberação.

### Liberada

As condições necessárias foram confirmadas e a comissão está disponível para pagamento.

### Paga

A comissão foi totalmente quitada.

---

## Pagamentos parciais

Uma comissão poderá receber mais de um pagamento.

Após cada pagamento, o sistema deverá:

1. registrar o valor pago;
2. atualizar o saldo restante;
3. verificar se a comissão foi totalmente quitada.

Caso ainda exista saldo:

```text
Liberada → novo pagamento
```

Caso a comissão tenha sido quitada:

```text
Liberada → Paga
```

---

## Atualização da situação da venda

As informações de pagamento/faturamento e retirada representam características da situação da venda.

Essas informações deverão ser tratadas separadamente quando necessário.

Exemplo:

```text
Situação de pagamento:
- Paga
- Não paga
- Faturada

Situação de retirada:
- Retirada
- Não retirada
```

Isso permite representar situações como:

```text
Faturada + Não retirada
```

e posteriormente:

```text
Faturada + Retirada
```

---

## Permissões relacionadas à venda

### Vendedor

Poderá:

- registrar venda;
- consultar suas vendas;
- atualizar a situação da venda;
- alterar o valor da venda.

Não poderá:

- alterar o valor de custo;
- confirmar a baixa da venda.

### Financeiro

Poderá:

- consultar vendas;
- verificar pagamento/faturamento;
- verificar retirada do equipamento quando aplicável;
- confirmar a baixa da venda.

---

## Autenticação

O acesso às funcionalidades do sistema dependerá da autenticação do usuário.

Após a autenticação, as funcionalidades disponíveis deverão respeitar o perfil cadastrado:

- Vendedor;
- Financeiro;
- Administrador.

---

[← Voltar para Visão Geral](README.md)
