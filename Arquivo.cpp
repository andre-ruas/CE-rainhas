#include "Arquivo.hpp"
#include <fstream>
#include <string>

Arquivo::Arquivo(const std::string& arq): arq{arq}
{
    if (!geraPopulacao())
    {
        exit(1);
    }
    
}
Arquivo::~Arquivo()
{
    
}

void** Arquivo::getMatrizInicial()
{   
    return this->matriz;
}



bool Arquivo::geraPopulacao()
{
    std::ifstream file(this->arq);

    if (!file)
    {
        return false;
    }

    std::string arquivo;

    std::string limite = "=";
    size_t pos = 0;
    int flag = 0;

    int limiteInf_int, limiteSup_int;
    float limiteInf_float, limiteSup_float;


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
                    //this->limiteInfReal = std::stoi(arquivo);

                    limiteInf_float = std::stoi(arquivo);
                }
                else
                {
                    //this->limiteInfInt = std::stoi(arquivo);

                    limiteInf_int = std::stoi(arquivo);
                }
            }
            else
            {
                arquivo.erase(0, pos + limite.length());
                if (this->cod == "float")
                {
                    // this->limiteSupReal = std::stoi(arquivo);
                    limiteSup_float = std::stoi(arquivo);
                }
                else
                {
                    // this->limiteSupInt = std::stoi(arquivo);
                    limiteSup_int = std::stoi(arquivo);
                }
            }
        }

        flag++;
    }

    if (this->cod == "bin")
    {
        PopulacaoInicial<int>* popInicial{new PopulacaoInicial<int>};
        this->matriz = (void**) popInicial->geraPopulacaoBinaria(this->tamPop, this->tamCromossomo);
        delete popInicial;
    }
    else if (this->cod == "int-perm")
    {
        PopulacaoInicial<int>* popInicial{new PopulacaoInicial<int>};
        this->matriz = (void**) popInicial->geraPopulacaoPerm(this->tamPop, this->tamCromossomo);
        delete popInicial;
    }
    else if (this->cod == "int")
    {
        PopulacaoInicial<int>* popInicial{new PopulacaoInicial<int>};
        this->matriz = (void**) popInicial->geraPopulacao(this->tamPop, this->tamCromossomo, limiteInf_int, limiteSup_int);
        delete popInicial;
    }
    else if (this->cod == "float")
    {
        this->flagInt = 0;
        PopulacaoInicial<float>* popInicial{new PopulacaoInicial<float>};
        this->matriz = (void**) popInicial->geraPopulacao(this->tamPop, this->tamCromossomo, limiteInf_float, limiteSup_float);
        delete popInicial;
    }
    else
    {
        std::cerr << "Codificacao invalida" << std::endl;
        return false;
    }

    return true;
}


const int Arquivo::getTamDNA()const
{
    return this->tamCromossomo;
}

const int Arquivo::getTamPOP()const
{
    return this->tamPop;
}