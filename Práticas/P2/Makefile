#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: compilar o programa matop
# Autor		: Wagner Meira Jr. (meira@dcc.ufmg.br)
# Histórico	: 2022-04-02 - arquivo criado
#---------------------------------------------------------------------
# Opções	: make run - compila tudo
#		: make clean - remove objetos e executável
#---------------------------------------------------------------------

CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/func.o $(OBJ)/tempo.o 
HDRS = $(INC)/func.h $(INC)/msgassert.h $(INC)/tempo.h
CFLAGS = -Wall -c -I$(INC)

EXE = $(BIN)/main

run:  $(EXE)
	$(EXE) -a -n 5
	$(EXE) -b -n 5
	$(EXE) -c -n 5
	$(EXE) -d -n 5


$(BIN)/main: $(OBJS)
	$(CC) -pg -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.c
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.c 

$(OBJ)/func.o: $(HDRS) $(SRC)/func.c
	$(CC) $(CFLAGS) -o $(OBJ)/func.o $(SRC)/func.c 

$(OBJ)/tempo.o: $(HDRS) $(SRC)/tempo.c
	$(CC) $(CFLAGS) -o $(OBJ)/tempo.o $(SRC)/tempo.c 	
clean:
	rm -f $(EXE) $(OBJS) gmon.out
