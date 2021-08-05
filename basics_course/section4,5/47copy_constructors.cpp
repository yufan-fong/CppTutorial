#include <iostream>
using namespace std;

class Animal {
private:
    string name;
    
public:
    Animal(){cout << "Animal created" << endl;};
    Animal(const Animal &other): name(other.name){cout << "Animal created by copying" << endl;};
    // syntax: const <class> <reference>
    // copies field from 'other' animal object to the present animal object
    // private fields can be accessed in constructor because they are within the same class
    // non-const methods cannot be called in copy constructors because of const in front
    void setName(string name){this->name = name;};
    void speak() const {cout << "My name is: " << name << endl;}
};

int main(){
    Animal animal1;
    animal1.setName("Freddy");

    Animal animal2 = animal1;

    animal1.speak();
    animal2.speak();

    animal2.setName("Bob");
    animal1.speak();
    animal2.speak();
    
    Animal animal3(animal2);
    animal3.speak();
}