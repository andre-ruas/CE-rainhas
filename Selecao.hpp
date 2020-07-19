#ifndef SELECAO_HPP
#define SELECAO_HPP

#include <string>
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

#include "Individuo.hpp"

class Selecao
{
public:
    Selecao()
    {
    }

    ~Selecao()
    {
    }

    std::vector<Individuo *> proxGeracao(std::vector<Individuo *> populacao, int tipo)
    {
        switch (tipo)
        {
        case 1:
            return this->roleta(populacao);
            break;
        case 2:
            return this->torneioEstocastico(populacao);
            break;
        case 3:
            return this->vizinhancaLinear(populacao);
            break;
        default:
            exit(1);
        }

        return {};
    }

private:
    std::vector<Individuo *> roleta(std::vector<Individuo *> populacao)
    {
        /*
            Roleta Sem Reposição. A cada par garante-se a não repetição de índices selecionados.
        */

        float fitnessPop = 0;
        std::vector<Individuo *>::iterator it = populacao.begin();
        for (; it != populacao.end(); it++)
        {
            fitnessPop += (*it)->getFitness();
        }

        std::vector<Individuo *> proxGeracao;
        std::vector<Individuo *>::iterator itProxGeracao;

        float aleatorio, somaParcial;
        size_t tam = populacao.size();
        // percorrer tam vezes (10)
        for (size_t i = 0; i < tam; i++)
        {
            aleatorio = static_cast<float>(rand()) / static_cast<float>(RAND_MAX / fitnessPop);
            somaParcial = 0;

            for (itProxGeracao = populacao.begin(); itProxGeracao != populacao.end(); itProxGeracao++)
            {
                // std::cerr << "1" << std::endl;
                somaParcial += (*itProxGeracao)->getFitness();
                if (somaParcial >= aleatorio)
                {
                    if (!proxGeracao.empty())
                    {
                        populacao.push_back(proxGeracao.back());
                        fitnessPop = fitnessPop + proxGeracao.back()->getFitness();
                        // std::cerr << "2" << std::endl;
                    }
                    proxGeracao.push_back(*itProxGeracao);
                    fitnessPop = fitnessPop - (*itProxGeracao)->getFitness();
                    populacao.erase(itProxGeracao);
                    // std::cerr << "3" << std::endl;
                    break;
                }
            }
            // std::cerr << "4" << std::endl;
        }

        return proxGeracao;
    }

    std::vector<Individuo *> torneioEstocastico(std::vector<Individuo *> populacao)
    {
        /*
    Torneio Estocástico. Parâmetros K e KP.
    */
        std::vector<Individuo *>::iterator it;
        std::vector<Individuo *> proxGeracao;
        float kp = 1;

        for (it = populacao.begin(); it != populacao.end(); it++)
        {
            int a = rand() % populacao.size();
            int b = rand() % populacao.size();

            if (kp >= (static_cast<float>(rand()) / static_cast<float>(RAND_MAX)))
            {
                if (populacao[a]->getFitness() >= populacao[b]->getFitness())
                {
                    //novaPopulacao[i] = populacao[a];
                    proxGeracao.push_back(populacao[a]);
                }
                else
                {
                    //novaPopulacao[i] = populacao[b];
                    proxGeracao.push_back(populacao[b]);
                }
            }
            else
            {
                if (populacao[a]->getFitness() <= populacao[b]->getFitness())
                {
                    //novaPopulacao[i] = populacao[a];
                    proxGeracao.push_back(populacao[a]);
                }
                else
                {
                    //novaPopulacao[i] = populacao[b];
                    proxGeracao.push_back(populacao[b]);
                }
            }
        }

        return proxGeracao;
    }

    std::vector<Individuo *> vizinhancaLinear(std::vector<Individuo *> populacao)
    {
        /*
            Vizinhança Linear (anel). Parâmetros D (Distância) e critério de seleção 
            dentro da vizinhança (melhor fitness, fitness proporcional, aleatório).
        */
        int distancia = 1;
        std::vector<Individuo*> proxGeracao;
        Individuo* melhorFitness;
        int total = (int) populacao.size();
        for (int i = 0; i < total; i++)
        {
            melhorFitness = populacao[i];
            for (int j = -distancia; j <= distancia; j++)
            {
                int pos = (i+j+total)%total;
                if (populacao[pos]->getFitness() > melhorFitness->getFitness())
                {
                    melhorFitness = populacao[pos];
                }
            }
            proxGeracao.push_back(melhorFitness);    
        }
        return proxGeracao;
    }
};
#endif
