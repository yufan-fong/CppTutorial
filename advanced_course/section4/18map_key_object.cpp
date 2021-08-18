#include <iostream>
#include <map>

class Person{
private:
    std::string name;
    int age;

public:

    // default constructor without any parameters is needed
    Person(): name(""), age(0) {
        //std::cout << "No param" << std::endl;
    }

    Person(std::string name, int age):name(name),age(age){
        //std::cout << "Yes param" << std::endl;
    }

    Person(const Person &other){
        // std::cout << "Copy constructor" << std::endl;
        name = other.name;
        age = other.age;
    }

    void print() const{
        std::cout << name << ": " << age << std::endl;
    }

    bool operator<(const Person &other) const{
        if(name == other.name){
            return age < other.age;
        } else{
            return name < other.name;
        }
    }

};

int main(){

    std::map<Person, int> people;

    people[Person("Mike", 40)] = 1;
    people[Person("Sue", 31)] = 25;
    people[Person("Raj", 23)] = 30;

    for(std::map<Person, int>::iterator it=people.begin(); it!=people.end(); it++){
        std::cout << it->second << ": " << std::flush;
        it->first.print();  // print() has to be a const method
    }
    return 0;
}