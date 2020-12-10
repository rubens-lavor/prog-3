#include <iostream>
#include "empregado.h"

void mostraEmpregado(){}

template< class... T > 
void mostraEmpregado(const Empregado& emp, const T... outros ){

    std::cout << "Empregado: "<<emp.nome()<< " " 
              << emp.sobrenome() 
              << "\t\t $$ "<<emp.salario()<<std::endl;
    mostraEmpregado(outros... );        
}

int main () {
    Empregado obj1, obj2;

    obj1.nome("André");
    obj1.sobrenome("Gonçalves");
    //
    obj2.nome("Adler");
    obj2.sobrenome("Soster");
    obj2.salario(60000);
    //
    mostraEmpregado(obj1,obj2);
    //
    obj2.salario(obj2.salario()*1.1);
    obj1.salario(obj1.salario()*1.1);
    //
    mostraEmpregado(obj1);
    mostraEmpregado(obj2);
    //
    return 0;
}
