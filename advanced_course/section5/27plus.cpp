#include "Complex.h"
#include "Complex.cpp"  // or `g++ -o 27plus.exe 27plus.cpp Complex.cpp` in terminal to link up

int main(){
    fyf::Complex c1(4,5);
    fyf::Complex c2(2,3);

    std::cout << c1+c2 << std::endl;

    fyf::Complex c3(4,2);
    fyf::Complex c4 = c3 + 7;

    std::cout << c4 << std::endl;

    return 0;
}