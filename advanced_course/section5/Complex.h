#pragma once
#include <iostream>

namespace fyf {

class Complex{
private:
    double real;
    double imaginary;

public:
    Complex();
    Complex(double real, double imaginary);
    Complex(const Complex &other);  //copy constructor 
    const Complex &operator=(const Complex &other);
    double getReal() const {return real;}
    double getImaginary() const {return imaginary;}
    bool operator==(const Complex &other);
    Complex operator*() const;
};

std::ostream &operator<<(std::ostream &out, const Complex &c);

Complex operator+(const Complex &c1, const Complex &c2);
Complex operator+(const Complex &c1, double d);
Complex operator+(double d, const Complex &c1);
}