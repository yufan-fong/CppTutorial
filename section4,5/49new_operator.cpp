#include <iostream>
using namespace std;

class Animal {
private:
    string name;
    
public:
    Animal(){
        cout << "Animal created" << endl;
    }
    
    Animal(const Animal &other): 
            name(other.name) {
        cout << "Animal created by copying" << endl;
    }

    ~Animal(){
        cout << "Destructor called" << endl;
    }
    
    void setName(string name) {
        this->name = name;
    }

    void speak() const {
        cout << "My name is: " << name << endl;
    }
};

Animal createAnimal(){ 
    // return obj from a fx
    // temporary obj created to return from a local fx
    Animal a;
    a.setName("Bertie");
    return a;
}

Animal *createAnimalPointer(){ 
    Animal *pAnimal = new Animal();
    // 'new' ensures that memory is not deleted until 'delete is called'
    pAnimal->setName("Fergie");
    return pAnimal;
}

int main(){
    Animal frog = createAnimal();
    frog.speak();

    Animal *pFrog = createAnimalPointer();
    // this is efficient because only 8bytes of pointer is copied
    // as compared to many bytes of obj properties
    pFrog -> speak();
    delete pFrog;

    return 0;
}