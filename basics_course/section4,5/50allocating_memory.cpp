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
    
    int *pInt = new int;
    *pInt = 8;
    cout << *pInt << endl;
    delete pInt;

    char *pMem = new char[1000];
    delete [] pMem;

    Animal *pAnimal = new Animal[5];
    delete [] pAnimal;
    // add '[]' after 'delete' if multiple obj pointers were created before

    pAnimal[3].setName("George");
    pAnimal[3].speak();

    return 0;
}