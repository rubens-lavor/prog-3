#include <iostream>

class Animal
{
private:
    /* data */
    static std::string nome;
    static int idade;

public:

Animal(std::string nome,int idade)
{
    this->nome=nome;
    this->idade=idade;
}

Animal(const Animal &a, std::string nome,int idade)
{
    a.idade=idade;
    a.nome=nome;
}

~Animal()
{
}

void setIdade(int idade){
    this->idade=idade;
}
int getIdade(){
    return this->idade;
}

void setNome(std::string nome){
    nome=nome;
}
std::string getNome(){
    return this->nome;
}

void correr(){

}
void comer(){

}

};
