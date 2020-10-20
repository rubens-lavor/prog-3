// Fig. 10.9: fig10_09.cpp
// Array class test program.
#include <iostream>
#include <stdexcept>
#include <typeinfo>

#include "Array.h"
using namespace std;

template <class Type>
void funcaoArray(Array<Type> array1, Array<Type> array2) {
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
    Array<Type> array3(array1);

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

    cout << fixed;
    cout << std::setprecision(2);
    cout << "array1:\n"
         << array1;

    try {
        cout << "\nAttempt to assign 1000 to array1[15]" << endl;
    } catch (out_of_range &ex) {
        cout << "An exception occurred: " << ex.what() << endl;
    }  // end catch
}

int main() {
    
    
    /*
    Array<string> str1(7);  // seven-element Array
    Array<string> str2;     // 10-element Array by default
    

    funcaoArray(str1, str2);
    */

    Array<int> int1;  // seven-element Array
    Array<int> int2;  // 10-element Array by default

    funcaoArray(int1, int2);

    Array<float> flt1(7);  // seven-element Array
    Array<float> flt2(6);  // 10-element Array by default

    funcaoArray(flt1, flt2);
}
