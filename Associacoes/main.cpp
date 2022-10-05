#include "ListaPF.hpp"

int main()
{
    string nome, endereco, cpf, cnpj;
    int op;

    ListaPF *lpf = new ListaPF();

    do
    {
        cout << "\n\n\tEscolha uma opção:" << endl;
        cout << "1. Cadastrar uma Pessoa Física;" << endl;
        cout << "2. Cadastrar uma Pessoa Jurídica;" << endl;
        cout << "3. Associar uma Pessoa Física a uma Pessoa Jurídica;" << endl;
        cout << "4. Imprimir a lista de Pessoas Físicas cadastradas;" << endl;
        cout << "5. Imprimir a lista de Pessoas Jurídicas cadastradas;" << endl;
        cout << "6. Imprimir a lista de associações;" << endl;
        cout << "0. Sair;" << endl;

        cin >> op;

        switch (op)
        {
        case 1:
            cout << "\nInsira o nome da Pessoa Física:" << endl;
            cin.ignore();
            getline(cin, nome);

            cout << "\nInsira o endereco da Pessoa Física:" << endl;
            getline(cin, endereco);

            cout << "\nInsira o cpf da Pessoa Física:" << endl;
            getline(cin, cpf);

            lpf->inserir_final(cpf, nome, endereco);
            break;

        case 2:
            if (lpf->vazio())
            {
                cout << "Não há como cadastrar uma Pessoa jurídica pois não há pessoas físicas cadastradas" << endl;
                break;
            }

            cout << "\nInsira o cpf da Pessoa Física a qual a nova Pessoa Jurídica será associada:" << endl;
            cin.ignore();
            getline(cin, cpf);

            if (lpf->existe(cpf))
            {
                cout << "\nInsira o nome da Pessoa Jurídica:" << endl;
                getline(cin, nome);

                cout << "\nInsira o endereco da Pessoa Jurídica:" << endl;
                getline(cin, endereco);

                cout << "\nInsira o cnpj da Pessoa Jurídica:" << endl;
                getline(cin, cnpj);

                lpf->cadPJ(cpf, cnpj, nome, endereco);
            }
            else
            {
                cout << "Pessoa Física não cadastrada!" << endl;
            }

            break;

        case 3:
            if (lpf->vazio())
            {
                cout << "Não há como associar uma Pessoa jurídica pois não há pessoas físicas cadastradas" << endl;
            }
            else
            {
                cout << "\nInsira o cpf da Pessoa Física a qual a Pessoa Jurídica será associada:" << endl;
                cin.ignore();
                getline(cin, cpf);

                if (lpf->existe(cpf))
                {
                    cout << "Insira o cnpj ao qual deseja associar a essa Pessoa fisica:" << endl;
                    getline(cin, cnpj);

                    lpf->associarPJ(cpf, cnpj);
                }
                else
                {
                    cout << "Pessoa Física não cadastrada!" << endl;
                }
            }
            break;

        case 4:
            lpf->imprimirLPF();
            break;

        case 5:
            lpf->imprimirListasPJ();
            break;

        case 6:
            lpf->imprimirAssociacoes();
            break;

        case 0:
            break;
        default:
            break;
        }

    } while (op != 0);

    return 0;
}