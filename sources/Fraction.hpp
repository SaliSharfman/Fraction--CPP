#pragma once
#include "sstream"
using namespace std;

namespace ariel
{
    class Fraction{
        private:
        int numerator, denominator;

        public:
        Fraction():numerator(0),denominator(1){}
        Fraction(const int& numerator,const int& denominator);
        Fraction(const double& rational);
        void reduce();
      
        //output
        friend ostream &operator <<(ostream &stream, const Fraction &fraction);

        //input
        friend istream &operator >>(istream &stream,  Fraction &fraction);

        //getters
        int getNumerator() const {return this->numerator;};
        int getDenominator() const {return this->denominator;};

        //add
        Fraction operator +(const Fraction &other) const;
        Fraction operator +(const double &other) const {return *this + Fraction(other);}
        friend Fraction operator +(const double &fraction1 ,const Fraction &fraction2){return fraction2 + fraction1;}

        //sub
        Fraction operator -(const Fraction &other) const;
        Fraction operator -(const double &other) const {return *this - Fraction(other);}
        friend Fraction operator -(const double &fraction1 ,const Fraction &fraction2){return Fraction(fraction1) - fraction2;}

        //div
        Fraction operator /(const Fraction &other) const;
        Fraction operator /(const double &other) const{return *this / Fraction(other);}
        friend Fraction operator /(const double &fraction1 ,const Fraction &fraction2){return  Fraction(fraction1)/ fraction2;}

        //mul
        Fraction operator *(const Fraction &other) const;
        friend Fraction operator *(const double &fraction1 ,const Fraction &fraction2){return fraction2 * fraction1;}

        
        // Prefix increment operator
        Fraction& operator++();
        // Postfix increment operator
        Fraction operator++(int);
        // Prefix reduction operator
        Fraction& operator--();
        // Postfix reduction operator
        Fraction operator--(int);

        //equals
        bool operator ==(const string &other) const;
        bool operator ==(const double &other) const{return *this == Fraction(other);}
        bool operator ==(const Fraction &other) const;
        friend bool operator ==(const double &fraction1 ,const Fraction &fraction2) {return fraction2 == fraction1;}

        //not equals
        bool operator !=(const double &other) const {return !(*this == other);}
        bool operator !=(const Fraction &other) const {return !(*this == other);}
        friend bool operator !=(const double &fraction1 ,const Fraction &fraction2) {return fraction2 != fraction1;}

        //greater equals
        bool operator >=(const double &other) const;
        bool operator >=(const Fraction &other) const{return *this-other>=0;}
        friend bool operator >=(const double &fraction1 ,const Fraction &fraction2) {return !(fraction2>fraction1);}

        //smaller equals
        bool operator <=(const Fraction &other) const {return !(*this>other);}
        friend bool operator <=(const double &fraction1 ,const Fraction &fraction2) {return !(fraction2<fraction1);}

        //greater
        bool operator >(const double &other) const;
        bool operator >(const Fraction &other) const {return *this-other>0;}
        friend bool operator >(const double &fraction1 ,const Fraction &fraction2) {return !(fraction2>=fraction1);}

        //smaller
        bool operator <(const double &other) const {return other > *this;}
        bool operator <(const Fraction &other) const {return other > *this;}
        friend bool operator <(const double &fraction1 ,const Fraction &fraction2) {return fraction2>fraction1;}

    };
}
