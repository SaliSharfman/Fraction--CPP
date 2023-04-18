#include "doctest.h"

#include <iostream>
#include <string>
using namespace std;

#include "sources/Fraction.hpp"
using namespace ariel;

const double eps =0.0001;
TEST_CASE("creating_fraction")
{
    CHECK_THROWS(Fraction(5,0));
    CHECK_NOTHROW(Fraction(5,7));
    CHECK_NOTHROW(Fraction(2.5674));
    CHECK(Fraction(2,3)=="2/3");
    CHECK(Fraction(0,3)=="0");
    CHECK(Fraction(0.8)=="4/5");
}

TEST_CASE("reduce")
{
    Fraction f1(20,30);
    Fraction f2(-47,-5);
    Fraction f3(-49,7);
    Fraction f4(12,-60);
    CHECK(f1=="20/30");
    CHECK(f2=="-47/-5");
    CHECK(f3=="-49/7");
    CHECK(f4=="12/-60");
    CHECK_NOTHROW(f1.reduce());
    CHECK_NOTHROW(f2.reduce());
    CHECK_NOTHROW(f3.reduce());
    CHECK_NOTHROW(f4.reduce());
    CHECK_NOTHROW(Fraction(2.5674));
    CHECK(f1=="2/3");
    CHECK(f2=="47/5");
    CHECK(f3=="-7/1");
    CHECK(f4=="-1/5");
}

TEST_CASE("grather_than")
{
    Fraction f1(24,2);
    CHECK(f1>=12);
    CHECK(f1>12-eps);
    CHECK(!(f1>=12+eps));
    CHECK(!(f1>12));
    CHECK(!(f1>12+eps));

}

TEST_CASE("addition")
{
    Fraction f1(1,3);
    Fraction f2(-1,-6);
    CHECK(f1+f2=="1/2");
    CHECK(f1+0.3>=0.6);
    CHECK(!(f1+0.3>=0.64));
    CHECK(f1++=="1/3");
    CHECK(f1=="4/3");
    CHECK(f1+f2+0.5=="2/1");

}


TEST_CASE("subtraction")
{
    Fraction f1(-1,-3);
    Fraction f2(1,6);
    CHECK(f1-f2=="1/6");
    CHECK(f1-0.3>=0);
    CHECK(!(f1-0.3>=0.04));
    CHECK(--f1=="-2/3");
    CHECK(f1=="-2/3");
    CHECK(f1-f2=="-5/6");
}

TEST_CASE("multiplication")
{
    Fraction f1(-1,-3);
    Fraction f2(1,6);
    CHECK(f1*f2=="1/18");
    CHECK(0.5*f1=="1/6");
    CHECK(1*f1=="1/3");
    CHECK(-2*f2=="-1/3");
    CHECK(0*f1=="0");
    CHECK(0*f2=="0");

}

TEST_CASE("division")
{
    Fraction f1(-1,-3);
    Fraction f2(1,6);
    CHECK(f1/f2=="2/1");
    CHECK(f2/2=="1/12");
    CHECK(f1/1.5=="2/9");
    CHECK_THROWS(f2/0);
    CHECK_THROWS(f1/(f1-f1));
    CHECK(f2/f2=="1/1");

}

