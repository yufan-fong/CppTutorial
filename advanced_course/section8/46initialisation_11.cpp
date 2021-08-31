#include <iostream>
#include <vector>

int main(){

    int value{5};
    std::cout << value << std::endl;

    int value2{};       // initialise as 0
    std::cout << value2 << std::endl;

    std::string text{"Heeyyyy"};
    std::cout << text << std::endl;

    int numbers[]{1,4,5,22};
    std::cout << numbers[3] << std::endl;

    int *pInts = new int[4]{33,2,1,44};
    std::cout << pInts[2] << std::endl;
    delete pInts;

    int *pInt2{};  // equivalent to int *pInt2 = nullptr;

    std::vector<std::string> names {"Sue", "Joe", "Hig"};
    std::cout << names[1] << std::endl;

    return 0;
}