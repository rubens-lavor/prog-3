#ifndef CONTA_H
#define CONTA_H
#include <iostream>
#include <string>

#include "pessoa.h"

/* 
A classe Conta define um tipo de dado abstrato
para a criação criação da estrutura de classes de
contas bancárias

*/

/*
- A classe Conta é base para as classes ContaComum, ContaPoupança e ContaEspecial, por meio do conceito de herança
*/
class Conta {
   private:
    static int contasCriadas;  //contador de objetos da classe Conta

    /*
    - atributo que armazena a senha da conta
    */
    std::string senha = "";

   protected:
    /*
    o atributo número é utilizado para referenciar o número da conta.
    */
    int numero;

    /*
    o atributo correntista, do tipo Pessoa, é utilizado para referenciar um correntista.
    */
    Pessoa *correntista;

    /*
    o atributo saldo é utilizado para referenciar o saldo da conta.
    */
    float saldo{};


   public:
    /*
        Construtor padrão da Classe Conta
    */
    Conta();

    /*
    Construtor sobrecarregado da classe Conta

    Parametros:
        int numero, Pessoa correntista, float saldo, string senha
    Onde:
        numero --> inteiro que identifica o número da conta
        correntista --> objeto do tipo Pessoa que identifica o correntista da conta
        saldo --> float que identifica o saldo inicial
        senha --> string indetifica a senha da conta 
    */
    Conta(int numero, Pessoa &correntista, float saldo, std::string senha = "123");

    /*
        destrutor virtual padrão da Classe Conta
    */
    virtual ~Conta();

    /*  
        - O método valida a chave passada
        - parametro chave representa a senha passada para verificação/autenticação
        - returna true se chave seja válida; caso contrário false.
    */
    bool validacao(std::string chave) const;

    /*
        método que retorna o número da conta
    */
    int getNumero();

    /*
        - método que atualiza o número da conta
        - método usado pelo construtor
    */
    void setNumero(int num);

    /*
        retorna um ponteiro para um objeto Pessoa
    */
    Pessoa getCorrentista();

    /*
        - método que atribue um endereço de Pessoa ao atributo conrrentista
        - método usado pelo construtor
    */
    void setCorrentista(Pessoa &correntista);

    /*
    - método que retorna o saldo da conta
    */
    float getSaldo();

    /*
    - método que atualiza o saldo da conta
    */
    void setSaldo(float saldo);

    /*
    função que retorna o total de objetos instanciados
    */
    int getNumeroTotalDeContas();

    /*
        - O método verifica qual tipo de operação se deseja realizar e chama a função correspondente:
        - caso operação == 0 ---> sacar(float)
        - caso operação == 1 ---> depositar(float)
        - em ambos os casos passando o valor recebido por paramentro
        - Caso a operação tenha sido realizada retorna true, caso não seja possível, retorna false
    */
    bool movimentar(float valor, int operacao);

    /*
    - método que realiza depósito em conta
    */
    void depositar(float valor);

    
    /* Métodos polimorficos */

    /*
    - O método info() é sobrescrito nas classes ContaComum, ContaPoupança e ContaEspecial
    - info() imprime informações referentes a determinada conta, tais como numero da conta, nome do correntista, saldo, entre outros.
    */
    virtual void info() const;

    /*
    - O método sacar() é sobrescrito na classe ContaEspecial
    - Como conta especial possibilita saque mesmo sem saldo até determinado valor
    - a verificação acontece que maneira particular.

    - o método recebe um valor como parâmetro verifica se há saldo suficiente para realizar o saque,
    - Se sim retorna true, caso contrário, false.
    - na classe Conta, sacar() é implementado e as classes ContaComum e ContaPoupança herdam o método
    - sem necessidade de sobrescreve-lo.

    - sacar() é chamado dentro do método movimentar()
    */
    virtual bool sacar(float valor);
};

#endif
