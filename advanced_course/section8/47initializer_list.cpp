#include <iostream>
#include <vector>
#include <initializer_list>

class Test{
public:
    Test(std::initializer_list<std::string> texts){
        for(auto value: texts){
            std::cout << value << std::endl;
        }
    }

    void print(std::initializer_list<std::string> texts){
        for(auto value: texts){
            std::cout << value << std::endl;
        }
    }
};

int main(){
    std::vector<int> numbers {1,3,4,5};
    std::cout << numbers[3] << std::endl;

    Test fruits{"orange", "banana","apple"};
    fruits.print({"one","two","three"});

    return 0;
}