#include <iostream>

using namespace std;
/*
template <typename Type>
class Nome_da_classe {
    Type dado;

   public:
    Nome_da_classe(Type valor) : dado{valor} {}

    ~Nome_da_classe() {}

    Type formato() const{
        return dado;
    }
};

//template especialisada
template <>
class Nome_da_classe<std::string> {
    std::string dado;

   public:
    Nome_da_classe(std::string valor) : dado{valor} {}

    ~Nome_da_classe() {}

    std::string formato() const{
        return dado;
    }
};

int main() {
    Nome_da_classe<int> obj1(2);
    Nome_da_classe<std::string> obj2("oi");

    std::cout << obj1.formato() << std::endl;
    std::cout << obj2.formato() << std::endl;

    return 0;
}
*/

template <class T> T max (T &a, T &b){
    return (a>b)? a:b;
}

template <> int max <int> (int &a, int &b){
    cout << "Chamou ";
    return (a>b)? a:b;
}

int max(int x, int y){
    cout << "Aqui ";
    return (x>y)? x:y;
}

int main(){
    int a = 10, b = 20;
    cout << max(a,b);
    cout << max(42,'4');
}

