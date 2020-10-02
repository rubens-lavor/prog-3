#include <iostream>
#include <vector>
#include "Departamento.hpp"

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

