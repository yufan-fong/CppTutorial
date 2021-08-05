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

int main(){
    Animal *pCat1 = new Animal();  // pointer to an obj
    pCat1->setName("Freddy");
    pCat1->speak();
    delete pCat1;  
    // 'delete' is necessary when 'new' is called
    // may cause memory leak otherwise

    Animal *pCat2 = NULL;
    // to indicate that pointer is not pointing to anything
    // calling delete on NULL pointer may cause crash
    
    cout << sizeof(pCat1) << endl;
    // pointer is 8 bytes

    return 0;
}