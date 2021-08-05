#include <iostream>
using namespace std;

int main(){
    for(int i=0; i<5; i++){
        cout << "i is : " << i << endl;
        if(i==3){
            break;
        }
        cout << "Looping..." << endl;
    }
    cout << "Program quitting..." << endl;

    for(int i=0; i<5; i++){
        cout << "i is : " << i << endl;
        if(i==3){
            continue;       
            // does not continue with the rest of the loop
            // goes on to next iteration
        }
        cout << "Looping..." << endl;
    }
    cout << "Program quitting..." << endl;

    const string password = "hello45";     // const means variable cannot be reassigned later in program
    string input;
    
    do{ //executes at least once, then it checks while condition
        cout << "Enter password > " << flush;
        cin >> input;

        if(password == input){
            break;
        }
        else{
            cout << "Access denied" << endl;
        } 
    } while(true);
    cout << "Access granted" << endl;

    // while(true){
    //     cout << "Enter password > " << flush;
    //     cin >> input;

    //     if(password == input){
    //         cout << "Access granted" << endl;
    //         break;
    //     }
    //     else{
    //         cout << "Access denied" << endl;
    //     }
    // }

    return 0;
}