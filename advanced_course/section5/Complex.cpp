#include "Complex.h"

namespace fyf {

Complex::Complex(): real(0), imaginary(0){}

Complex::Complex(double real, double imaginary): real(real), imaginary(imaginary){}

Complex::Complex(const Complex &other){  //copy constructor
    this->real = other.real;
    this->imaginary = other.imaginary;
}

const Complex &Complex::operator=(const Complex &other){
    this->real = other.real;
    this->imaginary = other.imaginary;
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Complex &c){
    out << "(" << c.getReal() << "," << c.getImaginary() << ")";
    return out;
}

Complex operator+(const Complex &c1, const Complex &c2){
    // complex as both parameters
    return Complex(c1.getReal() + c2.getReal(), c1.getImaginary() + c2.getImaginary());
}

Complex operator+(const Complex &c1, double d){
    // double as 2nd parameter
    return Complex(c1.getReal()+d, c1.getImaginary());
}

Complex operator+(double d, const Complex &c1){
    // double as 1st parameter
    return Complex(c1.getReal()+d, c1.getImaginary());
}

bool Complex::operator==(const Complex &other){
    return (real == other.real) && (imaginary == other.imaginary);
}

Complex Complex::operator*() const {
    return Complex(real, -imaginary);
}

}