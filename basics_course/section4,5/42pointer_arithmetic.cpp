#include <iostream>
using namespace std;

int main(){
    const int NSTRINGS = 5;
    string texts[NSTRINGS] = {"one","two","three","four","five"};
    string *pTexts = texts;
    cout << *pTexts << endl;

    pTexts++;
    cout << *pTexts << endl;
    string *pEnd = &texts[NSTRINGS-1];
    cout << *pEnd << endl;
    
    pTexts = &texts[0];
    while(pTexts != pEnd){      // comparing pointers
        cout << *pTexts << endl;
        pTexts++;
    }

    pTexts = &texts[0];
    pEnd = &texts[NSTRINGS];    // dont try to print this value
    long elements = (long)(pEnd - pTexts);
    cout << elements << endl;
    return 0;
}