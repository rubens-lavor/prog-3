#include "feetinches1.h"

void FeetInches::simplify() {
    if (this->inches > 0) {
        while (this->inches > 12) {
            this->feet ++;
            this->inches -= 12;
        }
    } else {
        while (this->inches < 0) {
            this->feet --;
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