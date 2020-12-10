#include <iostream>

class Cachorro{
    std::string racacachorro;
    int altura;
public:
    Cachorro() {
        altura = 1;
    }
    void crescer() {
        altura += 1;
    }
    //accesor e mutators
    void raca(std::string nova){ //método de alteração
        racacachorro = nova;
    }
    std::string raca() const{ //método de consulta
        return racacachorro;
    }
};

enum class Genero{    FICCAO,    COMEDIA,    TERROR};

std::string genero2str(Genero algum){
    std::string resposta = "SEM GENERO";
    switch (algum)
    {
    case Genero::FICCAO:
        resposta = "FICCAO";
        break;
    case Genero::COMEDIA:
        resposta = "COMEDIA";
        break;
    case Genero::TERROR:
        resposta = "TERROR";
        break;
    }
    return resposta;
}

class Musica {
    public:

    Genero meu_genero;
};

int main(){
    Cachorro toto;
    toto.crescer();
    toto.raca("Vira-lata");
    std::cout << "Toto - raça: "<<toto.raca()<<"\n";
    Genero gen;

    //    gen == 1;
    std::cout << "Genero " << genero2str(Genero::TERROR) << std::endl;
    return 0;
}