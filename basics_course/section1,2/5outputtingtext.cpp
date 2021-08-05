#include <iostream>
//input output stream

using namespace std;

int main(){
    cout << "Starting program..." << flush;
    // tells OS to output text without line feed

    cout << "Outputting my text" << endl; 
    //endl flushes out any saved (text) outputs

    cout << "More text here" << endl;
    
    cout << "apple " << "banana " << "orange " << endl;

    return 0;
}