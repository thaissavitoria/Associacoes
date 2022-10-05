#ifndef PESSOAFISICA_HPP
#define PESSOAFISICA_HPP

#include "Pessoa.hpp"
#include "ListaPJ.hpp"

class PF : public Pessoa
{
private:
    string cpf;
    PF *prox;
    ListaPJ *lpj;

public:
    PF();
    PF(string cpf, string nome, string endereco);

    void setCpf(string cpf);
    string getCpf();

    void setProx(PF *novo);
    PF *getProx();

    void imprimirPF();

    void imprimirLista();

    bool existePJ(string cnpj);

    void puxarParaLPJ(string cnpj,string nome,string endereco);

    PJ* getPJ(string cnpj);

    void associarPJ2(PJ* aux);

    bool listaVazia();
    
    void imprimirAssociacoes();

    void voltarFalse();
};
#endif