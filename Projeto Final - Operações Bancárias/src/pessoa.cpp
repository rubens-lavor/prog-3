#include "../includes/pessoa.h"

Pessoa::Pessoa() {
}

Pessoa::Pessoa(std::string _nome, std::string _CPF) {
    this->nome = _nome;
    this->CPF = _CPF;
}

Pessoa::~Pessoa() {
}

void Pessoa::setNome(std::string _nome) {
    this->nome = _nome;
}

void Pessoa::setCPF(std::string _CPF) {
    this->CPF = _CPF;
}

std::string Pessoa::getNome() {
    return this->nome;
}

std::string Pessoa::getCPF() {
    return this->CPF;
}
