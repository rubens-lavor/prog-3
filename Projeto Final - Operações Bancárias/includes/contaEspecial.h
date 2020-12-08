#ifndef CONTAESPECIAL_H
#define CONTAESPECIAL_H

#include "conta.h"
#include "taxa.h"


/*
 - class ContaEspecial deriva de Conta e Taxa
 - Como se trata de uma herança publica e multipla, 
 - ContaEspecial herda todos os métodos e atributos das classes Conta e Taxa. 
*/

class ContaEspecial : public Conta, public Taxa
{    
private:
    /*O aributo limite, define o quanto o correntista pode sacar além de seu saldo depositado*/
    float limite;

    /*O aributo limiteAtual, guarda o valor de limite que ainda pode ser sacado*/
    float limiteAtual;

public:

    /*
     - Construtor padrão da classe ContaEspecial
    */
    ContaEspecial();

    /*
     - Construtor sobrecarregado da classe ContaEspecial
     - A partir dele também é construido um objeto Conta, chamando o construtor sobrecarregado da classe Conta
    */
    ContaEspecial(int numero, Pessoa &correntista, float saldo, float limite);

    /*
     - destrutor padrão da classe ContaEspecial
    */
    ~ContaEspecial();

    /*
        - retorna o valor do atributo limite
    */
    float getLimite();

    /*
        - atualiza o valor do atributo limite
    */
    void setLimite(float valor);

    /*
     - método mostra no terminal informações referentes a determinada conta especial
    */
    virtual void info() const override;
    //virtual bool movimentar(float valor, int operacao) override; 


    /*
     - o método recebe um valor como parâmetro verifica se há saldo suficiente para realizar o saque,
     - senão há saldo, verifica se há limite. 
     - Se o saque for realizado retorna true, caso contrário, false.
    */
    virtual bool sacar(float valor) override;
    
    //virtual float getTaxaManutencao() override;
    /*
     - desconta um valor referente a taxa de manutenção da conta especial
    */
    virtual void descontarTaxaManutencao() override;

    /*
     - é necessário implementar incremento_juros(), senão a classe ContaEspecial se torna abstrata
     - isso não convém porque a classe ContaEspecial precisa ser instanciada.
     - como não há juros na conta especial a função não realiza operação nessa classe.
    */
    virtual void incremento_juros() override {};
    
};

#endif