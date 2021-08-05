#include <iostream>
using namespace std;

int main(){
    int i = 0;

    while(i<=3){
        cout << "Hello there" << endl;
        i = i + 1; // i++
    }

    cout << "Program quitting..." << endl;

    const string password = "hello45";     // const means variable cannot be reassigned later in program
    string input;
    
    do{ //executes at least once, then it checks while condition
        cout << "Enter password > " << flush;
        cin >> input;

        if(password != input){
            cout << "Access denied" << endl;
        }
    } while(input != password);

    cout << "Access granted" << endl;

    return 0;
}