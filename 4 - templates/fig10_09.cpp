// Fig. 10.9: fig10_09.cpp
// Array class test program.
#include <iostream>
#include <stdexcept>
#include <typeinfo>
#include "Array.h"
using namespace std;

template <class Type>
void funcaoArray (Array<Type> &array1, Array<Type> &array2){

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
    cout << "\nEnter 17 integers:" << endl;
    cin >> array1 >> array2;

    cout << "\nAfter input, the Arrays contain:\n"
         << "array1:\n"
         << array1
         << "array2:\n"
         << array2;
    
    // use overloaded inequality (!=) operator
    cout << "\nEvaluating: array1 != array2" << endl;

    if ( !(array1 == array2)){

        cout << "array1 and array2 are not equal" << endl;
    }
    Array<string> array3(array1);  // invokes copy constructor

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

    // use overloaded subscript operator to create rvalue
    cout << "\narray1[5] is " << array1[5];

    // use overloaded subscript operator to create lvalue
    cout << "\n\nAssigning 1000 to array1[5]" << endl;

    auto tipo = array1[0];

    /*
    cout << "\n string -> " << typeid( string ).name() << endl;
    cout << "\n char -> " << typeid( char ).name() << endl;
    */



    array1[5] = array1.setMil(tipo);
    cout << "array1:\n"
         << array1;
    
    try {
        cout << "\nAttempt to assign 1000 to array1[15]" << endl;
        array1[15] = array1.setMil(array1[0]);  // ERROR: subscript out of range
    }                          // end try
    catch (out_of_range &ex) {
        cout << "An exception occurred: " << ex.what() << endl;
    }  // end catch
}


int main() {
    Array<string> str1(7);  // seven-element Array
    Array<string> str2;     // 10-element Array by default

    funcaoArray(str1,str2);

    /*

    Array<int> int1(7);  // seven-element Array
    Array<int> int2;     // 10-element Array by default

    funcaoArray(int1,int2);

    Array<string> str1(7);  // seven-element Array
    Array<string> str2;     // 10-element Array by default

    funcaoArray(str1,str2);
    
    */
    // print integers1 size and contents
    
    
    
}  // end main
