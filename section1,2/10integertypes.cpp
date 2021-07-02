#include <iostream>
#include <limits.h>
using namespace std;

int main(){
    int value = 546;
    cout << value << endl;
    cout << "Max int value: " << INT_MAX << endl;
    cout << "Min int value: " << INT_MIN << endl;

    long lValue = LONG_MAX;
    cout << "lValue: " << LONG_MAX << endl;

    short int sValue = 23434;
    cout << "sValue: " << sValue << endl;

    cout << "Size of int: " << sizeof(int) << endl;
    cout << "Size of short int: " << sizeof(short int) << endl;
    cout << "Size of long int: " << sizeof(long int) << endl;
    cout << "Size of long: " << sizeof(long) << endl;
    // i think the size varies from system & computer hardware? tbc

    unsigned int uValue = 492312; //positive integer only

    return 0;
}