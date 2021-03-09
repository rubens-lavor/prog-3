#include <iostream>
#include <vector>

#include "pilha.h"


void testaPilha() {
    Pilha<char> p{10};

    for (int i = 0; i < 10; i++)
        p.empilha(i + 65);

    for (int i = 0; i < 10; i++)
        if (!(p.vazia()))
            std::cout << p.topo() << "\n";

    for (int i = 0; i < 10; i++) {
        p.desempilha();
        if (!(p.vazia()))
            std::cout << p.topo() << "\n";
    }
}

int main() {
    testaPilha();

    return 0;
}