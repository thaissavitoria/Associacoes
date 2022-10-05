#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <iostream>
#include <string>

using namespace std;

class Pessoa
{
private:
    string nome;
    string endereco;

public:
    Pessoa();
    Pessoa(string nome, string endereco);

    void setNome(string nome);
    string getNome();

    void setEndereco(string endereco);
    string getEndereco();

    void imprimir();
};
#endif