#include <iostream>

template<class T>
void print(T n){
    std::cout << "Template version: " << n << std::endl;
}

//overloading
void print(int value){  
    std::cout << "Non-template version: " << value << std::endl;
}

int main(){
    print<std::string>("Hello");
    print<int>(5);

    print("Hi there");  // type inference
    print(44);      // no type inference, non-template version
    print<>(44);    // template version

    return 0;
}