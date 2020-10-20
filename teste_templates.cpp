#include <iostream>
using namespace std;

template <class T>
class Array {
    T *ptr;
    size_t size;

    template <typename>
    friend std::ostream &operator<<(std::ostream &, const Array<T> &);
    template <typename>
    friend std::istream &operator>>(std::istream &, Array<T> &);

   public:
    explicit Array(int arraySize = 10)
        : size(arraySize > 0 ? arraySize : throw invalid_argument("Array size must be greater than 0")),
          ptr(new Type[size]) {
        ptr = new Type[arraySize];
        for (size_t i = 0; i < size; ++i)
            ptr[i] = {};
    }

    Array(const Array &arrayToCopy)
        : size(arrayToCopy.size),
          ptr(new Type[size]) {
        for (size_t i = 0; i < size; ++i)
            ptr[i] = arrayToCopy.ptr[i];
    }

    ~Array() {
        delete[] ptr;
    }

    /*
    void setptr() {
        ptr[5] = 1000;
    }
    */

    size_t getSize() const {
        return size;
    }

    T getPtr(size_t indice) const {
        return ptr[indice];
    }

    void setPtr(size_t indice, T elemento) {
        ptr[indice] = elemento;
    }

    const Array<T> &operator=(const Array &right) {
        if (&right != this) {
            if (size != right.size) {
                delete[] ptr;
                size = right.size;
                ptr = new T[size];
            }

            for (size_t i = 0; i < size; ++i)
                ptr[i] = right.ptr[i];
        }

        return *this;
    }

    bool operator==(const Array &right) const {
        if (size != right.size)
            return false;

        for (size_t i = 0; i < size; ++i)
            if (ptr[i] != right.ptr[i])
                return false;

        return true;
    }

    T &operator[](size_t subscript) {
        if (subscript < 0 || subscript >= size)
            throw out_of_range("Subscript out of range");

        return ptr[subscript];
    }

    T operator[](size_t subscript) const {
        if (subscript < 0 || subscript >= size)
            throw out_of_range("Subscript out of range");

        return ptr[subscript];
    }

    void setString() {
        cout << "\nolá string\n";
    }
    void setInt() {
        cout << "\nolá int\n";
    }
    void setFloat() {
        cout << "\nolá float\n";
    }
};

// Template partial specialization: T is specified to be string.
template <>
class Array<string> {
    string *ptr;
    int size;
    int max_size;

   public:
    Array(int initial_size) : size(0) {
        max_size = 1;
        while (initial_size >= max_size)
            max_size *= 2;
        ptr = new string[max_size];
        cout << "string\n";
    }
    void setptr() {
        ptr[5] = "1000";
    }
};

int main() {
    Array<int> dict(10);
    Array<float> dict2(10);
    Array<string> *dict_specialized = new Array<string>(10);

    return 0;
}