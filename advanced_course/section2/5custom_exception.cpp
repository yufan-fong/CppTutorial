#include <iostream>

class MyException: public std::exception{    // inherit from built-in class
public:
    virtual const char* what() const throw(){ 
        // throw() >> doesn't throw any exceptions  
        return "Something bad happened";
    }
};

class Test{
public:
    void goesWrong(){
        throw MyException();
    }
    
    // // can only throw bad_alloc error
    // void goesWrong2() throw(bad_alloc){
    //     // results in runtime/compile error
    //     throw MyException();
    // }
    
};

int main(){

    Test test;
    try{
        test.goesWrong();
        // this will throw an object from the MyException class
    }
    catch(MyException &e){
        std::cout << e.what() << std::endl;
    }
    return 0;
}