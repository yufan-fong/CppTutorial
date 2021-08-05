#include <iostream>
using namespace std;

int main(){
    cout << "Enter your name: " << flush;
    // insertion operator
    string input;
    cin >> input;
    // extraction operator
    cout << "You entered: " << input << endl;

    int age;
    cout << "Enter your age: " << flush;
    cin >> age;
    cout << "Your age is " << age << endl;

    return 0;
}