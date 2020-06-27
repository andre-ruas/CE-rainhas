#include "Populacao.hpp"
#include <fstream>
#include <string>

Populacao::Populacao()
{
}
Populacao::~Populacao()
{
    
}

void Populacao::geraPopulacao(std::string arqOriginal)
{
    // posteriormente fazer a extracao dos valores do arquivo em outra func privada
    std::ifstream file(arqOriginal);

    if (!file)
    {
        std::cerr << "Não foi possivel abrir o arquivo" << std::endl;
        exit(1);
    }

    std::string arquivo;

    std::string limite = "=";
    size_t pos = 0;
    int flag = 0;

    while (!file.eof())
    {
        file >> arquivo;

        while ((pos = arquivo.find(limite)) != std::string::npos)
        {
            if (flag == 0)
            {
                arquivo.erase(0, pos + limite.length());
                this->cod = arquivo;
            }
            else if (flag == 1)
            {
                arquivo.erase(0, pos + limite.length());
                this->tamPop = std::stoi(arquivo);
            }
            else if (flag == 2)
            {
                arquivo.erase(0, pos + limite.length());
                this->tamCromossomo = std::stoi(arquivo);
            }
            else if (flag == 3)
            {
                arquivo.erase(0, pos + limite.length());
                if (this->cod == "float")
                {
                    this->limiteInfReal = std::stoi(arquivo);
                }
                else
                {
                    this->limiteInfInt = std::stoi(arquivo);
                }
            }
            else
            {
                arquivo.erase(0, pos + limite.length());
                if (this->cod == "float")
                {
                    this->limiteSupReal = std::stoi(arquivo);
                }
                else
                {
                    this->limiteSupInt = std::stoi(arquivo);
                }
            }
        }

        flag++;
    }

    if (this->cod == "bin")
    {
        PopulacaoInicial<int>* popInicial{new PopulacaoInicial<int>};
        this->matrizInt = popInicial->geraPopulacaoBinaria(this->tamPop, this->tamCromossomo);
        delete popInicial;
    }
    else if (this->cod == "int-perm")
    {
        PopulacaoInicial<int>* popInicial{new PopulacaoInicial<int>};
        this->matrizInt = popInicial->geraPopulacaoPerm(this->tamPop, this->tamCromossomo);
        delete popInicial;
    }
    else if (this->cod == "int")
    {
        PopulacaoInicial<int>* popInicial{new PopulacaoInicial<int>};
        this->matrizInt = popInicial->geraPopulacao(this->tamPop, this->tamCromossomo, this->limiteInfInt, this->limiteSupInt);
        delete popInicial;
    }
    else if (this->cod == "float")
    {
        PopulacaoInicial<float>* popInicial{new PopulacaoInicial<float>};
        this->matrizFloat = popInicial->geraPopulacao(this->tamPop, this->tamCromossomo, this->limiteInfReal, this->limiteSupReal);
        delete popInicial;
    }
    else
    {
        std::cerr << "Codificacao invalida" << std::endl;
        exit(1);
    }
}

int** Populacao::getPopulacaoInt()
{
    return this->matrizInt;
}
float** Populacao::getPopulacaoFloat()
{
   return this->matrizFloat;
}

void Populacao::showPopulacao()
{
    if (this->matrizInt == nullptr)
    {
        showPopulacaoFloat();
        return;
    }
    
    for (int i = 0; i < this->tamPop ; i++)
    {
        std::cout << i << " - ";

        for (int j = 0; j < this->tamCromossomo; j++)
        {
            std::cout << matrizInt[i][j] << " ";
        }

       std::cout << std::endl;     
    }
    

}

void Populacao::showPopulacaoFloat()
{
     for (int i = 0; i < this->tamPop ; i++)
    {
        for (int j = 0; j < this->tamCromossomo; j++)
        {
            std::cout << matrizFloat[i][j] << " ";
        }

       std::cout << std::endl;     
    }

}

const int Populacao::getDimensao()const
{
    return this->tamCromossomo;
}

const int Populacao::getTamPop()const
{
    return this->tamPop;
}