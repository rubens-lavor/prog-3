#include <iostream>

class Carro
{
private:
    /* data */
    std::string modelo;
    float velocidade;

public:

Carro(std::string modelo,float velocidade)
{

    this->modelo=modelo;
    this->velocidade=velocidade;
}


Carro(const Carro &a)
{
    //std::cout<<"contrutor de cópia"<< std::endl;
    
    velocidade=a.velocidade;
    modelo=a.modelo;
    
}



~Carro()
{
}

void setvelocidade(float velocidade){
    this->velocidade=velocidade;
}
int getvelocidade(){
    return this->velocidade;
}

void setmodelo(std::string modelo){
    this->modelo=modelo;
}
std::string getmodelo(){
    return this->modelo;
}

void correr(){

}
void parar(){

}


};

void foo(Carro a){

}

int main(){

    Carro gato("eu",3);
    //foo(gato);
    Carro cachorro = gato;
    std::cout << gato.getmodelo()<<"\n";
    std::cout << cachorro.getvelocidade()<<"\n";

    return 0;
}
