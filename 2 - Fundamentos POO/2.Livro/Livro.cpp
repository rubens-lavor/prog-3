#include "Livro.hpp"

Livro::Livro(std::string titulo, std::string autor, std::string num0, std::string num1, std::string num2, std::string dig)
{
    if (valida_ISBN(num0, num1, num2, dig))
    {
        setTitulo(titulo);
        setAutor(autor);

        std::string codigo{(num0 + "-" + num1 + "-" + num2 + "-" + dig)};
        setISBN(codigo);

    }
    else
    {
        std::cout << "código inválido" << std::endl;
    }
}

Livro::~Livro()
{
}

bool Livro::getEmprestimo()
{
    return emprestado;
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
    return autor;
}

void Livro::setAutor(std::string autor)
{
    this->autor = autor;
}

std::string Livro::getISBN()
{
    return ISBN;
}

void Livro::setISBN(std::string codigo)
{
   ISBN=codigo;
}

bool Livro::valida_ISBN(std::string str0, std::string str1, std::string str2, std::string dig)
{

    std::string str[3];

    str[0] = str0;
    str[1] = str1;
    str[2] = str2;

    for (int i = 0; i < 3; i++)
    {
        //str=str+std::to_string(i);

        if (!valida_numero(str[i]))
        {
            return false;
        }
    }

    return (dig.length() == 1 && isalnum(dig[0]));
}

bool Livro::valida_numero(std::string str)
{

    for (long unsigned int i = 0; i < str.length(); i++)
    {

        if (!isdigit(str[i]))
        {
            return false;
        }
    }

    return true;
}
