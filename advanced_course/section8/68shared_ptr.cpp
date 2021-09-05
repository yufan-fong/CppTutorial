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

int main(){
    std::shared_ptr<Test> pTest1(new Test);
    std::shared_ptr<Test> pTest3(nullptr);

    {
        std::shared_ptr<Test> pTest2 = std::make_shared<Test>();
        pTest3 = pTest2;    // this is the crucial line to extend the scope of the shared_ptr
        auto pTest4 = pTest2;
    }

    std::cout << "Finished" << std::endl;
    return 0;
}