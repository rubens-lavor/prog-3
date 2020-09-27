#include <iostream>

class Animal
{
private:
    /* data */
    std::string nome;
    int idade;

public:
    Animal(/* args */);
    Animal(std::string nome, int idade);
    ~Animal();

    void correr();
    void comer();

    void setIdade(int idade);
    int getIdade();

    void setNome(std::string nome);
    std::string getNome();
};

Animal::Animal(/* args */)
{
}

Animal::Animal()
{
}

Animal::Animal(std::string nome, int idade)
{
    setIdade(idade);
    setNome(nome);
    this->comer();
}

void Animal::setIdade(int idade){
    this->idade=idade;
}
int Animal::getIdade(){
    return this->idade;
}

void Animal::setNome(std::string nome){
    nome=nome;
}
std::string Animal::getNome(){
    return this->nome;
}

void Animal::correr(){

}
void Animal::comer(){

}
