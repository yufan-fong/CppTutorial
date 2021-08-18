#include <iostream>
#include <vector>

int main(){

    // std::vector<double> numbers;
    std::vector<double> numbers(20);
    std::cout << "Size: " << numbers.size() << std::endl;

    int capacity = numbers.capacity();
    std::cout << "Capacity: " << capacity << std::endl;

    // Demonstrates how capacity doubles when the array exceeds its allocated memory
    for(int i=0;i<1000;i++){
        if(numbers.capacity() != capacity){
            capacity = numbers.capacity();
            std::cout << "Capacity: " << capacity << std::endl;
        }
        numbers.push_back(i);
    }

    

    return 0;
}
