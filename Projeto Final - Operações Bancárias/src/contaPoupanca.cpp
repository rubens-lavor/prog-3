#include "../includes/contaPoupanca.h"

ContaPoupanca::ContaPoupanca(int _numero, Pessoa &_correntista, float _saldo) : Conta(_numero, _correntista, _saldo) {
}

ContaPoupanca::~ContaPoupanca() {
}

void ContaPoupanca::info() const {
    std::cout << "Conta Poupança" << std::endl;
    std::cout << "Número....................: " << this->numero << std::endl;
    std::cout << "Correntista...............: " << this->correntista->getNome() << std::endl;
    std::cout << "Saldo.....................: " << this->saldo << std::endl;
    std::cout << "CPF.......................: " << this->correntista->getCPF() << std::endl;
}

void ContaPoupanca::incremento_juros() {
    this->saldo *= this->getTaxa_juros_poupanca();
}