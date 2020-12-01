#include <iostream>

using namespace std;

/*
class Base {
    protected:
    int a;
    public:
    Base(){a=42;}
};

class Derived1: public Base {
    public: int c;
};

class Derived2: public Base {
    public: int c;
};

class DerivedDerived: public Derived1, Derived2 {
    public:
    void show() {cout << a;}
};

int main(){

    DerivedDerived d;
    d.show();
    return 0;
}
*/

/*
class Base {
    public:
    int x;
    void show() {cout <<"Em Base ";}
};

class Derived: public Base {
    public:
    void show() {cout <<"Em Derived ";}
    Derived(){x=10;}
};

int main(){

    Base *bp, b;
    Derived d;
    bp=&d;
    bp->show();
    cout << bp->x;
    return 0;
}
*/

/*
class Base {
    protected:
    int a;
    public:
    Base(){a=42;}
};

class Derived1: public virtual Base {
    public: int c;
};

class Derived2: public virtual Base {
    public: int c;
};

class DerivedDerived: public Derived1, Derived2 {
    public:
    void show() {cout << a;}
};

int main(void){

    DerivedDerived d;
    d.show();
    return 0;
}
*/
/*
class A {
    public:
    A(){cout<<"1";}
    A(const A &obj){cout <<"2";}

};

class B: virtual A {
    public:
    B(){cout<<"3";}
    B(const B &obj){cout <<"4";}

};

class C final: virtual A{
    public:
    C(){cout<<"5";}
    C(const C &obj){cout <<"6";}

};

class D:B,C {
    public:
    D(){cout<<"7";}
    D(const D &obj){cout <<"8";}

};

int main(){
    D d1;
    D d(d1);
}

*/

/*
class Base1 {
    static int val;
    public:
    Base1(){val++; cout << "Base1 Construtor"<< endl;}
    ~Base1(){val++; cout << "Base1 destrutor"<< endl;}
};
int Base1::val=0;

class Base2 {
    static int val;
    public:
    Base2(){cout << "Base2 Construtor"<< endl;}
    ~Base2(){cout << "Base2 destrutor"<< endl;}
};

class Derived: public Base1, public Base2 {
public:
Derived(){++val; cout << "Derived construtor"<<endl;}
~Derived(){cout << "Derived destrutor"<< val <<endl;}
};

int main(){
    Derived d;
    return 0;
}
*/
