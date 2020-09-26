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
}

bool Livro::valida_ISBN(std::string codigo[4])
{

    int cont_valida;
    int cont = 0;

    while (cont<4)
    {
        /* code */
        //if(valida_codigo(codigo[i],cont)){

        }

        cont ++;
    }
    
    

    //while (codigo[i] != ' ' && codigo[i] != '\n')

    for (int i = 0; i < codigo.length(); i++)
    {
        /* code */

        if (cont < 3)
        {
            if (!isdigit(codigo[i]))
            {
                return false;
            }
            cont ++;
        }
        else
        {
            return (codigo[i].length() == 1);
        }
    }

}

/*
bool valida_codigo (std::string codigo, int cont){

    for (int i = 0; i < codigo.length(); i++)
    {

        if (cont < 3)
        {
            if (!isdigit(codigo[i]))
            {
                return false;
            }
        }
        else
        {
            return (codigo[i].length() == 1);
        }
    }
}


*/