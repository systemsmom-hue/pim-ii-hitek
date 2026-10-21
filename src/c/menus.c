#include <stdio.h>
#include "menus.h"
#include "vendas.h"
#include "financeiro.h"
#include "administrador.h"
#include <string.h>

void menuUsuario(MYSQL *conexao, Colaborador usuario) {
    int opcao;

    do {
        printf("\n========== MENU VENDEDOR ==========\n");
        printf("Usuario: %s\n", usuario.nome);
        printf("1 - Cadastrar venda/OS\n");
        printf("2 - Consultar minhas vendas\n");
        printf("3 - Atualizar valor da venda\n");
        printf("4 - Atualizar situacao da venda\n");
        printf("5 - Consultar minhas comissoes\n");
        printf("0 - Sair\n");
        printf("Escolha: ");

        if (scanf("%d", &opcao) != 1) {
            printf("\nEntrada invalida.\n");

            int c;
            while ((c = getchar()) != '\n' && c != EOF);

            opcao = -1;
            continue;
        }

        switch (opcao) {
            case 1:
                cadastrarVenda(conexao, usuario);
                break;

            case 2:
                consultarMinhasVendas(conexao, usuario);
                break;

            case 3:
                atualizarVenda(conexao, usuario);
                break;

            case 4:
            atualizarSituacaoVenda(conexao, usuario);
            break;

            case 5:
            consultarMinhasComissoes(conexao, usuario);
            break;

            case 0:
                printf("\nSaindo do menu Vendedor...\n");
                break;

            default:
                printf("\nOpcao invalida.\n");
        }

    } while (opcao != 0);
}

void menuAdministrador(MYSQL *conexao, Colaborador usuario) {
    int opcao;
    (void) conexao;

    do {
        printf("\n========== MENU ADMINISTRADOR ==========\n");
        printf("Usuario: %s\n", usuario.nome);
        printf("1 - Consultar vendas\n");
        printf("2 - Consultar comissoes\n");
        printf("3 - Alterar percentual\n");
        printf("4 - Gerenciar colaboradores\n");
        printf("5 - Gerenciar usuarios\n");
        printf("6 - Registrar ajustes de comissao\n");
        printf("7 - Relatorio geral\n");
        printf("0 - Sair\n");
        printf("Escolha: ");

        if (scanf("%d", &opcao) != 1) {
            printf("\nEntrada invalida.\n");

            int c;
            while ((c = getchar()) != '\n' && c != EOF);

            opcao = -1;
            continue;
        }

        switch (opcao) {
            case 1:
                consultarVendasAdministrador(conexao);
                break;

            case 2:
                consultarComissoesAdministrador(conexao);
                break;

            case 3: 
                alterarPercentualComissao(conexao, usuario);
                break;
            case 4:
                menuColaboradores(conexao, usuario);
                break;

            case 5:
                gerenciarUsuarios(conexao, usuario);
                break;

            case 6: 
                menuAjustesComissao(conexao, usuario);
                break;

            case 7:
            consultarRelatorioAdministrador(conexao);
            break;

            case 0:
                printf("\nSaindo do sistema...\n");
                break;

            default:
            printf("\nOpcao invalida.\n");
        }
    } while (opcao != 0);
}

void menuFinanceiro(MYSQL *conexao, Colaborador usuario) {
    int opcao;


    do {
        printf("\n========== MENU FINANCEIRO ==========\n");
        printf("Usuario: %s\n", usuario.nome);
        printf("1 - Consultar vendas\n");
        printf("2 - Consultar comissoes pendentes\n");
        printf("3 - Confirmar baixa de venda\n");
        printf("4 - Consultar comissoes liberadas\n");
        printf("5 - Registrar pagamento de comissao\n");
        printf("6 - Consultar pagamentos realizados\n");
        printf("7 - Consultar descontos pendentes\n");
        printf("0 - Sair\n");
        printf("Escolha: ");

        if (scanf("%d", &opcao) != 1) {
            printf("\nEntrada invalida.\n");

            int c;
            while ((c = getchar()) != '\n' && c != EOF);

            opcao = -1;
            continue;
        }

        switch (opcao) {
            case 1:
                consultarVendasFinanceiro(conexao);
                break;

            case 2:
                consultarComissoesPendentes(conexao);
                break;

            case 3:
                confirmarBaixaVenda(conexao, usuario);
                break;

            case 4:
                consultarComissoesLiberadas(conexao);
                break;

            case 5:
                registrarPagamentoComissao(conexao, usuario);
                break;

            case 6:
                consultarPagamentosRealizados(conexao);
                break;

            case 7:
                consultarDescontosPendentes(conexao);
                break;

            case 0:
                printf("\nSaindo do menu Financeiro...\n");
                break;

            default:
                printf("\nOpcao invalida.\n");
        }

    } while (opcao != 0);
}

void menuColaboradores(MYSQL *conexao, Colaborador usuario) {
    int opcao;

    do {
        printf("\n========== GERENCIAR COLABORADORES ==========\n");
        printf("1 - Listar colaboradores\n");
        printf("2 - Cadastrar colaborador\n");
        printf("3 - Atualizar colaborador\n");
        printf("4 - Ativar/Inativar colaborador\n");
        printf("0 - Voltar ao menu Administrador\n");
        printf("Escolha: ");

        if (scanf("%d", &opcao) != 1) {
            printf("\nEntrada invalida.\n");

            int c;
            while ((c = getchar()) != '\n' && c != EOF);

            opcao = -1;
            continue;
        }

        switch (opcao) {
            case 1:
                gerenciarColaboradores(conexao);
                break;

            case 2:
                cadastrarColaborador(conexao);
                break;

            case 3:
                atualizarColaborador(conexao);
                break;

            case 4:
                alterarStatusColaborador(conexao, usuario);
                break;

            case 0:
                printf("\nVoltando ao menu Administrador...\n");
                break;

            default:
                printf("\nOpcao invalida.\n");
        }

    } while (opcao != 0);
}

void menuAjustesComissao(MYSQL *conexao, Colaborador usuario) {
    int opcao;

    if (strcmp(usuario.perfil, "ADMINISTRADOR") != 0) {
        printf("\nAcesso negado.\n");
        return;
    }

    do {
        printf("\n========== AJUSTES DE COMISSAO ==========\n");
        printf("1 - Registrar novo ajuste\n");
        printf("2 - Consultar ajustes registrados\n");
        printf("0 - Voltar ao menu Administrador\n");
        printf("Escolha: ");

        if (scanf("%d", &opcao) != 1) {
            printf("\nEntrada invalida.\n");

            int c;
            while ((c = getchar()) != '\n' && c != EOF);

            opcao = -1;
            continue;
        }

        switch (opcao) {
            case 1:
                registrarAjusteComissao(conexao, usuario);
                break;

            case 2:
                consultarAjustesComissao(conexao);
                break;

            case 0:
                printf("\nVoltando ao menu Administrador...\n");
                break;

            default:
                printf("\nOpcao invalida.\n");
        }

    } while (opcao != 0);
}