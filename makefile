parametrosCompilacao=-Wall #-Wshadow

all: rainhas

rainhas: main.o Arquivo.o PopulacaoInicial.hpp Rainhas.o Individuo.o
	g++ -o rainhas main.o Arquivo.o PopulacaoInicial.hpp Rainhas.o Individuo.o $(parametrosCompilacao) 

main.o: main.cpp
	g++ -c main.cpp $(parametrosCompilacao)

Arquivo.o: Arquivo.hpp Arquivo.cpp
	g++ -c Arquivo.cpp $(parametrosCompilacao)

Rainhas.o: Rainhas.hpp Rainhas.cpp
	g++ -c Rainhas.cpp $(parametrosCompilacao)

Individuo.o: Individuo.hpp Individuo.cpp
	g++ -c Individuo.cpp $(parametrosCompilacao)

clean:
	rm -f *.o *.gch rainhas