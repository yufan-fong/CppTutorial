#include <iostream>

class Test {
private:
    int id;
    std::string name;

public:
    Test(): id(0), name(""){}

    Test(int id, std::string name): id(id), name(name){}

    void print() const {
        // has to be a const method
        std::cout << id << ": "<< name << std::endl;
    }

    // assignment operator
    const Test &operator=(const Test &other){
        std::cout << "Assignment running" << std::endl;
        this->id = other.id;
        this->name = other.name;
        return *this;
    }

    // copy constructor
    Test(const Test &other){
        std::cout << "Copy constructor running" << std::endl;
        this->id = other.id;
        this->name = other.name;
        // or just, *this = other;
    }
};

int main(){
    Test test1(10, "Mike");
    test1.print();

    Test test2(20, "Bob");
    test2 = test1;  // shallow copy by default
    test2.print();

    std::cout << std::endl;

    Test test4 = test1;  // copy constructor
    test4.print();

    return 0;
}