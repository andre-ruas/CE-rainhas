#ifndef INDIVIDUO_HPP
#define INDIVIDUO_HPP

#include <iostream>
#include <vector>
#include <random>
#include <time.h>

class Individuo{

    public:
            Individuo(int* vetorGenes, int dimensao);
            ~Individuo();

            void calcFitness();
            Individuo* crossOver(Individuo* b);
            void mutacao(float probMutacao);

            int getFitness();
            void showGenes();

    private:
        std::vector<int> genes;
        int fitness, dimensao;

};

#endif






