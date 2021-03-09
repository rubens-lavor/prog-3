#ifndef LIVRO_H
#define LIVRO_H

#include <iostream>


class Livro
{
private:
    std::string ISBN;
    std::string titulo;
    std::string autor;

    bool emprestado = false;

public:


    Livro(std::string,std::string,std::string,std::string ,std::string ,std::string);
    ~Livro();

    bool getEmprestimo();
    void setEmprestimo(bool emprestado);

    std::string getTitulo();
    void setTitulo(std::string);

    std::string getAutor();
    void setAutor(std::string autor);

    std::string getISBN();
    void setISBN(std::string codigo);

    bool valida_ISBN(std::string str0,std::string str1,std::string str2,std::string dig);

    bool valida_numero (std::string str);

};

#endif

