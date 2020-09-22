#include <iostream>
#include "Pilha.hpp"

namespace Pilha
{

    Pilha::Pilha(/* args */)
    {
        //vet = new String[100];
        //max = 99;
        //topo = -1;
    }

    Pilha::~Pilha()
    {
        //delete[] vet;
    }

    void Pilha::empilhar()
    {
        std::cout << "\n\nDigite um elemento para ser inserido: ";
        char elemento[100];
        setbuf(stdin, NULL);
        fgets(elemento, 100, stdin);

        //vet[++topo] = elemento;
        vet.push_back(elemento);

        //vet.pop_back(elemento);
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
            //topo--;
        }
    }

    /*
    std::string Pilha::getTopo()
    {
        std::cout << vet[topo] << std::endl;
        return;
    }
    */

    /*
    bool Pilha::pilha_vazia()
    {
        return (topo == -1);
    }
    */

   /*
    void Pilha::setElemento()
    {
        std::cout << "\n\nDigite um elemento para ser inserido: ";
        char elemento[100];
        setbuf(stdin, NULL);
        fgets(elemento, 100, stdin);

        std::string elem = elemento;

        //std::cout << nome << std::endl;

        empilhar(elem);
    }
    */

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