#include <iostream>
#include <vector>
#include <string>

/*
class Quadrado {
    int q;

    public:
    Quadrado(int y=7):q{y}{}
    Quadrado& operator+(const int& par) const{ return Quadrado(q+par);}
    Quadrado& operator+(const int& par) const{ return Quadrado(q+q);}
    //void operator++(){q++;}
    int show() const {return q;}
};
*/

/*
using namespace std;

class Point {
private: int x, y;
public:
Point() : x(0), y(0) {}
Point& operator()(int dx, int dy);
void show() {cout << "x = " << x << ", y = " << y;}

};

Point& Point::operator()(int dx, int dy){
    x=dx; y=dy;
    return *this;
}

*/

template<typename T> std::ostream& operator <<(std::ostream& os, const std::vector<T>& vec){
    for (auto& el : vec){os << el << ' ';}
    return os;
}

int main(){

    std::vector<std::string> vec ={
        "Prefiro","pizza","quadrada", "!"
    };

    std::cout << vec << std::endl;
    /*
    Point pt;
    pt(3,2);
    pt.show();
    //r++;
    //std::cout << r.show() << std::endl;
    */
    return 0;
}