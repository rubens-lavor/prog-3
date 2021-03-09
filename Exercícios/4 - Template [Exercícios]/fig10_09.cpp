#include <typeinfo>

#include "Array.h"

using namespace std;


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
    }  
    cout << "\n\nAssigning 1000 to array1[5]" << endl;

    set_1000_na_posicao_5(array1);

    cout << "array1:\n"
         << array1;

    try {
        cout << "\nAttempt to assign 1000 to array1[15]" << endl;
    } catch (out_of_range &ex) {
        cout << "An exception occurred: " << ex.what() << endl;
    } 
}


template <class T>
void set_1000_na_posicao_5(Array<T> &array1) {
    if (typeid(int).name() == typeid(array1[0]).name()) {
        array1.setPtr(5, 1000);
    }

    if (typeid(float).name() == typeid(array1[0]).name()) {
        array1.setPtr(5, 1000.00);
        cout << fixed;
        cout << setprecision(2);
    }

}

// Template partial specialization: T is specified to be string.
template <>
void set_1000_na_posicao_5(Array<string> &array1) {
    array1.setPtr(5, "1000");
}

int main() {
    Array<int> array1;
    Array<int> array2;
    cout << "\n--- INTEIRO ---\n";
    funcaoArray(array1, array2);
    
    Array<float> array3(7);
    Array<float> array4(6);
    cout << "\n--- FLOAT ---\n";
    funcaoArray(array3, array4);

    Array<string> array_string1(6);
    Array<string> array_string2(8);
    cout << "\n--- STRING ---\n";
    funcaoArray(array_string1, array_string2);

    return 0;
}