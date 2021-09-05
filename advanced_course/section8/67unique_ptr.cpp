#include <iostream>
#include <memory>

class Test {
public:
    Test(){
        std::cout << "Created" << std::endl;
    }

    void greet(){
        std::cout << "Hello" << std::endl;
    }

    ~Test(){
        std::cout << "Destroyed" << std::endl;
    }
};

class Temp {
private:
    std::unique_ptr<Test[]> pTest;  //just declaration of variable

public:
    Temp(): pTest(new Test[2]){};   // no need for destructor
};

int main(){
    std::unique_ptr<int> pInt(new int);
    *pInt = 7;
    std::cout << *pInt << std::endl;

    std::unique_ptr<Test> pTest(new Test);
    pTest->greet();

    std::cout << "Finished" << std::endl;

    Temp temp;

    return 0;
}