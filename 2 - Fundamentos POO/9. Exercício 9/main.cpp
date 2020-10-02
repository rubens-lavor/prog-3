#include "Empresa.hpp"

int main() {
    Funcionario f1("José");
    Funcionario f2("Maria");
    Funcionario f3("Lucia");
    Funcionario f4("Ana");
    Funcionario f5("Luidi");
    Funcionario f6("Mário");
    Funcionario f7("Léia");

    Departamento d1("Departamento de Finanças");
    Departamento d2("Departamento de Marketing");
    Departamento d3("Departamento de Contabilidade");
    Departamento d4("Departamento de Cobranças");
    Departamento d5("Departamento de Compras");

    Empresa e;

    e.setDepartamento(&d1);
    e.setDepartamento(&d2);
    e.setDepartamento(&d3);
    e.setDepartamento(&d4);
    e.setDepartamento(&d5);

    d1.setFuncionario(&f1, 2000.00, "12/08/2019");
    d1.setFuncionario(&f2, 2000.00, "10/10/2019");
    d1.setFuncionario(&f3, 2000.00, "12/05/2018");
    d2.setFuncionario(&f4, 2100.00, "22/02/2018");
    d2.setFuncionario(&f5, 2100.00, "25/02/2018");
    d3.setFuncionario(&f6, 2050.00, "15/01/2020");
    d3.setFuncionario(&f7, 2050.00, "12/07/2019");

    d1.mostra_funcionarios();
    d2.mostra_funcionarios();
    d3.mostra_funcionarios();

    d1.aumento();
    std::cout << "\n";

    e.mostra_depar();

    return 0;
}
