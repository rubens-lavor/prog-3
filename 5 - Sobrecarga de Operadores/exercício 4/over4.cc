#include <iostream>
#include "feetinches4.h"

using namespace std;
int main()
 {
 FeetInches first, second; // Define two objects.
 
 // Get a distance for the first object.
 cout << "Enter a distance in feet and inches.\n";
 cin >> first;
 // Get a distance for the second object.
 cout << "Enter another distance in feet and inches.\n";
 cin >> second;
 // Display the values in the objects.
 cout << "The values you entered are:\n";
 cout << first << " and " << second << endl;
 return 0;
 }
