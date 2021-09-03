#include <iostream>
#include <vector>

class Test{
public:
    Test(){
        std::cout << "constructor" << std::endl;
    }

    Test(int i){
        std::cout << "int constructor" << std::endl;
    }

    Test(const Test &other){
        std::cout << "copy constructor" << std::endl;
    }

    Test &operator=(const Test &other){
        std::cout << "assignment" << std::endl;
        return *this;
    }

    ~Test(){
        std::cout << "Destructor" << std::endl;
    }

    friend std::ostream &operator<<(std::ostream &out, const Test &test);
};

std::ostream &operator<<(std::ostream &out, const Test &test){
    out << "Hello from test";
    return out;
}

Test getTest(){
    return Test();
}

int main(){
    Test test1 = getTest();     // copy constructor, not assignment operator
    std::cout << test1 << std::endl;
    return 0;
}