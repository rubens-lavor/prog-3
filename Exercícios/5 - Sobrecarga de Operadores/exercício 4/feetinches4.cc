#include "feetinches4.h"

void FeetInches::simplify() {
    if (this->inches > 0) {
        while (this->inches >= 12) {
            this->feet++;
            this->inches -= 12;
        }
    } else {
        while (this->inches < 0) {
            this->feet--;
            this->inches += 12;
        }
    }
}

FeetInches FeetInches::operator+(const FeetInches &a) {
    return FeetInches(feet + a.getFeet(), inches + a.getInches());
}
FeetInches FeetInches::operator-(const FeetInches &a) {
    return FeetInches(feet - a.getFeet(), inches - a.getInches());
}

// Prefix ++
FeetInches FeetInches::operator++() {
    inches++;
    simplify();
    return *this;
}

// Postfix ++
FeetInches FeetInches::operator++(int) {
    FeetInches temp = *this;
    ++*this;
    return temp;
}

// Overloaded >
bool FeetInches::operator>(const FeetInches &a) {
    simplify();
    return (feet > a.feet);
}

// Overloaded <
bool FeetInches::operator<(const FeetInches &a) {
    return !(*this > a) && !(*this == a);
}

// Overloaded ==
bool FeetInches::operator==(const FeetInches &a) {
    simplify();
    return (feet == a.feet && inches == a.inches);
}

// overloaded input operator for class FeetInches;
// inputs values for entire FeetInches
istream &operator>>(istream &input, FeetInches &a) {
    input >> a.feet;
    input >> a.inches;
    a.simplify();
    return input;  // enables cin >> first >> second;
}

// overloaded output operator for class FeetInches
ostream &operator<<(ostream &output, const FeetInches &a) {
    output << a.feet << " feet, " << a.inches << " inches";
    return output;  // enables cout << first << second;
}
