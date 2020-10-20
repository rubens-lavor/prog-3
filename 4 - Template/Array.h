#ifndef ARRAY_H
#define ARRAY_H

#include <iomanip>
#include <iostream>
#include <stdexcept>

using namespace std;
template <class Type>
class Array {
    template <typename>
    friend std::ostream &operator<<(std::ostream &, const Array<Type> &);
    template <typename>
    friend std::istream &operator>>(std::istream &, Array<Type> &);

   public:
    explicit Array(int arraySize = 10)
        : size(arraySize > 0 ? arraySize : throw invalid_argument("Array size must be greater than 0")),
          ptr(new Type[size]) {
        ptr = new Type[arraySize];
        for (size_t i = 0; i < size; ++i)
            ptr[i] = {};  // set pointer-based array element
    }

    //template <class Type>
    Array(const Array &arrayToCopy)
        : size(arrayToCopy.size),
          ptr(new Type[size]) {
        for (size_t i = 0; i < size; ++i)
            ptr[i] = arrayToCopy.ptr[i];  // copy into object
    }                                     // end Array copy constructor

    ~Array() {
        delete[] ptr;  // release pointer-based array space
    }                  // end destructor

    size_t getSize() const {
        return size;  // number of elements in Array
    }

    Type getPtr(size_t indice) const {
        return ptr[indice];
    }

    void setPtr(size_t indice, Type elemento) {
        ptr[indice] = elemento;
    }

    const Array<Type> &operator=(const Array &right) {
        if (&right != this)  // avoid self-assignment
        {
            if (size != right.size) {
                delete[] ptr;          // release space
                size = right.size;     // resize this object
                ptr = new Type[size];  // create space for Array copy
            }                          // end inner if

            for (size_t i = 0; i < size; ++i)
                ptr[i] = right.ptr[i];  // copy array into object
        }                               // end outer if

        return *this;  // enables x = y = z, for example
    }

    bool operator==(const Array &right) const {
        if (size != right.size)
            return false;  // arrays of different number of elements

        for (size_t i = 0; i < size; ++i)
            if (ptr[i] != right.ptr[i])
                return false;  // Array contents are not equal

        return true;  // Arrays are equal
    }

    Type &operator[](size_t subscript) {
        // check for subscript out-of-range error
        if (subscript < 0 || subscript >= size)
            throw out_of_range("Subscript out of range");

        return ptr[subscript];  // reference return
    }                           // end function operator[]

    Type operator[](size_t subscript) const {
        // check for subscript out-of-range error
        if (subscript < 0 || subscript >= size)
            throw out_of_range("Subscript out of range");

        return ptr[subscript];  // returns copy of this element
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

   private:
    size_t size;  // pointer-based array size
    Type *ptr;    // pointer to first element of pointer-based array
};

template <class Type>
istream &operator>>(istream &input, Array<Type> &a) {
    Type elemento;
    for (size_t i = 0; i < a.getSize(); ++i) {
        input >> elemento;
        a.setPtr(i, elemento);
    }

    return input;  // enables cin >> x >> y;
}

template <class Type>
ostream &operator<<(ostream &output, const Array<Type> &a) {
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
