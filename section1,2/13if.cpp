# include <iostream>
using namespace std;

int main(){
    string password = "hello45";
    cout << "Enter your password > " << flush; // << is put to

    string input;
    cin >> input; // >> is get from

    if(input == password){
        cout << "Password accepted!" << endl;
    }

    if(input != password){
        cout << "Access denied..." << endl;
    }

    return 0;
}