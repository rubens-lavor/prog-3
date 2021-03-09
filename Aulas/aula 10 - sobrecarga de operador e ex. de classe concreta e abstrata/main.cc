#include <iostream>
/*
-desenho (anime, cartoon, stopmotion)
desenho 
    tocar
    parar
*/

class Desenho {  //concreta ou abstrata?

    std::string onome;

   public:
    std::string nome() { return onome; }
    void nome(std::string n) { onome = n; }

    void tocar() {}
    virtual void parar() { std::cout << "Parou Desenho\n"; };
    Desenho() {
        std::cout << "Desenho\n";
    }
    virtual ~Desenho() {
        std::cout << "~Desenho\n";
    }
};

class Anime : public Desenho {  //c ou a?
   public:
    void parar() override { std::cout << "Parou anime\n"; }
    Anime() {
        std::cout << "Anime\n";
    }
    ~Anime() {
        std::cout << "~Anime\n";
    }
};

class Cartoon final : public Anime {  //c ou a?
   public:
    void parar() override { std::cout << "Parou cartoon\n"; }
    Cartoon() {
        std::cout << "Cartoon\n";
    }
    ~Cartoon() {
        std::cout << "~Cartoon\n";
    }
};

std::ostream& operator<<(std::ostream& out, Anime& a) {
    out << a.nome() << "\n";
    return out;
}

std::istream& operator>>(std::istream& in, Anime& a) {
    std::cout << "Qual é o nome do anime?: ";
    std::string name;
    std::getline(std::cin, name);
    a.nome(name);
    return in;
}

void pararDesenho(Desenho& d) {
    d.parar();
}

void matar(Desenho* d){
    delete d;
}

int main() {
//    Anime um;
    Cartoon dois,*tres;

    tres= new Cartoon{};

    // pararDesenho(um);
    pararDesenho(dois);
    pararDesenho(*tres);

    matar(tres);

}