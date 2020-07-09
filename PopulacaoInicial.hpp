#ifndef POPULACAOINICIAL_HPP
#define POPULACAOINICIAL_HPP

#include <string>
#include <ctime> 
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <random>

template <typename T>

class PopulacaoInicial{

    friend class Arquivo;

    private:

        T** matriz{nullptr};

        PopulacaoInicial()
        {
            
        }
        ~PopulacaoInicial()
        {
            // std::cerr << "Populacao Inicial Destruida" << std::endl;
        }

        int** geraPopulacaoBinaria(int tamPop, int tamCromossomo)
        {

            matriz = new int* [tamPop];

            for (int i = 0; i < tamPop; i++)
            {
                matriz[i] = new int[tamCromossomo];
            }
            

            srand((unsigned) time(NULL));

            for (int i = 0; i < tamPop; i++)
            {
                for (int j = 0; j < tamCromossomo; j++)
                {
                    matriz[i][j] = rand()%2;
                }
                
            }
            
            return matriz;
        }
        T** geraPopulacao(int tamPop, int tamCromossomo, T limiteMin, T limiteMax)
        {
            matriz = new T* [tamPop];

            for (int i = 0; i < tamPop; i++)
            {
                matriz[i] = new T[tamCromossomo];
            }

            srand((unsigned) time(NULL));

            for (int i = 0; i < tamPop; i++)
            {
                for (int j = 0; j < tamCromossomo; j++)
                {
                    matriz[i][j] = (limiteMin + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(limiteMax-limiteMin+1))));
                }
                
            }

            return matriz;

        }
        int** geraPopulacaoPerm(int tamPop, int tamCromossomo)
        {
            
            srand((unsigned) time(NULL));
            matriz = new int* [tamPop];

            for (int i = 0; i < tamPop; i++)
            {
                matriz[i] = new int[tamCromossomo];
            }

    
            for (int i = 0; i < tamPop; i++)
            {
                for (int j = 0; j < tamCromossomo; j++)
                {
                    matriz[i][j] = j;
                } 
                
            }

            for (int i = 0; i < tamPop; i++)
            {
                std::random_shuffle(matriz[i],matriz[i]+tamCromossomo);
            }

            return matriz;
        }
        
};



#endif

