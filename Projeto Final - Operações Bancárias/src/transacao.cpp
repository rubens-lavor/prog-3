#include "../includes/transacao.h"

Transacao::Transacao() {
}

Transacao::~Transacao() {
}

bool Transacao::realizarTransacao(Conta &conta, float valor, std::string historico, int op, float saldo_anterior) {
    Movimento mov(conta, historico, valor, op, saldo_anterior);

    if (!conta.movimentar(valor, op)) {
        return false;
    }

    this->movimentos.push_back(mov);
    return true;
}

void Transacao::estornaTransacao() {
    for (Movimento mov : this->movimentos) {
        movimentos.pop_back();
    }

    /* outra forma

    while (!movimentos.empty()){
        movimentos.pop_back();
    }

    */
}

void Transacao::extrato(Conta &c1, std::string _senha ) const {
    float saldo_anterior_ = 0;
    bool validacao = c1.validacao(_senha);
    int num_conta = c1.getNumero();

    std::cout << "\n-----------------------------------------" << std::endl;
    std::cout << "Emissão de Extrato:\n";

    c1.info();

    std::cout << "\nMovimentações: " << std::endl;

    for (Movimento mov : this->movimentos) {
        if (mov.getConta().getNumero() == num_conta && validacao) {
            std::cout << "Descrição.....:" << mov.getHistorico() << std::endl;
            std::cout << "Valor.........:" << mov.getValor() << std::endl;
            std::cout << "Operação......:" << (mov.getOperacao() ? "Deposito" : "Saque") << std::endl;
            saldo_anterior_ = mov.getSaldoAnterior();
        }
    }

    std::cout << "\nSaldo Anterior: " << saldo_anterior_ << std::endl;
    std::cout << "Saldo Atual: " << c1.getSaldo()<< std::endl;

}