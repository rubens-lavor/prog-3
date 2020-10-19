// Fig. 10.9: fig10_09.cpp
// Array class test program.
#include <iostream>
#include <stdexcept>

#include <typeinfo>

#include "Array.h"
using namespace std;


int main() {
    Array<string> integers1(7);  // seven-element Array
    Array<string> integers2;     // 10-element Array by default

    // print integers1 size and contents
    
    cout << "Size of Array integers1 is "
         << integers1.getSize()
         << "\nArray after initialization:\n"
         << integers1;

    // print integers2 size and contents
    cout << "\nSize of Array integers2 is "
         << integers2.getSize()
         << "\nArray after initialization:\n"
         << integers2;

    // input and print integers1 and integers2
    cout << "\nEnter 17 integers:" << endl;
    cin >> integers1 >> integers2;

    cout << "\nAfter input, the Arrays contain:\n"
         << "integers1:\n"
         << integers1
         << "integers2:\n"
         << integers2;
    
    // use overloaded inequality (!=) operator
    cout << "\nEvaluating: integers1 != integers2" << endl;

    if ( !(integers1 == integers2)){

        cout << "integers1 and integers2 are not equal" << endl;
    }

    // create Array integers3 using integers1 as an
    // initializer; print size and contents
    Array<string> integers3(integers1);  // invokes copy constructor

    cout << "\nSize of Array integers3 is "
         << integers3.getSize()
         << "\nArray after initialization:\n"
         << integers3;
        

    // use overloaded assignment (=) operator
    cout << "\nAssigning integers2 to integers1:" << endl;
    integers1 = integers2;  // note target Array is smaller

    cout << "integers1:\n"
         << integers1
         << "integers2:\n"
         << integers2;


    // use overloaded equality (==) operator
    cout << "\nEvaluating: integers1 == integers2" << endl;

    if (integers1 == integers2)
        cout << "integers1 and integers2 are equal" << endl;

    // use overloaded subscript operator to create rvalue
    cout << "\nintegers1[5] is " << integers1[5];

    // use overloaded subscript operator to create lvalue
    cout << "\n\nAssigning 1000 to integers1[5]" << endl;

    auto tipo = integers1[0];
    /*
    cout << "\n string -> " << typeid( string ).name() << endl;
    cout << "\n char -> " << typeid( char ).name() << endl;
    */



    integers1[5] = integers1.setMil(tipo);
    cout << "integers1:\n"
         << integers1;


    //tipo = 3;
    /*

    
   NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE

o -> PKc

5ArrayINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE 
    
    */


    // attempt to use out-of-range subscript
    
    try {
        cout << "\nAttempt to assign 1000 to integers1[15]" << endl;
        integers1[15] = integers1.setMil(integers1[0]);  // ERROR: subscript out of range
    }                          // end try
    catch (out_of_range &ex) {
        cout << "An exception occurred: " << ex.what() << endl;
    }  // end catch
    
}  // end main
