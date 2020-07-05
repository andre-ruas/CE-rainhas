#ifndef ARQUIVO_HPP
#define ARQUIVO_HPP

#include <iostream>
#include <string>
#include "PopulacaoInicial.hpp"

class Arquivo{

    public:

        Arquivo(const std::string& arq);
        ~Arquivo();

        void** getMatrizInicial();
        const int getTamDNA()const;
        const int getTamPOP()const;


    private:

        bool geraPopulacao();
        const std::string& arq;
        int tamPop, tamCromossomo;
        int flagInt = 1;
        std::string cod;
        void** matriz;
};



#endif

