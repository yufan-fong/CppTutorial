#include <iostream>
using namespace std;

class Animal {
public:
    void speak() {cout << "Grrrr" << endl;}
};

// Animal is super/parent class, Cat is sub-class
class Cat: public Animal {
public:
    void scratch(){cout << "YIKES" << endl;}
};

int main(){

    Animal a;
    a.speak();

    Cat cat;
    cat.speak();
    cat.scratch();

    return 0;
}