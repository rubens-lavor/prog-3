#include "../includes/conta.h"

Conta::Conta() {
    contasCriadas++;
}

Conta::Conta(int _numero, Pessoa &_correntista, float _saldo, std::string _senha) {
    contasCriadas++;
    this->setNumero(_numero);
    this->correntista = &_correntista;
    this->senha = _senha;
    this->setSaldo(_saldo);
}

Conta::~Conta() {
}

bool Conta::validacao(std::string chave) const {
    return chave == senha ? true : false;
}

void Conta::setNumero(int num) {
    this->numero = num;
}

int Conta::getNumero() {
    return this->numero;
}

void Conta::setCorrentista(Pessoa &_correntista) {
    this->correntista = &_correntista;
}

Pessoa Conta::getCorrentista() {
    return *correntista;
}

void Conta::setSaldo(float _saldo) {
    this->saldo = _saldo;
}

float Conta::getSaldo() {
    return this->saldo;
}

//métodos de transações bancárias---------------

void Conta::depositar(float valor) {
    this->setSaldo(this->getSaldo() + valor);
    //std::cout << "Depósito no valor de: R$ "<< valor << std::endl;
    //std::cout << "Operação Realizada" << std::endl;
    //std::cout << "Saldo Atual após o depósito: "<< this->getSaldo() <<std::endl;
}

bool Conta::sacar(float valor) {
    if (this->getSaldo() >= valor) {
        //std::cout << "Saque no valor de: R$ " << valor << std::endl;
        this->setSaldo(this->getSaldo() - valor);
        //std::cout << "Operação Realizada" << std::endl;
        //std::cout << "Saldo Atual após o saque: "<< this->getSaldo() <<std::endl;
        return true;
    } else {
        std::cout << "Saldo Insuficiente" << std::endl;
        return false;
    }
}

bool Conta::movimentar(float valor, int operacao) {
    if (operacao == 1)  //depositar
    {
        this->depositar(valor);
        //std::cout << "Operação Depositar realizada com sucesso."<<std::endl;
        return true;

    } else if (operacao == 0)  //sacar
    {
        if (this->sacar(valor)) {
            //std::cout << "Operação Sacar realizada com sucesso."<<std::endl;
            return true;
        } else {
            std::cout << "Saldo Insuficiente" << std::endl;
            return false;
        }

    } else {
        return false;
    }
}

int Conta::contasCriadas = 0;

int Conta::getNumeroTotalDeContas() {
    return contasCriadas;
}

void Conta::info() const {}
