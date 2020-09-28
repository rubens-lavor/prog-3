//Quantas vezes aparece a string "Msg" na saída?

#include <iostream>
using namespace std;

class MSG
{
private:
    /* data */
public:

    MSG(){ cout<< " Msg ";}
~MSG(){ cout<< " Msg ";}
};

int foo (MSG m) { m; }

int main (){
    MSG m1,m2,m3,*m4;
    { MSG m2; }
    foo(m3);
    foo(m2);
}

