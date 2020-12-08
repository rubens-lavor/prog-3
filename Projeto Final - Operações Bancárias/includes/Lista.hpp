#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <memory>

/*Template de class*/

/*
 A classe Lista armazena os objetos de contas criadas
*/

/*
 - uma vez que os objetos são passados por referencia, 
 - é possível acessar métodos sobrescritos das classes derivadas
 - por meio da classe Lista.
*/
template <class T>
class Lista {
   private:
    //T *contas;

    /*
     - ponteiro para elementos do tipo T que será definido em tempo de execução
    */
    std::unique_ptr<T[]> contas;

    /*
     - atributo tam guarda o numeros de elementos colocados no vetor
    */
    size_t tam = 0;

    /*
     - size é o tamanho do vetor, se não for especificado, o contrutor atualiza o zise para 10 
    */
    size_t size = 0;


    /*template de função*/
    /* Protótipos de função para operador de fluxo de saída sobrecarregado*/
    template <typename>
    friend std::ostream &operator<<(std::ostream &, Lista<T> &);
    /*
        friend é um atributo especial de acesso a classes. 
        Com ele declaramos que uma função fora de uma classe é amiga da mesma.
        "friend" dentro de uma classe, permite que a função  
        possa ler e manipular atributos e métodos privados e/ou protegidos

        nesse caso o atributo friend deve ser empregado pois o operador <<
        deve ser sobrecarregado como função e não como método
    */

   public:

   /*
    - Construtor padrão da clase Lista
   */
    Lista(size_t _size = 10) : size(_size) {
        /*
        contas = new T[size];
        for (size_t i = 0; i < size; ++i)
            contas[i] = {};
        */

       //Constrói um objeto do tipo T e o envolve em um std :: unique_ptr 
        contas = std::make_unique<T[]>(size);
    }

    /*
    - desstrutor padrão da clase Lista
   */
    ~Lista() {
        //delete[] contas;
    }

    /*
     - retorna o numero de elementos no vetor
    */
    size_t getTam() const {
        return tam;
    }


    /*Sobrecarga de operadores*/

    /*
     - operador += sobrecarregado
     - adiciona um elemnto  à lista, do tipo T
     - a ser definido durante a execução
    */
    void operator+=(T &c) {
        contas[tam] = c;
        tam++;
    }

    /*
     * operador [] sobrecarregado
     * retorna um elemento T da lista
    */
    T &operator[](size_t indice) const {
        return contas[indice];
    }
};


/*Template de função*/
/* operador de saída sobrecarregado para a classe Lista */
template <class T>
std::ostream &operator<<(std::ostream &output, const Lista<T> &lista) {

    output << "Tamanho da lista:" << lista.getTam() << "\n";
    std::string nome{};
    int numero;

    for (size_t i = 0; i < lista.getTam(); i++) {
        
        /* - uso do operador [] */
        nome = lista[i].getCorrentista().getNome();
        numero = lista[i].getNumero();

        output << "Correntista: " << nome << "  Numero da Conta: " << numero << "\n";
    }

    return output;
}

#endif