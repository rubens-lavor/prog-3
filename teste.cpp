#include <iostream>


class Count{
    static int count;
public:
    Count(){
        Count::count++;
    }
    Count(const Count &c){
        c.count++;
    }
    static int qtd(){
        return Count::count;
    }
};

int Count::count = 0;

void foo(Count bar){
    bar.qtd();
}

void boo(const Count bar){
    bar.qtd();
}

int main(){
    Count c1,c2,c3,c4,c5;
    foo(c2);
    boo(c3);
    std::cout << std::endl << Count::qtd() << std::endl;

    return 0;
}

