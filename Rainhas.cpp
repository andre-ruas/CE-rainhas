#include "Rainhas.hpp"

Rainhas::Rainhas()
{

}

Rainhas::Rainhas(int** populacao, int dimensao)
:populacao{populacao} , dimensao{dimensao}
{

}

Rainhas::~Rainhas()
{

}

void Rainhas::preencheVetorColisoes()
{
    for (int i = 0; i < this->dimensao; i++)
    {
        this->vetorColisoes.push_back(qtdColisoes(this->populacao[i]));
    }
}

void Rainhas::showVetorColisoes()
{
    std::vector<int>::iterator it = this->vetorColisoes.begin();
    for (; it != this->vetorColisoes.end(); it++)
    {
        std::cout << *it << " ";
    }

    std::cout << std::endl;
    
}

std::vector<int>& Rainhas::getVetorColisoes()
{
    return this->vetorColisoes;
}

void Rainhas::showInfo()
{
    std::cout << "Melhor Individuo: " << this->melhorIndividuo << std::endl;
    std::cout << "Pior Individuo: " << this->piorIndividuo << std::endl;
}

// o que tem menor numero de colisoes
void Rainhas::defMelhorIndividuo()
{
    int menor = this->vetorColisoes.front();
    int pos = 0;

    for (int i = 0; i < this->dimensao; i++)
    {
        if (this->vetorColisoes[i] < menor)
        {
            menor = this->vetorColisoes[i];
            pos = i;
        }
            
    }

    this->melhorIndividuo = pos;
}
void Rainhas::defPiorIndividuo()
{
    int maior = this->vetorColisoes.front();
    int pos = 0;

    for (int i = 0; i < this->dimensao; i++)
    {
        if (this->vetorColisoes[i] > maior)
        {
            maior = this->vetorColisoes[i];
            pos = i;
        }
    }

    this->piorIndividuo = pos;
}

// retorna a qtd de colisoes do individuo
int Rainhas::qtdColisoes(int *individuo)
{
    int colisoes = 0;
    for (int i = 0; i < this->dimensao; i++)
    {
        for (int j = 0; j < this->dimensao; j++)
        {

            if (abs(i-j) == abs(individuo[i] - individuo[j]) && i != j)
            {
                colisoes++;
            }
            
        }
        
    }
    return colisoes;
}