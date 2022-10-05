#ifndef LISTAPF_HPP
#define LISTAPF_HPP

#include "PessoaFisica.hpp"

class ListaPF
{
private:
    PF *cabecaLPF;
    PF *caudaLPF;

public:
    ListaPF();

    virtual ~ListaPF();

    bool vazio();

    void inserir_final(string cpf,string nome,string endereco);

    int size();

    bool existe(string cpf);

    void imprimirLPF();

    void cadPJ(string cpf,string cnpj,string nome,string endereco);

    void associarPJ(string cpf, string cnpj);

    void imprimirListasPJ();

    void imprimirAssociacoes();
};
#endif