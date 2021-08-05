#include <iostream>
using namespace std;

/* == equal
*  != not equal
*  > more than
*  < less than
*  <= , >= , and && , or ||
*/

int main(){
    int value1 = 7;
    int value2 = 4;

    if(value1 >= 5){
        cout << "Condition 1: TRUE" << endl;
    }
    else{
        cout << "Condtion 1: FALSE" << endl;
    }

    if(value1 >= 5 && value2 < 3){
        cout << "Condition 2: TRUE" << endl;
    }
    else{
        cout << "Condtion 2: FALSE" << endl;
    }

    if(value1 >= 5 || value2 < 3){
        cout << "Condition 3: TRUE" << endl;
    }
    else{
        cout << "Condtion 3: FALSE" << endl;
    }

    bool condition4 = (value2 != 8) && (value1 == 10);
    bool condition5 = value2 < 10;

    if(condition4 || condition5){
        cout << "Condition 4 OR 5: TRUE" << endl;
    }
    else{
        cout << "Condtion 4 OR 5: FALSE" << endl;
    }

    return 0;
}