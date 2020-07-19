#include "Rainhas.hpp"

Rainhas::Rainhas(void **matriz, int dimensao, int tamPOP,
                 int defSelecao, int nrExecucoes, int nrGeracoes, bool temElitismo)
    : matriz{(int **)matriz}, dimensao{dimensao}, tamPOP{tamPOP}, defSelecao{defSelecao},
      nrExecucoes{nrExecucoes}, nrGeracoes{nrGeracoes}, temElitismo{temElitismo}
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
    int i = 0;
    for (it = this->populacao.begin(); it != this->populacao.end(); it++)
    {
        std::cout << i << " - ";
        i++;
        (*it)->showGenes();
    }
    std::cout << std::endl;
}

void Rainhas::selecaoNatural()
{
    Selecao s1;
    this->populacao = s1.proxGeracao(this->populacao, this->defSelecao);
    proxGeracao();
}

//aplica crossover + mutacao
void Rainhas::proxGeracao()
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, this->populacao.size() - 1);

    for (int i = 0; i < (int)this->populacao.size(); i++)
    {
        int a = dist(mt);
        int b = dist(mt);
        Individuo *filho{this->populacao[a]->crossOver(this->populacao[b])}; // crossover
        filho->mutacao(probMutacao);
        this->populacao[i] = filho;
    }
}

void Rainhas::cicloEvolutivo()
{
    int i = 0;
    while (i < this->nrGeracoes)
    {
        calcFitness();
        //melhorar esse if :/
        if (this->temElitismo)
        {
            elitismo(); //-> remove o pior individuo e insere o melhor da geracao passada
        }
        avaliacao();
        armazenaTodaPOP(); // fins visuais
        // showPopulacao();
        selecaoNatural();
        //aplicar operadores genéticos.
        i++;
    }
    this->graficoFitness();
}

void Rainhas::armazenaTodaPOP()
{
    std::vector<Individuo *>::iterator it = this->populacao.begin();

    // remover posteriormente - guardando toda populacao para visualização
    for (it = this->populacao.begin(); it != this->populacao.end(); it++)
    {
        this->allPOP.push_back(*it);
    }
}
void Rainhas::elitismo()
{
    /*
    Preserva o melhor indivíduo para a próxima geração
    */
    if (this->melhoresIndividuos.size() == 0)
    {
        return;
    }
    std::vector<Individuo *>::iterator it = this->populacao.begin();
    this->piorIndividuo = *it;

    for (; it != this->populacao.end(); it++)
    {
        if ((*it)->getFitness() < this->piorIndividuo->getFitness())
        {
            this->piorIndividuo = *it;
        }
    }
    /* trocando o pior individuo da geracao atual 
            pelo melhor individuo da geracao anterior */
    it = this->populacao.begin();
    for (; it != this->populacao.end(); it++)
    {
        if (*it == this->piorIndividuo)
        {
            *it = *(this->melhoresIndividuos.end() - 1);
            break;
        }
    }
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
    // std::vector<Individuo *>::iterator it = this->allPOP.begin();

    for (; it != this->melhoresIndividuos.end(); it++)
    {
        outfile << std::fixed << std::setprecision(5) << (*it)->getFitness() << std::endl;
    }

    outfile.close();

    gnuplot p;

    p("set term png");
    p("set output \"resultado.png\"");
    // p("set style data line");
    p("set style data points");
    // p("set yrange [-.5:+.5]");    //ajustar de acordo com a dimensao
    // p("set grid ytics mytics"); // draw lines for each ytics and mytics
    // p("set ytics 2");           // set the spacing for the mytics
    // p("set grid");
    //    p("plot \"./saida.txt\" title \"Problema Rainhas\" lt 7 lc rgb \"black\" w lp");
    p("plot \"./saida.txt\" title \"Problema Maximizacao\" lw 3 pt 7 w lp");
}
