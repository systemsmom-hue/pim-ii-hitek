#ifndef BANCO_H
#define BANCO_H
#include "modelos.h"
#include <mysql.h>

MYSQL *conectarBanco(void);

void desconectarBanco(MYSQL *conexao);


double buscarPercentualAtual(MYSQL *conexao);

int salvarVenda(MYSQL *conexao, Venda venda);

int salvarComissao(MYSQL *conexao, Comissao comissao);

#endif