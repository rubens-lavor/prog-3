#include "Empresa.hpp"

int main() {
    std::shared_ptr<Funcionario> f1(new Funcionario("José"));
    std::shared_ptr<Funcionario> f2(new Funcionario("Maria"));
    std::shared_ptr<Funcionario> f3(new Funcionario("Lucia"));
    std::shared_ptr<Funcionario> f4(new Funcionario("Ana"));
    std::shared_ptr<Funcionario> f5(new Funcionario("Luidi"));
    std::shared_ptr<Funcionario> f6(new Funcionario("Mário"));
    std::shared_ptr<Funcionario> f7(new Funcionario("Léia"));

    std::shared_ptr<Departamento> d1(new Departamento("Departamento de Finanças"));
    std::shared_ptr<Departamento> d2(new Departamento("Departamento de Contabilidade"));
    std::shared_ptr<Departamento> d3(new Departamento("Departamento de Cobranças"));
    std::shared_ptr<Departamento> d4(new Departamento("Departamento de Marketing"));
    std::shared_ptr<Departamento> d5(new Departamento("Departamento de Compras"));

    /*
    Departamento d2("Departamento de Marketing");
    Departamento d3("Departamento de Contabilidade");
    Departamento d4("Departamento de Cobranças");
    Departamento d5("Departamento de Compras");
    */
    Empresa e;

    //std::shared_ptr<Departamento> d1 = Departamento("Departamento de Finanças");

    e.setDepartamento(d1);
    e.setDepartamento(d2);
    e.setDepartamento(d3);
    e.setDepartamento(d4);
    e.setDepartamento(d5);


    d1->setFuncionario(f1, 2000.00, "12/08/2019");
    d1->setFuncionario(f2, 2000.00, "10/10/2019");
    d1->setFuncionario(f3, 2000.00, "12/05/2018");
    d2->setFuncionario(f4, 2100.00, "22/02/2018");
    d2->setFuncionario(f5, 2100.00, "25/02/2018");
    d3->setFuncionario(f6, 2050.00, "15/01/2020");
    d3->setFuncionario(f7, 2050.00, "12/07/2019");

    d1->mostra_funcionarios();
    d2->mostra_funcionarios();
    d3->mostra_funcionarios();

    d1->aumento();
    std::cout << "\n";

    e.mostra_depar();

    return 0;
}
