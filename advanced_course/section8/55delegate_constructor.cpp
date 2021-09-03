#include <iostream>

class Parent{
    int dogs;
    std::string text;

public:
    Parent(){
        dogs = 5;
        std::cout << "No param parent constructor " << std::endl;
    }

    // it is possible to do the following in C++11:
    // Parent(): Parent("hello"){}

    Parent(std::string text){
        dogs = 5;
        this->text = text;
        std::cout << "String parent constructor" << std::endl;
    }
};

class Child:public Parent{
public:
    Child(){}
    //Child(): Parent("hello"){}
};

int main(){
    Parent parent;
    Child child;
    return 0;
}