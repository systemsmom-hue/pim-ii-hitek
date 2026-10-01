# Regras de Negócio

As regras de negócio definem as condições e comportamentos que devem ser respeitados pelo Sistema de Gestão de Comissões.

---

## RN01 — Percentual de comissão

O percentual padrão de comissão considerado atualmente é de **1%**, podendo ser alterado por usuário autorizado.

---

## RN02 — Um responsável por venda

Cada venda deverá possuir apenas **um colaborador responsável pela comissão**.

---

## RN03 — Confirmação da venda

A comissão dependerá da confirmação da situação da venda antes de ser liberada.

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

## Autenticação

O acesso às funcionalidades do sistema dependerá da autenticação do usuário.

Após a autenticação, as funcionalidades disponíveis deverão respeitar o perfil cadastrado:

- Vendedor;
- Financeiro;
- Administrador.
