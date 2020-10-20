
/*
#include "Array.h"  // Array class definition

#include <iomanip>
#include <iostream>
#include <stdexcept>
using namespace std;



// overloaded input operator for class Array;
// inputs values for entire Array
template <class Type>
istream &operator>>(istream &input, Array<Type> &a) {
    for (size_t i = 0; i < a.size; ++i)
        input >> a.ptr[i];

    return input;  // enables cin >> x >> y;
}  // end function

// overloaded output operator for class Array
template <class Type>
ostream &operator<<(ostream &output, const Array<Type> &a) {
    // output private ptr-based array
    for (size_t i = 0; i < a.size; ++i) {
        output << setw(12) << a.ptr[i];

        if ((i + 1) % 4 == 0)  // 4 numbers per row of output
            output << endl;
    }  // end for

    if (a.size % 4 != 0)  // end last line of output
        output << endl;

    return output;  // enables cout << x << y;
}  // end function operator<<

*/
