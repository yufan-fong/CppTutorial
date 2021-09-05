#include <iostream>

class Parent {
public:
    virtual void speak(){
        std::cout << "Parent" << std::endl;
    }
};

class Brother: public Parent {

};

class Sister: public Parent {

};

int main(){
    Parent parent;
    Brother brother;
    Sister sister;

    Parent *pp = &brother;
    Sister *ps1 = dynamic_cast<Sister *>(pp);       // returns nullptr
    Sister *ps2 = static_cast<Sister *>(pp);        // returns valid reference
    Sister *ps3 = reinterpret_cast<Sister *>(pp);   // returns valid reference

    if(ps3 == nullptr){
        std::cout << "Invalid cast" << std::endl;
        // occurs when parent object is casted to a child pointer (downcast)
    } else {
        std::cout << ps3 << std::endl;
    }
    
    return 0;
}