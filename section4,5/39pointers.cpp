#include <iostream>
using namespace std;

void manipulate(double *pValue){ //pointer is passed here
    cout << "2. dValue in manipulate: " << *pValue << endl;
    *pValue = 10; //value at address = 10
    cout << "3. dValue in manipulate: " << *pValue << endl;
}

int main(){
    int nValue = 8;
    int *pnValue = &nValue; //int pointer = memory address of nValue
    nValue = 9;
    cout << "Pointer to int address: " << pnValue << endl;
    cout << "Int value: " << nValue << endl;
    cout << "Int value via pointer: " << *pnValue << endl; //dereference pointer to change value in memory address

    cout << "=========================" << endl;
    double dValue = 123.4;
    cout << "1. dValue: " << dValue << endl;
    manipulate(&dValue);    // use pointers to store memory address
    cout << "4. dValue: " << dValue << endl;

    return 0;
}