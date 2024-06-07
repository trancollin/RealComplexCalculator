#include "Complex.h"
#include <iostream>
#include <cmath>
#include <iomanip>

//returns the value of the complex number depending on circumstances
//if the real num portion is 0, just the imaginary portion is returned
//if the imaginary portion is 0, just the real portion is returned
//if the imaginary portion is positive, both portions are printed with a + in between
//if the imaginary portion is negative, both portions are printed, since the negative imaginary would print like real-imaginary
std::ostream& operator<<(std::ostream &out, const Complex &inum){
    if(inum.realNum == 0) {
        out << std::fixed << std::setprecision(2) << inum.imagNum << "i";
    }
    else if(inum.imagNum == 0) {
        out << std::fixed << std::setprecision(2) << inum.realNum;
    }
    else if(inum.imagNum > 0) {
            out << std::fixed << std::setprecision(2) << inum.realNum << "+" << inum.imagNum << "i";
    }
    else {
            out << std::fixed << std::setprecision(2) << inum.realNum << inum.imagNum << "i";   
    }

    return out;
}

//if the real number and imaginary portions of two complex numbers are equal, return true, else return false
bool Complex::operator==(Complex inum2) {
    if (fabs(realNum - inum2.realNum) < 0.0001 && fabs(imagNum - inum2.imagNum) < 0.0001) {
        return true;
    }
    else {
        return false;
    }
}
//if the magnitude of this complex num is less than another, return true, else return false
bool Complex::operator<(const Complex inum2) {
    if (fabs(sqrt(pow(realNum, 2) + pow(imagNum, 2))) < fabs(sqrt(pow(inum2.realNum, 2) + pow(inum2.imagNum, 2)))) {
        return true;
    }
    else {
        return false;
    }
}
//if the magnitude of this complex num is greater than another, return true, else return false
bool Complex::operator>(Complex inum2) {
    if (fabs(sqrt(pow(realNum, 2) + pow(imagNum, 2))) > fabs(sqrt(pow(inum2.realNum, 2) + pow(inum2.imagNum, 2)))) {
        return true;
    }
    else {
        return false;
    }
}

