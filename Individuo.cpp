#include "Individuo.hpp"



 Individuo::Individuo(int* vetorGenes, int dimensao) : dimensao{dimensao}
 {
     for (int i = 0; i < dimensao; i++)
     {
         this->genes.push_back(vetorGenes[i]);
     }
 }

Individuo::~Individuo()
{

}

int Individuo::getFitness()
{
    return this->fitness;
}

void Individuo::calcFitness()
{
     int valorMax, colisoes = 0;

    for (int i = 0; i < this->dimensao; i++)
    {
        for (int j = 0; j < this->dimensao; j++)
        {

            if (abs(i - j) == abs(this->genes[i] - this->genes[j]) && i != j)
            {
                colisoes++;
            }
        }
    }

    valorMax = this->dimensao * (this->dimensao -1);

    this->fitness = valorMax - colisoes;

}

void Individuo::showGenes()
{
    std::vector<int> :: iterator it = this->genes.begin();
    for (; it != this->genes.end(); it++)
    {
        std::cout << " "<< *it;
    }
    
    std::cout << std::endl;
}