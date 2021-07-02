#include <iostream>
using namespace std;

/* As good practice, incude 'virtual' in front of any class
methods that can be overridden. Base class must have 'virtual'
if there are overridden methods in subclass.

Destructors should be virtual too to ensure that the specific
subclass destructor is called.
*/

class Animal{    // top of hierarchy, base class
    public:
    virtual void speak(){
        // 'virtual' allows this method to be overrode in subclasses
        // only required for base class
        cout << "????" << endl;
    }

    /* OR make pure virtual method
    virtual void speak() = 0;
    any subclass must override this method
    */
};

class Cat: public Animal {     // subclass of Animal
    public:
    void speak(){
        cout << "RrrRRrr" << endl;
    }
    ~Cat(){};
};

class HouseCat: public Cat{     // subclass of Cat
    public:
    void speak(){
        cout << "Meow" << endl;
    }
    ~HouseCat(){};
};

int main(){
    
    Animal* pAnimal1 = new Cat;  
    // base class pointer can refer to any derived class object
    
    pAnimal1->speak();

    Animal* pAnimal2 = new HouseCat;

    pAnimal2->speak();

    delete pAnimal1;
    delete pAnimal2;
    
    return 0;
}