#ifndef PESSOAJURIDICA_HPP
#define PESSOAJURIDICA_HPP

#include "Pessoa.hpp"

class PJ:public Pessoa
{
    private:
    string cnpj;
    PJ* prox;
    

    public:
    PJ();
    PJ(string cnpj,string nome, string endereco);

    bool printed;

    void setCnpj(string cnpj);
    string getCnpj();

    void setProx(PJ* novo);
    PJ* getProx();

    void imprimirPJ();

};
#endif