
#include <iostream>
#include "Populacao.hpp"
#include "Rainhas.hpp"

int main()
{
    Populacao p1;

    p1.geraPopulacao("entrada.txt");
    p1.showPopulacao();

    Rainhas r1{p1.getPopulacaoInt(), p1.getDimensao()};
    r1.preencheVetorColisoes();
    r1.defMelhorIndividuo();
    r1.defPiorIndividuo();

    std::cout << std::endl;

    r1.showVetorColisoes();
    r1.showInfo();

    // int maxColisoes[8] = {0,1,2,3,4,5,6,7};
    // int zeroColisoes[8] = {0,6,3,5,7,1,4,2};

    return 0;
}