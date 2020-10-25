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
    return FeetInches(feet + a.getFeet(),inches + a.getInches());
}
FeetInches FeetInches::operator-(const FeetInches &a) {
    return FeetInches(feet - a.getFeet(), inches - a.getInches());
}