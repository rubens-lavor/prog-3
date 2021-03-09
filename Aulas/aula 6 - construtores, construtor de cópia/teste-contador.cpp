#include "contador.h"
#include <limits>
#include <iostream>

int main(){

    Contador cont{};
    cont.mostra();
    cont.setContador(-5);
    cont.mostra();
    cont.setContador(10);
    cont.mostra();
    cont.aumenta();
    cont.mostra();
    cont.setContador(std::numeric_limits<long>::max() - 1);
    cont.mostra();
    cont.aumenta();
    cont.mostra();
    cont.aumenta();
    cont.mostra();
    cont.aumenta();
    cont.mostra();
    cont.diminui();
    cont.mostra();
    cont.setContador(1);
    cont.mostra();
    cont.diminui();
    cont.mostra();
    cont.diminui();
    cont.mostra();

    std::cout << "Retorna valor do contador: " << cont.valor();

    return 0;
}
