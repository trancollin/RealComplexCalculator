#ifndef COMPLEX_H
#define COMPLEX_H

#include "Real.h"

class Complex : public Real {
    public:
        //default constructor
        Complex(){
            imagNum = 0;
        }
        //constructor for if a real and imaginary number are passed
        Complex(double rnum, double inum) : Real(rnum) {
            imagNum = inum; 
            realNum = rnum;
        }
        //accessor method
        //returns real number portion if 0 is passed
        //return imaginary number portion if any other number is passed; the number used is 1 in all operation functions
        double getNum(int k) const{
            if(k == 0){
                k+=k;
                return realNum;
            }
            else {
                k+=k;
                return imagNum;
            }
        }
        //mutator method
        virtual void setNum(double num) {
            imagNum = num;
        }
        //overloaded operators
        friend std::ostream& operator<<(std::ostream &out, const Complex &inum);
        bool operator==(Complex inum2);
        bool operator<(Complex inum2);
        bool operator>(Complex inum2);
        
    private:
        double imagNum;
};
#endif