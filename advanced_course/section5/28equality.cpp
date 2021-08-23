#include "Complex.h"
#include "Complex.cpp"

int main(){
    fyf::Complex c1(3,2);
    fyf::Complex c2(4,4);

    if(c1 == c2){
        std::cout << "Equal" << std::endl;
    }
    else{
        std::cout << "Not equal" << std::endl;
    }
}