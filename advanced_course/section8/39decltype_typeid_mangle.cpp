#include <iostream>
#include <typeinfo>

int main(){
    std::string value;
    std::cout << typeid(value).name() << std::endl;

    decltype(value) person = "Bob";
    std::cout << typeid(person).name() << std::endl;

    return 0;
}