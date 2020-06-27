#ifndef RAINHAS_HPP
#define RAINHAS_HPP

#include <string>
#include <iostream>
#include <vector>


class Rainhas{

    public:

        Rainhas();
        Rainhas(int** populacao, int dimensao);
        ~Rainhas();

        std::vector<int>& getVetorColisoes();
        void preencheVetorColisoes();
        void showInfo();
        void defMelhorIndividuo();
        void defPiorIndividuo();

        void showVetorColisoes();

        //futuramente privada
        int qtdColisoes(int* individuo);

    private:
        std::vector<int> vetorColisoes;
        int** populacao;
        int melhorIndividuo, piorIndividuo, dimensao;
        
};



#endif






