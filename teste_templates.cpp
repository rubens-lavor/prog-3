#include <iostream>
using namespace std;

template <class T>
T funcao(T valor){
    
    if (typeid(string).name() == typeid(valor).name()) {
        string x = "2";
        return x;
     }

    if (typeid(int).name() == typeid(valor).name()) {
        cout << "\nint\n";
        return 2;
    }

    if (typeid(float).name() == typeid(valor).name()) {
        cout << "\nfloat\n";
        return 2.5;
    }
    
    return true;
}

int main(){

    auto x = funcao(10);

    cout << x ;


    /*
    if (typeid(string).name() == typeid(funcao(10.50)).name()) {
        cout << "\nstring\n";
    }

    if (typeid(int).name() == typeid(funcao(10.50)).name()) {
        cout << "\nint\n";
    }

    if (typeid(float).name() == typeid(funcao(10.50)).name()) {
        cout << "\nfloat\n";
    }

    */


    return 0;
}