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
    int setISBN(char *codigo);

    bool valida_numero(char *codigo);
};

Livro::Livro(/* args */)
{
}

Livro::~Livro()
{
}

bool Livro::getEmprestimo()
{
}

void Livro::setEmprestimo(bool emprestado)
{
    this->emprestado = emprestado;
}

std::string Livro::getTitulo()
{
    return titulo;
}

void Livro::setTitulo(std::string titulo)
{
    this->titulo = titulo;
}

std::string Livro::getAutor()
{
}

void Livro::setAutor()
{
}

std::string Livro::getISBN()
{
}

int Livro::setISBN(char *codigo)
{
   if (valida_numero(codigo)){
       //ISBN = codigo;
   }
    
}

bool Livro::valida_numero(char *numero){

    int i = 0;

        while (numero[i] != ' ' && numero[i] != '\n')
        {
            /* code */

            if (!isdigit(numero[i]))
            {
                return false;
            }

            std::cout << i;
            i++;
        }

        return true;
}
