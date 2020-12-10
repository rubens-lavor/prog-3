#include "empregado.h"

Empregado::Empregado()
{
    name = "John";
    surname = "Doe";
    dindin = 50000;
}

void Empregado::nome(std::string novonome)
{
    name = novonome;
}
void Empregado::sobrenome(std::string novosobrenome)
{
    surname = novosobrenome;
}
void Empregado::salario(unsigned int novosalario)
{
    if (novosalario < 0)
    {
        dindin = 0;
    }
    dindin = novosalario;
}

std::string Empregado::nome() const
{
    return name;
}
std::string Empregado::sobrenome() const
{
    return surname;
}
int Empregado::salario() const
{
    return dindin;
}
