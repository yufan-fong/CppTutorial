#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    float fValue = 76.4;
    cout << "Size of float: " << sizeof(fValue) << endl;
    // can only rely on float to give about 5sf accuracy
    cout << fixed << fValue << endl;
    cout << scientific << fValue << endl;
    cout << setprecision(20) << fixed << fValue << endl;

    double dValue = 76.123456;
    cout << setprecision(20) << fixed << dValue << endl;

    // long double

    return 0;
}