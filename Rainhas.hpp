#ifndef RAINHAS_HPP
#define RAINHAS_HPP

#include <string>
#include <iostream>
#include <vector>
#include <math.h>
#include <random>
#include <iomanip>
#include <fstream> 
#include <time.h>

#include "gnuplot.h"
#include "Individuo.hpp"
#include "Selecao.hpp"

class Rainhas{

    public:

        Rainhas(void** matriz, int dimensao, int tamPOP,
        int defSelecao, int nrExecucoes, int nrGeracoes, bool temElitismo);
        ~Rainhas();

        void cicloEvolutivo();
        void showPopulacao();

    private:

        void geraPopulacaoInicial();
        void calcFitness();
        void selecaoNatural(); // conjunto dos individuos com as quantidades baseadas na funcao fitness  (Método de Selecao Proporcional)
        void proxGeracao();  // cria a geracao seguinte (aplica crossover e mutacao)
        void avaliacao();
        void graficoFitness();
        void elitismo();
        void armazenaTodaPOP();

        int** matriz;
        int dimensao, tamPOP, defSelecao, nrExecucoes, nrGeracoes;
        bool temElitismo;

        float probMutacao = 0.02;

        std::vector<Individuo*> populacao;
        std::vector<Individuo*> melhoresIndividuos; 
        std::vector<Individuo*> allPOP; // conjunto de individuos repetidos com base nas suas fitness
        Individuo* piorIndividuo{nullptr};
};

#endif
