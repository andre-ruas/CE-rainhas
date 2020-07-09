#include "Rainhas.hpp"

Rainhas::Rainhas(void **matriz, int dimensao, int tamPOP)
    : matriz{(int **)matriz}, dimensao{dimensao}, tamPOP{tamPOP}
{
    geraPopulacaoInicial();
}

Rainhas::~Rainhas()
{
    //desalocar as instancias de Individuos criadas.
}

void Rainhas::geraPopulacaoInicial()
{
    // preenche vetor populacao.
    for (int i = 0; i < this->tamPOP; i++)
    {
        Individuo *rainha{new Individuo{this->matriz[i], this->dimensao}};
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
    std::vector<Individuo *>::iterator it;
    for (it = this->populacao.begin(); it != this->populacao.end(); it++)
    {
        (*it)->showGenes();
    }
    std::cout << std::endl;
}

void Rainhas::showFitnessPop()
{
    std::vector<Individuo *>::iterator it;

    for (it = this->populacao.begin(); it != this->populacao.end(); it++)
    {
        std::cout << (*it)->getFitness() << " ";
    }
    std::cout << std::endl;
}

void Rainhas::selecaoNatural()
{
    float maxFitness = (this->dimensao) * (this->dimensao - 1);
    this->populacaoIntermediaria.clear(); //zera a pop intermediaria

    for (int i = 0; i < (int)this->populacao.size(); i++)
    {
        float fitness = populacao[i]->getFitness() / maxFitness;
         
        int nrElementos = floor(fitness * 100); //(Método de Selecao Proporcional)
        /* 
            Obs:
            Valores de fitness muito semelhantes, a inserção na populacao intermediaria
            nao esta proporcional ao valor da fitness

            int nrElementos;
            if (populacao[i]->getFitness() > floor(maxFitness * 0.97))
            {
                nrElementos = floor(fitness * 500);
            }
            else
            {
                nrElementos = floor(fitness * 50);
            }
        */
        for (int j = 0; j < nrElementos; j++)
        {
            this->populacaoIntermediaria.push_back(this->populacao[i]);
        }
    }
}

void Rainhas::proxGeracao()
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, this->populacaoIntermediaria.size() - 1);

    for (int i = 0; i < (int)this->populacao.size(); i++)
    {
        int a = dist(mt);
        int b = dist(mt);
        Individuo *filho{this->populacaoIntermediaria[a]->crossOver(this->populacaoIntermediaria[b])}; // crossover
        filho->mutacao(probMutacao);
        this->populacao[i] = filho;
    }
    this->nrGeracoes++;
}

void Rainhas::cicloEvolutivo()
{
    // chamada sem elitismo
    this->calcFitness();
    this->avaliacao(); 
    this->selecaoNatural();
    this->proxGeracao();

    while (this->nrGeracoes < 1000)
    {
        this->calcFitness();
        this->showFitnessPop();
        //this->elitismo();
        this->avaliacao(); 
        this->selecaoNatural();
        this->proxGeracao();
    }

    this->graficoFitness();
}

void Rainhas::elitismo()
{
    std::vector<Individuo *>::iterator it = this->populacao.begin();

    std::vector<Individuo *>::iterator itPiorIndividuo = this->populacao.begin();

    for (; it != this->populacao.end(); it++)
    {
        if ((*it)->getFitness() < (*itPiorIndividuo)->getFitness())
        {
            itPiorIndividuo = it;
        }
    }
    this->populacao.erase(itPiorIndividuo);
    this->populacao.push_back(this->melhoresIndividuos.back());
}

// guarda o melhor individuo de cada iteração
void Rainhas::avaliacao()
{
    std::vector<Individuo *>::iterator it = this->populacao.begin();

    Individuo *melhorIndividuo{*it};

    for (; it != this->populacao.end(); it++)
    {
        if ((*it)->getFitness() > melhorIndividuo->getFitness())
        {
            melhorIndividuo = *it;
        }
    }
    this->melhoresIndividuos.push_back(melhorIndividuo);
}

void Rainhas::graficoFitness()
{
    std::ofstream outfile("saida.txt");

    std::vector<Individuo *>::iterator it = this->melhoresIndividuos.begin();
    int i = 1;
    for (; it != this->melhoresIndividuos.end(); it++)
    {
        outfile << (*it)->getFitness() << std::endl;
        i++;
    }

    outfile.close();

    gnuplot p;

    p("set term png");
    p("set output \"resultado.png\"");
    p("set style data line");
    //p("set yrange [0:300]");    //ajustar de acordo com a dimensao
    // p("set grid ytics mytics"); // draw lines for each ytics and mytics
    // p("set ytics 2");           // set the spacing for the mytics
    // p("set grid");
//    p("plot \"./saida.txt\" title \"Problema Rainhas\" lt 7 lc rgb \"black\" w lp");
    p("plot \"./saida.txt\" title \"Problema Rainhas\" lw 3 ");
}
