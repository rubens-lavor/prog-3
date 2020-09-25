#ifndef Livro_hpp
#define Livro_hpp

#include <iostream>

class Livro
{
private:
    /* data */
    std::string ISBN[7] = {"numero","-","numero","-","numero","-","digito"};
    std::string titulo;
    std::string autor;

    bool emprestado = false;

public:
    Livro(/* args */);
    ~Livro();

    bool getEmprestimo();
    void setEmprestimo(bool emprestado);

    std::string getTitulo();
    void setTitulo(std::string titulo);

    std::string getAutor();
    void setAutor();

    std::string getISBN();
    int setISBN(std::string codigo[4]);

    bool valida_numero(std::string codigo);
};

#endif

