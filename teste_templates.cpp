#include <iostream>
using namespace std;

template <class T>
class Dictionary {
    T* values;
    int size;
    int max_size;

   public:
    Dictionary(int initial_size) : size(0) {
        max_size = 1;
        while (initial_size >= max_size)
            max_size *= 2;
        values = new T[max_size];
        cout << "int\n";
    }
    void setValues() {
        values[5] = 1000;
    }
};

// Template partial specialization: T is specified to be string.
template <>
class Dictionary<string> {
    string* values;
    int size;
    int max_size;

   public:
    Dictionary(int initial_size) : size(0) {
        max_size = 1;
        while (initial_size >= max_size)
            max_size *= 2;
        values = new string[max_size];
        cout << "string\n";
    }
    void setValues() {
        values[5] = "1000";
    }
};

int main() {
    Dictionary<int> dict(10);
    Dictionary<float> dict2(10);
    Dictionary<string> *dict_specialized = new Dictionary<string>(10);

    return 0;
}