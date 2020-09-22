#ifndef conta_h
#define conta_h

#include <iostream>
#include <vector>

namespace Pilha
{
    class Pilha
    {
    private:
        std::vector<std::string> vet{};

    public:
        Pilha(/* args */);
        ~Pilha();
        void empilhar();
        void desempilhar();
        void imprime_Pilha();
        int tamanho_pilha();
    };

} // namespace Pilha

#endif
