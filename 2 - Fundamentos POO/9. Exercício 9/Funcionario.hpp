#include <iostream>

class Funcionario
{
private:
    std::string nome;
    float salario{0};
    std::string data_admissao{"dd/mm/aa"};

public:
    Funcionario(/* args */){}
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

    void setAdmissao(std::string data)
    {
        this->data_admissao = data;
    }
    std::string getAdmissa()
    {
        return this->data_admissao;
    }
};