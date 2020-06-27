parametrosCompilacao=-Wall #-Wshadow

all: rainhas

rainhas: main.o Populacao.o PopulacaoInicial.hpp Rainhas.o
	g++ -o rainhas main.o Populacao.o PopulacaoInicial.hpp Rainhas.o $(parametrosCompilacao) 

main.o: main.cpp
	g++ -c main.cpp $(parametrosCompilacao)

Populacao.o: Populacao.hpp Populacao.cpp
	g++ -c Populacao.cpp $(parametrosCompilacao)

Rainhas.o: Rainhas.hpp Rainhas.cpp
	g++ -c Rainhas.cpp $(parametrosCompilacao)


clean:
	rm -f *.o *.gch rainhas