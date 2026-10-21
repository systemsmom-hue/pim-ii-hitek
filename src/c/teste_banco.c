#include <stdio.h>
#include "banco.h"

int main(void) {
    MYSQL *conexao = conectarBanco();

    if (conexao == NULL) {
        return 1;
    }

    printf("Banco hitek_comissoes esta acessivel.\n");

    desconectarBanco(conexao);
    return 0;
}