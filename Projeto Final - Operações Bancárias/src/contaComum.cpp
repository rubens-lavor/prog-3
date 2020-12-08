#include "../includes/contaComum.h"

ContaComum::ContaComum(int _numero, Pessoa &_correntista, float _saldo) : Conta(_numero, _correntista, _saldo) {
}

ContaComum::ContaComum() {}

ContaComum::~ContaComum() {
}

void ContaComum::descontarTaxaManutencao() {
    this->setSaldo(this->getSaldo() - this->getTaxaManutencao());
    //_conta->setSaldo(_conta->getSaldo() - this->getTaxaManutencao());
}

void ContaComum::info() const {
    std::cout << "Conta Comum :\n";
    std::cout << "Número da conta...........: " << this->numero << std::endl;
    std::cout << "Correntista...............: " << this->correntista->getNome() << std::endl;
    std::cout << "Saldo.....................: " << this->saldo << std::endl;
    std::cout << "CPF.......................: " << this->correntista->getCPF() << std::endl;
}