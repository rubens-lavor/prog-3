#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;

template <class T>
class Array {
    size_t size;
    T *ptr;

    template <typename>
    friend std::ostream &operator<<(std::ostream &, const Array<T> &);
    template <typename>
    friend std::istream &operator>>(std::istream &, Array<T> &);

   public:
    explicit Array(int arraySize = 10)
        : size(arraySize > 0 ? arraySize : throw invalid_argument("Array size must be greater than 0")),
          ptr(new T[size]) {
        ptr = new T[arraySize];
        for (size_t i = 0; i < size; ++i)
            ptr[i] = {};
    }

    Array(const Array &arrayToCopy)
        : size(arrayToCopy.size),
          ptr(new T[size]) {
        for (size_t i = 0; i < size; ++i)
            ptr[i] = arrayToCopy.ptr[i];
    }

    ~Array() {
        delete[] ptr;
    }

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
};

template <class T>
istream &operator>>(istream &input, Array<T> &a) {
    T elemento;
    for (size_t i = 0; i < a.getSize(); ++i) {
        input >> elemento;
        a.setPtr(i, elemento);
    }

    return input;  // enables cin >> x >> y;
}

template <class T>
ostream &operator<<(ostream &output, const Array<T> &a) {
    // output private ptr-based array
    for (size_t i = 0; i < a.getSize(); ++i) {
        output << setw(12) << a.getPtr(i);
        if ((i + 1) % 4 == 0)
            output << endl;
    }

    if (a.getSize() % 4 != 0)
        output << endl;

    return output;  // enables cout << x << y;
}

#endif
