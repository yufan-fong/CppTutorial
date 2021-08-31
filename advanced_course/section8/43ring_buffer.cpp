#include <iostream>
#include "ring.h"

int main(){

    ring<std::string> textring(3);     // ring buffer
    textring.add("one");
    textring.add("two");
    textring.add("three");
    textring.add("four");

    for(int i=0; i<textring.size(); i++){
        std::cout << textring.get(i) << std::endl;
    }

    return 0;
}