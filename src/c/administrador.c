#include <stdio.h>
#include "datas.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "administrador.h"
#include "financeiro.h"
#include "banco.h"

int validarDataAdmissao(const char *data);

void consultarVendasAdministrador(MYSQL *conexao) {
    printf("\n========== CONSULTA DE VENDAS - ADMINISTRADOR ==========\n");

    consultarVendasFinanceiro(conexao);
}

void consultarComissoesAdministrador(MYSQL *conexao) {
    MYSQL_RES *resultado;
    MYSQL_ROW linha;
    int quantidade = 0;
    double total = 0;

    const char *consulta =
        "SELECT c.id_comissao, v.numero_os, "
        "col.nome, v.valor_venda, "
        "c.percentual_aplicado, c.valor_comissao, "
        "c.status "
        "FROM comissao c "
        "INNER JOIN venda v ON v.id_venda = c.id_venda "
        "INNER JOIN colaborador col "
        "ON col.id_colaborador = v.id_colaborador "
        "ORDER BY c.id_comissao DESC";

    if (mysql_query(conexao, consulta) != 0) {
        printf("\nErro ao consultar comissoes: %s\n",
               mysql_error(conexao));
        return;
    }

    resultado = mysql_store_result(conexao);

    if (resultado == NULL) {
        printf("\nErro ao obter resultados: %s\n",
               mysql_error(conexao));
        return;
    }

    printf("\n========== COMISSOES - ADMINISTRADOR ==========\n");

    while ((linha = mysql_fetch_row(resultado)) != NULL) {
        double valor = linha[5] ? atof(linha[5]) : 0.0;

        quantidade++;
        total += valor;

        printf("\n----------------------------------\n");
        printf("ID da comissao: %s\n", linha[0]);
        printf("OS: %s\n", linha[1]);
        printf("Vendedor: %s\n", linha[2]);
        printf("Valor da venda: R$ %.2f\n", atof(linha[3]));
        printf("Percentual: %.2f%%\n", atof(linha[4]));
        printf("Comissao: R$ %.2f\n", valor);
        printf("Status: %s\n", linha[6]);
    }

    if (quantidade == 0) {
        printf("\nNenhuma comissao encontrada.\n");
    }

    printf("\n==================================\n");
    printf("Total de comissoes: %d\n", quantidade);
    printf("Valor total registrado: R$ %.2f\n", total);

    mysql_free_result(resultado);
}

void alterarPercentualComissao(MYSQL *conexao, Colaborador usuario) {
    double novoPercentual;
    double percentualAtual;
    int confirmar;
    char consulta[500];

    if (strcmp(usuario.perfil, "ADMINISTRADOR") != 0) {
        printf("\nAcesso negado.\n");
        return;
    }

    percentualAtual = buscarPercentualAtual(conexao);

    printf("\n========== ALTERAR PERCENTUAL ==========\n");
    printf("Percentual atual: %.2f%%\n", percentualAtual);
    printf("Novo percentual (exemplo: 2.5 para 2,5%%): ");

    if (scanf("%lf", &novoPercentual) != 1) {
        printf("\nValor invalido.\n");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        return;
    }

    if (!isfinite(novoPercentual) ||
        novoPercentual <= 0 ||
        novoPercentual > 100) {
        printf("\nO percentual deve estar entre 0 e 100, "
               "sem incluir o zero.\n");
        return;
    }

    printf("\nAlterar percentual de %.2f%% para %.2f%%? "
           "(1-Sim / 0-Nao): ",
           percentualAtual, novoPercentual);

    if (scanf("%d", &confirmar) != 1 || confirmar != 1) {
        printf("\nAlteracao cancelada.\n");
        return;
    }

    snprintf(
        consulta,
        sizeof(consulta),
        "INSERT INTO configuracao "
        "(percentual_atual, data_alteracao, id_administrador) "
        "VALUES (%.2f, NOW(), %d)",
        novoPercentual,
        usuario.id_colaborador
    );

    if (mysql_query(conexao, consulta) != 0) {
        printf("\nErro ao alterar percentual: %s\n",
               mysql_error(conexao));
        return;
    }

    printf("\nPercentual atualizado com sucesso!\n");
    printf("Novo percentual: %.2f%%\n", novoPercentual);
    printf("As comissoes anteriores nao foram alteradas.\n");
}

void consultarRelatorioAdministrador(MYSQL *conexao) {
    MYSQL_RES *resultado;
    MYSQL_ROW linha;

    const char *consulta =
        "SELECT "
        "(SELECT COUNT(*) FROM venda WHERE status = 'ATIVA'), "
        "(SELECT COALESCE(SUM(valor_venda), 0) "
        " FROM venda WHERE status = 'ATIVA'), "
        "(SELECT COUNT(*) FROM comissao WHERE status = 'PENDENTE'), "
        "(SELECT COUNT(*) FROM comissao WHERE status = 'LIBERADA'), "
        "(SELECT COUNT(*) FROM comissao WHERE status = 'PAGA'), "
        "(SELECT COALESCE(SUM(valor_comissao), 0) "
        " FROM comissao WHERE status <> 'CANCELADA'), "
        "(SELECT COALESCE(SUM(valor_pago), 0) "
        " FROM pagamento_comissao WHERE status = 'PAGO'), "
        "(SELECT COALESCE(SUM(valor_desconto), 0) "
        " FROM desconto WHERE aplicado = 1), "
        "(SELECT COALESCE(SUM(valor_desconto), 0) "
        " FROM desconto WHERE aplicado = 0)";

    if (mysql_query(conexao, consulta) != 0) {
        printf("\nErro ao gerar relatorio: %s\n",
               mysql_error(conexao));
        return;
    }

    resultado = mysql_store_result(conexao);

    if (resultado == NULL) {
        printf("\nErro ao obter relatorio: %s\n",
               mysql_error(conexao));
        return;
    }

    linha = mysql_fetch_row(resultado);

    if (linha != NULL) {
        printf("\n========== RELATORIO GERAL HITEK ==========\n");
        printf("Vendas ativas: %s\n", linha[0]);
        printf("Valor total das vendas ativas: R$ %.2f\n",
               atof(linha[1]));
        printf("Comissoes pendentes: %s\n", linha[2]);
        printf("Comissoes liberadas: %s\n", linha[3]);
        printf("Comissoes pagas: %s\n", linha[4]);
        printf("Valor total das comissoes: R$ %.2f\n",
               atof(linha[5]));
        printf("Total de pagamentos realizados: R$ %.2f\n",
               atof(linha[6]));
        printf("Descontos aplicados: R$ %.2f\n", atof(linha[7]));
        printf("Descontos pendentes: R$ %.2f\n", atof(linha[8]));
    }

    mysql_free_result(resultado);
}

void gerenciarColaboradores(MYSQL *conexao) {
    MYSQL_RES *resultado;
    MYSQL_ROW linha;
    int quantidade = 0;

    const char *consulta =
        "SELECT id_colaborador, nome, cargo, "
        "email, perfil, status "
        "FROM colaborador "
        "ORDER BY id_colaborador";

    if (mysql_query(conexao, consulta) != 0) {
        printf("\nErro ao consultar colaboradores: %s\n",
               mysql_error(conexao));
        return;
    }

    resultado = mysql_store_result(conexao);

    if (resultado == NULL) {
        printf("\nErro ao obter colaboradores: %s\n",
               mysql_error(conexao));
        return;
    }

    printf("\n========== COLABORADORES HITEK ==========\n");

    while ((linha = mysql_fetch_row(resultado)) != NULL) {
        quantidade++;

        printf("\n----------------------------------\n");
        printf("ID: %s\n", linha[0]);
        printf("Nome: %s\n", linha[1]);
        printf("Cargo: %s\n", linha[2]);
        printf("Email: %s\n", linha[3]);
        printf("Perfil: %s\n", linha[4]);
        printf("Status: %s\n", linha[5]);
    }

    if (quantidade == 0) {
        printf("\nNenhum colaborador cadastrado.\n");
    }

    printf("\nTotal de colaboradores: %d\n", quantidade);

    mysql_free_result(resultado);
}

void cadastrarColaborador(MYSQL *conexao) {
    char nome[101], cpf[15], email[101];
    char telefone[21], cargo[46];
    char dataAdmissao[11], login[51];
    char entradaData[32];
    char senha[101], perfil[20];
    char consulta[1600];

    int opcaoPerfil;

    printf("\n========== CADASTRAR COLABORADOR ==========\n");

    printf("Nome completo: ");
    scanf(" %100[^\n]", nome);

    printf("CPF (000.000.000-00): ");
    scanf("%14s", cpf);

    printf("Email: ");
    scanf("%100s", email);

    printf("Telefone: ");
    scanf("%20s", telefone);

    printf("Cargo: ");
    scanf(" %45[^\n]", cargo);

    do {
        printf("Data de admissao (DD/MM/AAAA): ");
        if (scanf("%31s", entradaData) != 1) return;
        if (dataParaMysql(entradaData, dataAdmissao)) break;
        printf("Data invalida. Use DD/MM/AAAA.\n");
    } while (1);

    printf("Login: ");
    scanf("%50s", login);

    printf("Senha temporaria: ");
    scanf("%100s", senha);

    printf("\n1 - Vendedor\n");
    printf("2 - Financeiro\n");
    printf("3 - Administrador\n");
    printf("Perfil: ");

    if (scanf("%d", &opcaoPerfil) != 1) {
        printf("\nPerfil invalido.\n");
        return;
    }

    switch (opcaoPerfil) {
        case 1:
            strcpy(perfil, "VENDEDOR");
            break;
        case 2:
            strcpy(perfil, "FINANCEIRO");
            break;
        case 3:
            strcpy(perfil, "ADMINISTRADOR");
            break;
        default:
            printf("\nPerfil invalido.\n");
            return;
    }

    // Escapa os dados fornecidos antes de montar o SQL.
    char nomeEsc[201], cpfEsc[29], emailEsc[201];
    char telefoneEsc[41], cargoEsc[91];
    char loginEsc[101], senhaEsc[201];

    mysql_real_escape_string(conexao, nomeEsc, nome, strlen(nome));
    mysql_real_escape_string(conexao, cpfEsc, cpf, strlen(cpf));
    mysql_real_escape_string(conexao, emailEsc, email, strlen(email));
    mysql_real_escape_string(conexao, telefoneEsc, telefone, strlen(telefone));
    mysql_real_escape_string(conexao, cargoEsc, cargo, strlen(cargo));
    mysql_real_escape_string(conexao, loginEsc, login, strlen(login));
    mysql_real_escape_string(conexao, senhaEsc, senha, strlen(senha));

    int tamanho = snprintf(
        consulta, sizeof(consulta),
        "INSERT INTO colaborador "
        "(nome, cpf, email, telefone, cargo, data_admissao, "
        "login, senha, perfil, status) "
        "VALUES ('%s', '%s', '%s', '%s', '%s', '%s', "
        "'%s', '%s', '%s', 'ATIVO')",
        nomeEsc, cpfEsc, emailEsc, telefoneEsc, cargoEsc,
        dataAdmissao, loginEsc, senhaEsc, perfil
    );

    if (tamanho < 0 || tamanho >= (int)sizeof(consulta)) {
        printf("\nErro: dados excederam o tamanho da consulta.\n");
        return;
    }

    if (mysql_query(conexao, consulta) != 0) {
        printf("\nErro ao cadastrar colaborador: %s\n",
               mysql_error(conexao));
        return;
    }

    printf("\nColaborador cadastrado com sucesso!\n");
    printf("ID: %llu\n",
           (unsigned long long) mysql_insert_id(conexao));
    printf("Nome: %s\n", nome);
    printf("Perfil: %s\n", perfil);
}

int validarDataAdmissao(const char *data) {
    char resultado[11];
    return dataParaMysql(data, resultado);
}

void atualizarColaborador(MYSQL *conexao) {
    int id, opcao;
    char consulta[1000];
    char novoValor[101];
    char valorSeguro[201];

    MYSQL_RES *resultado;
    MYSQL_ROW linha;

    printf("\n========== ATUALIZAR COLABORADOR ==========\n");
    printf("ID do colaborador: ");

    if (scanf("%d", &id) != 1 || id <= 0) {
        printf("\nID invalido.\n");
        return;
    }

    snprintf(
        consulta, sizeof(consulta),
        "SELECT nome, email, telefone, cargo "
        "FROM colaborador WHERE id_colaborador = %d",
        id
    );

    if (mysql_query(conexao, consulta) != 0) {
        printf("\nErro ao consultar colaborador: %s\n",
               mysql_error(conexao));
        return;
    }

    resultado = mysql_store_result(conexao);

    if (resultado == NULL) {
        printf("\nErro ao obter colaborador: %s\n",
               mysql_error(conexao));
        return;
    }

    linha = mysql_fetch_row(resultado);

    if (linha == NULL) {
        printf("\nColaborador nao encontrado.\n");
        mysql_free_result(resultado);
        return;
    }

    printf("\nNome: %s\n", linha[0]);
    printf("Email: %s\n", linha[1]);
    printf("Telefone: %s\n", linha[2] ? linha[2] : "-");
    printf("Cargo: %s\n", linha[3]);

    mysql_free_result(resultado);

    printf("\nQual informacao deseja alterar?\n");
    printf("1 - Nome\n");
    printf("2 - Email\n");
    printf("3 - Telefone\n");
    printf("4 - Cargo\n");
    printf("0 - Cancelar\n");
    printf("Escolha: ");

    if (scanf("%d", &opcao) != 1) {
        printf("\nOpcao invalida.\n");
        return;
    }

    const char *coluna;
    int limite;

    switch (opcao) {
        case 1:
            coluna = "nome";
            limite = 100;
            break;
        case 2:
            coluna = "email";
            limite = 100;
            break;
        case 3:
            coluna = "telefone";
            limite = 20;
            break;
        case 4:
            coluna = "cargo";
            limite = 45;
            break;
        case 0:
            printf("\nAtualizacao cancelada.\n");
            return;
        default:
            printf("\nOpcao invalida.\n");
            return;
    }

    printf("Novo valor: ");

    if (scanf(" %100[^\n]", novoValor) != 1) {
        printf("\nValor invalido.\n");
        return;
    }

    if ((int)strlen(novoValor) > limite) {
        printf("\nValor excede o limite de %d caracteres.\n",
               limite);
        return;
    }

    mysql_real_escape_string(
        conexao,
        valorSeguro,
        novoValor,
        strlen(novoValor)
    );

    snprintf(
        consulta, sizeof(consulta),
        "UPDATE colaborador SET %s = '%s' "
        "WHERE id_colaborador = %d",
        coluna, valorSeguro, id
    );

    if (mysql_query(conexao, consulta) != 0) {
        printf("\nErro ao atualizar colaborador: %s\n",
               mysql_error(conexao));
        return;
    }

    printf("\nColaborador atualizado com sucesso!\n");
}

void alterarStatusColaborador(MYSQL *conexao, Colaborador usuario) {
    int id, opcao;
    char consulta[500];
    char nome[101];
    char statusAtual[10];

    MYSQL_RES *resultado;
    MYSQL_ROW linha;

    if (strcmp(usuario.perfil, "ADMINISTRADOR") != 0) {
        printf("\nAcesso negado.\n");
        return;
    }

    printf("\n========== ALTERAR STATUS ==========\n");
    printf("ID do colaborador: ");

    if (scanf("%d", &id) != 1 || id <= 0) {
        printf("\nID invalido.\n");
        return;
    }

    if (id == usuario.id_colaborador) {
        printf("\nVoce nao pode alterar seu proprio status.\n");
        return;
    }

    snprintf(consulta, sizeof(consulta),
        "SELECT nome, status FROM colaborador "
        "WHERE id_colaborador = %d", id);

    if (mysql_query(conexao, consulta) != 0) {
        printf("\nErro: %s\n", mysql_error(conexao));
        return;
    }

    resultado = mysql_store_result(conexao);

    if (resultado == NULL) {
        printf("\nErro ao consultar colaborador.\n");
        return;
    }

    linha = mysql_fetch_row(resultado);

    if (linha == NULL) {
        printf("\nColaborador nao encontrado.\n");
        mysql_free_result(resultado);
        return;
    }

    snprintf(nome, sizeof(nome), "%s", linha[0]);
    snprintf(statusAtual, sizeof(statusAtual), "%s", linha[1]);

    mysql_free_result(resultado);

    printf("\nColaborador: %s\n", nome);
    printf("Status atual: %s\n", statusAtual);

    printf("\n1 - Ativar\n");
    printf("2 - Inativar\n");
    printf("0 - Cancelar\n");
    printf("Escolha: ");

    if (scanf("%d", &opcao) != 1) {
        printf("\nOpcao invalida.\n");
        return;
    }

    const char *novoStatus;

    switch (opcao) {
        case 1:
            novoStatus = "ATIVO";
            break;

        case 2:
            novoStatus = "INATIVO";
            break;

        case 0:
            printf("\nOperacao cancelada.\n");
            return;

        default:
            printf("\nOpcao invalida.\n");
            return;
    }

    if (strcmp(statusAtual, novoStatus) == 0) {
        printf("\nO colaborador ja possui esse status.\n");
        return;
    }

    snprintf(consulta, sizeof(consulta),
        "UPDATE colaborador SET status = '%s' "
        "WHERE id_colaborador = %d",
        novoStatus, id);

    if (mysql_query(conexao, consulta) != 0) {
        printf("\nErro ao alterar status: %s\n",
               mysql_error(conexao));
        return;
    }

    printf("\nStatus atualizado com sucesso!\n");
    printf("Colaborador: %s\n", nome);
    printf("Novo status: %s\n", novoStatus);
}

void gerenciarUsuarios(MYSQL *conexao, Colaborador usuario) {
    int id, opcao;
    char consulta[500];

    MYSQL_RES *resultado;
    MYSQL_ROW linha;

    if (strcmp(usuario.perfil, "ADMINISTRADOR") != 0) {
        printf("\nAcesso negado.\n");
        return;
    }

    printf("\n========== GERENCIAR USUARIOS ==========\n");
    printf("ID do colaborador: ");

    if (scanf("%d", &id) != 1 || id <= 0) {
        printf("\nID invalido.\n");
        return;
    }

    if (id == usuario.id_colaborador) {
        printf("\nVoce nao pode alterar seu proprio perfil.\n");
        return;
    }

    snprintf(
        consulta, sizeof(consulta),
        "SELECT nome, login, perfil, status "
        "FROM colaborador WHERE id_colaborador = %d",
        id
    );

    if (mysql_query(conexao, consulta) != 0) {
        printf("\nErro na consulta: %s\n", mysql_error(conexao));
        return;
    }

    resultado = mysql_store_result(conexao);

    if (resultado == NULL) {
        printf("\nErro ao obter resultado: %s\n",
               mysql_error(conexao));
        return;
    }

    linha = mysql_fetch_row(resultado);

    if (linha == NULL) {
        printf("\nColaborador nao encontrado.\n");
        mysql_free_result(resultado);
        return;
    }

    printf("\nNome: %s\n", linha[0]);
    printf("Login: %s\n", linha[1]);
    printf("Perfil atual: %s\n", linha[2]);
    printf("Status: %s\n", linha[3]);

    mysql_free_result(resultado);

    printf("\nSelecione o novo perfil:\n");
    printf("1 - Vendedor\n");
    printf("2 - Financeiro\n");
    printf("3 - Administrador\n");
    printf("0 - Cancelar\n");
    printf("Escolha: ");

    if (scanf("%d", &opcao) != 1) {
        printf("\nOpcao invalida.\n");
        return;
    }

    const char *novoPerfil;

    switch (opcao) {
        case 1:
            novoPerfil = "VENDEDOR";
            break;

        case 2:
            novoPerfil = "FINANCEIRO";
            break;

        case 3:
            novoPerfil = "ADMINISTRADOR";
            break;

        case 0:
            printf("\nOperacao cancelada.\n");
            return;

        default:
            printf("\nOpcao invalida.\n");
            return;
    }

    printf("\nConfirmar alteracao para %s?\n", novoPerfil);
    printf("1 - Sim\n");
    printf("2 - Nao\n");
    printf("Escolha: ");

    int confirmar;

    if (scanf("%d", &confirmar) != 1 || confirmar != 1) {
        printf("\nAlteracao cancelada.\n");
        return;
    }

    snprintf(
        consulta, sizeof(consulta),
        "UPDATE colaborador SET perfil = '%s' "
        "WHERE id_colaborador = %d",
        novoPerfil, id
    );

    if (mysql_query(conexao, consulta) != 0) {
        printf("\nErro ao alterar perfil: %s\n",
               mysql_error(conexao));
        return;
    }

    printf("\nPerfil atualizado com sucesso!\n");
    printf("Novo perfil: %s\n", novoPerfil);
}

void registrarAjusteComissao(MYSQL *conexao, Colaborador usuario) {
    int idComissao;
    double valorDesconto;
    char motivo[256];
    char motivoSeguro[512];
    char consulta[1200];

    MYSQL_RES *resultado;
    MYSQL_ROW linha;

    if (strcmp(usuario.perfil, "ADMINISTRADOR") != 0) {
        printf("\nAcesso negado.\n");
        return;
    }

    printf("\n========== REGISTRAR AJUSTE DE COMISSAO ==========\n");
    printf("ID da comissao: ");

    if (scanf("%d", &idComissao) != 1 || idComissao <= 0) {
        printf("\nID invalido.\n");
        return;
    }

    snprintf(
        consulta, sizeof(consulta),
        "SELECT c.valor_comissao, c.status, "
        "v.numero_os, col.nome "
        "FROM comissao c "
        "INNER JOIN venda v ON c.id_venda = v.id_venda "
        "INNER JOIN colaborador col "
        "ON v.id_colaborador = col.id_colaborador "
        "WHERE c.id_comissao = %d",
        idComissao
    );

    if (mysql_query(conexao, consulta) != 0) {
        printf("\nErro na consulta: %s\n", mysql_error(conexao));
        return;
    }

    resultado = mysql_store_result(conexao);

    if (resultado == NULL) {
        printf("\nErro ao obter resultado: %s\n",
               mysql_error(conexao));
        return;
    }

    linha = mysql_fetch_row(resultado);

    if (linha == NULL) {
        printf("\nComissao nao encontrada.\n");
        mysql_free_result(resultado);
        return;
    }

    double valorComissao = atof(linha[0]);

    printf("\nVendedor: %s\n", linha[3]);
    printf("OS: %s\n", linha[2]);
    printf("Valor da comissao: R$ %.2f\n", valorComissao);
    printf("Status: %s\n", linha[1]);

    if (strcmp(linha[1], "CANCELADA") == 0) {
        printf("\nNao e permitido ajustar uma comissao cancelada.\n");
        mysql_free_result(resultado);
        return;
    }

    mysql_free_result(resultado);

    printf("\nValor do desconto (R$): ");

    if (scanf("%lf", &valorDesconto) != 1 ||
        !(valorDesconto > 0.0) ||
        valorDesconto > valorComissao) {
        printf("\nValor invalido. Informe um valor positivo "
               "que nao ultrapasse a comissao.\n");
        return;
    }

    printf("Motivo do ajuste: ");

    if (scanf(" %255[^\n]", motivo) != 1) {
        printf("\nMotivo invalido.\n");
        return;
    }

    if (strlen(motivo) == 0) {
        printf("\nO motivo nao pode estar vazio.\n");
        return;
    }

    mysql_real_escape_string(
        conexao,
        motivoSeguro,
        motivo,
        strlen(motivo)
    );

    printf("\nConfirma o registro deste ajuste?\n");
    printf("Valor: R$ %.2f\n", valorDesconto);
    printf("Motivo: %s\n", motivo);
    printf("1 - Sim\n");
    printf("2 - Nao\n");
    printf("Escolha: ");

    int confirmar;

    if (scanf("%d", &confirmar) != 1 || confirmar != 1) {
        printf("\nOperacao cancelada.\n");
        return;
    }

    snprintf(
        consulta, sizeof(consulta),
        "INSERT INTO desconto "
        "(id_comissao_origem, valor_desconto, motivo, "
        "data_registro, aplicado) "
        "VALUES (%d, %.2f, '%s', NOW(), 0)",
        idComissao, valorDesconto, motivoSeguro
    );

    if (mysql_query(conexao, consulta) != 0) {
        printf("\nErro ao registrar ajuste: %s\n",
               mysql_error(conexao));
        return;
    }

    printf("\nAjuste registrado com sucesso!\n");
    printf("ID do ajuste: %llu\n",
           (unsigned long long)mysql_insert_id(conexao));
    printf("Status: PENDENTE DE APLICACAO\n");
    printf("O valor da comissao original foi preservado.\n");
}

void consultarAjustesComissao(MYSQL *conexao) {
    const char *consulta =
        "SELECT d.id_desconto, "
        "c.id_comissao, "
        "col.nome, "
        "v.numero_os, "
        "d.valor_desconto, "
        "d.motivo, "
        "DATE_FORMAT(d.data_registro, '%d/%m/%Y'), "
        "d.aplicado, "
        "DATE_FORMAT(d.data_aplicacao, '%d/%m/%Y') "
        "FROM desconto d "
        "INNER JOIN comissao c "
        "ON d.id_comissao_origem = c.id_comissao "
        "INNER JOIN venda v "
        "ON c.id_venda = v.id_venda "
        "INNER JOIN colaborador col "
        "ON v.id_colaborador = col.id_colaborador "
        "ORDER BY d.id_desconto DESC";

    MYSQL_RES *resultado;
    MYSQL_ROW linha;
    int total = 0;

    printf("\n========== AJUSTES DE COMISSAO ==========\n");

    if (mysql_query(conexao, consulta) != 0) {
        printf("\nErro ao consultar ajustes: %s\n",
               mysql_error(conexao));
        return;
    }

    resultado = mysql_store_result(conexao);

    if (resultado == NULL) {
        printf("\nErro ao obter resultado: %s\n",
               mysql_error(conexao));
        return;
    }

    while ((linha = mysql_fetch_row(resultado)) != NULL) {
        printf("\n----------------------------------------\n");
        printf("ID do ajuste: %s\n", linha[0]);
        printf("ID da comissao: %s\n", linha[1]);
        printf("Vendedor: %s\n", linha[2]);
        printf("OS: %s\n", linha[3]);
        printf("Valor: R$ %.2f\n", atof(linha[4]));
        printf("Motivo: %s\n", linha[5] ? linha[5] : "-");
        printf("Data do registro: %s\n",
               linha[6] ? linha[6] : "-");

        printf("Situacao: %s\n",
               atoi(linha[7]) == 1 ? "APLICADO" : "PENDENTE");

        printf("Data da aplicacao: %s\n",
               linha[8] ? linha[8] : "-");

        total++;
    }

    if (total == 0) {
        printf("\nNenhum ajuste registrado.\n");
    }

    printf("\nTotal de ajustes: %d\n", total);

    mysql_free_result(resultado);
}