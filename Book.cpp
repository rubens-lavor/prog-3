#include <iostream>
using namespace std;
class Book{
public:
    Book(/* args */){}
    Book(std::string s):name(s){}
    void display(){ cout << name; }
private:
    std::string name;
};

int main(){

    return 0;
}
