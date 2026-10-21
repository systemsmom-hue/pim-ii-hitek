#ifndef MENUS_H
#define MENUS_H

#include <mysql.h>
#include "modelos.h"

void menuUsuario(MYSQL *conexao, Colaborador usuario);

void menuFinanceiro(MYSQL *conexao, Colaborador usuario);

void menuAdministrador(MYSQL *conexao, Colaborador usuario);

void menuColaboradores(MYSQL *conexao, Colaborador usuario);

void registrarAjusteComissao(MYSQL *conexao, Colaborador usuario);

void menuAjustesComissao(MYSQL *conexao, Colaborador usuario);

#endif