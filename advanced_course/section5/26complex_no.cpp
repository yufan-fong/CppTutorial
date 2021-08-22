#include <iostream>

class Complex{
private:
    double real;
    double imaginary;

public:
    Complex(): real(0), imaginary(0){};

    Complex(double real, double imaginary): real(real), imaginary(imaginary){};

    Complex(const Complex &other){  //copy constructor
        this->real = other.real;
        this->imaginary = other.imaginary;
    }

    const Complex &operator=(const Complex &other){
        this->real = other.real;
        this->imaginary = other.imaginary;
        return *this;
    }

    double getReal() const {return real;}

    double getImaginary() const {return imaginary;}
};

std::ostream &operator<<(std::ostream &out, const Complex &c){
    out << "(" << c.getReal() << "," << c.getImaginary() << ")";
    return out;
}

int main(){
    Complex c1;
    Complex c2(2,3);
    Complex c3 = c1; // c3(c1), copy constructor

    std::cout << c2 << std::endl;
    std::cout << c3 << " " << c1 << std::endl;

    return 0;
}