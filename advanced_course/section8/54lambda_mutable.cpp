#include <iostream>

int main(){
    int cats = 5;

    [cats]() mutable {      // capture cats by value
        cats = 8;           // mutable allows cats value to change
        std::cout << cats << std::endl;
    }();

    std::cout << cats << std::endl;     // cats remains unchanged outside of lambda

    return 0;
}