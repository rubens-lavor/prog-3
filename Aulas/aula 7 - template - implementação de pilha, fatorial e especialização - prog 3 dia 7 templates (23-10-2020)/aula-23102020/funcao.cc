#include <iostream>
#include <vector>

#include "funcao.h"


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
    std::cout << square(20) << "\n";
    std::cout << square(10.0) << "\n";
    std::cout << square(10.0f) << "\n";

    Data<bool> obj1{};
    obj1.mostra();

    Data<double> obj2;
    obj2.mostra();

    std::cout << "Fatorial: " << Factorial<4>::RET << "\n";

    testaPilha();

    return 0;
}
