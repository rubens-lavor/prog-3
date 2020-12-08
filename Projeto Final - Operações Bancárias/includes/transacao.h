#ifndef TRANSACAO_H
#define TRANSACAO_H

#include <vector>

#include "movimento.h"

/* A relação entre as classes Transação e Movimento é do tipo composição */

/*
    A classe Transacao é composta por objs do tipo Movimento, existe uma relação entre a classe Transação e a classe Movimento na forma de uma composição.
    No momento em que uma transacao deixar de existir, serão destruídos todos os movimentos associados a essa transação.
*/

/* A classe Transacao controla operações de movimento da conta */
/* efetiva uma movimentação na conta e aprensenta o extrato delas*/

class Transacao {
   private:
    /*
     - vetor de obj do tipo movimento
     - reponsável por armazenar as movimentações realizadas pelos correntistas 
    */
    std::vector<Movimento> movimentos;

   public:
    /*Construtor padrão da classe Transacao*/
    Transacao();

    /*Destrutor padrão da classe Transacao*/
    ~Transacao();

    /*
        O método realizarTransacao() cria e adiciona um objeto do tipo Movimento ao vector movimentos.
        Se a transação foi realizada return true, senão false.
    */
    bool realizarTransacao(Conta &conta, float valor, std::string historico, int op, float saldo_anterior);

    /*
        - retira do vector movimentos uma transacao estornada 
    */
    void estornaTransacao();

    /*
        - imprime o extrato bancário de determinada conta, acessando o vector movimentos
        - Parametros: um obj Conta passado por referencia e uma senha para verificação  
    */
    void extrato(Conta &c1, std::string senha) const;
};

#endif