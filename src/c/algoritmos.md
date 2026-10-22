# Algoritmos e Pseudocódigos - Sistema HiTek

Este documento contém a especificação dos principais algoritmos e pseudocódigos que regem a lógica de negócios da aplicação de Gestão de Vendas e Comissões do PIM II.

---

## 1. Algoritmo de Autenticação de Usuários

**Descrição:** Valida as credenciais de acesso do colaborador, sanitizando as entradas contra *SQL Injection* e verificando se o perfil e status estão ativos.

```text
ALGORITMO autenticarUsuario
ENTRADAS: loginInformado (TEXTO), senhaInformada (TEXTO)
SAÍDAS: usuarioAutenticado (ESTRUTURA Colaborador) OU NULO

INÍCIO
    ESCREVER "Informe o Login:"
    LER loginInformado
    ESCREVER "Informe a Senha:"
    LER senhaInformada

    loginEscapado <- SANITIZAR_SQL(loginInformado)
    senhaEscapada <- SANITIZAR_SQL(senhaInformada)

    query <- "SELECT id_colaborador, nome, cargo, perfil, status 
              FROM colaborador 
              WHERE login = 'loginEscapado' AND senha = 'senhaEscapada'"

    resultado <- EXECUTAR_SQL(query)

    SE resultado EXISTE ENTÃO
        SE resultado.status = 'INATIVO' ENTÃO
            ESCREVER "Acesso Negado: Usuário inativo no sistema."
            RETORNAR NULO
        SENÃO
            ESCREVER "Autenticação realizada com sucesso! Bem-vindo, ", resultado.nome
            RETORNAR resultado
        FIM_SE
    SENÃO
        ESCREVER "Login ou senha inválidos."
        RETORNAR NULO
    FIM_SE
FIM
```

---

## 2. Algoritmo de Cadastro de Venda e Cálculo de Comissão

**Descrição:** Cadastra uma nova OS/Venda, calcula a margem de lucro e gera a comissão correspondente. Se a margem for inferior a 30%, exibe um alerta de atenção sem aplicar penalidades no valor da comissão.

```text
ALGORITMO cadastrarVenda
ENTRADAS: idColaborador (INTEIRO), numeroOS (TEXTO), valorVenda (REAL), custo (REAL)
SAÍDAS: Sucesso ou Falha no registro

INÍCIO
    ESCREVER "Informe o Número da OS:"
    LER numeroOS

    ESCREVER "Informe o Valor da Venda (R$):"
    LER valorVenda

    SE valorVenda <= 0 ENTÃO
        ESCREVER "Erro: O valor da venda deve ser maior que zero."
        RETORNAR FALHA
    FIM_SE

    ESCREVER "Informe o Custo do Equipamento/Serviço (R$):"
    LER custo

    SE custo < 0 ENTÃO
        ESCREVER "Erro: O custo não pode ser negativo."
        RETORNAR FALHA
    FIM_SE

    // 1. Cálculo da Margem de Lucro (%)
    margem <- ((valorVenda - custo) / valorVenda) * 100.0

    // 2. Alerta de Margem Baixa (< 30%)
    SE margem < 30.0 ENTÃO
        ESCREVER "ALERTA INFORMATIVO: A margem de lucro (", margem, "%) está abaixo do mínimo recomendado (30%)."
    FIM_SE

    // 3. Obter percentual de comissão ativo na configuração global
    percentualAtivo <- BUSCAR_CONFIGURACAO_ATUAL() // Padrão: 1.00%

    // 4. Cálculo do valor bruto da comissão
    valorComissao <- valorVenda * (percentualAtivo / 100.0)

    // 5. Inserção na Tabela de Vendas
    idVendaGerado <- EXECUTAR_SQL(
        "INSERT INTO venda (id_colaborador, numero_os, valor_venda, custo, margem, status) 
         VALUES (idColaborador, 'numeroOS', valorVenda, custo, margem, 'ATIVA')"
    )

    // 6. Registro da Comissão associada (Status PENDENTE)
    EXECUTAR_SQL(
        "INSERT INTO comissao (id_venda, percentual_aplicado, valor_comissao, status, data_calculo) 
         VALUES (idVendaGerado, percentualAtivo, valorComissao, 'PENDENTE', AGORA())"
    )

    ESCREVER "Venda cadastrada e comissão registrada com sucesso!"
    ESCREVER "Valor da Comissão Gerada: R$ ", valorComissao
    RETORNAR SUCESSO
FIM
```

---

## 3. Algoritmo de Validação e Liberação de Comissão

**Descrição:** Verifica os critérios operacionais necessários para mudar o status de uma comissão de `PENDENTE` para `LIBERADA`.

```text
ALGORITMO liberarComissao
ENTRADAS: idVenda (INTEIRO)
SAÍDAS: Atualização do status da comissão

INÍCIO
    venda <- EXECUTAR_SQL("SELECT faturada, equipamento_retirado FROM venda WHERE id_venda = idVenda")

    SE venda NÃO ENCONTRADA ENTÃO
        ESCREVER "Venda não localizada."
        RETORNAR FALHA
    FIM_SE

    // Regra de Liberação: Venda faturada (1) E equipamento retirado (1)
    SE venda.faturada = 1 E venda.equipamento_retirado = 1 ENTÃO
        EXECUTAR_SQL(
            "UPDATE comissao 
             SET status = 'LIBERADA', data_conferencia = AGORA() 
             WHERE id_venda = idVenda AND status = 'PENDENTE'"
        )
        ESCREVER "Comissão liberada com sucesso para pagamento!"
        RETORNAR SUCESSO
    SENÃO
        ESCREVER "Condições não atingidas. A comissão permanece PENDENTE."
        ESCREVER "Faturada: ", venda.faturada, " | Retirado: ", venda.equipamento_retirado
        RETORNAR FALHA
    FIM_SE
FIM
```

---

## 4. Algoritmo de Alteração do Percentual de Comissão (Administrador)

**Descrição:** Permite ao administrador atualizar a alíquota padrão global de comissão para novas vendas.

```text
ALGORITMO alterarPercentualComissao
ENTRADAS: idAdministrador (INTEIRO), novoPercentual (REAL)
SAÍDAS: Sucesso ou Falha

INÍCIO
    ESCREVER "Informe o novo percentual de comissão (%):"
    LER novoPercentual

    SE novoPercentual <= 0 OU novoPercentual > 100 ENTÃO
        ESCREVER "Erro: O percentual deve ser maior que 0 e menor ou igual a 100."
        RETORNAR FALHA
    FIM_SE

    ESCREVER "Confirma alterar o percentual para ", novoPercentual, "%? (1-Sim / 0-Não)"
    LER confirmacao

    SE confirmacao = 1 ENTÃO
        EXECUTAR_SQL(
            "INSERT INTO configuracao (percentual_atual, data_alteracao, id_administrador) 
             VALUES (novoPercentual, AGORA(), idAdministrador)"
        )
        ESCREVER "Percentual global atualizado com sucesso para ", novoPercentual, "%!"
        RETORNAR SUCESSO
    SENÃO
        ESCREVER "Alteração cancelada."
        RETORNAR FALHA
    FIM_SE
FIM
```

---

## 5. Algoritmo de Ajuste/Desconto em Comissão

**Descrição:** Registra um abatimento ou desconto em uma comissão sem alterar seu valor original histórico.

```text
ALGORITMO registrarAjusteComissao
ENTRADAS: idComissao (INTEIRO), valorDesconto (REAL), motivo (TEXTO)
SAÍDAS: Registro na tabela desconto

INÍCIO
    comissao <- EXECUTAR_SQL("SELECT valor_comissao, status FROM comissao WHERE id_comissao = idComissao")

    SE comissao.status = 'CANCELADA' ENTÃO
        ESCREVER "Não é permitido registrar ajuste para comissão cancelada."
        RETORNAR FALHA
    FIM_SE

    SE valorDesconto <= 0 OU valorDesconto > comissao.valor_comissao ENTÃO
        ESCREVER "Erro: Valor do desconto inválido ou superior ao valor da comissão."
        RETORNAR FALHA
    FIM_SE

    motivoEscapado <- SANITIZAR_SQL(motivo)

    EXECUTAR_SQL(
        "INSERT INTO desconto (id_comissao_origem, valor_desconto, motivo, data_registro, aplicado) 
         VALUES (idComissao, valorDesconto, 'motivoEscapado', AGORA(), 0)"
    )

    ESCREVER "Ajuste de comissão registrado como PENDENTE DE APLICAÇÃO."
    RETORNAR SUCESSO
FIM
```
