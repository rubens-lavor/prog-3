#ifndef CONTAPOUPANCA_H
#define CONTAPOUPANCA_H

#include "conta.h"
#include "taxa.h"

/*
 - class ContaPoupanca deriva de Conta e Taxa
 - Como se trata de uma herança publica e multipla, 
 - ContaPoupanca herda todos os métodos e atributos das classes Conta e Taxa. 
*/

class ContaPoupanca : public Conta, public Taxa {
   private:
   /* Não há atributos em ContaPoupanca além dos já definidos em class Conta e class Taxa */
   public:

   /*
     - Construtor da classe ContaPoupanca
     - A partir dele também é construido um objeto Conta, chamando o construtor sobrecarregado da classe Conta
    */
    ContaPoupanca(int numero, Pessoa &correntista, float saldo);

    /*
     - Destrutos da classe ContaPoupanca
    */
    ~ContaPoupanca();

    /*
     - método mostra no terminal informações referentes a determinada conta poupança
    */
    virtual void info() const override;

    /*
        incremento_juros() reajusta o valor do saldo de acordo com o juros
    */
    virtual void incremento_juros() override;

    /*
     - é necessário implementar descontarTaxaManutencao(), senão a classe ContaPoupanca se torna abstrata
     - isso não convém porque a classe ContaPoupanca precisa ser instanciada.
     - como não há taxa manutencao na conta poupança a função não realiza operação nessa classe.
    */
    virtual void descontarTaxaManutencao() override{};
};

#endif