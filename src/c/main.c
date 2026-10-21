#include <stdio.h>
#include <string.h>
#include "modelos.h"
#include "autenticacao.h"
#include "menus.h"
#include "calculos.h"
#include "banco.h"

int main(void)  {
    MYSQL *conexao;
    Colaborador usuario;
    int resultadoLogin;
    int continuar = 1;

    conexao = conectarBanco();

    if (conexao == NULL) {
        return 1;
    }

    while (continuar == 1) {

        printf("==========================================\n");
        printf("   SISTEMA DE GERENCIAMENTO DE COMISSOES  \n");
        printf("                  HITEK                   \n");
        printf("==========================================\n");

        resultadoLogin = fazerLogin(conexao, &usuario);

        if (resultadoLogin == -1) {
            printf("\nLogin ou senha incorretos.\n");
        } else {
            printf("\nBem-Vindo, %s\n", usuario.nome);
            
            if (strcmp(usuario.perfil, "ADMINISTRADOR") == 0) {
                menuAdministrador(conexao, usuario);

            } else if (strcmp(usuario.perfil, "VENDEDOR") == 0) {
                menuUsuario(conexao, usuario);

            } else if (strcmp(usuario.perfil, "FINANCEIRO") == 0) {
                menuFinanceiro(conexao, usuario);

            } else {
                printf("\nErro: perfil de usuario nao reconhecido.\n");
            }
        }

        printf("Deseja fazer outro login? (1-Sim / 2-Nao): ");
        scanf("%d", &continuar);
    }

    desconectarBanco(conexao);
    printf("Programa encerrado.\n");

    return 0;
}