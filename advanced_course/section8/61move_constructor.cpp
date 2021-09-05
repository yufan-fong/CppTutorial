#include <iostream>
#include <vector>
#include <cstring>

class Test{
private:
    static const int SIZE=100;
    int *_pBuffer{nullptr};

public:
    Test(){
        _pBuffer = new int[SIZE]{};
        // _pBuffer = new int[SIZE];
        // std::memset(_pBuffer, 0, sizeof(int)*SIZE);
    }

    Test(int i){
        _pBuffer = new int[SIZE]{};

        for(int i=0; i<SIZE; i++){
            _pBuffer[i] = 7*i;
        }
    }

    Test(const Test &other){
        _pBuffer = new int[SIZE]{};
        memcpy(_pBuffer, other._pBuffer, SIZE*sizeof(int)); // copy bytes
    }

    Test(Test &&other){
        std::cout << "Move constructor" << std::endl;
        _pBuffer = other._pBuffer;
        other._pBuffer = nullptr;
    }

    Test &operator=(const Test &other){
        _pBuffer = new int[SIZE]{};
        memcpy(_pBuffer, other._pBuffer, SIZE*sizeof(int)); // copy bytes
        return *this;
    }

    ~Test(){
        delete [] _pBuffer;
    }

    friend std::ostream &operator<<(std::ostream &out, const Test &test);
};

std::ostream &operator<<(std::ostream &out, const Test &test){
    return out;
}

Test getTest(){
    return Test();
}

int main(){
    Test test1 = getTest();     // copy constructor, not assignment operator
    std::cout << test1 << std::endl;

    std::vector<Test> vec;
    vec.push_back(Test());  //move constructor

    return 0;
}