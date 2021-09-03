 #include <iostream>

class Test {
private:
    int one{1};
    int two{2};

public:
    void run(){
        int three{3};
        int four{4};
        auto pLambda = [this, three, four](){   // this to capture all instance variables by reference
            std::cout << one << std::endl;
            std::cout << two << std::endl;
            std::cout << three << std::endl;
            std::cout << four << std::endl;
        };
        pLambda();
    }
};

int main(){
    Test test;
    test.run();

    return 0;
}