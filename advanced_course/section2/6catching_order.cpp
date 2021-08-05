#include <iostream>
//#include <exception>

void goesWrong(){
    bool error1Detected = true;
    bool error2Detected = false;

    if(error1Detected){
        throw std::bad_alloc();
    }
    if(error2Detected){
        throw std::exception();
    }
}

int main(){
    try{
        goesWrong();
    }
    catch(std::exception &e){
        // error2Detected
        std::cout<< "Error2: " << e.what()<<std::endl;
        // this catch is triggered because bad_alloc is a sub-class of std::exception
    }
    catch(std::bad_alloc &e){
        // error1Detected
        std::cout<< "Error1: " << e.what()<<std::endl;
    }

    // thus, should catch sub-class errors before parent class errors

    return 0;
}