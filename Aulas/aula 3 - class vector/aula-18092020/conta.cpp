#include <iostream>
#include "conta.h"

namespace topico2 {

Conta::Conta(int valor) : saldo{valor}{ //impede a conversão implícita
    if (saldo < 0) {
        saldo = 0;
        std::cout << "Saldo inicial era inválido\n";
    }
}

//delegando construtor
Conta::Conta() : Conta{0} {}
//qual é a necessidade de ter 2 construtores?
//qual dos construtores ele chama?
//função-membro ou método
void Conta::credito(unsigned int valor){
    saldo = saldo + valor;
    //saldo += valor;
}
void Conta::debito(unsigned int valor){
    if (valor > saldo){
        std::cout << "Valor para retirar é maior que o saldo disponível.\n";
    }
    else {
        saldo = saldo - valor;
    }
}

int Conta::getsaldo() const {
    return saldo;
}

}// fim namespace topico2