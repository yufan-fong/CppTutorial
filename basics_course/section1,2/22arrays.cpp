#include <iostream>
using namespace std;

int main(){
    
    // errors wont be given if index is out of range

    int values[3];   // 3 items in array
    // values[0] = 4;
    values[1] = 55;
    values[2] = 25;
    cout << values[0] << endl;
    cout << values[1] << endl;
    cout << values[2] << endl;

    double numbers[4] = {2.5,23.4,123.4,22.3};
    for(int i=0;i<4;i++){
        cout << numbers[i] << endl;
    }

    int numberArray[8] = {};    // empty array
    int numberOfElements = sizeof(numberArray)/sizeof(int);
    for(int i=0;i<numberOfElements;i++){
        cout << numberArray[i] << endl;
    }

    string fruits[] = {"apple","banana","pear"};
    for(int i=0;i<3;i++){
        cout << fruits[i] << endl;
    }

    return 0;
}