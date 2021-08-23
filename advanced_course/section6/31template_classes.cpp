#include <iostream>

template<class T>
class Test{
private:
    T obj;  // variable is named obj, is of type T
public:
    Test(T obj){
        this->obj = obj;
    }

    void print(){
        std::cout << obj << std::endl;
    }
};

int main(){
    Test<std::string> test1("Hello");
    test1.print();
    
    Test<int> test2(34);
    test2.print();

    return 0;
}