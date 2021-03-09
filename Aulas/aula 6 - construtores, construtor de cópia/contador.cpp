#include "contador.h"

#include <iostream>
#include <limits>

void Contador::setContador(long x) {
    if (x < 0) {
        x = 0;
    }
    this->contador = x;
}

void Contador::aumenta() {
    if (this->contador < std::numeric_limits<long>::max()) {
        this->contador++;
    }
}

void Contador::diminui() {
    if (contador > 0) {
        contador--;
    }
}

long Contador::valor() const {
    return contador;
}

void Contador::mostra() const {
    std::cout << contador << "\n";
}