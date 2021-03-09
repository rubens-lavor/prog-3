#include <iostream>
#include <memory>
#include <vector>

//1 
template <int n>
struct Factorial {
    enum { RET = Factorial<n - 1>::RET * n };
};

template <>
struct Factorial<0> {
    enum { RET = 1 };
};

//2 - C++17
constexpr long factorial(const int n){
    if(n<=0)
        return 0;
    return factorial(n-1)*n;
}

/*
Factorial<3>::RET  ->  Factorial<3 - 1>::RET * 3 -> 2*3 -> RET = 6;
Factorial<2>::RET  ->  Factorial<2 - 1>::RET * 2 -> 1*2
Factorial<1>::RET  ->  Factorial<1 - 1>::RET * 1 -> 1*1 
Factorial<0>::RET  ->  Factorial<0>::RET == 1
*/

template <typename Qualquer = int, int N = 42>
class Data {
    Qualquer formato;

   public:
    Data() : formato{} {}

    Qualquer forma() const {
        return formato;
    }

    void mostra() const {
        if (std::is_same<Qualquer, double>::value) {
            std::cout << " DOUBLE!!! \n";
        }
        std::cout << formato << "\n";
    }
};

template <>
class Data<bool> {
    bool formato;

   public:
    Data() : formato{true} {}

    bool forma() const {
        return formato;
    }
    void mostra() const {
        std::cout << " BOOL !!! \n";
        std::cout << std::boolalpha << formato << "\n";
    }
};

template <typename Qualquer>
Qualquer square(Qualquer x) {
    std::cout << "template ";
    return x * x;
}

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

    ~Pilha() {
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
