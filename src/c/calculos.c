#include "calculos.h"

double calcularMargem(double valorVenda, double custo) {
    if (valorVenda <= 0) {
        return -1;
    }

    return ((valorVenda - custo) / valorVenda) *100;
}

double calcularComissao(double valorVenda, double percentual) {
    return valorVenda * (percentual / 100);
}

int verificarLiberacao(int faturada, int equipamentoRetirado) {
    if (faturada == 1 && equipamentoRetirado == 1) {
        return 1;
    }
    return 0;
}