#include <iostream>
#include <memory>
#include <vector>

template <class Tipo>
class Pilha {
//    Tipo* outros;
    std::unique_ptr<Tipo[]> outros;
    int maximo, top;

   public:
    Pilha(unsigned capacidade = 20) : top{-1} {
//        outros = new Tipo[capacidade];
        outros = std::make_unique<Tipo[]>(capacidade);
        maximo = capacidade;
    }

    ~Pilha(){
//        delete[] outros;
    }

    bool vazia() const {
        return (top == -1);
    }

    bool cheia() const {
        return (top == (maximo - 1));
    }

    Tipo topo() const {
        return (outros[top]);
    }

    void empilha(Tipo v) {
        if (!cheia()) {
            top++;
            outros[top] = v;
        }
    }

    void desempilha() {
        if (!vazia()) {
            top--;
        }
    }
};