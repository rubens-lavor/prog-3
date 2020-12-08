#include "../includes/contaEspecial.h"

ContaEspecial::ContaEspecial() {
}

ContaEspecial::~ContaEspecial() {
}

ContaEspecial::ContaEspecial(int _numero, Pessoa &_correntista, float _saldo, float _limite) : Conta(_numero, _correntista, _saldo) {
    this->setLimite(_limite);
    this->limiteAtual = _limite;
}

float ContaEspecial::getLimite() {
    return this->limite;
}

void ContaEspecial::setLimite(float valor) {
    this->limite = valor;
}

bool ContaEspecial::sacar(float valor) {
    if (valor > this->saldo) {
        if (valor > this->saldo + this->limiteAtual) {
            return false;
        } else {
            this->saldo -= valor;
            this->limiteAtual += this->saldo;
            //this->saldo = 0;
        }
    } else {
        this->saldo -= valor;
    }

    return true;
}

void ContaEspecial::descontarTaxaManutencao() {
    this->setSaldo(this->getSaldo() - this->getTaxaManutencao());
}

void ContaEspecial::info() const {
    std::cout << "Conta Especial - Número...........: " << this->numero << std::endl;
    std::cout << "Correntista.......................: " << this->correntista->getNome() << std::endl;
    std::cout << "Saldo.............................: " << this->saldo << std::endl;
    std::cout << "Limite Conta Especial.............: " << this->limite << std::endl;
    std::cout << "Limite Atual......................: " << this->limiteAtual << std::endl;
    std::cout << "CPF...............................: " << this->correntista->getCPF() << std::endl;
}