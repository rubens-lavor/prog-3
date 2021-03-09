#ifndef Livro_hpp
#define Livro_hpp

#include <iostream>

enum class Genero{ficcao, nao_ficcao, periodico, biografia, infantil};

class Livro
{
private:
    /* data */
    std::string ISBN;
    std::string titulo;
    std::string autor;

    std::string genero{};
    bool emprestado = false;

public:

    Genero gen;

    Livro(std::string,std::string,std::string,std::string ,std::string ,std::string, enum Genero);
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

    void setGen(Genero);
    std::string getGen();
};

#endif

