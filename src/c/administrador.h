#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include <mysql.h>
#include "modelos.h"

void consultarVendasAdministrador(MYSQL *conexao);

void consultarComissoesAdministrador(MYSQL *conexao);

void alterarPercentualComissao(MYSQL *conexao, Colaborador usuario);

void consultarRelatorioAdministrador(MYSQL *conexao);

void gerenciarColaboradores(MYSQL *conexao);

void cadastrarColaborador(MYSQL *conexao);

void atualizarColaborador(MYSQL *conexao);

void alterarStatusColaborador(MYSQL *conexao, Colaborador usuario);

void gerenciarUsuarios(MYSQL *conexao, Colaborador usuario);

void consultarAjustesComissao(MYSQL *conexao);

#endif