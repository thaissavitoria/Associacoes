#include "ListaPF.hpp"

ListaPF::ListaPF()
{
    cabecaLPF = NULL;
    caudaLPF = NULL;
}

ListaPF::~ListaPF()
{
    delete cabecaLPF;
}

bool ListaPF::vazio()
{
    return (cabecaLPF == NULL);
}

void ListaPF::inserir_final(string cpf, string nome, string endereco)
{
    PF *nova_PF = new PF(cpf, nome, endereco);

    if (vazio())
    {
        cabecaLPF = nova_PF;
        caudaLPF = nova_PF;
    }
    else
    {
        caudaLPF->setProx(nova_PF);
        caudaLPF = nova_PF;
    }
}

int ListaPF::size()
{
    if (vazio())
        return 0;

    PF *p = cabecaLPF;
    int tam = 0;

    do
    {
        p = p->getProx();
        tam++;
    } while (p);

    return tam;
}

bool ListaPF::existe(string cpf)
{
    PF *pd = cabecaLPF;

    while (pd)
    {
        if (pd->getCpf() == cpf)
        {
            cout << "PESSOA FISICA ENCONTRADA:" << endl;
            pd->imprimirPF();
            return true;
        }
        pd = pd->getProx();
    }

    cout << "PESSOA FISICA NÃO ENCONTRADA!" << endl;
    return false;
}

void ListaPF::imprimirLPF()
{
    cout << ".......Imprimindo Lista de Pessoas Físicas........" << endl;

    if (vazio())
        cout << "Lista de Pessoas Físicas NÃO possui pessoas Físicas!" << endl;

    PF *pd = cabecaLPF;

    while (pd)
    {
        pd->imprimirPF();
        pd = pd->getProx();
    }
}

void ListaPF::cadPJ(string cpf, string cnpj, string nome, string endereco)
{
    PF *aux = cabecaLPF;

    while (aux)
    {
        if (aux->getCpf() == cpf)
        {
            aux->puxarParaLPJ(cnpj, nome, endereco);
            break;
        }
        aux = aux->getProx();
    }
}

void ListaPF::associarPJ(string cpf, string cnpj)
{
    PF *aux = cabecaLPF;
    PJ *pjaux;
    bool control = false;

    while (aux && control == false)
    {
        if (!aux->listaVazia())
        {
            if (aux->existePJ(cnpj))
            {
                pjaux = aux->getPJ(cnpj);
                control = true;
                break;
            }
        }
        aux = aux->getProx();
    }

    aux = cabecaLPF;

    if (control)
    {
        while (aux)
        {
            if (aux->getCpf() == cpf)
            {
                aux->imprimirPF();
                aux->associarPJ2(pjaux);
                break;
            }
            aux = aux->getProx();
        }
    }
    else
    {
        cout << "Pessoa Jurídica não cadastrada" << endl;
    }
}

void ListaPF::imprimirListasPJ()
{
    PF *aux = cabecaLPF;
    bool control = false;

    while (aux)
    {
        if (!aux->listaVazia())
        {
            aux->imprimirLista();
            control = true;
        }
        aux = aux->getProx();
    }

    if (!control)
    {
        cout << "Não há Pessoa Jurídicas Cadastradas!" << endl;
    }
    else
    {
        aux = cabecaLPF;

        while (aux)
        {
            aux->voltarFalse();
            aux = aux->getProx();
        }
    }
}

void ListaPF::imprimirAssociacoes()
{
    PF *aux = cabecaLPF;
    bool control = false;

    while (aux)
    {
        if (!aux->listaVazia())
        {
            aux->imprimirAssociacoes();
            control = true;
            cout << endl;
        }
        aux = aux->getProx();
    }

    if (!control)
    {
        cout << "Não há Associações!" << endl;
    }
}