#include <iostream>
#include <vector>

int main(){

    auto animals = {"dog", "cat", "lion"};
    for(auto name: animals){
        std::cout << name << std::endl;
    }

    std::string greeting = "Hello";
    for(auto c:greeting){
        std::cout << c << std::endl;
    }

    std::vector<int> numbers;
    numbers.push_back(4);
    numbers.push_back(22);
    numbers.push_back(451);
    for(int number:numbers){
        std::cout << number << std::endl;
    }

    return 0;
}