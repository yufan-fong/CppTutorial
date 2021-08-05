#include <iostream>
using namespace std;

int main(){
    int color = 0x123456;
    int red = color & 0xFF0000;

    /*
    color: 101011000100110100110100
    mask:  111111110000000000000000
    result:101011000000000000000000
    */

   cout << hex << red << endl;
   red = red >> 16;   
   cout << hex << red << endl;

   int green = (color & 0x00FF00) >> 8;
   int blue = color & 0x0000FF;
   cout << hex << green << endl;
   cout << hex << blue << endl;

   // bitwise or: |

    return 0;
}