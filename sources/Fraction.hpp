#pragma once
#include "iostream"
using namespace std;

namespace ariel
{
    class Fraction{
        private:
        int numerator, denominator;

        public:
        Fraction(const int& numerator,const int& denominator);
        Fraction(const double& rational);
        void reduce();
      
        //output
        friend ostream &operator <<(ostream &stream, const Fraction &fraction);

        //input
        friend istream &operator >>(istream &stream,  Fraction &fraction);
        string toString() const;

        Fraction operator +(const Fraction &other) const;
        Fraction operator +(const double &other) const;

        Fraction operator -(const Fraction &other) const;
        Fraction operator -(const double &other) const;

        Fraction operator /(const Fraction &other) const;

        Fraction operator *(const Fraction &other) const;
        friend Fraction operator *(const double &fraction1 ,const Fraction &fraction2);

        
        
        // Prefix reduction operator
        Fraction& operator--();
        // Postfix increment operator
        Fraction operator++(int);

        bool operator ==(const string &other) const;

        bool operator >=(const double &other) const;
        bool operator >=(const Fraction &other) const;

        bool operator >(const double &other) const;
        bool operator >(const Fraction &other) const;

    };
}
