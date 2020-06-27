#ifndef POPULACAO_HPP
#define POPULACAO_HPP

#include <iostream>
#include <string>
#include "PopulacaoInicial.hpp"

class Populacao{

    public:

        Populacao();
        ~Populacao();

        void geraPopulacao(std::string arqOriginal);
        int** getPopulacaoInt();
        const int getDimensao()const;
        const int getTamPop()const;
        float** getPopulacaoFloat();
        void showPopulacao();

    private:

        void showPopulacaoFloat();
        int tamPop, tamCromossomo, limiteInfInt{0},limiteSupInt{0};
        float limiteInfReal{0},limiteSupReal{0};
        std::string cod;
        int** matrizInt{nullptr};
        float** matrizFloat{nullptr};   
};



#endif

