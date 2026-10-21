#include <stdio.h>
#include <string.h>
#include "vendas.h"
#include "datas.h"
#include "calculos.h"
#include "banco.h"
#include <stdlib.h>
#define MAX_VENDAS 100

static Venda vendas[MAX_VENDAS];
static Comissao comissoes[MAX_VENDAS];
static int quantidadeVendas = 0;

void cadastrarVenda(MYSQL *conexao, Colaborador usuario) {
    double percentualAtual = buscarPercentualAtual(conexao);
    Venda venda = {0};
    Comissao comissao = {0};
    int opcaoPagamento;
    int equipamentoRetirado;
    char entradaData[32];

    venda.id_colaborador = usuario.id_colaborador;

    if (quantidadeVendas >= MAX_VENDAS) {
        printf("\nLimite de vendas atingido.\n");
        return;
    }

    printf("\n--- CADASTRO DE VENDA ---\n");

    printf("Numero da OS: ");
    scanf("%30s", venda.numero_os);

    do {
        printf("Data da venda (DD/MM/AAAA): ");
        if (scanf("%31s", entradaData) != 1) return;
        if (dataParaMysql(entradaData, venda.data_venda)) break;
        printf("Data invalida. Use DD/MM/AAAA.\n");
    } while (1);

    printf("Nome do cliente: ");
    scanf(" %100[^\n]", venda.nome_cliente);

    do {
        printf("Valor da venda: R$ ");

        if (scanf("%lf", &venda.valor_venda) != 1) {
            printf("Digite um valor numerico valido.\n");

            int c;
            while ((c = getchar()) != '\n' && c != EOF);

            venda.valor_venda = 0;
            continue;
        }

        if (venda.valor_venda <= 0) {
            printf("O valor da venda deve ser maior que zero.\n");
        }

    } while (venda.valor_venda <= 0);

    do {
        printf("Custo: R$ ");

        if (scanf("%lf", &venda.custo) != 1) {
            printf("Digite um custo numerico valido.\n");

            int c;
            while ((c = getchar()) != '\n' && c != EOF);

            venda.custo = -1;
            continue;
        }

        if (venda.custo < 0) {
            printf("O custo nao pode ser negativo.\n");
        }

    } while (venda.custo < 0);

    printf("\n--- FORMA DE PAGAMENTO ---");
    printf("\n1 - PIX\n");
    printf("2 - Cartao\n");
    printf("3 - Boleto\n");
    printf("4 - Dinheiro\n");
    printf("Selecione:");
    scanf("%d", &opcaoPagamento);

    switch (opcaoPagamento) {
        case 1:
            strcpy(venda.forma_pagamento, "PIX");
            break;
        case 2:
            strcpy(venda.forma_pagamento, "CARTAO");
             break;
        case 3:
            strcpy(venda.forma_pagamento, "BOLETO");
            break;
        case 4:
            strcpy(venda.forma_pagamento, "DINHEIRO");
            break;
        default:
        printf("\nForma de pagamento invalida!\n");
        printf("Cadastro cancelado, nenhuma venda foi salva.\n");
        return;
    }

    printf("Venda faturada? (1-Sim / 0-Nao): ");
    scanf("%d", &venda.faturada);

    printf("Venda paga pelo cliente? (1-Sim / 0-Nao): ");
    scanf("%d", &venda.venda_paga);

    printf("Equipamento retirado? (1-Sim / 0-Nao): ");
    scanf("%d", &equipamentoRetirado);

    if (equipamentoRetirado == 1) {
        do {
            printf("Data da retirada (DD/MM/AAAA): ");
            if (scanf("%31s", entradaData) != 1) return;
            if (dataParaMysql(entradaData, venda.data_retirada)) break;
            printf("Data invalida. Use DD/MM/AAAA.\n");
        } while (1);

    } else {
        strcpy(venda.data_retirada, "");
    }

    venda.margem = calcularMargem(
        venda.valor_venda,
        venda.custo
    );

    comissao.percentual_aplicado = percentualAtual;
    comissao.valor_comissao = calcularComissao(
        venda.valor_venda,
        percentualAtual
    );

    strcpy(comissao.status, "PENDENTE");

    strcpy(venda.status, "ATIVA");

    printf("\n--- RESULTADO DO CADASTRO ---\n");
    printf("Vendedor: %s\n", usuario.nome);
    printf("OS: %s\n", venda.numero_os);
    printf("Cliente: %s\n", venda.nome_cliente);
    printf("Margem: %.2f%%\n", venda.margem);

    if (venda.margem < 30) {
        printf("ATENCAO: margem abaixo de 30%%!\n");
    }

    printf("Comissao: R$ %.2f\n", comissao.valor_comissao);
    printf("Status: %s\n", comissao.status);

    if (mysql_autocommit(conexao, 0) != 0) {
        printf("Erro ao iniciar transacao %s\n", mysql_error(conexao));
        return;
    }

    int idVendaSalva = salvarVenda(conexao, venda);

    if (idVendaSalva == 0) {
        mysql_rollback(conexao);
        mysql_autocommit(conexao, 1);

        printf("Operacao cancelada. Nenhum dado foi salvo.\n");
        return;
    }

    comissao.id_venda = idVendaSalva;

    int idComissaoSalva = salvarComissao(conexao, comissao);

    if (idComissaoSalva == 0) {
        mysql_rollback(conexao);
        mysql_autocommit(conexao, 1);

        printf("Operacao cancelada. A venda foi desfeita.\n");
        return;
    }

    if (mysql_commit(conexao) != 0) {
        printf(
            "Erro ao confirmar transacao: %s\n",
            mysql_error(conexao)
        );

        mysql_rollback(conexao);
        mysql_autocommit(conexao, 1);
        return;
    }

    mysql_autocommit(conexao, 1);

    venda.id_venda = idVendaSalva;
    comissao.id_comissao = idComissaoSalva;
    comissao.id_venda = idVendaSalva;

    vendas[quantidadeVendas] = venda;
    comissoes[quantidadeVendas] = comissao;
    quantidadeVendas++;

    printf("\nVenda e comissao salvas com sucesso no MySQL.\n");
 
}

void listarVendas(void) {
    if (quantidadeVendas == 0) {
        printf("\nNenhuma venda cadastrada.\n");
        return;
    }

    printf("\n============= VENDAS CADASTRADAS =============\n");

    for (int i = 0; i < quantidadeVendas; i++) {
        printf("\nVenda %d\n", i + 1);
        printf("OS: %s\n", vendas[i].numero_os);
        printf("Cliente: %s\n", vendas[i].nome_cliente);
        printf("Valor: R$ %.2f\n", vendas[i].valor_venda);
        printf("Margem: %.2f%%\n", comissoes[i].valor_comissao);
        printf("Status da comissao: %s\n", comissoes[i].status);
    }
}

void consultarMinhasVendas(MYSQL *conexao, Colaborador usuario) {
    char consulta[1000];
    MYSQL_RES *resultado;
    MYSQL_ROW linha;
    int quantidade = 0;

    snprintf(
        consulta,
        sizeof(consulta),
        "SELECT v.numero_os, v.nome_cliente, "
        "DATE_FORMAT(v.data_venda, '%d/%m/%Y'), v.valor_venda, v.margem, "
        "c.valor_comissao, c.status "
        "FROM venda v "
        "LEFT JOIN comissao c ON c.id_venda = v.id_venda "
        "WHERE v.id_colaborador = %d "
        "ORDER BY v.id_venda DESC",
        usuario.id_colaborador
    );

    if (mysql_query(conexao, consulta) != 0) {
        printf("\nErro ao consultar vendas: %s\n",
               mysql_error(conexao));
        return;
    }

    resultado = mysql_store_result(conexao);

    if (resultado == NULL) {
        printf("\nErro ao obter resultados: %s\n",
               mysql_error(conexao));
        return;
    }

    printf("\n========== MINHAS VENDAS ==========\n");
    printf("Vendedor: %s\n", usuario.nome);

    while ((linha = mysql_fetch_row(resultado)) != NULL) {
        quantidade++;

        printf("\n----------------------------------\n");
        printf("OS: %s\n", linha[0] ? linha[0] : "-");
        printf("Cliente: %s\n", linha[1] ? linha[1] : "-");
        printf("Data: %s\n", linha[2] ? linha[2] : "-");
        printf("Valor: R$ %.2f\n",
               linha[3] ? atof(linha[3]) : 0.0);
        printf("Margem: %.2f%%\n",
               linha[4] ? atof(linha[4]) : 0.0);
        printf("Comissao: R$ %.2f\n",
               linha[5] ? atof(linha[5]) : 0.0);
        printf("Status da comissao: %s\n",
               linha[6] ? linha[6] : "SEM COMISSAO");
    }

    if (quantidade == 0) {
        printf("\nNenhuma venda encontrada para este vendedor.\n");
    }

    printf("\nTotal de vendas: %d\n", quantidade);

    mysql_free_result(resultado);
}

void atualizarVenda(MYSQL *conexao, Colaborador usuario) {
    char numeroOS[31];
    char osSegura[61];
    char consulta[1000];

    MYSQL_RES *resultado;
    MYSQL_ROW linha;

    int idVenda;
    double custo;
    double percentual;
    double novoValor;
    double novaMargem;
    double novaComissao;

    printf("\n========== ATUALIZAR VENDA ==========\n");
    printf("Numero da OS: ");
    scanf("%30s", numeroOS);

    mysql_real_escape_string(
        conexao,
        osSegura,
        numeroOS,
        strlen(numeroOS)
    );

    if (mysql_autocommit(conexao, 0) != 0) {
        printf("Erro ao iniciar transacao: %s\n",
               mysql_error(conexao));
        return;
    }

    snprintf(
        consulta,
        sizeof(consulta),
        "SELECT v.id_venda, v.custo, c.percentual_aplicado "
        "FROM venda v "
        "INNER JOIN comissao c ON c.id_venda = v.id_venda "
        "WHERE v.numero_os = '%s' "
        "AND v.id_colaborador = %d "
        "AND v.status = 'ATIVA' "
        "AND v.data_baixa IS NULL "
        "AND c.status = 'PENDENTE' "
        "FOR UPDATE",
        osSegura,
        usuario.id_colaborador
    );

    if (mysql_query(conexao, consulta) != 0) {
        printf("Erro ao consultar venda: %s\n",
               mysql_error(conexao));
        goto cancelar;
    }

    resultado = mysql_store_result(conexao);

    if (resultado == NULL) {
        printf("Erro ao obter venda: %s\n",
               mysql_error(conexao));
        goto cancelar;
    }

    linha = mysql_fetch_row(resultado);

    if (linha == NULL) {
        printf("\nVenda nao encontrada ou atualizacao nao permitida.\n");
        mysql_free_result(resultado);
        goto cancelar;
    }

    idVenda = atoi(linha[0]);
    custo = atof(linha[1]);
    percentual = atof(linha[2]);

    mysql_free_result(resultado);

    printf("\nCusto registrado: R$ %.2f\n", custo);
    printf("Percentual da comissao: %.2f%%\n", percentual);
    printf("Novo valor da venda: R$ ");

    if (scanf("%lf", &novoValor) != 1 ||
        novoValor <= 0) {

        printf("\nValor invalido.\n");

        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        goto cancelar;
    }

    novaMargem = calcularMargem(novoValor, custo);
    novaComissao = calcularComissao(novoValor, percentual);

    snprintf(
        consulta,
        sizeof(consulta),
        "UPDATE venda "
        "SET valor_venda = %.2f, margem = %.2f "
        "WHERE id_venda = %d",
        novoValor,
        novaMargem,
        idVenda
    );

    if (mysql_query(conexao, consulta) != 0) {
        printf("Erro ao atualizar venda: %s\n",
               mysql_error(conexao));
        goto cancelar;
    }

    snprintf(
        consulta,
        sizeof(consulta),
        "UPDATE comissao "
        "SET valor_comissao = %.2f, data_calculo = NOW() "
        "WHERE id_venda = %d AND status = 'PENDENTE'",
        novaComissao,
        idVenda
    );

    if (mysql_query(conexao, consulta) != 0) {
        printf("Erro ao atualizar comissao: %s\n",
               mysql_error(conexao));
        goto cancelar;
    }

    if (mysql_commit(conexao) != 0) {
        printf("Erro ao confirmar alteracoes: %s\n",
               mysql_error(conexao));
        goto cancelar;
    }

    mysql_autocommit(conexao, 1);

    printf("\n========== VENDA ATUALIZADA ==========\n");
    printf("OS: %s\n", numeroOS);
    printf("Novo valor: R$ %.2f\n", novoValor);
    printf("Custo mantido: R$ %.2f\n", custo);
    printf("Nova margem: %.2f%%\n", novaMargem);
    printf("Nova comissao: R$ %.2f\n", novaComissao);
    printf("Status: PENDENTE\n");

    if (novaMargem < 30) {
        printf("ATENCAO: margem abaixo de 30%%!\n");
    }

    return;

cancelar:
    mysql_rollback(conexao);
    mysql_autocommit(conexao, 1);
}

void atualizarSituacaoVenda(MYSQL *conexao, Colaborador usuario) {
    char numeroOS[31];
    char osSegura[61];
    char consulta[1000];
    char dataRetirada[11] = "";
    char entradaData[32];

    MYSQL_RES *resultado;
    MYSQL_ROW linha;

    int idVenda;
    int faturada, vendaPaga, retirada;
    int opcao;

    printf("\n========== ATUALIZAR SITUACAO DA VENDA ==========\n");
    printf("Numero da OS: ");
    scanf("%30s", numeroOS);

    mysql_real_escape_string(
        conexao, osSegura, numeroOS, strlen(numeroOS)
    );

    snprintf(
        consulta, sizeof(consulta),
        "SELECT v.id_venda, v.faturada, v.venda_paga, "
        "v.data_retirada "
        "FROM venda v "
        "INNER JOIN comissao c ON c.id_venda = v.id_venda "
        "WHERE v.numero_os = '%s' "
        "AND v.id_colaborador = %d "
        "AND v.status = 'ATIVA' "
        "AND v.data_baixa IS NULL "
        "AND c.status = 'PENDENTE'",
        osSegura, usuario.id_colaborador
    );

    if (mysql_query(conexao, consulta) != 0) {
        printf("Erro ao consultar venda: %s\n", mysql_error(conexao));
        return;
    }

    resultado = mysql_store_result(conexao);

    if (resultado == NULL) {
        printf("Erro ao obter resultado: %s\n", mysql_error(conexao));
        return;
    }

    linha = mysql_fetch_row(resultado);

    if (linha == NULL) {
        printf("\nVenda nao encontrada ou atualizacao nao permitida.\n");
        mysql_free_result(resultado);
        return;
    }

    idVenda = atoi(linha[0]);
    faturada = atoi(linha[1]);
    vendaPaga = atoi(linha[2]);

    if (linha[3] != NULL) {
        snprintf(dataRetirada, sizeof(dataRetirada), "%s", linha[3]);
    }

    mysql_free_result(resultado);

    printf("\nSituacao atual:\n");
    printf("Faturada: %s\n", faturada ? "SIM" : "NAO");
    printf("Paga pelo cliente: %s\n", vendaPaga ? "SIM" : "NAO");
    char dataFormatada[32];
    printf("Retirada: %s\n", dataRetirada[0] ? dataParaBrasil(dataRetirada, dataFormatada) : "NAO RETIRADO");

    printf("\n1 - Atualizar pagamento do cliente\n");
    printf("2 - Atualizar faturamento\n");
    printf("3 - Atualizar retirada do equipamento\n");
    printf("0 - Cancelar\n");
    printf("Escolha: ");

    if (scanf("%d", &opcao) != 1) {
        printf("Opcao invalida.\n");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        return;
    }

    switch (opcao) {
        case 1:
            printf("Cliente pagou? (1-Sim / 0-Nao): ");
            if (scanf("%d", &vendaPaga) != 1 ||
                (vendaPaga != 0 && vendaPaga != 1)) {
                printf("Valor invalido.\n");
                return;
            }

            snprintf(
                consulta, sizeof(consulta),
                "UPDATE venda SET venda_paga = %d "
                "WHERE id_venda = %d AND id_colaborador = %d "
                "AND data_baixa IS NULL AND status = 'ATIVA' "
                "AND EXISTS (SELECT 1 FROM comissao c "
                "WHERE c.id_venda = venda.id_venda "
                "AND c.status = 'PENDENTE')",
                vendaPaga, idVenda, usuario.id_colaborador
            );
            break;

        case 2:
            printf("Venda faturada? (1-Sim / 0-Nao): ");
            if (scanf("%d", &faturada) != 1 ||
                (faturada != 0 && faturada != 1)) {
                printf("Valor invalido.\n");
                return;
            }

            snprintf(
                consulta, sizeof(consulta),
                "UPDATE venda SET faturada = %d "
                "WHERE id_venda = %d AND id_colaborador = %d "
                "AND data_baixa IS NULL AND status = 'ATIVA' "
                "AND EXISTS (SELECT 1 FROM comissao c "
                "WHERE c.id_venda = venda.id_venda "
                "AND c.status = 'PENDENTE')",
                faturada, idVenda, usuario.id_colaborador
            );
            break;

        case 3:
            printf("Equipamento retirado? (1-Sim / 0-Nao): ");
            if (scanf("%d", &retirada) != 1 ||
                (retirada != 0 && retirada != 1)) {
                printf("Valor invalido.\n");
                return;
            }

            if (retirada == 1) {
                printf("Data da retirada (DD/MM/AAAA): ");
                if (scanf("%31s", entradaData) != 1 ||
                    !dataParaMysql(entradaData, dataRetirada)) {
                    printf("Data invalida. Use DD/MM/AAAA.\n");
                    return;
                }

                snprintf(
                    consulta, sizeof(consulta),
                    "UPDATE venda SET data_retirada = '%s' "
                    "WHERE id_venda = %d AND id_colaborador = %d "
                    "AND data_baixa IS NULL AND status = 'ATIVA' "
                    "AND EXISTS (SELECT 1 FROM comissao c "
                    "WHERE c.id_venda = venda.id_venda "
                    "AND c.status = 'PENDENTE')",
                    dataRetirada, idVenda, usuario.id_colaborador
                );
            } else {
                snprintf(
                    consulta, sizeof(consulta),
                    "UPDATE venda SET data_retirada = NULL "
                    "WHERE id_venda = %d AND id_colaborador = %d "
                    "AND data_baixa IS NULL AND status = 'ATIVA' "
                    "AND EXISTS (SELECT 1 FROM comissao c "
                    "WHERE c.id_venda = venda.id_venda "
                    "AND c.status = 'PENDENTE')",
                    idVenda, usuario.id_colaborador
                );
            }
            break;

        case 0:
            printf("\nAtualizacao cancelada.\n");
            return;

        default:
            printf("\nOpcao invalida.\n");
            return;
    }

    if (mysql_query(conexao, consulta) != 0) {
        printf("Erro ao atualizar situacao: %s\n", mysql_error(conexao));
        return;
    }

    if (mysql_affected_rows(conexao) == 0) {
        printf("\nNenhuma alteracao realizada. Verifique a situacao da venda.\n");
        return;
    }

    printf("\nSituacao da venda atualizada com sucesso!\n");
    printf("A validacao e a baixa continuam sob responsabilidade do Financeiro.\n");
}

void consultarMinhasComissoes(MYSQL *conexao, Colaborador usuario) {
    char consulta[1000];
    MYSQL_RES *resultado;
    MYSQL_ROW linha;
    int quantidade = 0;
    double totalComissoes = 0;

    snprintf(
        consulta,
        sizeof(consulta),
        "SELECT v.numero_os, v.nome_cliente, "
        "v.valor_venda, c.percentual_aplicado, "
        "c.valor_comissao, c.status "
        "FROM comissao c "
        "INNER JOIN venda v ON v.id_venda = c.id_venda "
        "WHERE v.id_colaborador = %d "
        "ORDER BY v.id_venda DESC",
        usuario.id_colaborador
    );

    if (mysql_query(conexao, consulta) != 0) {
        printf("\nErro ao consultar comissoes: %s\n",
               mysql_error(conexao));
        return;
    }

    resultado = mysql_store_result(conexao);

    if (resultado == NULL) {
        printf("\nErro ao obter resultados: %s\n",
               mysql_error(conexao));
        return;
    }

    printf("\n========== MINHAS COMISSOES ==========\n");
    printf("Vendedor: %s\n", usuario.nome);

    while ((linha = mysql_fetch_row(resultado)) != NULL) {
        double valorComissao = atof(linha[4]);

        quantidade++;
        totalComissoes += valorComissao;

        printf("\n----------------------------------\n");
        printf("OS: %s\n", linha[0]);
        printf("Cliente: %s\n", linha[1]);
        printf("Valor da venda: R$ %.2f\n", atof(linha[2]));
        printf("Percentual: %.2f%%\n", atof(linha[3]));
        printf("Comissao: R$ %.2f\n", valorComissao);
        printf("Status: %s\n", linha[5]);
    }

    if (quantidade == 0) {
        printf("\nNenhuma comissao encontrada.\n");
    }

    printf("\n==================================\n");
    printf("Total de comissoes: %d\n", quantidade);
    printf("Valor total das comissoes: R$ %.2f\n", totalComissoes);

    mysql_free_result(resultado);
}