#include <iostream>
#include <vector>
//#include "Funcionario.hpp"
///#include "Departamento.hpp"
//#include "Empresa.hpp"

class Funcionario
{
private:
    std::string nome;
    float salario{0};
    std::string data_admissao{"dd/mm/aa"};

public:
    Funcionario(/* args */);
    Funcionario(std::string nome)
    {
        this->nome = nome;
    }
    ~Funcionario()
    {
    }
    void setSalario(float valor)
    {
        this->salario = valor;
    }
    float getSalario()
    {
        return this->salario;
    }
    void setNome(std::string nome)
    {
        this->nome = nome;
    }

    std::string getNome()
    {
        return this->nome;
    }
    /*
    void setNome(std::string);
    std::string getNome();
    void setSalario(float valor);
    float getSalario();
    */

    void setAdmissao(std::string data)
    {
        this->data_admissao = data;
    }
    std::string getAdmissa()
    {
        return this->data_admissao;
    }
};

class Departamento
{
private:
    std::string nome;
    Funcionario _funcionario;
    std::vector<Funcionario> vetor_funcionarios;

public:

    Departamento(std::string nome)
    {
        this->nome = nome;
    }

    Departamento(/* args */)
    {
    }

    ~Departamento()
    {
    }
    void aumento()
    {

        for (auto v:vetor_funcionarios)
        {
            v.setSalario(v.getSalario() * 1.1);
            std::cout << v.getNome() << " - " << v.getSalario() << std::endl;
        }
    }
    void setFuncionario(Funcionario fun, float salario, std::string data_adm)
    {
        this->_funcionario = fun;

        this->_funcionario.setSalario(salario);
        this->_funcionario.setAdmissao(data_adm);
        vetor_funcionarios.push_back(this->_funcionario);
    }

    void mostra_funcionarios()
    {
        std::cout << "Funcionários do " << this->nome << ":" << std::endl;

        for (auto v : vetor_funcionarios)
        {
            std::cout << v.getNome() << " - " << v.getSalario() << std::endl;
        }

        std::cout << std::endl;
    }

    void setNome(std::string nome)
    {
        this->nome = nome;
    }
    std::string getNome()
    {
        return this->nome;
    }
};


class Empresa
{
private:
    std::string nome;
    std::string CNPJ;
    std::vector<Departamento> departamento;

public:
    Empresa(/* args */){}
    ~Empresa(){}

    void setDepartamento(Departamento d)
    {
        if (departamento.size() == 10)
        {
            std::cout << "Número máximo de departamentos\n";
            return;
        }
        departamento.push_back(d);
    }

    void mostra_depar(){
        for (auto v : departamento)
    {
        std::cout << v.getNome() << " - " << std::endl;
    }
    }

};

int main()
{
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

    e.setDepartamento(d1);
    e.setDepartamento(d2);
    e.setDepartamento(d3);
    e.setDepartamento(d4);
    e.setDepartamento(d5);
    

    //d.setNome("Departamento de Finança");
    //std::cout << f1.getNome();

    d1.setFuncionario(f1,2000.00,"12/08/2019");
    std::cout << "salario f1: "<<f1.getSalario();
    d1.setFuncionario(f2,2000.00,"10/10/2019");
    d1.setFuncionario(f3,2000.00,"12/05/2018");
    d2.setFuncionario(f4,2100.00,"22/02/2018");
    d2.setFuncionario(f5,2100.00,"25/02/2018");
    d3.setFuncionario(f6,2050.00,"15/01/2020");
    d3.setFuncionario(f7,2050.00,"12/07/2019");

    d1.mostra_funcionarios();
    d2.mostra_funcionarios();
    d3.mostra_funcionarios();

    d1.aumento();

    d1.mostra_funcionarios();

    std::cout << f1.getSalario();

    e.mostra_depar();


    return 0;
}
