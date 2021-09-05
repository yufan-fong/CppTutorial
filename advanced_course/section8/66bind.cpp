#include <iostream>
#include <functional>

class Test {
public:
    int T_add(int a, int b, int c){
        std::cout << a << ", " << b << ", " << c << std::endl;
        return a+b+c;
    }
};

int add(int a, int b, int c){
    std::cout << a << ", " << b << ", " << c << std::endl;
    return a+b+c;
}

void run(std::function<int(int, int)> func){
    func(7,3);
}

int main(){

    auto sum = std::bind(add,3,4,5);
    sum();

    // using placeholders
    auto sum2 = std::bind(add, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
    std::cout << sum2(10,20,30) << std::endl;

    auto sum3 = std::bind(add, std::placeholders::_2, std::placeholders::_1, 10);
    std::cout << sum3(20,30) << std::endl;

    // using standard functions
    run(sum3);

    // binding to class methods
    Test test;
    auto sum4 = std::bind(&Test::T_add, test, std::placeholders::_2, std::placeholders::_1, 10);
    std::cout << sum4(15,25) << std::endl;

    return 0;
}