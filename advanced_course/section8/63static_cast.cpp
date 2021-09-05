#include <iostream>

class Parent {
public:
    void speak(){
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

    float value = 3.23;

    std::cout << (int)value << std::endl;
    std::cout << static_cast<int>(value) << std::endl;

    Parent *pp = &brother;
    Brother *pb = static_cast<Brother *>(&parent);  // prone to error
    std::cout << pb << std::endl;

    Parent *ppb = &brother;                         // Parent pointer to child object
    Brother *pbb = static_cast<Brother *>(ppb);     // Child pointer to parent pointer
    std::cout << pbb << std::endl;

    Parent &&p = Parent();                          // RValue reference to RValue
    Parent &&p2 = static_cast<Parent &&>(parent);   // RValue reference to LValue object
    p2.speak();

    return 0;
}