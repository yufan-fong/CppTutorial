#include <iostream>

int main(){

    int value = 1;
    value++; // postfix: use the variable, then implement
    ++value; // prefix: implement then use the variable

    std::cout << "Start: " << value << std::endl;

    std::cout << "Postfix: " << value++ << std::endl;
    std::cout << value << std::endl;

    std::cout << "Prefix: " << ++value << std::endl;
    std::cout << value << std::endl;

    return 0;
}