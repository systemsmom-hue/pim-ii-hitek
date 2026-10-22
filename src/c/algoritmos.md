# 🛠️ Algoritmos e Pseudocódigo do Sistema em C

Este documento descreve os algoritmos e pseudocódigos das principais rotinas do **Sistema de Gestão de Comissões — Hitek Informática**, desenvolvido em Linguagem C com suporte à API `mysql.h`.

---

## 1. Algoritmo 1: Autenticação de Usuário e Controle de Acesso (`autenticarUsuario`)

Este algoritmo valida as credenciais informadas pelo operador, recupera seu perfil e define o nível de permissão (RBAC - *Role-Based Access Control*).

### Pseudocódigo

```text
ALGORITMO autenticarUsuario
ENTRADA: login (texto), senha (texto)
SAÍDA: id_usuario (inteiro), perfil (texto), sucesso (booleano)

INÍCIO
    EXIBIR "--- TELA DE LOGIN ---"
    LER login
    LER senha
    
    hash_senha <- GERAR_MD5(senha)
    
    sql_query <- "SELECT id_usuario, perfil, status FROM usuario WHERE login = 'login' AND senha_hash = 'hash_senha'"
    resultado <- EXECUTAR_QUERY_MYSQL(sql_query)
    
    SE resultado POSSUI_REGISTRO ENTÃO
        SE resultado.status = 'INATIVO' ENTÃO
            EXIBIR "Usuário desativado. Entre em contato com o Administrador."
            RETORNAR FALSO
        SENÃO
            id_usuario <- resultado.id_usuario
            perfil <- resultado.perfil
            EXIBIR "Acesso concedido. Bem-vindo!"
            REGISTRAR_LOG_ACESSO(id_usuario)
            RETORNAR VERDADEIRO
        FIM_SE
    SENÃO
        EXIBIR "Login ou senha incorretos."
        RETORNAR FALSO
    FIM_SE
FIM
```

---

## 2. Algoritmo 2: Cadastro de Venda e Cálculo da Comissão (`cadastrarVenda`)

Registra uma nova nota fiscal, verifica a margem de lucro e calcula automaticamente a comissão associada.

### Pseudocódigo

```text
ALGORITMO cadastrarVenda
ENTRADA: id_colaborador (inteiro), numero_nf (texto), cliente (texto), valor_total (real), margem_lucro (real)
SAÍDA: id_venda (inteiro), sucesso (booleano)

INÍCIO
    SE valor_total <= 0 OU margem_lucro < 0 ENTÃO
        EXIBIR "Erro: Valores de venda e margem devem ser positivos."
        RETORNAR FALSO
    FIM_SE

    // Busca percentual padrão do colaborador
    sql_colab <- "SELECT percentual_comissao FROM colaborador WHERE id_colaborador = id_colaborador AND status = 'ATIVO'"
    colab_data <- EXECUTAR_QUERY_MYSQL(sql_colab)

    SE NAO_ENCONTRADO(colab_data) ENTÃO
        EXIBIR "Erro: Colaborador não localizado ou inativo."
        RETORNAR FALSO
    FIM_SE

    percentual_aplicado <- colab_data.percentual_comissao

    // Regra de Negócio: Se a margem for menor que a mínima exigida, aplica fator de redução
    margem_minima <- OBTER_CONFIGURACAO("MARGEM_MINIMA_COMISSAO") // Ex: 10%
    SE margem_lucro < margem_minima ENTÃO
        percentual_aplicado <- percentual_aplicado * 0.50 // Redução de 50% na comissão
    FIM_SE

    valor_comissao <- valor_total * (percentual_aplicado / 100.0)

    // Início da Transação SQL
    INICIAR_TRANSACAO_SQL()

    sql_venda <- "INSERT INTO venda (id_colaborador, numero_nf, cliente, valor_total, margem_lucro, status_comissao) VALUES (id_colaborador, numero_nf, cliente, valor_total, margem_lucro, 'GERADA')"
    id_venda <- EXECUTAR_INSERT_MYSQL(sql_venda)

    sql_comissao <- "INSERT INTO comissao (id_venda, id_colaborador, valor_base, percentual_aplicado, valor_comissao, status) VALUES (id_venda, id_colaborador, valor_total, percentual_aplicado, valor_comissao, 'PENDENTE')"
    EXECUTAR_INSERT_MYSQL(sql_comissao)

    SE AMBAS_OPERACIONALIZADAS_COM_SUCESSO ENTÃO
        CONFIRMAR_TRANSACAO_SQL() // COMMIT
        EXIBIR "Venda e comissão cadastradas com sucesso!"
        RETORNAR VERDADEIRO
    SENÃO
        DESFAZER_TRANSACAO_SQL() // ROLLBACK
        EXIBIR "Erro ao registrar venda no banco de dados."
        RETORNAR FALSO
    FIM_SE
FIM
```

---

## 3. Algoritmo 3: Liberação de Comissão pelo Financeiro (`liberarComissao`)

Permite ao setor financeiro alterar o status de uma comissão de `PENDENTE` para `LIBERADA`.

### Pseudocódigo

```text
ALGORITMO liberarComissao
ENTRADA: id_comissao (inteiro), id_usuario_financeiro (inteiro)
SAÍDA: sucesso (booleano)

INÍCIO
    sql_valida <- "SELECT status FROM comissao WHERE id_comissao = id_comissao"
    comissao_data <- EXECUTAR_QUERY_MYSQL(sql_valida)

    SE comissao_data.status != 'PENDENTE' ENTÃO
        EXIBIR "Erro: Apenas comissões com status PENDENTE podem ser liberadas."
        RETORNAR FALSO
    FIM_SE

    sql_update <- "UPDATE comissao SET status = 'LIBERADA' WHERE id_comissao = id_comissao"
    sucesso_update <- EXECUTAR_UPDATE_MYSQL(sql_update)

    SE sucesso_update ENTÃO
        EXIBIR "Comissão ID ", id_comissao, " liberada para pagamento com sucesso."
        RETORNAR VERDADEIRO
    SENÃO
        EXIBIR "Falha ao atualizar status da comissão."
        RETORNAR FALSO
    FIM_SE
FIM
```

---

## 4. Algoritmo 4: Baixa de Pagamento de Comissão (`registrarPagamento`)

Efetiva a quitação financeira de uma comissão previamente liberada, atualizando seu status para `PAGA`.

### Pseudocódigo

```text
ALGORITMO registrarPagamento
ENTRADA: id_comissao (inteiro), meio_pagamento (texto), comprovante (texto)
SAÍDA: sucesso (booleano)

INÍCIO
    sql_comissao <- "SELECT valor_comissao, status FROM comissao WHERE id_comissao = id_comissao"
    dados <- EXECUTAR_QUERY_MYSQL(sql_comissao)

    SE dados.status != 'LIBERADA' ENTÃO
        EXIBIR "Erro: A comissão precisa estar LIBERADA para receber pagamento."
        RETORNAR FALSO
    FIM_SE

    INICIAR_TRANSACAO_SQL()

    sql_pagamento <- "INSERT INTO pagamento (id_comissao, valor_pago, meio_pagamento, comprovante_ref) VALUES (id_comissao, dados.valor_comissao, meio_pagamento, comprovante)"
    EXECUTAR_INSERT_MYSQL(sql_pagamento)

    sql_update_comissao <- "UPDATE comissao SET status = 'PAGA' WHERE id_comissao = id_comissao"
    EXECUTAR_UPDATE_MYSQL(sql_update_comissao)

    SE AMBAS_OK ENTÃO
        CONFIRMAR_TRANSACAO_SQL()
        EXIBIR "Pagamento de comissão registrado com sucesso!"
        RETORNAR VERDADEIRO
    SENÃO
        DESFAZER_TRANSACAO_SQL()
        EXIBIR "Falha na transação de pagamento."
        RETORNAR FALSO
    FIM_SE
FIM
```

---

## 📜 Documentação Relacionada

* [Estrutura do Banco de Dados](../../docs/04-banco-de-dados/modelo-fisico.md)
* [Scripts SQL](../../database/sql/README.md)
* [Visão Geral do Projeto](../../docs/01-visao-geral/README.md)
