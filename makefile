# makefile
#
# Nome: Alexandre Saura.
# Nome: Fábio Thomaz.
# Nome: Ricardo Oliveira.
# Curso: Ciência da Computação.
# Prof.: Ciro Cirne Trindade.
# Disciplina: Estrutura de Dados II.
# Universidade Católica de Santos.
#
# 2º Trabalho de Estrutura de Dados II.

##### Variáveis #####
# Compilador
CC=gcc

# Flags
CFLAGS=-W -Wall

# Executável
EXEC=aplicacao

# Nome do executavel
PROJ_NAME=aplicacao

# Arquivos source, i.e. extensão .c
C_SRC=$(wildcard *.c)

# Arquivos objeto, i.e. extensão .o
OBJ=$(C_SRC:.c=.o)

##### Regras e dependências #####
$(PROJ_NAME): $(OBJ)
	$(CC) -o $(PROJ_NAME) $(OBJ) $(CFLAGS) -lm
	@echo "\nCompilação finalizada!\nDigite 'make run' e tecle <enter> para executar a aplicacao"

main.o: main.c hashmap.o ferramentas.o
	$(CC) -c main.c $(CFLAGS)

listaord.o: listaord.h
	$(CC) -c listaord.c $(CFLAGS)

hashmap.o: hashmap.h listaord.h
	$(CC) -c hashmap.c $(CFLAGS)

ferramentas.o: ferramentas.h
	$(CC) -c ferramentas.c $(CFLAGS)

avl.o: avl.h
	$(CC) -c avl.c $(CFLAGS)

# Executar
run:
	./$(EXEC)

# Limpar de arquivos
clean:
	rm -rf *.o

# Apagar tudo o que deve ser modificado
mrproper:
	rm -rf $(EXEC)