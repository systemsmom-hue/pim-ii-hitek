#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "autenticacao.h"

int fazerLogin(MYSQL *conexao, Colaborador *usuario) {
    char login[51];
    char senha[256];
    char loginSeguro[101];
    char senhaSegura[511];
    char consulta[1000];

    MYSQL_RES *resultado;
    MYSQL_ROW linha;

    printf("\nLogin: ");
    scanf("%50s", login);

    printf("Senha: ");
    scanf("%255s", senha);

    mysql_real_escape_string(
        conexao, loginSeguro, login, strlen(login)
    );

    mysql_real_escape_string(
        conexao, senhaSegura, senha, strlen(senha)
    );

    snprintf(
        consulta,
        sizeof(consulta),
        "SELECT id_colaborador, nome, login, senha, perfil, status "
        "FROM colaborador "
        "WHERE login = '%s' AND senha = '%s' AND status = 'ATIVO' "
        "LIMIT 1",
        loginSeguro,
        senhaSegura
    );

    if (mysql_query(conexao, consulta) != 0) {
        printf("Erro ao consultar usuario: %s\n",
                mysql_error(conexao));
        return -1;
    }

    resultado = mysql_store_result(conexao);
    linha = mysql_fetch_row(resultado);

    if (linha == NULL) {
        mysql_free_result(resultado);
        return -1;
    }

    usuario->id_colaborador = atoi(linha[0]);
    strcpy(usuario->nome, linha[1]);
    strcpy(usuario->login, linha[2]);
    strcpy(usuario->senha, linha[3]);
    strcpy(usuario->perfil, linha[4]);
    strcpy(usuario->status, linha[5]);

    mysql_free_result(resultado);
    return 1;

}

