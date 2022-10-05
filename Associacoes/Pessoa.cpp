#include "Pessoa.hpp"

Pessoa::Pessoa()
{}

Pessoa::Pessoa(string nome,string endereco)
{
    this->endereco=endereco;
    this->nome=nome;
}

void Pessoa::setNome(string nome)
{
    this-> nome=nome;
}

void Pessoa::setEndereco(string endereco)
{
    this->endereco=endereco;
}

string Pessoa::getEndereco()
{
    return this->endereco;
}

string Pessoa::getNome()
{
    return this->nome;
}

void Pessoa::imprimir()
{
    cout<<"NOME: "<<nome<<endl;
    cout<<"ENDERECO: "<<endereco<<endl;
}