#include <iostream>

class Test{


};

template<typename T>
void call(T &&arg){
    //check(arg);       // does not evaluate the arg type as desired
    //check(static_cast<T>(arg));
    check(std::forward<T>(arg));
}

void check(Test &test){
    std::cout << "LValue" << std::endl;
}

void check(Test &&test){
    std::cout << "RValue" << std::endl;
}

int main(){
    Test test;
    auto &&t = test;
    call(test);
    call(Test());

    return 0;
}