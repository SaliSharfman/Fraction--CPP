#include "Fraction.hpp"
#include <cmath>
using namespace std;
using namespace ariel;

Fraction:: Fraction(const int& numerator,const int& denominator):numerator(numerator), denominator(denominator){
    if (denominator == 0)
        throw invalid_argument("devision by zero");
    
}
Fraction:: Fraction(const double& d){
    double num =d;
    int den =1;
    while(round(num) != num){
        num=num*10;
        den*=10;
    }
    this->numerator = int(num);
    this->denominator = den;
    this->reduce();
}
void Fraction::reduce(){
    int sign = 1;
    if(this->numerator<0){
        sign*=-1;
        this->numerator*=-1;
    }
    if(this->denominator<0){
        sign*=-1;
        this->denominator*=-1;
    }
    int d = abs(this->denominator);
    for(int i=min(this->numerator,this->denominator);i>1;i--){
        if(this->numerator%i==0 && this->denominator%i==0 ){
            this->numerator = this->numerator/i;
            this->denominator = this->denominator/i;
            break;
        }
    }
    this->numerator*=sign;
}

ostream &ariel::operator <<(ostream &os, const Fraction &f) {
    os << f.numerator;
    if(f.numerator!=0)
        os << '/' << f.denominator;
    return os;
}


istream &ariel::operator >>(istream &is,  Fraction &f) {
    int num, den;
    is >> num >> den;
    f = Fraction(num, den);
    return is;
}

Fraction Fraction:: operator+(const Fraction &other) const{
    Fraction f(this->numerator*other.denominator + other.numerator*this->denominator, this->denominator*other.denominator);
    f.reduce();
    return f;
}

Fraction Fraction:: operator+(const double &other) const{
    
    return *this + Fraction(other);
}


Fraction Fraction:: operator-(const Fraction &other) const{
    
    return *this + Fraction(-other.numerator,other.denominator);
}

Fraction Fraction:: operator-(const double &other) const{ 
    
    return *this - Fraction(other);
}

Fraction Fraction:: operator/(const Fraction &other) const{
    if (other.numerator == 0){
        throw invalid_argument("devision by zero");
        return *this;
    }
    return *this * Fraction(other.denominator,other.numerator);
}

Fraction Fraction:: operator*(const Fraction &other) const{
    
    Fraction f(this->numerator*other.numerator,this->denominator*other.denominator);
    f.reduce();
    return f;
}

Fraction ariel:: operator*(const double &f1 ,const Fraction &f2) {
    
    return Fraction(f1) * f2;
}

// Postfix increment operator
Fraction Fraction::operator++(int) {
    // Make a copy of the current object
    Fraction old = *this;
    // Increment numerator
    this->numerator += this->denominator;
    // Return the old (pre-incremented) object
    this->reduce();
    return old;
}

// Prefix reduction operator
Fraction& Fraction::operator--() {
    // Increment numerator
    this->numerator -= this->denominator;
    this->reduce();
    // Return updated object
    return *this;
 }

bool Fraction:: operator == (const string &str) const{
    return((str=="0" &&this->numerator == 0) || str== to_string(this->numerator)+"/"+to_string(this->denominator));
}

bool Fraction:: operator >= (const double &other) const{ 
    if(other==0)
        return *this+1 >=1;
    return this->numerator >= this->denominator*other;
}

bool Fraction:: operator >= (const Fraction &other) const{
    return *this-other>=0;
}

bool Fraction:: operator > (const double &other) const{
    if(other==0)
        return *this+1 >1;
    return this->numerator > this->denominator*other;
}

bool Fraction:: operator > (const Fraction &other) const{ 
    return *this-other>0;
}
