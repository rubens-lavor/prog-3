#include <iostream>
#include <string>

class a{

public:
    virtual void prnt(){
        std::cout<<"a"<<std::endl;
    }
};

class b: public a{

public:
    virtual void prnt(){
        std::cout<<"B"<<std::endl;
    }
};

int main() {
    a* array[3];
    array[0] = new a();
    array[1] = new b();
    array[2] = new a();

    array[1]->prnt();

    // Don't forget to delete them!
    for (int i = 0; i < 3; ++i) {
        delete array[i];
    }
}