#include "ListaPJ.hpp"

ListaPJ::ListaPJ()
{
    cabeca = NULL;
    cauda = NULL;
}

ListaPJ::~ListaPJ()
{
    delete cabeca;
}

bool ListaPJ::vazio()
{
    return (cabeca == NULL);
}

void ListaPJ::inserir_final(string cnpj, string nome, string endereco)
{
    PJ *nova_pj = new PJ(cnpj, nome, endereco);

    if (vazio())
    {
        cabeca = nova_pj;
        cauda = nova_pj;
    }
    else
    {
        cauda->setProx(nova_pj);
        cauda = nova_pj;
    }
}

int ListaPJ::size()
{
    if (vazio())
        return 0;

    PJ *p = cabeca;
    int tam = 0;

    do
    {
        p = p->getProx();
        tam++;
    } while (p);

    return tam;
}

bool ListaPJ::existe(string cnpj)
{
    PJ *pd = cabeca;
    bool exis = false;

    while (pd)
    {
        if (pd->getCnpj() == cnpj)
        {
            cout << "PESSOA JURÍDICA ENCONTRADA:" << endl;
            pd->imprimirPJ();
            exis = true;
        }
        pd = pd->getProx();
    }

    if (exis)
        return exis;
    else
    {
        cout << "PESSOA JURÍDICA NÃO ENCONTRADA!" << endl;
        return exis;
    }
}

void ListaPJ::imprimirLisPJ()
{
    PJ *pd = cabeca;

    if (vazio())
        cout << "Lista de Pessoas Jurídicas NÃO possui pessoas jurídicas!" << endl;

    while (pd)
    {
        if (!pd->printed)
        {
            pd->imprimirPJ();
            pd->printed = true;
        }
        pd = pd->getProx();
        cout << endl;
    }
}

void ListaPJ::imprimirLPJ()
{
    PJ *pd = cabeca;

    if (vazio())
        cout << "Lista de Pessoas Jurídicas NÃO possui pessoas jurídicas!" << endl;

    while (pd)
    {
        pd->imprimirPJ();
        pd = pd->getProx();
        cout << endl;
    }
}

PJ *ListaPJ::getCabeca()
{
    return this->cabeca;
}

void ListaPJ::adicionar(PJ *aux)
{
    PJ *nova_pj = new PJ(aux->getCnpj(), aux->getNome(), aux->getEndereco());

    if (vazio())
    {
        cabeca = nova_pj;
        cauda = nova_pj;
    }
    else
    {
        cauda->setProx(nova_pj);
        cauda = nova_pj;
    }
}

void ListaPJ::voltarFalse()
{
    PJ *pd = cabeca;

    while (pd)
    {
        pd->printed = false;
        pd = pd->getProx();
        cout << endl;
    }
}