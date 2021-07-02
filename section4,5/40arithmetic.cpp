#include <iostream>
using namespace std;

int main(){

    double value1 = 7/2;    // remainder discarded
    cout << value1 << endl;
    value1 = 7.0/2;
    cout << value1 << endl;
    value1 = (double)7/2;   // casting
    cout << value1 << endl;

    int value2 = (int)7.3;  // casting, no rounding, just discard after pt
    cout << value2 << endl;

    int value3 = 5;
    value3 += 1;
    cout << value3 << endl;

    int value4 = 10;
    value4 /= 2;
    cout << value4 << endl;

    int value5 = 12%5;
    cout << value5 << endl;

    

    return 0;
}
