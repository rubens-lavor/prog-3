#ifndef CONTACOMUM_H
#define CONTACOMUM_H

#include "conta.h"
#include "taxa.h"

/*
 - class ContaComum deriva de Conta e Taxa
 - Como se trata de uma herança publica e multipla, 
 - ContaComum herda todos os métodos e atributos das classes Conta e Taxa. 
*/
class ContaComum : public Conta, public Taxa {
   private:
   public:
   /*
     - Construtor padrão da classe ContaComum
    */
    ContaComum();
    /*
     - Construtor sobrecarregado da classe ContaComum
     - A partir dele também é construido um objeto Conta, chamando o construtor sobrecarregado da classe Conta
    */
    ContaComum(int numero, Pessoa &correntista, float saldo /*, float valor*/);

    /*
     - Destrutor padrão da classe ContaComum
    */
    ~ContaComum();

    /*
     - método mostra no terminal informações referentes a determinada conta comum
    */
    virtual void info() const override;

    /*
     - verifica se é possível realizar o saque, permitindo ou não a movimentação
     - o método movimentar da classe base Conta utiliza essa verificação
     - o método é polimorfo, pois Conta Especial permite o saque mesmo sem saldo, até um certo limite
    */
    //virtual bool sacar(float valor) override;

    /*
     - retorna o valor referente a taxa de manutenção
    */

    //virtual float getTaxaManutencao() override;

    /*
     - desconta um valor referente a taxa de manutenção da conta comum
    */
    virtual void descontarTaxaManutencao() override;

    /*
     - é necessário implementar incremento_juros(), senão a classe ContaComum se torna abstrata
     - isso não convém porque a classe ContaComum precisa ser instanciada.
     - como não há juros na conta comum a função não realiza operação nessa classe.
    */
    virtual void incremento_juros() override{};
};

#endif
