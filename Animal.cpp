#include <iostream>

class Animal
{
private:
    /* data */
    std::string nome;
    int idade;

public:

Animal(std::string nome,int idade)
{

    this->nome=nome;
    this->idade=idade;
}


Animal(const Animal &a)
{
    std::cout<<"contrutor de cópia"<< std::endl;
    /*
    a.idade=idade;
    a.nome=nome;
    */
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
    this->nome=nome;
}
std::string getNome(){
    return this->nome;
}

void correr(){

}
void comer(){

}


};

void foo(Animal a){

}

int main(){

    Animal gato("eu",3);
    foo(gato);
    std::cout << gato.getNome()<<"\n";
    return 0;
}
