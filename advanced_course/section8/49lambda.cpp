#include <iostream>

void test(void (*pFunc)()){
    pFunc();
}

int main(){

    auto func = [](){std::cout << "Hello" << std::endl;};     

    [](){std::cout << "Hello" << std::endl;}();         // () at the end
    func();                                             // calling the variable
    test(func);                                         // function pointer
    test([](){std::cout << "Hello" << std::endl;});

    return 0;
}