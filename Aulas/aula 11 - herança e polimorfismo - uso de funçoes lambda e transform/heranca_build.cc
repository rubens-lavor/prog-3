#include <iostream>
using namespace std;

class A{
public:
    A(){  std::cout << "constroi A\n";   }
    virtual ~A(){  std::cout << "destroi A\n";   }
};
 
class B: public A {
public:
    B(){ std::cout << "constroi B\n";  }
    ~B(){ std::cout << "destroi B\n";  }
};
 
class C: public B {
public:
    C() { std::cout << "constroi C\n";   }
    ~C() { std::cout << "destroi C\n";   }
};
 
class D: public C {
public:
    D() {  std::cout << "constroi D\n";    }
    ~D() {  std::cout << "destroi D\n";    }
   
};

	
int main() {
    cout<<"Estou construindo o D. Então, construindo: "<<endl;
    //D d;
    D *v=new D;
    A *aa=v;
    cout << "Antes do return" << endl;
    delete aa;
    return 0;
} 
