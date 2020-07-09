#include <iostream>
#include "Arquivo.hpp"
#include "Rainhas.hpp"

int main()
{
    Arquivo arq{"entrada.txt"};

    Rainhas r1{arq.getMatrizInicial(), arq.getTamDNA(), arq.getTamPOP()};
  
    r1.cicloEvolutivo();
    // int maxColisoes[8] = {0,1,2,3,4,5,6,7}; 
    // int zeroColisoes[8] = {0,6,3,5,7,1,4,2};
    return 0;
}
