 # ============================================================
# SISTEMA DE GESTÃO DE COMISSÕES — HITEK INFORMÁTICA
# Arquivo: Makefile
# Automobilização de compilação C com MySQL Client API (mysql.h)
# ============================================================

# Compilador e Flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 $(shell mysql_config --cflags 2>/dev/null || echo "-I/usr/include/mysql")
LIBS = $(shell mysql_config --libs 2>/dev/null || echo "-lmysqlclient")

# Diretórios
SRC_DIR = .
OBJ_DIR = obj
BIN_DIR = bin

# Nome do Executável Final
TARGET = $(BIN_DIR)/hitek_comissoes

# Arquivos Fontes
SRCS = main.c banco.c vendas.c financeiro.c administrador.c

# Objetos Gerados
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

# Regra Principal (Default)
.PHONY: all clean run setup

all: setup $(TARGET)

# Criação das pastas de binários/objetos se não existirem
setup:
	@mkdir -p $(OBJ_DIR) $(BIN_DIR)

# Linkagem do Executável Final
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LIBS)
	@echo "----------------------------------------------------"
	@echo " Compilação concluída com sucesso!"
	@echo " Executável gerado em: $(TARGET)"
	@echo "----------------------------------------------------"

# Compilação dos arquivos .c para .o
$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Executa o programa
run: all
	./$(TARGET)

# Limpeza dos arquivos compilados
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
	@echo "Arquivos de compilação limpos."
