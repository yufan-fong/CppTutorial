#include <iostream>
using namespace std;

int main(){
    // row by column
    
    string animals[2][3]={
        {"fox","dog","cat"},
        {"cow","bird","lion"}
    };

    // string is 8 bytes

    for(int i=0; i< sizeof(animals)/sizeof(animals[0]); i++){
        for(int j=0; j< sizeof(animals[0])/sizeof(string); j++){
            cout << animals[i][j] << " " << flush;
        }
        cout << endl;
    }

    // for(int i=0;i<2;i++){
    //     for(int j=0;j<3;j++){
    //         cout << animals[i][j] << " " << flush;
    //     }
    //     cout << endl;
    // }

    int table[10][10] = {};

    for(int i=1;i<11;i++){
        for(int j=1;j<11;j++){
            table[i][j]=i*j;
        }
    }

    for(int i=1;i<11;i++){
        for(int j=1;j<11;j++){
            cout << table[i][j] << "\t" << flush;
        }
        cout << endl;
    }

    return 0;
}