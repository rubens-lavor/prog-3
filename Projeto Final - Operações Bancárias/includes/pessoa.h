#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
#include <string>

/*A classe Pessoa define um correntista*/

class Pessoa {
   private:
    /*Nome da pessoa*/
    std::string nome;
    
    /*numero do cpf*/
    std::string CPF;

   public:

   /*
     - Construtor padrão da classe Pessoa
    */
    Pessoa();

    /*
     - Construtor sobrecarregado da classe Pessoa
    */
    Pessoa(std::string _nome, std::string _CPF);

    /*
     - Destrutor sobrecarregado da classe Pessoa
    */
    ~Pessoa();

    /*atribui o parametro recebido para o atritubo nome */
    void setNome(std::string _nome);

    /*atribui o parametro recebido para o atritubo CPF */
    void setCPF(std::string _CPF);

    /*retorna o atributo nome */
    std::string getNome();

    /*retorna o atributo CPF */
    std::string getCPF();
};

#endif

