#include <iostream>
#include <vector>
#include <cstring>

class Test{
private:
    static const int SIZE=100;
    int *_pBuffer;

public:
    Test(){
        std::cout << "constructor" << std::endl;
        _pBuffer = new int[SIZE]{};
        // _pBuffer = new int[SIZE];
        // std::memset(_pBuffer, 0, sizeof(int)*SIZE);
    }

    Test(int i){
        std::cout << "int constructor" << std::endl;
        _pBuffer = new int[SIZE]{};

        for(int i=0; i<SIZE; i++){
            _pBuffer[i] = 7*i;
        }
    }

    Test(const Test &other){
        std::cout << "copy constructor" << std::endl;
        _pBuffer = new int[SIZE]{};
        memcpy(_pBuffer, other._pBuffer, SIZE*sizeof(int)); // copy bytes
    }

    Test &operator=(const Test &other){
        std::cout << "assignment" << std::endl;
        _pBuffer = new int[SIZE]{};
        memcpy(_pBuffer, other._pBuffer, SIZE*sizeof(int)); // copy bytes
        return *this;
    }

    ~Test(){
        std::cout << "Destructor" << std::endl;
        delete [] _pBuffer;
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

void check(const Test &value){
    std::cout << "LValue function" << std::endl;
}

void check(Test &&value){
    std::cout << "RValue function" << std::endl;
}

int main(){
    Test test1 = getTest();     // copy constructor, not assignment operator
    std::cout << test1 << std::endl;

    std::vector<Test> vec;
    vec.push_back(Test());

    Test &ltest1 = test1;       // LValue ref pointing at RValue
    Test &&rtest1 = Test();     // RValue ref pointing to RValue

    check(test1);               // runs LValue function
    check(getTest());           // runs RValue function

    return 0;
}