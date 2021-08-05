#include <iostream>

#pragma pack(push, 1)   // 1 means to align the following data on single byte boundaries
struct Person{
    // string name; 
    // this wont work because strings are stored as pointers in the stack
    // the value is stored in the heap
    char name[50];
    int age;
    double weight;
};
#pragma pack(pop)   //undo the pragma directive

int main(){
    std::cout << sizeof(Person)<< std::endl;
    return 0;
}