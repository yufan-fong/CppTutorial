#include <iostream>
using namespace std;

int main(){
    char value = 127;
    cout << (int)value << endl;
    value++;
    cout << (int)value << endl;
    // using twos complement, min = -max-1
    // most significant bit is discarded during arithmetic

    return 0;
}