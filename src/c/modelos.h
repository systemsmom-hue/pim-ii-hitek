#ifndef MODELOS_H
#define MODELOS_H

/*permite chamar a estrutura simplesmente de Colaborador*/
typedef struct {
    int id_colaborador;
    char nome[101];
    char login[51];
    char senha[256];
    char perfil[20];
    char status[8];
} Colaborador;

typedef struct {
    int id_venda;
    char numero_os[31];
    int id_colaborador;
    char data_venda[11];
    char nome_cliente[101];
    double valor_venda;
    double custo;
    double margem;
    char forma_pagamento[16];
    int faturada;
    int venda_paga;
    char data_retirada[11];
    char descricao[256];
    char status[10];
} Venda; 

typedef struct {
    int id_comissao;
    int id_venda;
    double percentual_aplicado;
    double valor_comissao;
    char status[12];
} Comissao;

#endif
