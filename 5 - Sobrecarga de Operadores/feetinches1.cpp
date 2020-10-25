#include "feetinches1.h"

void FeetInches::simplify() {
    int cont = 0;
    if (this->inches > 0) {
        while (this->inches > 12) {
            cont++;
            this->inches -= 12;
        }
        this->feet += cont;
    } else {
        while (this->inches < 0) {
            cont++;
            this->inches += 12;
        }
        this->feet -= cont;
    }
}

FeetInches FeetInches::operator+(const FeetInches &a) {
    return FeetInches(a.getFeet() + feet, a.getInches()+ inches);
}  // Overloaded +
FeetInches operator-(const FeetInches &a, const FeetInches &b) {}  // Overloaded -