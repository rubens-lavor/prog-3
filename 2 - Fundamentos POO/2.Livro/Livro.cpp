#include "Livro.hpp"

Livro::Livro(std::string titulo, std::string autor, std::string str0, std::string str1, std::string str2, std::string dig)
{
    if (valida_ISBN(str0, str1, str2, dig))
    {
        setTitulo(titulo);
        setAutor(autor);

        std::string codigo{(str0 + " - " + str1 + " - " + str2 + " - " + dig)};
        setISBN(codigo);

        /*
        std::cout << codigo << std::endl;

        std::cout << "Livro registrado" << std::endl;
        */
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

    /*
    if (valida_ISBN(codigo[4]))
    {
        ISBN[0] = codigo[0];
        ISBN[2] = codigo[1];
        ISBN[4] = codigo[2];
        ISBN[6] = codigo[3];
    }

    int cont_valida = 0;

    for (int i = 0; i < 4; i++)
    {
        if (valida_ISBN(codigo[i]))
        {
            ISBN[2 * i + 1] = codigo[i];
            cont_valida++;
        }
    }

    if (cont_valida != 4)
    {
        std::cout << "informe um código válido"
                  << "\n";
        return 0;
    }

    return 1;
    */

   ISBN=codigo;
}

bool Livro::valida_ISBN(std::string str0, std::string str1, std::string str2, std::string dig)
{

    /*
    int cont_valida;
    int cont = 0;
    */
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

    for (int i = 0; i < str.length(); i++)
    {

        if (!isdigit(str[i]))
        {
            return false;
        }
    }

    return true;
}
