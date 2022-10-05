#include "PessoaJuridica.hpp"

PJ::PJ()
{
    this->prox = NULL;
}

PJ::PJ(string cnpj, string nome, string endereco) : Pessoa(nome, endereco)
{
    this->cnpj = cnpj;
    this->prox = NULL;
    this->printed=false;
}

void PJ::setCnpj(string cnpj)
{
    this->cnpj = cnpj;
}

string PJ::getCnpj()
{
    return this->cnpj;
}

void PJ::imprimirPJ()
{
    imprimir();
    cout << "CNPJ: " << cnpj << endl;
}

void PJ::setProx(PJ *novo)
{
    this->prox = novo;
}

PJ *PJ::getProx()
{
    return this->prox;
}