#include <iostream>
#include "Pilha.hpp"
//#include "Pilha.cpp"

namespace PLH = Pilha;

int Menu(int Opcao = 5)
{
    do
    {

        std::cout << "\n\n 1 - Empilhar";
        std::cout << "\n 2 - Desempilhar";
        std::cout << "\n 3 - Verificar Tamanho da Pilha";
        std::cout << "\n 4 - Imprimir Itens da Pilha";
        std::cout << "\n 0 - Sair\n\n";

        std::cout << "Escolha uma opção [0-1-2-3-4]: ";

        setbuf(stdin, NULL);
        std::cin >> Opcao;

    } while ((Opcao < 0) || (Opcao > 4));

    return Opcao;
}

int main()
{
    /**
    std::string nome[10]={"eu","nós","vós","eles"};
    std::cout<<nome[3]<<std::endl;
    */

    PLH::Pilha p;

    int Opcao;

    Opcao = Menu();

    while (Opcao != 0)
    {
        switch (Opcao)
        {
        case 1:
            p.empilhar();
            break;

        case 2:
            p.desempilhar();
            break;
        
        case 3:
            std::cout<<"Quantidade de elementos: "<<p.tamanho_pilha()<<std::endl;
            break;

        case 4:
            p.imprime_Pilha();
            break;
       
        default:
            break;
        }
        Opcao = Menu();
    }

    return 0;
}