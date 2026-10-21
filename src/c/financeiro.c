#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "financeiro.h"
#include "datas.h"

void consultarVendasFinanceiro(MYSQL *conexao) {
    MYSQL_RES *resultado;
    MYSQL_ROW linha;
    int quantidade = 0;
    const char *consulta =
        "SELECT v.numero_os, v.nome_cliente, "
        "col.nome, v.valor_venda, v.faturada, "
        "v.venda_paga, v.data_retirada, "
        "v.data_baixa, c.status "
        "FROM venda v "
        "INNER JOIN colaborador col "
        "ON col.id_colaborador = v.id_colaborador "
        "LEFT JOIN comissao c "
        "ON c.id_venda = v.id_venda "
        "ORDER BY v.id_venda DESC";
    if (mysql_query(conexao, consulta) != 0) {
        printf("\nErro ao consultar vendas: %s\n",
               mysql_error(conexao));
        return;
    }

    resultado = mysql_store_result(conexao);
    if (resultado == NULL) {
        printf("\nErro ao obter vendas: %s\n",
               mysql_error(conexao));
        return;
    }

    printf("\n========== VENDAS - FINANCEIRO ==========\n");
    while ((linha = mysql_fetch_row(resultado)) != NULL) {
        char dataRetiradaBR[32], dataBaixaBR[32];
        quantidade++;
        printf("\n----------------------------------\n");
        printf("OS: %s\n", linha[0] ? linha[0] : "-");
        printf("Cliente: %s\n", linha[1] ? linha[1] : "-");
        printf("Vendedor: %s\n", linha[2] ? linha[2] : "-");
        printf("Valor: R$ %.2f\n",
               linha[3] ? atof(linha[3]) : 0.0);
        printf("Faturada: %s\n",
               linha[4] && atoi(linha[4]) ? "SIM" : "NAO");
        printf("Paga pelo cliente: %s\n",
               linha[5] && atoi(linha[5]) ? "SIM" : "NAO");
        printf("Retirada: %s\n",
               linha[6] ? dataParaBrasil(linha[6], dataRetiradaBR) : "NAO RETIRADO");
        printf("Baixa financeira: %s\n",
               linha[7] ? dataParaBrasil(linha[7], dataBaixaBR) : "NAO REALIZADA");
        printf("Comissao: %s\n",
               linha[8] ? linha[8] : "SEM COMISSAO");
    }

    if (quantidade == 0) {
        printf("\nNenhuma venda cadastrada.\n");
    }

    printf("\nTotal de vendas: %d\n", quantidade);
    mysql_free_result(resultado);
}

void consultarComissoesPendentes(MYSQL *conexao) {
    MYSQL_RES *resultado;
    MYSQL_ROW linha;
    int quantidade = 0;
    const char *consulta =
        "SELECT v.numero_os, v.nome_cliente, col.nome, "
        "v.valor_venda, c.valor_comissao, "
        "v.faturada, v.venda_paga, v.data_retirada "
        "FROM comissao c "
        "INNER JOIN venda v ON v.id_venda = c.id_venda "
        "INNER JOIN colaborador col "
        "ON col.id_colaborador = v.id_colaborador "
        "WHERE c.status = 'PENDENTE' "
        "AND v.status = 'ATIVA' "
        "ORDER BY v.id_venda DESC";
    if (mysql_query(conexao, consulta) != 0) {
        printf("\nErro ao consultar comissoes: %s\n",
               mysql_error(conexao));
        return;
    }

    resultado = mysql_store_result(conexao);
    if (resultado == NULL) {
        printf("\nErro ao obter comissoes: %s\n",
               mysql_error(conexao));
        return;
    }

    printf("\n========== COMISSOES PENDENTES ==========\n");
    while ((linha = mysql_fetch_row(resultado)) != NULL) {
        char dataRetiradaBR[32];
        quantidade++;
        printf("\n----------------------------------\n");
        printf("OS: %s\n", linha[0]);
        printf("Cliente: %s\n", linha[1]);
        printf("Vendedor: %s\n", linha[2]);
        printf("Valor da venda: R$ %.2f\n", atof(linha[3]));
        printf("Comissao: R$ %.2f\n", atof(linha[4]));
        printf("Faturada: %s\n",
               atoi(linha[5]) ? "SIM" : "NAO");
        printf("Cliente pagou: %s\n",
               atoi(linha[6]) ? "SIM" : "NAO");
        printf("Retirada: %s\n",
               linha[7] ? dataParaBrasil(linha[7], dataRetiradaBR) : "NAO RETIRADO");
    }

    if (quantidade == 0) {
        printf("\nNenhuma comissao pendente encontrada.\n");
    }

    printf("\nTotal de comissoes pendentes: %d\n", quantidade);
    mysql_free_result(resultado);
}

void confirmarBaixaVenda(MYSQL *conexao, Colaborador usuario) {
    char numeroOS[31];
    char osSegura[61];
    char consulta[1200];
    MYSQL_RES *resultado;
    MYSQL_ROW linha;
    int idVenda, faturada, vendaPaga, retirada;
    int confirmar;
    double valorComissao;
    if (strcmp(usuario.perfil, "FINANCEIRO") != 0) {
        printf("\nAcesso negado. Apenas o Financeiro pode confirmar a baixa.\n");
        return;
    }

    printf("\n========== CONFIRMAR BAIXA ==========\n");
    printf("Numero da OS: ");
    if (scanf("%30s", numeroOS) != 1) {
        printf("Numero da OS invalido.\n");
        return;
    }

    mysql_real_escape_string(
        conexao, osSegura, numeroOS, strlen(numeroOS)
    );
    if (mysql_autocommit(conexao, 0) != 0) {
        printf("Erro ao iniciar transacao: %s\n", mysql_error(conexao));
        return;
    }

    snprintf(
        consulta, sizeof(consulta),
        "SELECT v.id_venda, v.faturada, v.venda_paga, "
        "v.data_retirada, c.valor_comissao "
        "FROM venda v "
        "INNER JOIN comissao c ON c.id_venda = v.id_venda "
        "WHERE v.numero_os = '%s' "
        "AND v.status = 'ATIVA' "
        "AND v.data_baixa IS NULL "
        "AND c.status = 'PENDENTE' "
        "FOR UPDATE",
        osSegura
    );
    if (mysql_query(conexao, consulta) != 0) {
        printf("Erro ao consultar venda: %s\n", mysql_error(conexao));
        goto cancelar;
    }

    resultado = mysql_store_result(conexao);
    if (resultado == NULL) {
        printf("Erro ao obter resultado: %s\n", mysql_error(conexao));
        goto cancelar;
    }

    linha = mysql_fetch_row(resultado);
    if (linha == NULL) {
        printf("\nVenda nao encontrada ou baixa nao permitida.\n");
        mysql_free_result(resultado);
        goto cancelar;
    }

    idVenda = atoi(linha[0]);
    faturada = atoi(linha[1]);
    vendaPaga = atoi(linha[2]);
    retirada = (linha[3] != NULL);
    valorComissao = atof(linha[4]);
    mysql_free_result(resultado);
    printf("\nOS: %s\n", numeroOS);
    printf("Venda faturada: %s\n", faturada ? "SIM" : "NAO");
    printf("Cliente pagou: %s\n", vendaPaga ? "SIM" : "NAO");
    printf("Equipamento retirado: %s\n", retirada ? "SIM" : "NAO");
    printf("Valor da comissao: R$ %.2f\n", valorComissao);
    if ((!faturada && !vendaPaga) ||
        (faturada && !retirada)) {
        printf("\nVenda nao atende as condicoes de liberacao.\n");
        goto cancelar;
    }

    printf("\nConfirmar baixa desta venda? (1-Sim / 0-Nao): ");
    if (scanf("%d", &confirmar) != 1 || confirmar != 1) {
        printf("\nBaixa cancelada.\n");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        goto cancelar;
    }

    snprintf(
        consulta, sizeof(consulta),
        "UPDATE venda "
        "SET data_baixa = NOW(), id_financeiro_baixa = %d "
        "WHERE id_venda = %d "
        "AND status = 'ATIVA' AND data_baixa IS NULL",
        usuario.id_colaborador, idVenda
    );
    if (mysql_query(conexao, consulta) != 0 ||
        mysql_affected_rows(conexao) != 1) {
        printf("Erro ao registrar baixa: %s\n", mysql_error(conexao));
        goto cancelar;
    }

    snprintf(
        consulta, sizeof(consulta),
        "UPDATE comissao "
        "SET status = 'LIBERADA', data_conferencia = NOW() "
        "WHERE id_venda = %d AND status = 'PENDENTE'",
        idVenda
    );
    if (mysql_query(conexao, consulta) != 0 ||
        mysql_affected_rows(conexao) != 1) {
        printf("Erro ao liberar comissao: %s\n", mysql_error(conexao));
        goto cancelar;
    }

    if (mysql_commit(conexao) != 0) {
        printf("Erro ao confirmar transacao: %s\n", mysql_error(conexao));
        goto cancelar;
    }

    mysql_autocommit(conexao, 1);
    printf("\nBaixa financeira realizada com sucesso!\n");
    printf("Responsavel: %s\n", usuario.nome);
    printf("Comissao LIBERADA para pagamento.\n");
    return;
cancelar:
    mysql_rollback(conexao);
    mysql_autocommit(conexao, 1);
}

void consultarComissoesLiberadas(MYSQL *conexao) {
    MYSQL_RES *resultado;
    MYSQL_ROW linha;
    int quantidade = 0;
    double total = 0;

    // O saldo considera o que foi pago e os descontos ja utilizados.
    const char *consulta =
        "SELECT v.numero_os, col.nome, c.id_comissao, c.valor_comissao, "
        "COALESCE((SELECT SUM(p.valor_pago) FROM pagamento_comissao p "
        "WHERE p.id_comissao = c.id_comissao AND p.status = 'PAGO'), 0), "
        "COALESCE((SELECT SUM(d.valor_desconto) FROM desconto d "
        "INNER JOIN pagamento_comissao p "
        "ON p.id_pagamento = d.id_pagamento_aplicacao "
        "WHERE p.id_comissao = c.id_comissao AND p.status = 'PAGO' "
        "AND d.aplicado = 1), 0) "
        "FROM comissao c "
        "INNER JOIN venda v ON v.id_venda = c.id_venda "
        "INNER JOIN colaborador col ON col.id_colaborador = v.id_colaborador "
        "WHERE c.status = 'LIBERADA' ORDER BY v.id_venda DESC";

    if (mysql_query(conexao, consulta) != 0) {
        printf("Erro ao consultar comissoes: %s\n", mysql_error(conexao));
        return;
    }
    resultado = mysql_store_result(conexao);
    if (resultado == NULL) {
        printf("Erro ao obter resultados: %s\n", mysql_error(conexao));
        return;
    }

    printf("\n========== COMISSOES LIBERADAS ==========\n");
    while ((linha = mysql_fetch_row(resultado)) != NULL) {
        double valor = atof(linha[3]);
        double pago = atof(linha[4]);
        double descontado = atof(linha[5]);
        double saldo = valor - pago - descontado;
        quantidade++;
        total += saldo;
        printf("\n----------------------------------\n");
        printf("OS: %s\n", linha[0]);
        printf("Vendedor: %s\n", linha[1]);
        printf("ID da comissao: %s\n", linha[2]);
        printf("Comissao bruta: R$ %.2f\n", valor);
        printf("Total pago: R$ %.2f\n", pago);
        printf("Descontos aplicados: R$ %.2f\n", descontado);
        printf("Saldo restante: R$ %.2f\n", saldo);
    }
    if (quantidade == 0) printf("\nNenhuma comissao liberada.\n");
    printf("\nTotal de comissoes liberadas: %d\n", quantidade);
    printf("Saldo total a pagar: R$ %.2f\n", total);
    mysql_free_result(resultado);
}

void registrarPagamentoComissao(MYSQL *conexao, Colaborador usuario) {
    int idComissao, confirmar, forma, opcao, quantidadeDescontos = 0;
    int idColaborador;
    int idsDescontos[200];
    long long totalCentavos, pagoCentavos, saldoCentavos;
    long long descontoAplicadoCentavos, descontoSelecionadoCentavos = 0;
    long long valorBruto, valorLiquido;
    unsigned long long idPagamento;
    char dataCompetencia[11], consulta[1400];
    const char *formaPagamento;
    MYSQL_RES *resultado;
    MYSQL_ROW linha;
    double valorDigitado;
    int transacao = 0;

    if (strcmp(usuario.perfil, "FINANCEIRO") != 0) {
        printf("\nAcesso negado.\n");
        return;
    }

    printf("\n========== PAGAMENTO DE COMISSAO ==========\n");
    printf("ID da comissao: ");
    if (scanf("%d", &idComissao) != 1 || idComissao <= 0) {
        printf("ID invalido.\n");
        return;
    }

    if (mysql_autocommit(conexao, 0) != 0) {
        printf("Erro ao iniciar transacao: %s\n", mysql_error(conexao));
        return;
    }
    transacao = 1;

    // Bloqueia a comissao ate o fim do pagamento para evitar duas quitacoes.
    snprintf(consulta, sizeof(consulta),
        "SELECT ROUND(c.valor_comissao * 100), c.status, "
        "v.id_colaborador, v.data_venda FROM comissao c "
        "INNER JOIN venda v ON v.id_venda = c.id_venda "
        "WHERE c.id_comissao = %d FOR UPDATE", idComissao);
    if (mysql_query(conexao, consulta) != 0) {
        printf("Erro ao consultar comissao: %s\n", mysql_error(conexao));
        goto cancelar;
    }
    resultado = mysql_store_result(conexao);
    if (resultado == NULL) goto cancelar;
    linha = mysql_fetch_row(resultado);
    if (linha == NULL || strcmp(linha[1], "LIBERADA") != 0) {
        printf("\nComissao inexistente ou nao liberada.\n");
        mysql_free_result(resultado);
        goto cancelar;
    }
    totalCentavos = atoll(linha[0]);
    idColaborador = atoi(linha[2]);
    snprintf(dataCompetencia, sizeof(dataCompetencia), "%s", linha[3]);
    mysql_free_result(resultado);

    // Valores financeiros sao calculados em centavos para evitar arredondamentos.
    snprintf(consulta, sizeof(consulta),
        "SELECT COALESCE(ROUND(SUM(valor_pago) * 100), 0) "
        "FROM pagamento_comissao WHERE id_comissao = %d AND status = 'PAGO'",
        idComissao);
    if (mysql_query(conexao, consulta) != 0) goto cancelar;
    resultado = mysql_store_result(conexao);
    if (resultado == NULL) goto cancelar;
    linha = mysql_fetch_row(resultado);
    pagoCentavos = atoll(linha[0]);
    mysql_free_result(resultado);

    snprintf(consulta, sizeof(consulta),
        "SELECT COALESCE(SUM(ROUND(d.valor_desconto * 100)), 0) "
        "FROM desconto d INNER JOIN pagamento_comissao p "
        "ON p.id_pagamento = d.id_pagamento_aplicacao "
        "WHERE p.id_comissao = %d AND p.status = 'PAGO' AND d.aplicado = 1",
        idComissao);
    if (mysql_query(conexao, consulta) != 0) goto cancelar;
    resultado = mysql_store_result(conexao);
    if (resultado == NULL) goto cancelar;
    linha = mysql_fetch_row(resultado);
    descontoAplicadoCentavos = atoll(linha[0]);
    mysql_free_result(resultado);

    saldoCentavos = totalCentavos - pagoCentavos - descontoAplicadoCentavos;
    if (saldoCentavos <= 0) {
        printf("\nEsta comissao nao possui saldo disponivel.\n");
        goto cancelar;
    }

    // So considera descontos do vendedor, de meses anteriores a venda.
    // FOR UPDATE impede que outro pagamento utilize o mesmo desconto.
    snprintf(consulta, sizeof(consulta),
        "SELECT d.id_desconto, ROUND(d.valor_desconto * 100) "
        "FROM desconto d "
        "INNER JOIN comissao origem ON origem.id_comissao = d.id_comissao_origem "
        "INNER JOIN venda v ON v.id_venda = origem.id_venda "
        "WHERE v.id_colaborador = %d AND d.aplicado = 0 "
        "AND d.id_pagamento_aplicacao IS NULL "
        "AND d.data_registro < DATE_FORMAT('%s', '%%Y-%%m-01') "
        "ORDER BY d.data_registro, d.id_desconto FOR UPDATE",
        idColaborador, dataCompetencia);
    if (mysql_query(conexao, consulta) != 0) {
        printf("Erro ao verificar descontos: %s\n", mysql_error(conexao));
        goto cancelar;
    }
    resultado = mysql_store_result(conexao);
    if (resultado == NULL) goto cancelar;
    while ((linha = mysql_fetch_row(resultado)) != NULL) {
        long long valor = atoll(linha[1]);
        if (valor <= 0) continue;
        if (quantidadeDescontos >= 200) {
            printf("Quantidade de descontos excedeu o limite da consulta.\n");
            mysql_free_result(resultado);
            goto cancelar;
        }
        // So seleciona descontos inteiros que caibam no saldo.
        if (descontoSelecionadoCentavos + valor < saldoCentavos) {
            idsDescontos[quantidadeDescontos] = atoi(linha[0]);
            descontoSelecionadoCentavos += valor;
            quantidadeDescontos++;
        }
    }
    mysql_free_result(resultado);

    printf("\nComissao bruta: R$ %.2f\n", totalCentavos / 100.0);
    printf("Total pago: R$ %.2f\n", pagoCentavos / 100.0);
    printf("Descontos ja aplicados: R$ %.2f\n", descontoAplicadoCentavos / 100.0);
    printf("Saldo para quitar: R$ %.2f\n", saldoCentavos / 100.0);
    printf("Descontos elegiveis selecionados: R$ %.2f\n",
           descontoSelecionadoCentavos / 100.0);
    printf("\n1 - Pagamento parcial (sem novos descontos)\n");
    printf("2 - Quitar comissao (aplicar descontos elegiveis)\n");
    printf("0 - Cancelar\nEscolha: ");
    if (scanf("%d", &opcao) != 1 || opcao == 0) goto cancelar;

    if (opcao == 1) {
        printf("Valor do pagamento parcial: R$ ");
        if (scanf("%lf", &valorDigitado) != 1 || !isfinite(valorDigitado) ||
            valorDigitado <= 0 || valorDigitado > saldoCentavos / 100.0) {
            printf("\nValor invalido.\n");
            goto cancelar;
        }
        valorBruto = llround(valorDigitado * 100);
        if (valorBruto <= 0 || valorBruto >= saldoCentavos) {
            printf("\nPara quitar a comissao, escolha a opcao 2.\n");
            goto cancelar;
        }
        descontoSelecionadoCentavos = 0;
        quantidadeDescontos = 0;
    } else if (opcao == 2) {
        valorBruto = saldoCentavos;
    } else {
        printf("\nOpcao invalida.\n");
        goto cancelar;
    }
    valorLiquido = valorBruto - descontoSelecionadoCentavos;
    if (valorLiquido <= 0) {
        printf("\nPagamento liquido invalido.\n");
        goto cancelar;
    }

    printf("\n1 - PIX\n2 - Transferencia\n3 - Dinheiro\n");
    printf("Forma de pagamento: ");
    if (scanf("%d", &forma) != 1) goto cancelar;
    switch (forma) {
        case 1: formaPagamento = "PIX"; break;
        case 2: formaPagamento = "TRANSFERENCIA"; break;
        case 3: formaPagamento = "DINHEIRO"; break;
        default: printf("\nForma de pagamento invalida.\n"); goto cancelar;
    }

    printf("\nValor da comissao considerado: R$ %.2f\n", valorBruto / 100.0);
    printf("Descontos: R$ %.2f\n", descontoSelecionadoCentavos / 100.0);
    printf("Valor liquido a pagar: R$ %.2f\n", valorLiquido / 100.0);
    printf("Confirmar pagamento? (1-Sim / 0-Nao): ");
    if (scanf("%d", &confirmar) != 1 || confirmar != 1) {
        printf("\nPagamento cancelado.\n");
        goto cancelar;
    }

    snprintf(consulta, sizeof(consulta),
        "INSERT INTO pagamento_comissao "
        "(id_comissao, data_pagamento, valor_pago, forma_pagamento, status, id_responsavel) "
        "VALUES (%d, CURDATE(), %.2f, '%s', 'PAGO', %d)",
        idComissao, valorLiquido / 100.0, formaPagamento, usuario.id_colaborador);
    if (mysql_query(conexao, consulta) != 0) {
        printf("Erro ao registrar pagamento: %s\n", mysql_error(conexao));
        goto cancelar;
    }
    idPagamento = (unsigned long long)mysql_insert_id(conexao);

    // Vincula cada desconto ao pagamento antes de confirmar a transacao.
    for (int i = 0; i < quantidadeDescontos; i++) {
        snprintf(consulta, sizeof(consulta),
            "UPDATE desconto SET aplicado = 1, data_aplicacao = CURDATE(), "
            "id_pagamento_aplicacao = %llu "
            "WHERE id_desconto = %d AND aplicado = 0 "
            "AND id_pagamento_aplicacao IS NULL",
            idPagamento, idsDescontos[i]);
        if (mysql_query(conexao, consulta) != 0 || mysql_affected_rows(conexao) != 1) {
            printf("\nErro ao aplicar desconto %d: %s\n",
                   idsDescontos[i], mysql_error(conexao));
            goto cancelar;
        }
    }

    if (opcao == 2) {
        snprintf(consulta, sizeof(consulta),
            "UPDATE comissao SET status = 'PAGA' "
            "WHERE id_comissao = %d AND status = 'LIBERADA'", idComissao);
        if (mysql_query(conexao, consulta) != 0 || mysql_affected_rows(conexao) != 1) {
            printf("\nErro ao quitar comissao.\n");
            goto cancelar;
        }
    }

    if (mysql_commit(conexao) != 0) {
        printf("\nErro ao confirmar pagamento: %s\n", mysql_error(conexao));
        goto cancelar;
    }
    transacao = 0;
    mysql_autocommit(conexao, 1);
    printf("\nPagamento registrado com sucesso!\n");
    printf("Valor pago: R$ %.2f\n", valorLiquido / 100.0);
    printf("Descontos aplicados: R$ %.2f\n", descontoSelecionadoCentavos / 100.0);
    printf("Saldo restante: R$ %.2f\n", (saldoCentavos - valorBruto) / 100.0);
    printf("Status: %s\n", opcao == 2 ? "PAGA" : "LIBERADA");
    return;

cancelar:
    if (transacao) mysql_rollback(conexao);
    mysql_autocommit(conexao, 1);
}

void consultarPagamentosRealizados(MYSQL *conexao) {
    MYSQL_RES *resultado;
    MYSQL_ROW linha;
    int quantidade = 0;
    double totalPago = 0;
    const char *consulta =
        "SELECT p.id_pagamento, v.numero_os, "
        "col.nome AS vendedor, p.valor_pago, "
        "p.forma_pagamento, p.data_pagamento, "
        "resp.nome AS responsavel, "
        "COALESCE((SELECT SUM(d.valor_desconto) FROM desconto d "
        "WHERE d.id_pagamento_aplicacao = p.id_pagamento AND d.aplicado = 1), 0) "
        "FROM pagamento_comissao p "
        "INNER JOIN comissao c "
        "ON c.id_comissao = p.id_comissao "
        "INNER JOIN venda v "
        "ON v.id_venda = c.id_venda "
        "INNER JOIN colaborador col "
        "ON col.id_colaborador = v.id_colaborador "
        "LEFT JOIN colaborador resp "
        "ON resp.id_colaborador = p.id_responsavel "
        "WHERE p.status = 'PAGO' "
        "ORDER BY p.id_pagamento DESC";
    if (mysql_query(conexao, consulta) != 0) {
        printf("\nErro ao consultar pagamentos: %s\n",
               mysql_error(conexao));
        return;
    }

    resultado = mysql_store_result(conexao);
    if (resultado == NULL) {
        printf("\nErro ao obter pagamentos: %s\n",
               mysql_error(conexao));
        return;
    }

    printf("\n========== HISTORICO DE PAGAMENTOS ==========\n");
    while ((linha = mysql_fetch_row(resultado)) != NULL) {
        double valor = linha[3] ? atof(linha[3]) : 0.0;
        quantidade++;
        totalPago += valor;
        printf("\n----------------------------------\n");
        printf("ID do pagamento: %s\n", linha[0]);
        printf("OS: %s\n", linha[1]);
        printf("Vendedor: %s\n", linha[2]);
        printf("Valor pago: R$ %.2f\n", valor);
        printf("Forma de pagamento: %s\n", linha[4]);
        char dataPagamentoBR[32];
        printf("Data: %s\n", dataParaBrasil(linha[5], dataPagamentoBR));
        printf("Responsavel: %s\n",
               linha[6] ? linha[6] : "NAO INFORMADO");
        printf("Descontos vinculados: R$ %.2f\n", atof(linha[7]));
    }

    if (quantidade == 0) {
        printf("\nNenhum pagamento realizado.\n");
    }

    printf("\n==================================\n");
    printf("Quantidade de pagamentos: %d\n", quantidade);
    printf("Total pago: R$ %.2f\n", totalPago);
    mysql_free_result(resultado);
}

void consultarDescontosPendentes(MYSQL *conexao) {
    const char *consulta =
        "SELECT d.id_desconto, "
        "col.nome, "
        "v.numero_os, "
        "d.valor_desconto, "
        "d.motivo, "
        "DATE_FORMAT(d.data_registro, '%d/%m/%Y'), "
        "DATE_FORMAT(DATE_ADD(LAST_DAY(d.data_registro), INTERVAL 1 DAY), '%m/%Y'), "
        "CASE "
        "WHEN DATE_FORMAT(CURDATE(), '%Y%m') > "
        "DATE_FORMAT(d.data_registro, '%Y%m') "
        "THEN 'ELEGIVEL' "
        "ELSE 'AGUARDANDO PROXIMO MES' "
        "END "
        "FROM desconto d "
        "INNER JOIN comissao c "
        "ON d.id_comissao_origem = c.id_comissao "
        "INNER JOIN venda v "
        "ON c.id_venda = v.id_venda "
        "INNER JOIN colaborador col "
        "ON v.id_colaborador = col.id_colaborador "
        "WHERE d.aplicado = 0 "
        "ORDER BY d.data_registro, d.id_desconto";
    MYSQL_RES *resultado;
    MYSQL_ROW linha;
    int total = 0;
    double valorTotal = 0.0;
    printf("\n========== DESCONTOS PENDENTES ==========\n");
    if (mysql_query(conexao, consulta) != 0) {
        printf("\nErro ao consultar descontos: %s\n",
               mysql_error(conexao));
        return;
    }

    resultado = mysql_store_result(conexao);
    if (resultado == NULL) {
        printf("\nErro ao obter resultado: %s\n",
               mysql_error(conexao));
        return;
    }
    while ((linha = mysql_fetch_row(resultado)) != NULL) {
        double valor = atof(linha[3]);
        printf("\n----------------------------------------\n");
        printf("ID do desconto: %s\n", linha[0]);
        printf("Vendedor: %s\n", linha[1]);
        printf("OS de origem: %s\n", linha[2]);
        printf("Valor: R$ %.2f\n", valor);
        printf("Motivo: %s\n", linha[4] ? linha[4] : "-");
        printf("Registrado em: %s\n", linha[5]);
        printf("Mes previsto: %s\n", linha[6]);
        printf("Situacao: %s\n", linha[7]);
        valorTotal += valor;
        total++;
    }

    if (total == 0) {
        printf("\nNenhum desconto pendente.\n");
    }

    printf("\nTotal de descontos: %d\n", total);
    printf("Valor total pendente: R$ %.2f\n", valorTotal);
    mysql_free_result(resultado);
}
