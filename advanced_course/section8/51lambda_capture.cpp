#include <iostream>

int main(){
    int one = 1;
    int two = 2;
    int three = 3;

    // capture one and two by value
    [one, two](){std::cout << one << ", " << two << std::endl;}();

    // capture all local variables by value
    [=](){std::cout << one << ", " << two << std::endl;}();

    // default capture all local variables by value, but capture three by reference
    [=, &three](){three=7; std::cout << one << ", " << two << std::endl;}();
    std::cout << three << std::endl;

    // capture all local variables by reference
    [&](){std::cout << one << ", " << two << std::endl;}();
    
    // default capture all local variables by reference, but capture two by value
    [&, two](){std::cout << one << ", " << two << std::endl;}();

    return 0;
}