#include <iostream>
#include <vector>

class Funcionario
{
private:
    std::string nome;
    float salario;
    std::string data_admissao{"dd/mm/aa"};

public:
    Funcionario(/* args */);
    ~Funcionario();
    void setNome(std::string);
    std::string getNome();
};

Funcionario::Funcionario(/* args */)
{
}

Funcionario::~Funcionario()
{
}
void Funcionario::setNome(std::string nome){
    this->nome=nome;
}

std::string Funcionario::getNome(){
    return this->nome;
}

class Departamento
{
private:
    std::string nome;
    int vec[10];
    //Funcionario fun;
    Funcionario vet[100];
    std::vector <Funcionario> vetor_funcionarios;
    int i{0};

public:
    Departamento(/* args */);
    ~Departamento();
    void setFuncionario(Funcionario);
    void mostra_funcionarios();
};

Departamento::Departamento(/* args */)
{
    
}

Departamento::~Departamento()
{
}

void Departamento::setFuncionario(Funcionario fun){
    vet[0] = fun;
    vetor_funcionarios.push_back(fun);
}

void Departamento::mostra_funcionarios(){
    std::cout << vet[0].getNome();

    for (auto v:vetor_funcionarios)
    {
        std::cout << v.getNome();
    }
    
    std::cout << vetor_funcionarios.front().getNome();
}

int main (){

    Departamento d;
    Funcionario f;
    Funcionario f2;

    f.setNome("josé");
    f2.setNome("maria");
    std::cout << f.getNome();

    d.setFuncionario(f);
    d.setFuncionario(f2);
    d.mostra_funcionarios();


    return 0;
}

