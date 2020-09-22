#ifndef conta_h
#define conta_h

#include <iostream>
#include <vector>
#include <cstring>

namespace Pilha
{
    class Pilha
    {
    private:
        std::vector<std::string> vet{};
        //int *vet;
        //int max;  //tamanho máximo da pilha
        //int topo=0; //marca o topo da pilha
    public:
        Pilha(/* args */);
        ~Pilha();
        void empilhar();
        void desempilhar();
        //std::string getTopo();
        void setElemento();
        //bool pilha_vazia();
        void imprime_Pilha();
        int tamanho_pilha();
    };

} // namespace Pilha

#endif
