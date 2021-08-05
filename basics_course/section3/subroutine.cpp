#include <iostream>
using namespace std;

void showMenu(){ // void means no return type
    cout << "1. \tSearch" << endl;
    cout << "2. \tView record" << endl;
    cout << "3. \tQuit" << endl;
}

int processSelection(){
    cout << "Enter your selection > " << flush;
    int input;
    cin >> input;
    return input;
}

int main(){
    
    showMenu();
    int selection = processSelection();

    switch(selection){
    case 1:
        cout << "Searching..." << endl;
        break;
    case 2:
        cout << "Viewing..." << endl;
        break;
    case 3:
        cout << "Quitting..." << endl;
        break;
    default:
        cout << "Please select an item from the menu." << endl;
    }

    return 0;
}