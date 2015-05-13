CFLAGS=-Wall
BIN=parser
CC=g++
RM=rm -f

ALL: parser

parser: list.o vlakno.o tab/lrtab.o tab/lrtab_b.o redukce.o scanner.o parser.o main.o 
	$(CC) $(CFLAGS) -o $(BIN) list.o vlakno.o tab/lrtab.o tab/lrtab_b.o redukce.o scanner.o parser.o main.o

clean:
	$(RM) *.o $(BIN)