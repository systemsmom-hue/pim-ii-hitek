#ifndef DATAS_H
#define DATAS_H
#include <stdio.h>
#include <string.h>

/* Entrada brasileira DD/MM/AAAA -> armazenamento MySQL AAAA-MM-DD. */
static int dataParaMysql(const char *br, char mysql[11]) {
    if (!br || strlen(br) != 10 || br[2] != '/' || br[5] != '/') return 0;
    for (int i = 0; i < 10; i++) {
        if (i != 2 && i != 5 && (br[i] < '0' || br[i] > '9')) return 0;
    }
    int d = (br[0]-'0')*10 + br[1]-'0';
    int m = (br[3]-'0')*10 + br[4]-'0';
    int y = (br[6]-'0')*1000 + (br[7]-'0')*100 + (br[8]-'0')*10 + br[9]-'0';
    if (y < 1000 || m < 1 || m > 12) return 0;
    int dias[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (m == 2 && (y%400==0 || (y%4==0 && y%100!=0))) dias[1] = 29;
    if (d < 1 || d > dias[m-1]) return 0;
    snprintf(mysql, 11, "%04d-%02d-%02d", y, m, d);
    return 1;
}

/* Para exibir valores DATE ou DATETIME recuperados do MySQL. */
static const char *dataParaBrasil(const char *mysql, char destino[32]) {
    if (!mysql || !mysql[0]) return "-";
    if (strlen(mysql) < 10 || mysql[4] != '-' || mysql[7] != '-') return mysql;
    if (strlen(mysql) >= 19) {
        snprintf(destino, 32, "%.2s/%.2s/%.4s %.8s", mysql+8, mysql+5, mysql, mysql+11);
    } else {
        snprintf(destino, 32, "%.2s/%.2s/%.4s", mysql+8, mysql+5, mysql);
    }
    return destino;
}
#endif
