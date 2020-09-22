#include <iostream>
#include "Pilha.hpp"

namespace Pilha
{

    Pilha::Pilha(/* args */)
    {
 
    }

    Pilha::~Pilha()
    {

    }

    void Pilha::empilhar()
    {
        std::cout << "\n\nDigite um elemento para ser inserido: ";
        char elemento[100];
        setbuf(stdin, NULL);
        fgets(elemento, 100, stdin);

        vet.push_back(elemento);
    }

    void Pilha::desempilhar()
    {
        if (vet.size() == 0)
        {
            std::cout << "Pilha vazia" << std::endl;
        }
        else
        {
            vet.pop_back();
        }
    }


    void Pilha::imprime_Pilha()
    {
        if (vet.size() == 0)
        {
            std::cout << "Pilha vazia" << std::endl;
        }

        for (int i = vet.size()-1; i >= 0; i--)
        {
            std::cout << vet[i] << std::endl;
        }
    }

    int Pilha::tamanho_pilha()
    {
        return vet.size();
    }

} // namespace Pilha