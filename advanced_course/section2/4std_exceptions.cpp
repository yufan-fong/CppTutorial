#include <iostream>

class CanGoWrong{
public:
    CanGoWrong(){
        char *pMemory = new char [99999999999];     // memory allocation too large
        delete [] pMemory;
    }
};

int main(){
    try{
        CanGoWrong wrong;
    }
    catch(std::bad_alloc &e){
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    return 0;
}