#ifndef FINANCEIRO_H
#define FINANCEIRO_H

#include <mysql.h>
#include "modelos.h"

void consultarVendasFinanceiro(MYSQL *conexao);

void consultarComissoesPendentes(MYSQL *conexao);

void confirmarBaixaVenda(MYSQL *conexao, Colaborador usuario);

void consultarComissoesLiberadas(MYSQL *conexao);

void registrarPagamentoComissao(MYSQL *conexao, Colaborador usuario);

void consultarPagamentosRealizados(MYSQL *conexao);

void consultarDescontosPendentes(MYSQL *conexao);

#endif