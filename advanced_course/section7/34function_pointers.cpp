#include <iostream>

void test(){
    std::cout << "Hello" << std::endl;
}

int main(){
    test();

    void (*pTest)();    // creates function pointer that takes no parameters, returns void
    pTest = &test;      // set pTest to the defined function
    (*pTest)();         // dereference the pointer, call the function with ()

    // void (*pTest)() = test;
    // pTest();

    return 0;
}