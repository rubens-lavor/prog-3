#include <iostream>
#include <stdexcept>
#include <typeinfo>
#include <iomanip>

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
    Array(int arraySize = 10)
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

// Template partial specialization: T is specified to be string.
/*
template <>
class Array<string> {
    size_t size;
    string *ptr;

    template <typename>
    friend std::ostream &operator<<(std::ostream &, const Array<string> &);
    template <typename>
    friend std::istream &operator>>(std::istream &, Array<string> &);

   public:
    Array(int arraySize = 10)
        : size(arraySize > 0 ? arraySize : throw invalid_argument("Array size must be greater than 0")),
          ptr(new string[size]) {
        ptr = new string[arraySize];
        for (size_t i = 0; i < size; ++i)
            ptr[i] = {};
    }

    Array(const Array &arrayToCopy)
        : size(arrayToCopy.size),
          ptr(new string[size]) {
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
   /*

    size_t getSize() const {
        return size;
    }

    string getPtr(size_t indice) const {
        return ptr[indice];
    }

    void setPtr(size_t indice, string elemento) {
        ptr[indice] = elemento;
    }

    const Array<string> &operator=(const Array &right) {
        if (&right != this) {
            if (size != right.size) {
                delete[] ptr;
                size = right.size;
                ptr = new string[size];
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

    string &operator[](size_t subscript) {
        if (subscript < 0 || subscript >= size)
            throw out_of_range("Subscript out of range");

        return ptr[subscript];
    }

    string operator[](size_t subscript) const {
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
*/

template <class T>
void funcaoArray(Array<T> array1, Array<T> array2) {
    cout << "Size of Array array1 is "
         << array1.getSize()
         << "\nArray after initialization:\n"
         << array1.getSize();

    // print array2 size and contents
    cout << "\nSize of Array array2 is "
         << array2.getSize()
         << "\nArray after initialization:\n"
         << array2.getSize();

    // input and print array1 and array2
    cout << "\nEnter " << array1.getSize() + array2.getSize() << " values:" << endl;
    cin >> array1 >> array2;

    cout << "\nAfter input, the Arrays contain:\n"
         << "array1:\n"
         << array1
         << "array2:\n"
         << array2;

    // use overloaded inequality (!=) operator
    cout << "\nEvaluating: array1 != array2" << endl;

    if (!(array1 == array2)) {
        cout << "array1 and array2 are not equal" << endl;
    }

    //Array <string> array3(array1);  // invokes copy constructor
    Array<T> array3(array1);

    cout << "\nSize of Array array3 is "
         << array3.getSize()
         << "\nArray after initialization:\n"
         << array3;

    cout << "\nAssigning array2 to array1:" << endl;
    array1 = array2;

    cout << "array1:\n"
         << array1
         << "array2:\n"
         << array2;

    cout << "\nEvaluating: array1 == array2" << endl;

    if (array1 == array2)
        cout << "array1 and array2 are equal" << endl;

    try {
        // use overloaded subscript operator to create rvalue
        cout << "\narray1[5] is " << array1[5];
    }  // end try
    catch (out_of_range &ex) {
        cout << "An exception occurred: " << ex.what() << endl;
    }  // end catch

    // use overloaded subscript operator to create lvalue
    cout << "\n\nAssigning 1000 to array1[5]" << endl;


    if (typeid(string).name() == typeid(array1[0]).name()) {
        array1.setString();
        //array1.setPtr(5,"1000");
    }

    if (typeid(int).name() == typeid(array1[0]).name()) {
        array1.setInt();
        array1.setPtr(5, 1000);
    }

    if (typeid(float).name() == typeid(array1[0]).name()) {
        array1.setFloat();
        array1.setPtr(5, 1000.00);
    }

    //cout << fixed;
    //cout << setprecision(2);
    cout << "array1:\n"
         << array1;

    try {
        cout << "\nAttempt to assign 1000 to array1[15]" << endl;
    } catch (out_of_range &ex) {
        cout << "An exception occurred: " << ex.what() << endl;
    }  // end catch
}

template <>
void funcaoArray(Array<string> array1, Array<string> array2) {
    cout << "Size of Array array1 is "
         << array1.getSize()
         << "\nArray after initialization:\n"
         << array1.getSize();

    // print array2 size and contents
    cout << "\nSize of Array array2 is "
         << array2.getSize()
         << "\nArray after initialization:\n"
         << array2.getSize();

    // input and print array1 and array2
    cout << "\nEnter " << array1.getSize() + array2.getSize() << " values:" << endl;
    cin >> array1 >> array2;

    cout << "\nAfter input, the Arrays contain:\n"
         << "array1:\n"
         << array1
         << "array2:\n"
         << array2;

    // use overloaded inequality (!=) operator
    cout << "\nEvaluating: array1 != array2" << endl;

    if (!(array1 == array2)) {
        cout << "array1 and array2 are not equal" << endl;
    }

    //Array <string> array3(array1);  // invokes copy constructor
    Array<string> array3(array1);

    cout << "\nSize of Array array3 is "
         << array3.getSize()
         << "\nArray after initialization:\n"
         << array3;

    cout << "\nAssigning array2 to array1:" << endl;
    array1 = array2;

    cout << "array1:\n"
         << array1
         << "array2:\n"
         << array2;

    cout << "\nEvaluating: array1 == array2" << endl;

    if (array1 == array2)
        cout << "array1 and array2 are equal" << endl;

    try {
        // use overloaded subscript operator to create rvalue
        cout << "\narray1[5] is " << array1[5];
    }  // end try
    catch (out_of_range &ex) {
        cout << "An exception occurred: " << ex.what() << endl;
    }  // end catch

    // use overloaded subscript operator to create lvalue
    cout << "\n\nAssigning 1000 to array1[5]" << endl;


    if (typeid(string).name() == typeid(array1[0]).name()) {
        array1.setString();
        array1.setPtr(5,"1000");
    }

    /*

    if (typeid(int).name() == typeid(array1[0]).name()) {
        array1.setInt();
        array1.setPtr(5, 1000);
    }

    if (typeid(float).name() == typeid(array1[0]).name()) {
        array1.setFloat();
        array1.setPtr(5, 1000.00);
    }

    */

    //cout << fixed;
    //cout << setprecision(2);
    cout << "array1:\n"
         << array1;

    try {
        cout << "\nAttempt to assign 1000 to array1[15]" << endl;
    } catch (out_of_range &ex) {
        cout << "An exception occurred: " << ex.what() << endl;
    }  // end catch
}

int main() {
    Array<int> dict(10);
    Array<int> dict2(10);
    funcaoArray(dict,dict2);

    Array<string> dict_specialized(10);
    Array<string> dict_specialized2(10);
    funcaoArray(dict_specialized,dict_specialized2);

    return 0;
}