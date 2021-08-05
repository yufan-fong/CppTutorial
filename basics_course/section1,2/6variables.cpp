#include <iostream>
using namespace std;

int main(){
    int numberCats = 5;
    int numberDogs = 6;
    cout << "Number of cats: " << numberCats << endl;
    cout << "Number of dogs: " << numberDogs << endl;
    cout << "Total animals: " << numberCats + numberDogs << endl;
    numberDogs = numberDogs+1;
    cout << "New number of dogs: " << numberDogs << endl;
    return 0;
}