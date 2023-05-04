#include "Fraction.hpp"
#include <iostream>
#include <cmath>
using namespace std;
using namespace ariel;

//constructors
Fraction:: Fraction(const int& numerator,const int& denominator):numerator(numerator), denominator(denominator){
    if (denominator == 0)
        throw invalid_argument("devision by zero");
    this->reduce();
    
}
Fraction:: Fraction(const double& d){
    double num =d;
    int den =1;
    while(round(num) != num && den < 1000){
        num=num*10;
        den*=10;
    }
    this->numerator = round(num);
    this->denominator = den;
    this->reduce();
}

//uclid algorithm for finding the gratest common devidor between 2 integer numbers.
int gcd(int a,int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

//reducing the frugtion
void Fraction:: reduce(){
    if(this->numerator == 0)
        this-> denominator =1;
    else if (this->numerator%this->denominator ==0 || this->denominator%this->numerator ==0||1){
        int sign = 1;
        if(this->numerator<0){
            sign*=-1;
            this->numerator*=-1;
        }
        if(this->denominator<0){
            sign*=-1;
            this->denominator*=-1;
        }
        int a = max(this->numerator,this->denominator);
        int b = this ->numerator +this ->denominator -a;
        int commonDivisor = gcd(a, b);
        numerator /= commonDivisor;
        denominator /= commonDivisor;
        this->numerator*=sign;
    }
}

//output
ostream &ariel::operator <<(ostream &os, const Fraction &fraction) {
    Fraction f = fraction;
    f.reduce();
    int sign =1;
    if (f.denominator < 0)
        sign = -1;
    os << f.numerator * sign;
    if(f.numerator!=0)
        os << '/' << f.denominator * sign;
    return os;
}

//input
istream &ariel::operator >>(istream &is,  Fraction &f){
    int num, den;
    char delimiter;

    if (!(is >> num)) {
        throw runtime_error("Error: Invalid input for numerator.");
    }

     is >> ws; // Skip leading whitespace

    // Check if there is a delimiter
    if (!is.eof() && (is.peek() == ',' || is.peek() == ' ')) 
        is >> delimiter;

    if (!(is >> den)) {
        throw runtime_error("Error: Invalid input for denominator.");
    }
    if(den == 0)
          throw runtime_error("devision by zero");
    f = Fraction(num, den);
    return is;
}

//add
Fraction Fraction:: operator+(const Fraction &other) const{
    int max = numeric_limits<int>::max();
    int min = numeric_limits<int>::min();
    //overflow check
    if ((this->numerator == max ^ this->denominator == max)
        || (this->numerator <= min + 100 && other.numerator <= min + 100))
        throw overflow_error("overflow");
    return Fraction(this->numerator*other.denominator + other.numerator*this->denominator, this->denominator*other.denominator);
}

//sub
Fraction Fraction:: operator-(const Fraction &other) const{
    int max = std::numeric_limits<int>::max();
    int min = std::numeric_limits<int>::min();
    //overflow check
    if ((this-> numerator <= min + 100 && other.numerator <= min + 100)
            || (this-> numerator >= max - 100 && other.numerator <= min + 100))
        throw overflow_error("overflow");
    return *this + Fraction(-other.numerator,other.denominator);
}

//dev
Fraction Fraction:: operator/(const Fraction &other) const{
    int max = std::numeric_limits<int>::max();
    //overflow check
    if ((this-> denominator == max && this-> numerator < max - 100)
            || (this-> numerator == max && this-> denominator != max))
        throw overflow_error("overflow");

    //devition by zero check
    if (other.numerator == 0)
        throw runtime_error("devision by zero");

    return Fraction (this->numerator*other.denominator,this->denominator*other.numerator);
}

//mul
Fraction Fraction:: operator*(const Fraction &other) const{
    int max = std::numeric_limits<int>::max();

    //overflow check
    if ((this->numerator == max ^ this->denominator == max)
            || (other.numerator == max && other.denominator != max))
        throw overflow_error("overflow");
    return Fraction (this->numerator*other.numerator,this->denominator*other.denominator);
}


// Prefix increment operator
Fraction& Fraction::operator++() {
    // Increment 
   *this=*this+1;
    // Return updated object
    return *this;
 }
 
// Postfix increment operator
Fraction Fraction::operator++(int) {
    // Make a copy of the current object
    Fraction old = *this;
    // Increment 
    *this=*this+1;
    // Return the old (pre-incremented) object
    return old;
}

// Postfix reduction operatorFraction ariel:: operator*(const double &f1 ,const Fraction &f2) {
Fraction Fraction::operator--(int) {
    // Make a copy of the current object
    Fraction old = *this;
    // Increment
    *this=*this-1;
    return old;
}

// Prefix reduction operator
Fraction& Fraction::operator--() {
    // Increment
    *this=*this-1;
    // Return updated object
    return *this;
 }

//equals to string
bool Fraction:: operator == (const string &str) const{
    return((str=="0" &&this-> numerator == 0) || str== to_string(this-> numerator)+"/"+to_string(this-> denominator));
}

//equals to fraction
bool Fraction:: operator == (const Fraction &other) const{
    Fraction tmp1 = *this;
    Fraction tmp2 = other;
    tmp1.reduce();
    tmp2.reduce();
    return tmp1.numerator == tmp2.numerator && tmp1.denominator == tmp2.denominator;
}

//grater equals
bool Fraction:: operator >= (const double &other) const{ 
    if(other==0)
        return *this+1 >=1;
    return this->numerator >= this->denominator*other;
}

//grater
bool Fraction:: operator > (const double &other) const{
    if(other==0)
        return *this+1 >1;
    return this->numerator > this->denominator*other;
}


