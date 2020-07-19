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

            float getFitness();
            void showGenes();

    private:
        std::vector<int> genes;
        float fitness{0};
        int dimensao;

        int colisoes{0};

};

#endif






