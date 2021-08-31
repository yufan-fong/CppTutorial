#include <iostream>

class Animal{   //abstract class
public:
    virtual void speak() = 0; // =0 means no implementation
    virtual void run() = 0;
};

class Dog: public Animal {
public:
    virtual void speak(){
        std::cout << "WOOF!" << std::endl;
    }
};

class Labrador: public Dog {
public:
    virtual void run(){
        std::cout << "Labrador running" << std::endl;
    }
};

void test(Animal &a){
    a.run();
}

int main(){
    //Animal animal;    // cannot
    //Dog dog;          // cannot
    Labrador lab;
    lab.speak();

    Animal *animals[5];
    animals[0] = &lab;
    animals[0]->speak();

    test(lab);

}