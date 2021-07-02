#include <iostream>
using namespace std;

void showMenu(){ // void means no return type
    cout << "1. \tSearch" << endl;
    cout << "2. \tView record" << endl;
    cout << "3. \tQuit" << endl;
}

int getInput(){
    cout << "Enter your selection > " << flush;
    int input;
    cin >> input;
    return input;
}

void processSelection(int selection){
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
}

int main(){
    
    showMenu();
    int selection = getInput();
    processSelection(selection);
    
    return 0;
}