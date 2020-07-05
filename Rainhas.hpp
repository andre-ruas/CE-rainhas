#ifndef RAINHAS_HPP
#define RAINHAS_HPP

#include <string>
#include <iostream>
#include <vector>
#include "Individuo.hpp"

class Rainhas{

    public:

        Rainhas(void** matriz, int dimensao, int tamPOP);
        ~Rainhas();

        void calcFitness();
        void showFitnessPop();
        void showPopulacao();

    private:

        void geraPopulacaoInicial();
        int** matriz;
        int dimensao, tamPOP;
        std::vector<Individuo*> populacao;
};

#endif






