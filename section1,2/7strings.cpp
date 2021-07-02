#include <iostream>
using namespace std;

int main(){
    string phrase1 = "this is a string.";
    string phrase2 = " second string";
    cout << phrase1 << phrase2 << endl;
    string phrase3 = phrase1 + phrase2;
    cout << phrase3 << endl;
    return 0;
}