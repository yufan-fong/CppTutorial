#include <iostream>

void mightGoWrong(){
    int error = 1;
    if(error==1){
        throw 8;
    }
    else if(error == 2){
        throw "Something went wrong";
    }
    else{
        throw std::string("Something else happened");
    }


}

int main(){
    try{
    mightGoWrong();
    }
    catch(int e){
        std::cout<<"Error code: " << e << std::endl;
    }
    catch(char const * e){
        std::cout<<"Error message: " << e << std::endl;
    }
    catch(std::string &e){
        std::cout << "Caught an error object" << std::endl;
    }
    std::cout << "Still running..." << std::endl;
    return 0;
}