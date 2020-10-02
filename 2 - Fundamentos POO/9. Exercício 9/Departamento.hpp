#include <iostream>
#include <vector>
#include "Funcionario.hpp"

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

