#include <stdio.h>
#include "banco.h"
#include <stdlib.h>
#include <string.h>

MYSQL *conectarBanco(void) {
    MYSQL * conexao;

    conexao = mysql_init(NULL);

    if (conexao == NULL) {
        printf("Erro ao inicializar o MySQL.\n");
        return NULL;
    }

    if (mysql_real_connect(
            conexao,
            "localhost",
            "root",
            "",
            "hitek_comissoes",
            3306,
            NULL,
            0
    ) == NULL) {

        printf("Erro de conexão: %s\n", mysql_error(conexao));
        mysql_close(conexao);
        return NULL;
    }

    printf("Conexao com o MySQL realizada com sucesso!\n");
    return conexao;
}

void desconectarBanco(MYSQL * conexao) {
    if (conexao != NULL) {
        mysql_close(conexao);
    }
}

double buscarPercentualAtual(MYSQL *conexao) {
    MYSQL_RES *resultado;
    MYSQL_ROW linha;
    double percentual;

    if (mysql_query(
            conexao,
            "SELECT percentual_atual "
            "FROM configuracao "
            "ORDER BY id_configuracao DESC "
            "LIMIT 1"
        ) != 0) {
            
        printf("Erro ao buscar percentual: %s\n",
              mysql_error(conexao));
        return 1.00;
    }

    resultado = mysql_store_result(conexao);

    if (resultado == NULL) {
        printf("Erro ao obter percentual: %s\n",
            mysql_error(conexao));
        return 1.00;
    }

    linha = mysql_fetch_row(resultado);

    if (linha == NULL) {
        mysql_free_result(resultado);
        return 1.00;
    } 

    percentual = atof(linha[0]);
    mysql_free_result(resultado);

    return percentual;
}

int salvarVenda(MYSQL *conexao, Venda venda) {
    char consulta[2048];
    char numeroOsSeguro[61];
    char clienteSeguro[201];
    char descricaoSegura[511];

    mysql_real_escape_string(
        conexao,
        numeroOsSeguro,
        venda.numero_os,
        strlen(venda.numero_os)
    );

    mysql_real_escape_string(
        conexao,
        descricaoSegura,
        venda.descricao,
        strlen(venda.descricao)
    );

        mysql_real_escape_string(
        conexao,
        clienteSeguro,
        venda.nome_cliente,
        strlen(venda.nome_cliente)
    );

    char dataRetiradaSql[20];

    if (strlen(venda.data_retirada) > 0) {
        snprintf(
            dataRetiradaSql,
            sizeof(dataRetiradaSql),
            "'%s'",
            venda.data_retirada
        );
    } else {
        strcpy(dataRetiradaSql, "NULL");
    }

    snprintf(
        consulta,
        sizeof(consulta),
        "INSERT INTO venda "
        "(numero_os, id_colaborador, data_venda, nome_cliente, "
        "valor_venda, custo, margem, forma_pagamento, faturada, "
        "venda_paga, data_retirada, descricao, status) "
        "VALUES ('%s', %d, '%s', '%s', %.2f, %.2f, %.2f, "
        "'%s', %d, %d, %s, '%s', 'ATIVA')",
        numeroOsSeguro,
        venda.id_colaborador,
        venda.data_venda,
        clienteSeguro,
        venda.valor_venda,
        venda.custo,
        venda.margem,
        venda.forma_pagamento,
        venda.faturada,
        venda.venda_paga,
        dataRetiradaSql,
        descricaoSegura
    );

    if (mysql_query(conexao, consulta) != 0) {
        printf("Erro ao salvar venda: %s\n", mysql_error(conexao));
        return 0;
    }

    venda.id_venda = (int) mysql_insert_id(conexao);

    printf("Venda salva no MySQL com ID %d.\n", venda.id_venda);
    return venda.id_venda;
}

int salvarComissao(MYSQL *conexao, Comissao comissao) {
    char consulta[500];

    snprintf(
        consulta,
        sizeof(consulta),
        "INSERT INTO comissao "
        "(id_venda, percentual_aplicado, valor_comissao, status, "
        "data_calculo, data_conferencia) "
        "VALUES (%d, %.2f, %.2f, '%s', NOW(), NULL)",
        comissao.id_venda,
        comissao.percentual_aplicado,
        comissao.valor_comissao,
        comissao.status
    );

    if (mysql_query(conexao, consulta) != 0) {
        printf(
            "Erro ao salvar comissoes: %s\n",
            mysql_error(conexao)
        );
        return 0;
    }

    comissao.id_comissao = (int) mysql_insert_id(conexao);

    printf(
        "Comissao salva no MySQL com ID %d.\n",
        comissao.id_comissao
    );

    return comissao.id_comissao;
}