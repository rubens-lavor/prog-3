#include "funcao.h"

#include <iostream>
#include <vector>

void testaPilha() {
    Pilha<char> p{10};

    for (int i = 0; i < 10; i++)
        p.empilha(i + 65);

    for (int i = 0; i < 10; i++)
        if (!(p.vazia()))
            std::cout << p.topo() << "\n";

    for (int i = 0; i < 10; i++) {
        p.desempilha();
        if (!(p.vazia()))
            std::cout << p.topo() << "\n";
    }
}

int main() {
    std::cout << square(20) << "\n";
    std::cout << square(10.0) << "\n";
    std::cout << square(10.0f) << "\n";

    Data<bool> obj1{};
    obj1.mostra();

    Data<double> obj2;
    obj2.mostra();

    std::cout << "Fatorial: " << Factorial<4>::RET << "\n";

    testaPilha();

    int q;
    std::cin >> q;

    std::cout << factorial(q) << std::endl;

    return 0;
}

/*
a composição eh dona da parte
a parte so existe em uma objeto em cada momento
e quando a objeto morre 
ou eh destruida no caso
a parte eh destruida

e na agregacao a parte pode estar em mais de uma classe
e nao necessariamente morre quando a classe para de existir
mas na associacao de modo geral
a classe deve conter a parte
e a parte nao "sabe" q eh parte da classe
*/

class pessoa {
    protected:
    int idade;
    std::string nome;
    void ot_nome();

};

class funcionario : public pessoa {
    int idade;
   public:
    void bonus(long) {
        nome = "RUBENS";
        pessoa::idade = 23;
        idade = 22;
    }
};

class aluno : public pessoa {
};

class monitor final : public aluno{

};

class professor final : public funcionario {
};


class banco {
    //    funcionario& presidente;
    funcionario* presidente;

   public:
    banco(funcionario* novo_presidente) : presidente{novo_presidente} {
        pagarbonus();
    }

    void pagarbonus() {
        if (presidente != nullptr) {
            presidente->bonus(10000000);
        }
    }
};

void teste() {
    funcionario rubens;

    {
        banco besc{&rubens}, banespa{nullptr};
    }

    banco bamerindus{&rubens};
}
