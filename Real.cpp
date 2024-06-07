#include "Real.h"
#include <iostream>
#include <cmath>
#include <iomanip>

//returns the value of realNum to two decimal places
std::ostream& operator<<(std::ostream &out, const Real &rnum){
    out << std::fixed << std::setprecision(2) << rnum.realNum;
    return out;
}

//checks to see if two Real numbers are equal
//returns true if so, false if not
bool Real::operator==(Real rnum2) {
    if (fabs(realNum - rnum2.realNum) < 0.0001) {
        return true;
    }
    else {
        return false;
    }
}

//checks to see if this real num is less than another
//returns true if so, false if not
bool Real::operator<(Real rnum2) {
    if (realNum < rnum2.realNum) {
        return true;
    }
    else {
        return false;
    }
}
//checks to see if this real num is greater than another
//returns true if so, false if not
bool Real::operator>(const Real rnum2) {
    if (realNum > rnum2.realNum) {
        return true;
    }
    else {
        return false;
    }    
}

