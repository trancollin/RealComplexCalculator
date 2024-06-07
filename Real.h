#ifndef REAL_H
#define REAL_H

#include <iostream>


class Real{
    public:
        //default constructor
        Real(){
            realNum = 0;
        }
        //constructor if parameter rnum is passed
        Real(double rnum){
            realNum = rnum;
        }
        //the parameter in the accessor function is a work around to the template bugging if two different accessor functions were used 
        //ex: it would say that Real numbers weren't allowed to use getImagNum (the original accessor for complex) despite dynamic casting to make sure this wasn't possible
        //therefore, I made the accessor in Real virtual, and included a parameter to choose whether to return the real or imaginary portion of a complex number
        //the Real accessor returns realNum no matter what int is passed
        // k += k is to prevent a warning from popping up (unused variable)
        virtual double getNum(int k) const{
            k += k;
            return realNum;
        }
        //mutator method
        virtual void setNum(double num){
            realNum = num;
        }
        //overloaded operators
        friend std::ostream& operator<<(std::ostream &out, const Real &rnum);
        bool operator==(Real rnum2);
        bool operator<(Real rnum2);
        bool operator>(Real rnum2);
        
    protected:
        double realNum;
};
#endif 