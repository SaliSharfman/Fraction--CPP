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

ostream &ariel::operator <<(ostream &os, const Fraction &f){
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

Fraction ariel:: operator+(const Fraction &f1 ,const Fraction &f2){
    Fraction f(f1.numerator*f2.denominator + f2.numerator*f1.denominator, f1.denominator*f2.denominator);
    f.reduce();
    return f;
}

Fraction ariel:: operator+(const Fraction &f1 ,const double &f2){
    
    return f1 + Fraction(f2);
}


Fraction ariel:: operator-(const Fraction &f1 ,const Fraction &f2){
    
    return f1 + Fraction(-f2.numerator,f2.denominator);
}

Fraction ariel:: operator-(const Fraction &f1 ,const double &f2){
    
    return f1 - Fraction(f2);
}

Fraction ariel:: operator/(const Fraction &f1 ,const Fraction &f2){
    if (f2.numerator == 0){
        throw invalid_argument("devision by zero");
        return f1;
    }
    return f1 * Fraction(f2.denominator,f2.numerator);
}

Fraction ariel:: operator*(const Fraction &f1 ,const Fraction &f2){
    
    Fraction f(f1.numerator*f2.numerator,f1.denominator*f2.denominator);
    f.reduce();
    return f;
}

Fraction ariel:: operator*(const double &f1 ,const Fraction &f2){
    
    return Fraction(f1) * f2;
}

// Postfix increment operator
Fraction Fraction::operator++(int) {
    // Make a copy of the current object
    Fraction old = *this;
    // Increment numerator
    numerator += denominator;
    // Return the old (pre-incremented) object
    this->reduce();
    return old;
}

// Prefix reduction operator
Fraction& Fraction::operator--() {
    // Increment numerator
    numerator -= denominator;
    this->reduce();
    // Return updated object
    return *this;
 }

bool ariel:: operator == (const Fraction &f1, const string &str){
    return((str=="0" &&f1.numerator == 0) || str== to_string(f1.numerator)+"/"+to_string(f1.denominator ));
}

bool ariel:: operator >= (const Fraction &f1, const double &f2){
    if(f2==0)
        return f1+1 >=1;
    return f1.numerator >= f1.denominator*f2;
}

bool ariel:: operator >= (const Fraction &f1, const Fraction &f2){
    return f1-f2>=0;
}

bool ariel:: operator > (const Fraction &f1 ,const double &f2){
    if(f2==0)
        return f1+1 >1;
    return f1.numerator > f1.denominator*f2;
}

bool ariel:: operator > (const Fraction &f1 ,const Fraction &f2){
    return f1-f2>0;
}


