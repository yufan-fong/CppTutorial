#include <iostream>
using namespace std;

int main(){
    
    char text1[6] = {'h','e','l','l','o',0};
    // strings as char arrays have to be null terminated
    cout << text1 << endl;
    char text2[] = "hello";
    cout << text2 << endl;

    for(int i=0;i<sizeof(text2);i++){
        cout << i << ": " << text2[i] << endl;
    }

    int k = 0;
    while(true) {
        if(text2[k]==0) {
            break;
        }
        cout << text2[k] << flush;
        k++;
    }
    cout << endl;

    char text3[] = "hello";
    int nChars = sizeof(text3)-1;  // -1 accounts for terminating char

    cout << nChars << endl;
    char *pStart = text3;
    char *pEnd = text3 + nChars - 1;
    cout << *pEnd << endl;

    while(pStart < pEnd){
        char save = *pStart;
        *pStart = *pEnd;
        *pEnd = save;

        pStart++;
        pEnd--;
    }
    cout << text3 << endl;

    char text4[nChars];
    char *pStart4 = text4;
    char *pEnd3 = text3 + nChars - 1;
    for(int i=nChars; i>0; i--) {
        *pStart4 = *pEnd3;
        pEnd3--;
        pStart4++;
    }
    cout << text4 << endl;

    return 0;
}