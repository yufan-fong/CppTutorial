#include <iostream>
#include <iomanip>
using namespace std;

int main() {

	unsigned char alpha = 0xFF;
	unsigned char red = 0x12;
	unsigned char green = 0x34;
	unsigned char blue = 0x56;

	unsigned int color = 0;

	color += alpha;
	color <<= 8; // left bit shift operator, moves all values by 8 bits/1 byte/2 hex digits
	color += red;
	color <<= 8;
	color += green;
	color <<= 8;
	color += blue;

	cout << setfill('0') << setw(8) << hex << color << endl;

	return 0;
}