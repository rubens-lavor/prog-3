#include "../includes/movimento.h"

Movimento::Movimento(Conta &_conta,
                     std::string _historico, float _valor, int _operacao,float _saldoAnterior) {
    this->conta = _conta;
    this->historico = _historico;
    this->valor = _valor;
    this->operacao = _operacao;
    this->saldoAnterior = _saldoAnterior;
}

Movimento::~Movimento() {
}

void Movimento::setConta(Conta _conta) {
    this->conta = _conta;
}

Conta Movimento::getConta() {
    return conta;
}

void Movimento::setHistorico(std::string _historico) {
    this->historico = _historico;
}

std::string Movimento::getHistorico() {
    return historico;
}

void Movimento::setValor(float _valor) {
    this->valor = _valor;
}

float Movimento::getValor() {
    return valor;
}

void Movimento::setSaldoAnterior(float _saldoAnterior) {
    this->saldoAnterior = _saldoAnterior;
}

float Movimento::getSaldoAnterior() {
    return saldoAnterior;
}

void Movimento::setOperacao(int _operacao) {
    this->operacao = _operacao;
}

int Movimento::getOperacao() {
    return operacao;
}
/*
bool Movimento::movimentar() {
    this->saldoAnterior = conta.getSaldo();
    if (operacao == 0)  //sacar
    {
        return this->conta.movimentar(this->valor, this->operacao);

    } else if (operacao == 1)  //depositar
    {
        this->conta.movimentar(this->valor, this->operacao);
        return true;
    }
    return false;
}
*/
