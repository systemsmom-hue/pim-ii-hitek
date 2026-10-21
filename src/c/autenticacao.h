#ifndef AUTENTICACAO_H
#define AUTENTICACAO_H

#include<mysql.h>
#include "modelos.h"

int fazerLogin(MYSQL *conexao, Colaborador *usuario);

#endif