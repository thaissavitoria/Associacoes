#include "PessoaFisica.hpp"

PF::PF()
{
    this->prox = NULL;
    this->lpj = new ListaPJ();
}

PF::PF(string cpf, string nome, string endereco) : Pessoa(nome, endereco)
{
    this->cpf = cpf;
    this->prox = NULL;
    this->lpj = new ListaPJ();
}

void PF::setCpf(string cpf)
{
    this->cpf = cpf;
}

string PF::getCpf()
{
    return this->cpf;
}

void PF::imprimirPF()
{
    imprimir();
    cout << "CPF: " << cpf << endl;
}

void PF::setProx(PF *novo)
{
    this->prox = novo;
}

PF *PF::getProx()
{
    return this->prox;
}

void PF::puxarParaLPJ(string cnpj, string nome, string endereco)
{
    this->lpj->inserir_final(cnpj, nome, endereco);
}

bool PF::existePJ(string cnpj)
{
    return this-> lpj->existe(cnpj);
}

PJ *PF::getPJ(string cnpj)
{
    PJ *pj = lpj->getCabeca();
    bool controle = false;

    while (pj && controle == false)
    {
        if (pj->getCnpj() == cnpj)
        {
            controle = true;
            break;
        }
        pj = pj->getProx();
    }

    pj->imprimirPJ();

    return pj;
}

void PF::associarPJ2(PJ *aux)
{
    this->lpj->adicionar(aux);
}

void PF::imprimirLista()
{
    this->lpj->imprimirLisPJ();
}

bool PF::listaVazia()
{
    return this->lpj->vazio();
}

void PF::imprimirAssociacoes()
{
    imprimirPF();

    cout << "ASSOCIACOES DE " << getNome() << endl;

    if (this->lpj->vazio())
    {
        cout << "Lista de Pessoas Jurídicas NÃO possui pessoas jurídicas!" << endl;
        return;
    }

    this->lpj->imprimirLPJ();
}

void PF::voltarFalse()
{
    lpj->voltarFalse();
}