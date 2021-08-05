#include <iostream>
using namespace std;

int main(){
    bool bValue = true;
    cout << bValue << endl;
    // 1 is True, 0 is False

    char cValue = 55;    // char represents ascii table, 1 byte
    cout << cValue << endl;
    char cValue2 = '7';
    cout << cValue << endl;
    cout << (int)cValue2 << endl;

    wchar_t wValue = 'o';     // bigger than char, 4 bytes
    cout << (char)wValue << endl;
    cout << "Size of wchar_t: " << sizeof(wchar_t) << endl;

    return 0;
}