#include <iostream>
#include <cstdlib>

#include "Pilha.cpp"

using namespace std;

int main()
{

    TipoPilha Pilha; /*Cria uma pilha*/
    TipoItem aux;
    int Opcao;

    InicializaPilhaVazia(&Pilha);

    Opcao = Menu();

    while (Opcao != 0)
    {
        switch (Opcao)
        {
        case 1:
            //cout << "Inserir Item";
            aux.Codigo = 1;
            cout << "\n\nDigite um elemento para ser inserido: ";

            setbuf(stdin, NULL);
            fgets(aux.Nome, 100, stdin);

            if (Empilhar(aux, &Pilha))
            {
                cout << "Elemento inserido" << endl;
            }
            else
            {
                cout << "ERRO" << endl;
            }

            break;

        case 2:
            if (Desempilhar(&Pilha, &aux))
            {
                cout << "Item foi removido da Pilha";
            }

            break;

        case 3:
            cout << "Quantidades de itens na pilha: " << TamanhoPilha(&Pilha);
            break;

        case 4:
            //cout << "\n\nconsulta\n\n";
            imprime_Pilha(&Pilha, &aux);
            break;

        default:
            break;
        }
        Opcao = Menu();
    }

    destroi_Pilha(&Pilha, &aux);

    return 0;
}
