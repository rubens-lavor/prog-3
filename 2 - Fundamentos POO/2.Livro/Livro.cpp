#include "Livro.hpp"

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

int Livro::setISBN(std::string codigo[4])
{
    for (int i = 0; i < 4; i++)
    {
        if (valida_numero(codigo[i]))
        {
            //ISBN = codigo;
        }
    }
}

bool Livro::valida_numero(std::string codigo)
{

    //int i = 0;

    //while (codigo[i] != ' ' && codigo[i] != '\n')

    for (int i = 0; i < codigo.length(); i++)
    {
        /* code */

        if (!isdigit(codigo[i]))
        {
            return false;
        }
    }

    //std::cout << i;
    //i++;

    return true;
}