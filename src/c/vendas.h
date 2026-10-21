#ifndef VENDAS_H
#define VENDAS_H
#include <mysql.h>

#include "modelos.h"

void cadastrarVenda(MYSQL *conexao, Colaborador usuario);

void listarVendas(void);

void consultarMinhasVendas(MYSQL *conexao, Colaborador usuario);

void atualizarVenda(MYSQL *conexao, Colaborador usuario);

void atualizarSituacaoVenda(MYSQL *conexao, Colaborador usuario);

void consultarMinhasComissoes(MYSQL *conexao, Colaborador usuario);

#endif