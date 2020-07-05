#include "Rainhas.hpp"

Rainhas::Rainhas(void** matriz, int dimensao, int tamPOP)
    :matriz{(int**) matriz}, dimensao{dimensao}, tamPOP{tamPOP}
{
    geraPopulacaoInicial();
}

Rainhas::~Rainhas()
{
    //desalocar as instancias de Individuo criadas.
}

void Rainhas::geraPopulacaoInicial()
{
    // preenche vetor populacao.
    for (int i = 0; i < this->tamPOP; i++)
    {
        Individuo* rainha{new Individuo{this->matriz[i], this->dimensao}};
        this->populacao.push_back(rainha);
    }
    
}

void Rainhas::calcFitness()
{
    for (int i = 0; i < this->tamPOP; i++)
    {
        this->populacao[i]->calcFitness();
    }
}

void Rainhas::showPopulacao()
{
    std::vector<Individuo*> :: iterator it;

    for (it = this->populacao.begin(); it != this->populacao.end(); it++)
    { 
        (*it)->showGenes();
    }

    std::cout << std::endl;
}

void Rainhas::showFitnessPop()
{
    std::vector<Individuo*> :: iterator it;

    for (it = this->populacao.begin(); it != this->populacao.end(); it++)
    { 
        std::cout << (*it)->getFitness() << " ";
    }
    std::cout << std::endl;
}




// retorna a qtd de colisoes do individuo
// int Rainhas::qtdColisoes(int *individuo)
// {
//     int colisoes = 0;
//     for (int i = 0; i < this->dimensao; i++)
//     {
//         for (int j = 0; j < this->dimensao; j++)
//         {

//             if (abs(i - j) == abs(individuo[i] - individuo[j]) && i != j)
//             {
//                 colisoes++;
//             }
//         }
//     }
//     return colisoes;
// }





