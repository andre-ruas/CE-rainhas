#ifndef INDIVIDUO_HPP
#define INDIVIDUO_HPP

#include <iostream>
#include <vector>

class Individuo{

    public:
            Individuo(int* vetorGenes, int dimensao);
            ~Individuo();

            void calcFitness();
            int getFitness();
            void showGenes();

    private:
        std::vector<int> genes;
        int fitness, dimensao;

};

#endif






