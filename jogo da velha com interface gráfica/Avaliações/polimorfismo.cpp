#include <iostream>

using namespace std;

/*
class Base {
    public:
    virtual void show() = 0;
};

class Derived: public Base {
    public:
    virtual void show(){cout << "Na Derivada \n";}
};


int main(void){

    Derived d;
    Base br = d;
    br.show();
    return 0;
}
*/

/*
class A {
    public:
    virtual void fun() {cout << "A::fun() ";}

};

class B: public A {
    public:
    virtual void fun() {cout << "B::fun() ";}

};

class C: protected B{
    public:
    virtual void fun() {cout << "C::fun() ";}

};

class D:B,C {
    public:
    D(){cout<<"7";}
    D(const D &obj){cout <<"8";}

};

int main(){
    B *bp = new C;
    bp->fun();
    return 0;
}*/

/*
class Base {
    public:
    virtual void show() {cout <<"In Base \n";}
};

class Derived: public Base {
    public:
    void show() {cout <<"In Derived \n";}
};

int main(){

    Base *bp = new Derived;
    bp->show();
    Base &br = *bp;
    br.show();
    return 0;
}*/

/*
class Base {
    public:
    virtual void show() = 0;
};


class Derived: public Base {
    public:
    virtual void show(){cout << "Na Derivada \n";}
};


int main(void){

    //Derived d;
    Base b;
    Base *bp;
    //br.show();
    return 0;
}
*/

/*
class Base {
    public:
    virtual void show() = 0;
};


class Derived: public Base { };


int main(void){

    Derived q;
    return 0;
}
*/

/*
class A {
    public:
    virtual void fun();

};

class B {
    public:
    void fun();

};

int main(){
    int a = sizeof(A), b = sizeof(B);
    if (a==b) cout << "a == b";
    else if (a>b) cout << "a > b";
    else cout << "a < b";
    
    return 0;
}
*/

class Base {
    public:
    int x;
    void show() {cout <<"Em Base ";}
};

class Derived: public Base {
    public:
    void show() {cout <<"Em Derived ";}
    Derived(){ x = 10; }
};

int main(void){

    Base *bp,b;
    Derived d;
    bp = &d;
    bp->show();
    cout << bp->x;
    return 0;
}