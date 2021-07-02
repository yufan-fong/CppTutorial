#include <iostream>
using namespace std;

class Frog {
private: //properties
    string name;

private: //methods
    string getName(){return name;}
    
public:
    Frog(string name): name(name){}
    void info(){cout << "My name is " << getName() << endl;}
    // try to have more methods as private (encapsulation)
};

int main(){

    Frog frog("Freddy");
    frog.info();

    return 0;
}