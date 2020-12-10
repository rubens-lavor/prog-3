#include <iostream>
using namespace std;


/*
template <typename T> T max(T x,, T y){
    return (x>y)? x:y;
}

int main(){

    cout << max(3,7) << std::endl;
    cout << max(3.0,7.0) << std::endl;
    cout << max(3,7.0) << std::endl;
    return 0;
}

*/

/*

int main(){

    cout << "cout<<\"int main()<<\" <<endl ";
    cout << "must return an integer value;";
}
*/

/*
class Base {
    public:
    int x, y;
    public:
    Base(int i, int j){x = i; y = j;}
    void print() {cout << "Quero pizza!";}
};

class Derived: public Base{
    public:
    Derived(int i, int j):Base(i,j){}
    void print() {cout << x << " " << y;}
};

int main(){

    Derived q(10,10);;
    Base *p=&q;
    p->print();

    return 0;
}
*/

class Base {
    public:
    virtual void show() = 0;
    void sair();
};

void Base::show(){
    this->sair();
}

class Derived: public Base {
    public:
    void show(){cout << "Na Derivada \n";}
};


int main(void){

    Derived d;
    //Base br;
    //br.show();
    return 0;
}

