CFLAGS=-Wall -std=c++11 -pthread
BIN=parser
CC=g++
RM=rm -f

ALL: parser

parser: list.o vlakno.o tab/lrtab.o tab/lrtab_b.o redukce.o scanner.o parser.o main.o 
	$(CC) $(CFLAGS) -o $(BIN) list.o vlakno.o tab/lrtab.o tab/lrtab_b.o redukce.o scanner.o parser.o main.o

clean:
	$(RM) *.o $(BIN)
	
main.o: main.cpp
	g++ -std=c++11 -pthread -c -o main.o main.cpp
parser.o: parser.cpp
	g++ -std=c++11 -pthread -c -o parser.o parser.cpp