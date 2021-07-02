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

    Animal *pAnimal = new Animal[26];

    char c = 'a';
    for (int i=0; i<26; i++, c++){
        string animalName(1,c);
        // cout << animalName << endl;
        pAnimal[i].setName(animalName);
        pAnimal[i].speak();
    }
    delete [] pAnimal;  

    return 0;
}