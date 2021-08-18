#include <iostream>
#include <map>

class Person{
private:
    std::string name;
    int age;

public:

    // default constructor without any parameters is needed
    Person(): name(""), age(0) {
        std::cout << "No param" << std::endl;
    }

    Person(std::string name, int age):name(name),age(age){
        std::cout << "Yes param" << std::endl;
    }

    Person(const Person &other){
        std::cout << "Copy constructor" << std::endl;
        name = other.name;
        age = other.age;
    }

    void print() const{
        std::cout << name << ": " << age << std::endl;
    }
};

int main(){

    std::map<int, Person> people;

    // map values are Person objects
    people[0] = Person("Mike", 40);     // constructors with & w/o params are called in this line
    people[12] = Person("Sue", 32);
    people[5] = Person("Raj", 20);

    people.insert(std::make_pair(19, Person("Ali",24)));
    people.insert(std::make_pair(23, Person("Sue",13)));

    for(std::map<int, Person>::iterator it=people.begin(); it!=people.end(); it++){
        std::cout << it->first << ": " << std::flush;
        it->second.print();     // second refers to the person object
    }
    return 0;
}