#include <iostream>
using namespace std;

int main(){
    string texts[] = {"one","two","three","four"};
    cout << sizeof(texts)/sizeof(string) << endl;
    int length = sizeof(texts)/sizeof(string);

    string *pTexts = texts;
    // array points do not contain info about memory size

    for(int i=0;i<length;i++){
        cout << pTexts[i] << " " << flush;
    }
    cout << endl;

    for(int i=0;i<length;i++){
        cout << *pTexts << " " << flush;
    }
    cout << endl;
    
    for(int i=0;i<length;i++, pTexts++){
        cout << *pTexts << " " << flush;
    }
    cout << endl;

    string *pElement = texts;       // gives address of first element
    string *pEnd = &texts[length];  // to get address of last element

    while(true){
        cout << *pElement << " " << flush;
        if(pElement == pEnd){      // comparing pointers, memory address values
            break;
        }
        pElement++;
    }
}