#include "Individuo.hpp"

Individuo::Individuo(int *vetorGenes, int dimensao) : dimensao{dimensao}
{
    for (int i = 0; i < dimensao; i++)
    {
        this->genes.push_back(vetorGenes[i]);
    }
}

Individuo::~Individuo()
{
}

float Individuo::getFitness()
{
    return this->fitness;
}

void Individuo::calcFitness()
{
    float valorMax;
    int colisoes = 0;

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

    valorMax = this->dimensao * (this->dimensao - 1);

    this->fitness = (valorMax - colisoes) / valorMax;

    this->colisoes = colisoes;
}

void Individuo::showGenes()
{
    std::vector<int>::iterator it = this->genes.begin();
    for (; it != this->genes.end(); it++)
    {
        std::cout << " " << *it;
    }
    std::cout << " -> F: "<< this->fitness << " C: " << this->colisoes << std::endl;
}

Individuo *Individuo::crossOver(Individuo *b)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    
    int *vetorGenes{new int[this->dimensao]};

    // corte no DNA
    std::uniform_int_distribution<int> dist (0,this->genes.size() - 2);
    int esq = dist(mt);
    std::uniform_int_distribution<int> d1 ( esq+1, (this->genes.size()));
    int dir = d1(mt);

    int j = 0;
    for (int i = esq; i < dir; i++)
    {
        vetorGenes[j] = this->genes[i];
        j++;
    }
    
    int flag;
    for (int i = 0; i < (int) b->genes.size(); i++)
    {
        flag = 0;

        for (int k = 0; k < j; k++)
        {
            if (b->genes[i] == vetorGenes[k])
            {
                flag = 1;
            }   
        }
        if (flag != 1 && j < this->dimensao)
        {
            vetorGenes[j] = b->genes[i];
            j++;
        }
    }

    Individuo *filho{new Individuo{vetorGenes, this->dimensao}};

    return filho;
}

void Individuo::mutacao(float probMutacao)
{

    for (int i = 0; i < (int) this->genes.size(); i++)
    {
        int aleatorio = rand() % 101;

        if ( aleatorio < probMutacao*100)
        {
            int a = rand() % this->genes.size();
            int b = rand() % this->genes.size();

            int aux = this->genes[a];
            this->genes[a] = this->genes[b];
            this->genes[b] = aux;
        }
    }
}