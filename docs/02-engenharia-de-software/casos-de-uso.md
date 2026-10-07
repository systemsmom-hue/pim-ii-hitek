# Casos de Uso

Os casos de uso representam as principais interações entre os usuários e o **Sistema de Gestão de Comissões — Hitek Informática**.

O sistema possui três atores principais:

- Vendedor;
- Financeiro;
- Administrador.

Além das funcionalidades específicas de cada perfil, todos os usuários deverão realizar autenticação para acessar o sistema.

---

## Atores

### Vendedor

Responsável pelo registro das vendas, atualização das informações permitidas da venda e acompanhamento de suas próprias vendas e comissões.

O Vendedor poderá atualizar a situação da venda e alterar seu valor, mas não poderá alterar o valor de custo.

### Financeiro

Responsável pelas verificações financeiras, confirmação da baixa das vendas e registro dos pagamentos das comissões.

### Administrador

Responsável pelo gerenciamento geral do sistema, incluindo usuários, colaboradores, vendas, comissões, pagamentos, configurações e relatórios.

---

# Casos de Uso do Vendedor

## UC01 — Registrar Venda

**Ator principal:** Vendedor

Permite ao vendedor registrar uma nova venda no sistema.

Durante o registro, o sistema deverá realizar as verificações necessárias relacionadas à margem da venda.

### Relacionamentos

```text
Registrar Venda
      |
      | <<include>>
      ↓
Verificar Margem
```

A verificação da margem é obrigatória durante o registro da venda.

Caso a margem calculada seja inferior a 30%, o sistema deverá apresentar um alerta.

```text
Alertar Margem Inferior a 30%
              |
              | <<extend>>
              ↓
        Verificar Margem
```

O alerta é uma extensão condicional, executada somente quando a margem for inferior a 30%.

---

## UC02 — Consultar Vendas

**Ator principal:** Vendedor

Permite ao vendedor consultar as vendas relacionadas a ele.

---

## UC03 — Consultar Comissão

**Ator principal:** Vendedor

Permite ao vendedor consultar suas comissões e acompanhar seus respectivos estados.

Os principais estados são:

```text
Pendente → Liberada → Paga
```

---

## UC15 — Atualizar Situação da Venda

**Ator principal:** Vendedor

Permite ao Vendedor atualizar informações relacionadas à situação da venda.

Entre as informações que poderão ser atualizadas estão:

- situação de pagamento;
- situação de faturamento;
- situação de retirada do equipamento, quando aplicável.

A atualização realizada pelo Vendedor não substitui a validação do Financeiro.

A confirmação da baixa da venda continuará sob responsabilidade do perfil Financeiro.

---

## UC16 — Alterar Valor da Venda

**Ator principal:** Vendedor

Permite ao Vendedor alterar o valor da venda registrada.

O perfil Vendedor **não poderá alterar o valor de custo**.

Quando a alteração do valor da venda afetar cálculos derivados, o sistema deverá considerar o valor atualizado conforme as regras de margem e comissão.

---

# Casos de Uso do Financeiro

## UC04 — Consultar Vendas

**Ator principal:** Financeiro

Permite ao Financeiro consultar as vendas registradas no sistema para realizar as verificações necessárias.

---

## UC05 — Confirmar Baixa da Venda

**Ator principal:** Financeiro

Permite ao Financeiro confirmar a baixa de uma venda após verificar as condições necessárias.

### Comportamentos incluídos

A confirmação da baixa inclui obrigatoriamente:

- verificar pagamento ou faturamento;
- registrar a data da baixa;
- registrar o usuário responsável pela baixa;
- calcular a comissão;
- alterar o status da comissão para **Liberada**.

Representação:

```text
Confirmar Baixa da Venda
      |
      | <<include>>
      ├── Verificar Pagamento/Faturamento
      ├── Registrar Data e Usuário Responsável pela Baixa
      ├── Calcular Comissão
      └── Alterar Status para Liberada
```

### Venda faturada

Quando a venda for faturada, deverá ser realizada a verificação da retirada do equipamento pelo cliente.

```text
Verificar Retirada do Equipamento
              |
              | <<extend>>
              ↓
     Confirmar Baixa da Venda
```

Essa verificação ocorre somente quando aplicável ao fluxo de venda faturada.

Enquanto a retirada do equipamento não for confirmada, a comissão deverá permanecer como **Pendente**.

---

## UC06 — Registrar Pagamento da Comissão

**Ator principal:** Financeiro

Permite ao Financeiro registrar pagamentos relacionados às comissões liberadas.

Após o registro de um pagamento, o sistema deverá verificar se a comissão foi totalmente quitada.

```text
Registrar Pagamento da Comissão
              |
              | <<include>>
              ↓
     Verificar Quitação da Comissão
```

Caso a quitação seja confirmada:

```text
Alterar Status para Paga
            |
            | <<extend>>
            ↓
Verificar Quitação da Comissão
```

Caso ainda exista saldo pendente, a comissão deverá permanecer como **Liberada**.

---

# Casos de Uso do Administrador

## UC07 — Gerenciar Usuários

**Ator principal:** Administrador

Permite ao Administrador realizar operações relacionadas aos usuários do sistema.

As operações previstas incluem:

- cadastrar usuário;
- editar usuário;
- bloquear usuário;
- consultar usuário.

---

## UC08 — Gerenciar Colaboradores

**Ator principal:** Administrador

Permite ao Administrador realizar o gerenciamento dos colaboradores cadastrados no sistema.

As operações previstas incluem:

- cadastrar colaborador;
- editar colaborador;
- consultar colaborador.

---

## UC09 — Gerenciar Vendas

**Ator principal:** Administrador

Permite ao Administrador consultar e gerenciar informações relacionadas às vendas registradas no sistema.

---

## UC10 — Gerenciar Comissões

**Ator principal:** Administrador

Permite ao Administrador consultar e gerenciar informações relacionadas às comissões.

Também poderão ser registrados ajustes de comissão quando necessário.

---

## UC11 — Gerar Relatórios

**Ator principal:** Administrador

Permite ao Administrador gerar e visualizar relatórios relacionados às informações registradas no sistema.

Os relatórios previstos abrangem:

- vendas;
- comissões.

---

## UC12 — Gerenciar Pagamentos

**Ator principal:** Administrador

Permite ao Administrador consultar e gerenciar informações relacionadas aos pagamentos das comissões.

---

## UC13 — Configurar Percentual de Comissão

**Ator principal:** Administrador

Permite ao Administrador alterar o percentual utilizado no cálculo das comissões.

O percentual padrão considerado atualmente é de **1%**.

---

# Caso de Uso de Autenticação

## UC14 — Autenticar Usuário

**Atores:** Vendedor, Financeiro e Administrador

Permite identificar o usuário antes de conceder acesso às funcionalidades do sistema.

Após a autenticação, o sistema deverá identificar o perfil do usuário e disponibilizar somente as funcionalidades correspondentes às suas permissões.

Os perfis disponíveis são:

- Vendedor;
- Financeiro;
- Administrador.

---

# Resumo dos Casos de Uso

| Código | Caso de Uso | Ator |
|---|---|---|
| UC01 | Registrar Venda | Vendedor |
| UC02 | Consultar Vendas | Vendedor |
| UC03 | Consultar Comissão | Vendedor |
| UC15 | Atualizar Situação da Venda | Vendedor |
| UC16 | Alterar Valor da Venda | Vendedor |
| UC04 | Consultar Vendas | Financeiro |
| UC05 | Confirmar Baixa da Venda | Financeiro |
| UC06 | Registrar Pagamento da Comissão | Financeiro |
| UC07 | Gerenciar Usuários | Administrador |
| UC08 | Gerenciar Colaboradores | Administrador |
| UC09 | Gerenciar Vendas | Administrador |
| UC10 | Gerenciar Comissões | Administrador |
| UC11 | Gerar Relatórios | Administrador |
| UC12 | Gerenciar Pagamentos | Administrador |
| UC13 | Configurar Percentual de Comissão | Administrador |
| UC14 | Autenticar Usuário | Todos |

---

# Relacionamentos Importantes

| Caso de Uso | Relação | Caso relacionado |
|---|---|---|
| Registrar Venda | `<<include>>` | Verificar Margem |
| Alertar Margem Inferior a 30% | `<<extend>>` | Verificar Margem |
| Confirmar Baixa da Venda | `<<include>>` | Verificar Pagamento/Faturamento |
| Confirmar Baixa da Venda | `<<include>>` | Registrar Data e Usuário Responsável pela Baixa |
| Confirmar Baixa da Venda | `<<include>>` | Calcular Comissão |
| Confirmar Baixa da Venda | `<<include>>` | Alterar Status para Liberada |
| Verificar Retirada do Equipamento | `<<extend>>` | Confirmar Baixa da Venda |
| Registrar Pagamento da Comissão | `<<include>>` | Verificar Quitação da Comissão |
| Alterar Status para Paga | `<<extend>>` | Verificar Quitação da Comissão |

---

## Observação sobre o Vendedor

A atualização da situação da venda pelo Vendedor representa o registro ou atualização das informações permitidas pelo seu perfil.

Essa ação não significa que o Vendedor poderá confirmar a baixa.

O fluxo permanece:

```text
Vendedor atualiza a situação da venda
        ↓
Financeiro verifica as informações
        ↓
Financeiro confirma a baixa
        ↓
Comissão pode ser liberada
```

O Vendedor também poderá alterar o valor da venda, mas não o valor de custo.

---

## Observação sobre autenticação

Com exceção do caso de uso **Autenticar Usuário**, as funcionalidades do sistema pressupõem que o usuário já esteja autenticado e autorizado de acordo com seu perfil.

O diagrama visual correspondente está disponível na seção de diagramas do projeto.

[Ver Diagramas](../03-diagramas/)

---

[← Voltar para Engenharia de Software](README.md)
