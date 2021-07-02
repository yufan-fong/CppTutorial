#include <iostream>
using namespace std;

// declare global variable
string numbers[] = {"one","two","three"};

void show1(const int nElements, string texts[]){
    // cout << sizeof(texts) << endl; returns size of pointer
    for (int i =0; i<nElements;i++){
        cout << texts[i] << endl;
    }
}

void show2(const int nElements, string *texts[]){
    // equivalent to show1
    for (int i =0; i<nElements;i++){
        cout << texts[i] << endl;
    }
}

void show3(string (&texts)[3]){
    int length = sizeof(texts)/sizeof(string);
    for (int i =0; i<length;i++){
        cout << texts[i] << endl;
    }
}

// Dont return pointers to local variables
// string texts[] = {"one","two","three"};


char *getMemory(){
    char *pMem = new char[100];
    return pMem;
}

void freeMemory(char *pMem){
    delete [] pMem;
}

int main(){
    string texts[] = {"apple","banna","orange"};
    cout << sizeof(texts) << endl;
    show1(3, texts);
    show3(texts);

    char *pMemory = getMemory();
    freeMemory(pMemory);

    return 0;
}