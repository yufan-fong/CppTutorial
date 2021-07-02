#include <iostream>
using namespace std;

class Animal {
private:
    string name;
    
public:
    void setName(string name){this->name = name;};
    // this refers to the object
    void speak() const {cout << "My name is: " << name << endl;}
    // const disallows any change in object properties
    // helps reduce bugs

};

int main(){

    const double PI = 3.141592; // use upperase for const variables
    cout << PI << endl;

    Animal animal;
    animal.setName("Freddy");
    animal.speak();

    int value = 8;
    int *pValue = &value;
    cout << *pValue << endl;
    int number = 11;
    pValue = &number;
    cout << *pValue << endl;

    int value2 = 3;
    // int * const pValue2 = &value2;
    int *pValue2 = &value2;
    cout << *pValue2 << endl;

    int number2 = 4;
    pValue2 = &number2;  
    // error with: int * const pValue2 = &value2;
    // const pointer to an int, cannot reassign pointer
    *pValue2 = 4;       
    // error with: const int *pValue2 = &value2;
    // pValue2 is a pointer to a const int, cannot reassign value
    cout << *pValue2 << endl;

    return 0;
}