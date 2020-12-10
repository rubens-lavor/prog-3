#include <string>

class Empregado
{
    std::string name, surname;
    int dindin;

public:
    Empregado();
    void nome(std::string novonome);
    void sobrenome(std::string novosobrenome);
    void salario(unsigned int novosalario);
    std::string nome() const;
    std::string sobrenome() const;
    int salario() const;
};