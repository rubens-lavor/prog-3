#include "Departamento.hpp"

class Empresa
{
private:
    std::string nome;
    std::string CNPJ;
    std::vector<Departamento*> departamento;

public:
    Empresa(/* args */){}
    ~Empresa(){}

    void setDepartamento(Departamento *d)
    {
        if (departamento.size() == 10)
        {
            std::cout << "Número máximo de departamentos\n";
            return;
        }
        departamento.push_back(d);
    }

    void mostra_depar(){
        std::string s{};
        for (auto v : departamento)
    {
        s = v->qtdade_funcionarios() < 2 ? " Funcionário " : " Funcionários" ;
        std::cout << v->getNome() << " - " << v->qtdade_funcionarios() << s << std::endl;
    }
    }

};