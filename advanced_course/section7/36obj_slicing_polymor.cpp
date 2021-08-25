#include <iostream>

class Parent {
private:
    int one;

public:
    Parent(): one(0) {}

    // need to define the no-param constructor if copy constructor is defined
    Parent (const Parent &other){
        std::cout << "Copy parent" << std::endl;
    }
    void print(){
        std::cout << "Print Parent" << std::endl;
    }
};

class Child: public Parent {
private:
    int two;
public:
    Child(): two(0){}
    
    void print(){
        std::cout << "Print Child" << std::endl;
    }
};

int main(){
    Child c1;
    Parent &p1 = c1;
    p1.print();

    Parent p2 = Child();
    p2.print();

    return 0;
}