#ifndef MOVIMENTO_H
#define MOVIMENTO_H

#include "conta.h"

/* A relação entre as classes Movimento e Conta é na forma de uma agregação */
/*
    A classe Movimento registra todas as atividades de determinada conta. 
    Por meio da classe Transacao, sempre que uma conta realiza um pagamento ou saque um obj Movimento é criado e associado a conta 
*/

class Movimento {
   private:

   /*obj conta*/
    Conta conta;

    /*historico armazena a descrição da transacao*/
    std::string historico;

    /*valor da transação*/
    float valor;

    /*saldo antes da transação*/
    float saldoAnterior;

    /*
        operacao:
        0 indica saque
        1 indica depósito
    */
    int operacao;

   public:

   /*
     - Construtor sobrecarregado da classe ContaComum
    */
    Movimento(Conta &conta, std::string historico, float valor, int operacao, float saldoAnterior);

    /*
     - Destrutor padrão da classe Movimento
    */
    ~Movimento();

    /*atribui o parametro recebido para o atritubo conta   */
    void setConta(Conta _conta);

    /*retorna o atributo conta do tipo Conta   */
    Conta getConta();

    /*atribui o parametro recebido para o atritubo historico */
    void setHistorico(std::string _historico);

    /*retorna o atributo historico */
    std::string getHistorico();

    /*atribui o parametro recebido para o atritubo valor */
    void setValor(float _valor);

    /*retorna o atributo valor */
    float getValor();

    /*atribui o parametro recebido para o atritubo saldoAnterior */
    void setSaldoAnterior(float _saldoAnterior);

    /*retorna o atributo saldoAnterior */
    float getSaldoAnterior();

    /*atribui o parametro recebido para o atritubo operacao */
    void setOperacao(int _operacao);

    /*retorna o atributo saldoAnterior */
    int getOperacao();

};

#endif