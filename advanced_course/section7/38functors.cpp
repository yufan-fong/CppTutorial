#include <iostream>

struct Test {      // base class, abstract class
    virtual bool operator()(std::string &text) = 0;
};

struct MatchTest: public Test{       // functor
  bool operator()(std::string &text){
      return text == "lion";
  }
};

void check(std::string &text, Test &test){
    if(test(text)){
        std::cout << "Text matches" << std::endl;
    }
    else{
        std::cout << "No match" << std::endl;
    }
}

int main(){
    MatchTest pred;
    std::string specie = "lion";
    std::cout << pred(specie) << std::endl;

    check(specie,pred);
    
    return 0;
}