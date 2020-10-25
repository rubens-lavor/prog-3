#include "feetinches3.h"

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
bool FeetInches::operator>(const FeetInches &) {}

// Overloaded <
bool FeetInches::operator<(const FeetInches &) {}

// Overloaded ==
bool FeetInches::operator==(const FeetInches &) {}
