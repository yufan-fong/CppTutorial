#include <iostream>
using namespace std;

int main(){
    int value = 8;

    switch(value){
    // case labels cannot be variables, but can be const
    case 4:     // take action if value is 4
        cout << "Value is 4" << endl;
        break;
    case 5: 
        cout << "Value is 5" << endl;
        break;
    case 6:
        cout << "Value is 6" << endl;
        break;
    default:    // if no case labels matched
        cout << "Unrecognised value" << endl;
    }

    return 0;
}