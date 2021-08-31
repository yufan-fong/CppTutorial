#include <iostream>
#include "ring.h"

int main(){

    ring<std::string> textring(3);     // ring buffer
    textring.add("one");
    textring.add("two");
    textring.add("three");
    textring.add("four");

    // C++98 style
    for(ring<std::string>::iterator it=textring.begin(); it != textring.end(); it++){
        std::cout << *it << std::endl;
    }

    std::cout << std::endl;

    // C++11 style
    for(std::string value: textring){
        std::cout << value << std::endl;
    }

    return 0;
}