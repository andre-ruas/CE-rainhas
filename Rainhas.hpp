#ifndef RAINHAS_HPP
#define RAINHAS_HPP

#include <string>
#include <iostream>
#include <vector>
#include <math.h>
#include <random>
#include <fstream> 
#include <time.h>

#include "gnuplot.h"
#include "Individuo.hpp"

class Rainhas{

    public:

        Rainhas(void** matriz, int dimensao, int tamPOP);
        ~Rainhas();

        void cicloEvolutivo();
        void showPopulacao();

    private:

        void geraPopulacaoInicial();
        void calcFitness();
        void selecaoNatural(); // conjunto dos individuos com as quantidades baseadas na funcao fitness  (Método de Selecao Proporcional)
        void proxGeracao();  // cria a geracao seguinte (aplica crossover e mutacao)
        void showFitnessPop();
        void avaliacao();
        void graficoFitness();
        void elitismo();

        int** matriz;
        int dimensao, tamPOP , nrGeracoes = 0;
        std::vector<Individuo*> populacao;
        float probMutacao = 0.03;

        std::vector<Individuo*> populacaoIntermediaria; // conjunto de individuos repetidos com base nas suas fitness

        std::vector<Individuo*> melhoresIndividuos; 
};

#endif
