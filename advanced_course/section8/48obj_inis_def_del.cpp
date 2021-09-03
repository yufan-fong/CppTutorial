// Object initialisation, default and delete

#include <iostream>

class Person{
private:
    int id{3};          // braces initialisation, done for all new objects
    std::string name{"Mike"};
public:
    Person() = default;   //default/implicit constructor was lost when a custom constructor was defined

    Person(int id): id(id) {
    }

    Person(const Person &other) = default;  //default implementation of copy constructor
    
    Person &operator=(const Person &other) = delete;    //remove the default implementation

    void print(){
        std::cout << id << ": " << name << std::endl;
    }
};

int main(){

    Person person;
    person.print();

    Person person2(34);
    person2.print();

    return 0;
}