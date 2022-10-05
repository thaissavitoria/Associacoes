#ifndef LISTAPJ_HPP
#define LISTAPJ_HPP

#include "PessoaJuridica.hpp"

class ListaPJ
{
private:
    PJ* cabeca;
    PJ* cauda;

public:
    ListaPJ();

    virtual ~ListaPJ();

    bool vazio();

    void inserir_final(string cnpj,string nome,string endereco);

    int size();

    bool existe(string cnpj);

    void imprimirLPJ();

    void imprimirLisPJ();

    PJ* getCabeca();

    void adicionar(PJ* aux);

    void voltarFalse();
};
#endif