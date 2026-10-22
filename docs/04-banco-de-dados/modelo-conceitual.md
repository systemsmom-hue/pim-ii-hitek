# 🧩 Modelo Conceitual de Banco de Dados

Este documento apresenta a modelagem conceitual do banco de dados do **Sistema de Gestão de Comissões — Hitek Informática**. A modelagem conceitual abstrai os detalhes técnicos do SGBD e se concentra no mapeamento do negócio, identificando as entidades, atributos e relacionamentos.

---

## 1. Mapeamento de Entidades e Atributos

O sistema é composto pelas seguintes entidades principais:

* **`USUARIO`**: Representa qualquer conta de usuário cadastrada no sistema com credenciais de acesso.
  * **Atributos:** `id_usuario` (identificador), `nome`, `email`, `senha_hash`, `perfil` (*ADMINISTRADOR*, *FINANCEIRO*, *COLABORADOR*), `ativo`, `data_cadastro`.

* **`COLABORADOR`**: Guarda as informações específicas dos vendedores/colaboradores que recebem comissões.
  * **Atributos:** `id_colaborador`, `id_usuario` (vínculo), `cpf`, `cargo`, `percentual_padrao`, `chave_pix`, `ativo`.

* **`VENDA`**: Registra as operações de venda realizadas pela Hitek Informática.
  * **Atributos:** `id_venda`, `id_colaborador` (vendedor), `numero_nf`, `valor_total`, `data_venda`, `observacao`.

* **`COMISSAO`**: Representa a apuração da comissão vinculada a uma venda específica.
  * **Atributos:** `id_comissao`, `id_venda`, `id_colaborador`, `percentual_aplicado`, `valor_bruto`, `valor_liquido`, `status` (*PENDENTE*, *LIBERADA*, *PAGA*, *CANCELADA*), `data_geracao`.

* **`PAGAMENTO`**: Registra a baixa e efetivação financeira do pagamento de uma comissão.
  * **Atributos:** `id_pagamento`, `id_comissao`, `id_usuario_financeiro` (quem efetuou), `data_pagamento`, `valor_pago`, `comprovante_ref`.

* **`DESCONTO`**: Registra deduções aplicadas sobre a comissão (ex.: encargos, taxas de antecipação ou devoluções).
  * **Atributos:** `id_desconto`, `id_comissao`, `tipo_desconto`, `valor_desconto`, `motivo`, `data_registro`.

* **`CONFIGURACAO`**: Parâmetros globais do sistema (ex.: percentual de comissão padrão do estabelecimento).
  * **Atributos:** `id_configuracao`, `chave`, `valor`, `descricao`, `data_atualizacao`.

---

## 2. Relacionamentos e Cardinalidades

Os relacionamentos entre as entidades e suas respectivas cardinalidades estão definidos conforme o fluxo de negócio:

1. **`USUARIO` 1:1 `COLABORADOR`**
   * *Regra:* Um usuário do perfil *COLABORADOR* possui exatamente um perfil funcional de colaborador associado. Um colaborador pertence a um único usuário.
   * *Cardinalidade:* `(1,1)` para `(0,1)`

2. **`COLABORADOR` 1:N `VENDA`**
   * *Regra:* Um colaborador pode realizar várias vendas. Cada venda é associada obrigatoriamente a um colaborador responsável.
   * *Cardinalidade:* `(1,1)` para `(0,N)`

3. **`VENDA` 1:1 `COMISSAO`**
   * *Regra:* Cada venda gera no máximo uma apuração de comissão. Cada comissão refere-se obrigatoriamente a uma única venda.
   * *Cardinalidade:* `(1,1)` para `(0,1)`

4. **`COMISSAO` 1:1 `PAGAMENTO`**
   * *Regra:* Uma comissão liberada pode receber no máximo um registro de pagamento definitivo.
   * *Cardinalidade:* `(1,1)` para `(0,1)`

5. **`COMISSAO` 1:N `DESCONTO`**
   * *Regra:* Uma comissão pode ter zero ou múltiplos descontos aplicados. Cada desconto refere-se a uma única comissão.
   * *Cardinalidade:* `(1,1)` para `(0,N)`

6. **`USUARIO` (Financeiro) 1:N `PAGAMENTO`**
   * *Regra:* Um usuário do setor financeiro pode dar baixa em diversos pagamentos de comissão. Cada pagamento é registrado por um único operador financeiro.
   * *Cardinalidade:* `(1,1)` para `(0,N)`

---

## 3. Diagrama Entidade-Relacionamento (DER Conceitual)

```text
  +------------------+         1:1         +------------------+
  |     USUARIO      |---------------------|   COLABORADOR    |
  +------------------+                     +------------------+
           |                                         |
           | 1:N (Financeiro)                        | 1:N
           v                                         v
  +------------------+                     +------------------+
  |    PAGAMENTO     |                     |      VENDA       |
  +------------------+                     +------------------+
           |                                         |
           | 1:1                                     | 1:1
           +-----------------+     +-----------------+
                             |     |
                             v     v
                          +------------------+
                          |     COMISSAO     |
                          +------------------+
                                   |
                                   | 1:N
                                   v
                          +------------------+
                          |     DESCONTO     |
                          +------------------+
```

---

## 📜 Documentação Relacionada

* [Modelo Lógico](modelo-logico.md)
* [Modelo Físico](modelo-fisico.md)
* [Normalização](normalizacao.md)
