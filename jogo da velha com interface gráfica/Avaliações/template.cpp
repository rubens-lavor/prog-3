#include <iostream>

using namespace std;
/*
template <typename Type>
class Nome_da_classe {
    Type dado;

   public:
    Nome_da_classe(Type valor) : dado{valor} {}

    ~Nome_da_classe() {}

    Type formato() const{
        return dado;
    }
};

//template especialisada
template <>
class Nome_da_classe<std::string> {
    std::string dado;

   public:
    Nome_da_classe(std::string valor) : dado{valor} {}

    ~Nome_da_classe() {}

    std::string formato() const{
        return dado;
    }
};

int main() {
    Nome_da_classe<int> obj1(2);
    Nome_da_classe<std::string> obj2("oi");

    std::cout << obj1.formato() << std::endl;
    std::cout << obj2.formato() << std::endl;

    return 0;
}
*/

/*

template <class T> T max (T &a, T &b){
    return (a>b)? a:b;
}

template <> int max <int> (int &a, int &b){
    cout << "Chamou ";
    return (a>b)? a:b;
}

int max(int x, int y){
    cout << "Aqui ";
    return (x>y)? x:y;
}

int main(){
    int a = 10, b = 20;
    cout << max(a,b);
    cout << max(42,'4');
}
*/

/*
template<class T> class Test {
    private:
    T val;
    public:
    static int count;
    Test() {count ++;}
};

template<class T> int Test <T>::count = 0;

int main(){
    Test<int> a;
    Test<int>b;
    Test<double>c;

    cout << Test<int>::count << endl;
    cout << Test<double>::count << endl;

    return 0;
}
*/
/*
template <int n> struct funStruct {
    static const int val = 2 * funStruct<n - 1>::val;
};

template <> struct funStruct<0> {
    static const int val = 1;
};

int main() {
    cout << funStruct<10>::val << endl;
    return 0;
}*/

class Book {
   public:
   private:
    string title;
    string author;
    int pages;
};

int main() {
    Book lv1=Book{};
    return 0;
}
