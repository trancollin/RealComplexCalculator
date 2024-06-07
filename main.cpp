/*
 * Collin Tran
 * ctt200001
 */

#include <iostream>
#include <fstream> 
#include <string>
#include <vector>
#include <typeinfo>
#include <iomanip>
#include <cmath>
#include <sstream>

#include "Real.h"
#include "Complex.h"

using namespace std;

//prototypes
void makeNumbers(string equation);
void readFile(ifstream &in);
void correctOperation(vector<Real> &r, vector<Complex> &c, string op);
bool isValid(string &equation);

//for all templates, dynamic casting is used to determine how to handle the operation

//multiplies numbers and prints the result
template <typename num, typename num2>
void multiply(num a, num2 b){
    Complex *c, *c2;
    c = dynamic_cast<Complex*>(&a);
    c2 = dynamic_cast<Complex*>(&b);

    //if both num are real
    if(c == nullptr && c2 == nullptr){
        Real real(a.getNum(0) * b.getNum(0));
        cout << real << endl;
    }
    //if num1 is real and num2 is complex
    else if(c == nullptr && c2 != nullptr){
        Complex complex((a.getNum(0) * b.getNum(0)), (a.getNum(0) * b.getNum(1)));
        cout << complex << endl;
    }
    //if both num are complex
    else{
        Complex complex((a.getNum(0) * b.getNum(0)) + (a.getNum(1) * b.getNum(1) * -1), (a.getNum(0) * b.getNum(1)) + (a.getNum(1) * b.getNum(0)));
        cout << complex << endl;
    }
}

//adds numbers and prints the result
template <typename num, typename num2>
void add(num a, num2 b){
    Complex *c, *c2;
    c = dynamic_cast<Complex*>(&a);
    c2 = dynamic_cast<Complex*>(&b);
    
    //if both num are real
    if(c == nullptr && c2 == nullptr){
        Real real(a.getNum(0) + b.getNum(0));
        cout << real << endl;
    }
    //if num1 is real and num2 is complex
    else if(c == nullptr && c2 != nullptr){
        Complex complex(a.getNum(0) + b.getNum(0), b.getNum(1));
        cout << complex << endl;
    }
    //if both num are complex
    else{
        Complex complex(a.getNum(0) + b.getNum(0), a.getNum(1) + b.getNum(1));
        cout << complex << endl;
    }
}

//subtracts numbers
template <typename num, typename num2>
void subtract(num a, num2 b){
    Complex *c, *c2;
    c = dynamic_cast<Complex*>(&a);
    c2 = dynamic_cast<Complex*>(&b);

    //if both num are real
    if(c == nullptr && c2 == nullptr){
        Real real(a.getNum(0) - b.getNum(0));
        cout << real << endl;
    }
    //if num1 is real and num2 is complex
    else if(c == nullptr && c2 != nullptr){
        Complex complex(a.getNum(0) - b.getNum(0), b.getNum(1));
        cout << complex << endl;
    }
    //if num1 is complex and num2 is real
    else if(c!= nullptr && c2 == nullptr){
        Complex complex(a.getNum(0) - b.getNum(0), a.getNum(1));
        cout << complex << endl;
    }
    //if both num are complex
    else{
        Complex complex((a.getNum(0) - b.getNum(0)), a.getNum(1) - b.getNum(1));
        cout << complex << endl;
    }
}

//divides numbers
template <typename num, typename num2>
void divide(num a, num2 b){
    Complex *c, *c2;
    c = dynamic_cast<Complex*>(&a);
    c2 = dynamic_cast<Complex*>(&b);

    //if both num are real
    if(c == nullptr && c2 == nullptr){
        Real real(a.getNum(0) / b.getNum(0));
        cout << real << endl;
    }
    //if num1 is real and num2 is complex
    else if(c == nullptr && c2 != nullptr){
        Complex complex((a.getNum(0) * b.getNum(0)) / (pow(b.getNum(0), 2) + pow(b.getNum(1), 2)), 
        (a.getNum(0) * (b.getNum(1) * -1)) / (pow(b.getNum(0), 2) + pow(b.getNum(1), 2)));
        cout << complex << endl;
    }
    //if num1 is complex and num2 is real
    else if(c != nullptr && c2 == nullptr){
        Complex complex(a.getNum(0) / b.getNum(0), a.getNum(1) / b.getNum(0));
        cout << complex << endl;
    }
    //if both num are complex
    else {
        Complex complex((a.getNum(0) * b.getNum(0) + a.getNum(1) * b.getNum(1)) / (pow(b.getNum(0), 2) + pow(b.getNum(1), 2)),
        (a.getNum(1) * b.getNum(0) - a.getNum(0) * b.getNum(1)) / (pow(b.getNum(0), 2) + pow(b.getNum(1), 2)));
        cout << complex << endl;
    }
}

//checks to see if num1 is less than num2
//prints true if so, false if not
template <typename num, typename num2>
void lessThan(num a, num2 b){
    Complex *c, *c2;
    c = dynamic_cast<Complex*>(&a);
    c2 = dynamic_cast<Complex*>(&b);

    //if both num are real
    if(c == nullptr && c2 == nullptr){
        if(a.getNum(0) < b.getNum(0)){
            cout << "true" << endl;
        }
        else {
            cout << "false" << endl;
        }
    }
    //if num1 is real and num2 is complex
    else if(c == nullptr && c2 != nullptr){
        Complex complex(a.getNum(0), 0);
        Complex complex2(b.getNum(0), b.getNum(1));
        if (complex < complex2){
            cout << "true" << endl;
        }
        else {
            cout << "false" << endl;
        }
    }
    //if num1 is complex and num2 is real
    else if(c != nullptr && c2 == nullptr){
        Complex complex(a.getNum(0), a.getNum(1));
        Complex complex2(b.getNum(0), 0);
        if (complex < complex2){
            cout << "true" << endl;
        }
        else {
            cout << "false" << endl;
        }
    }
    //if both num are complex
    else{
        Complex complex(a.getNum(0), a.getNum(1));
        Complex complex2(b.getNum(0), b.getNum(1));
        if(complex < complex2) {
            cout << "true" << endl;
        }
        else {
            cout << "false" << endl;
        }
    }
}

//checks to see if num1 is greater than num2
//prints true if so, false if not
template <typename num, typename num2>
void moreThan(num a, num2 b){
    Complex *c, *c2;
    c = dynamic_cast<Complex*>(&a);
    c2 = dynamic_cast<Complex*>(&b);

    //if both num are real
    if(c == nullptr && c2 == nullptr){
        if(a.getNum(0) > b.getNum(0)){
            cout << "true" << endl;
        }
        else {
            cout << "false" << endl;
        }
    }
    //if num1 is real and num2 is complex
    else if(c == nullptr && c2 != nullptr){
        Complex complex(a.getNum(0), 0);
        Complex complex2(b.getNum(0), b.getNum(1));
        if (complex > complex2){
            cout << "true" << endl;
        }
        else {
            cout << "false" << endl;
        }
    }
    //if num1 is complex and num2 is real
    else if(c != nullptr && c2 == nullptr){
        Complex complex(a.getNum(0), a.getNum(1));
        Complex complex2(b.getNum(0), 0);
        if (complex > complex2){
            cout << "true" << endl;
        }
        else {
            cout << "false" << endl;
        }
    }
    //if both num are complex
    else{
        Complex complex(a.getNum(0), a.getNum(1));
        Complex complex2(b.getNum(0), b.getNum(1));
        if(complex > complex2) {
            cout << "true" << endl;
        }
        else {
            cout << "false" << endl;
        }
    }
}

//checks to see if num1 is equal to num2
//prints true if so, false if not
template <typename num, typename num2>
void equal(num a, num2 b){
    Complex *c, *c2;
    c = dynamic_cast<Complex*>(&a);
    c2 = dynamic_cast<Complex*>(&b);

    //if both num are real
    if(c == nullptr && c2 == nullptr){
        if(a.getNum(0) == b.getNum(0)){
            cout << "true" << endl;
        }
        else {
            cout << "false" << endl;
        }
    }
    //if num1 is real and num2 is complex
    else if(c == nullptr && c2 != nullptr){
        Complex complex(a.getNum(0), 0);
        Complex complex2(b.getNum(0), b.getNum(1));
        if (complex == complex2){
            cout << "true" << endl;
        }
        else {
            cout << "false" << endl;
        }
    }
    //if both num are complex
    else{
        Complex complex(a.getNum(0), a.getNum(1));
        Complex complex2(b.getNum(0), b.getNum(1));
        if(complex == complex2) {
            cout << "true" << endl;
        }
        else {
            cout << "false" << endl;
        }
    }
}
/*
 * performs the correct operation based on the operator found in the equation
 * depending on the size of the vectors, the function passes the appropriate numbers into the respective operation function
 * the function also passes the first integer used to denote the first number in the equation for the operations in which order matters
 */
void correctOperation(vector<Real> &r, vector<Complex> &c, string op, int first){
    char op_char = op[0];
    switch(op_char){
        case '*':
            if(r.size() == 2){
                multiply(r.at(0), r.at(1));
            }
            else if(c.size() == 2){
                multiply(c.at(0), c.at(1));
            }
            else {
                multiply(r.at(0), c.at(0));
            }
            break;
            
        case '+':
            if(r.size() == 2){
                add(r.at(0), r.at(1));
            }
            else if(c.size() == 2){
                add(c.at(0), c.at(1));
            }
            else {
                add(r.at(0), c.at(0));
            }
            break;

        case '-':
            if(r.size() == 2){
                subtract(r.at(0), r.at(1));
            }
            else if(c.size() == 2){
                subtract(c.at(0), c.at(1));
            }
            else if((r.size() == 1) && (first == 1)){
                subtract(r.at(0), c.at(0));
            }
            else {
                subtract(c.at(0), r.at(0));
            }
            break;

        case '/':
            if(r.size() == 2){
                divide(r.at(0), r.at(1));
            }
            else if(c.size() == 2){
                divide(c.at(0), c.at(1));
            }
            else if((r.size() == 1) && (first == 1)){
                divide(r.at(0), c.at(0));
            }
            else {
                divide(c.at(0), r.at(0));
            }
            break;

        case '<':
            if(r.size() == 2){
                lessThan(r.at(0), r.at(1));
            }
            else if(c.size() == 2){
                lessThan(c.at(0), c.at(1));
            }
            else if((r.size() == 1) && (first == 1)){
                lessThan(r.at(0), c.at(0));
            }
            else {
                lessThan(c.at(0), r.at(0));
            }
            break;

        case '>':
            if(r.size() == 2){
                moreThan(r.at(0), r.at(1));
            }
            
            else if(c.size() == 2){
                moreThan(c.at(0), c.at(1));
            }
            else if((r.size() == 1) && (first == 1)){
                moreThan(r.at(0), c.at(0));
            }
            else {
                moreThan(c.at(0), r.at(0));
            }
            break;

        case '=':
            if(r.size() == 2){
                equal(r.at(0), r.at(1));
            }
            else if(c.size() == 2){
                equal(c.at(0), c.at(1));
            }
            else {
                equal(r.at(0), c.at(0));
            }
            break;
    }
}
/*
 * takes the terms from the function and makes real or complex numbers out of them 
 * numbers are stored in vectors based off of their type
 * validity of terms and operator is checked in this program in order to save lines
 * terms are valid if they don't have more than one decimal, and the equation is valid if it uses a valid operator
 * operator between complex numbers (ex: the plus in 2+3i) is also checked
 * the functions records whether or not the first number in the equation is real, which is vital to division, subtraction, etc.
 * if the first number is real, first is set to 1, otherwise it remains 0
 * if everything is valid, the original equation is printed and the vectors, operator, and first integer are sent to correctOperation
 * if an invalid term or operator is found, the function ends
 */
void makeNumbers(string equation) {
    vector<Real>r;
    vector<Complex>c;
    double rnum = 0;
    int first = 0;
    string op = "";
    string term = "";
    string eq = equation;
    //makes first term into real number if no i is detected
    if(equation.substr(0, equation.find(' ')).find('i') == string::npos) {
            term = equation.substr(0, equation.find(' '));
            if(term.find('.') == term.rfind('.')){
                r.push_back(Real(stod(equation.substr(0, equation.find(' ')))));
                first = 1;
            }
            else {
                return;
            }
    }
    //makes complex num 0 + i if the term is just i
    else if(equation.at(0) == 'i'){
        c.push_back(Complex(0, 1));
    }
    //executes if the number is complex
    else {
        //loop checks for location of + or - in a complex number
        for(int i = 0; i < (int)equation.find(' '); i++) {
            if(isdigit(equation.at(i)) == 0 && equation.at(i) != 'i' && equation.at(i) != '.' && i != 0)
            {
                //checks to see invalid operator in complex num; if so, the function ends
                if(equation.at(i) != '+' && equation.at(i) != '-'){
                    return;
                }
                term = equation.substr(0, i);
                if(term.find('.') == term.rfind('.')) {
                    //makes complex number if + or - was detected
                    rnum = stod(equation.substr(0, i));
                    equation.erase(0, i);
                    //makes imaginary portion of complex num 1 if the latter half is just i
                    if(equation.at(1) == 'i')
                    {
                        c.push_back(Complex(rnum, 1));
                    }
                    //executes if latter half is not just i
                    else{
                        term = equation.substr(0, equation.find('i'));
                        if(term.find('.') == term.rfind('.')) {
                            c.push_back(Complex(rnum, stod(equation.substr(0, equation.find('i')))));   
                        }
                        else {
                            return;
                        }
                    }
                    break;
                }
                else{
                    return;
                }
            }
            //could not find + or - in complex num, num is just imaginary
            else if(i == (int)equation.find(' ') - 1){
                if(equation.at(0) == 'i')
                {
                    c.push_back(Complex(0, 1));
                }
                else {
                    term = equation.substr(0, equation.find('i'));
                    if(term.find('.') == term.rfind('.')) {
                        c.push_back(Complex(0, stod(equation.substr(0, equation.find('i')))));
                    }
                    else{
                        return;
                    }
                }
            }
        }
    }
    //gets operator used in equation and checks to see if it is valid
    op = equation.substr(equation.find(' ') + 1, 1);
    if((op == "+" || op == "-" || op == "*" || op == "/" || op == "<" || op == ">" || op == "=") && (isspace(equation.at(equation.find(' ') + 2)) != 0)){
        equation.erase(0, equation.find(' ') + 3);
        term = equation;
        //makes term real number is no i is detected
        if(equation.find('i') == string::npos) {
            if(equation.find('.') == equation.rfind('.')) {
                r.push_back(Real(stod(equation))); 
            }
            else {
                return;
            }
        }
        //makes complex num 0 + i if the term is just i
        else if(equation.at(0) == 'i'){
            c.push_back(Complex(0, 1));
        }
        //executes if the number is complex
        else {
            //loop checks for the location of the + or - in the complex num
            for(int i = 0; i < (int)equation.size(); i++) {
                if(isdigit(equation.at(i)) == 0 && equation.at(i) != 'i' && equation.at(i) != '.' && i != 0)
                {
                    //checks to see invalid operator in complex num; if so, the function ends
                    if(equation.at(i) != '+' && equation.at(i) != '-'){
                        return;
                    }
                    term = equation.substr(0, i);
                    if(term.find('.') == term.rfind('.')) {
                        rnum = stod(equation.substr(0, i));
                        equation.erase(0, i);
                        //makes imaginary portion of complex num 1 if the latter half is just i
                        if(equation.at(1) == 'i')
                        {
                            c.push_back(Complex(rnum, 1));
                        }
                        //makes complex number if + or - was detected
                        else {
                            term = equation.substr(0, equation.find('i'));
                            if(term.find('.') == term.rfind('.')){
                                c.push_back(Complex(rnum, stod(equation.substr(0, equation.find('i')))));
                            }
                            else {
                                return;
                            }
                        }
                        break;
                    }
                    else {
                        return;
                    }
                }
                //could not find + or -
                else if(i == (int)equation.size() - 1){
                    //makes imaginary portion of complex num 1 if the latter half is just i
                    if(equation.at(0) == 'i')
                    {
                        c.push_back(Complex(0, 1));
                    }
                    else {
                        term = equation.substr(0, equation.find('i'));
                        if(term.find('.') == term.rfind('.')){
                            c.push_back(Complex(0, stod(equation.substr(0, equation.find('i')))));
                        }
                        else {
                            return;
                        }
                    }
                }
            }
        }
    }
    else{
        return;
    }
    //if everything is valid, equation is printed and correctOperation is executed
    cout << eq << '\t';
    correctOperation(r, c, op, first);
}

bool isValid(string &equation){
    int index = (int)equation.size() - 1;
    while(isspace(equation.at(index))){
        equation.erase(index);
        index--;
    }
    for(int i = 0; i < (int)equation.size(); i++){
        if((isalpha(equation.at(i)) != 0) && (equation.at(i) != 'i')) {
            return false;
        }
    }
    return true;
}

//a line from the file is taken and put into string equation as long as another line that isn't whitespace can be taken from the file
//if equation has no invalid input, it is used as the parameter for makeNumbers
void readFile(ifstream &in) {
    string equation = "";
    
    while(getline(in, equation) && equation != ""){
        if(!isspace(equation.at(0))){
            if(isValid(equation)){
                makeNumbers(equation);   
            }
        }
    }
}

/*
 * creates ifstream inFS, takes input for filename and opens the file specified
 * if the file opens, the file is read
 * the file closes at the end
 */
int main()
{
    ifstream inFS;
    string fileName;
    fileName = "sample_expressions.txt";
    //cin >> fileName;
    inFS.open(fileName);
    if(inFS.is_open()){
        readFile(inFS);
    }
    inFS.close();
    
    return 0;
}
