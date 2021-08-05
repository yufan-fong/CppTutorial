#include <iostream>
#include <fstream>

#pragma pack(push, 1)
struct Person{
    char name[50];
    int age;
    double height;
};
#pragma pack(pop)

int main(){

    Person person = {"Fred", 25, 1.71};
    std::string fileName = "test.bin";

    ///// Write binary file /////
    std::ofstream outFile;  //output stream
    outFile.open(fileName,std::ios::binary);    // default is txt file format
    
    if(!outFile.is_open()){
        return 1;
    }

    // supply the address of the struct object
    // do recasting because write expects a char pointer
    // next, supply the size of data to write
    outFile.write(reinterpret_cast<char*>(&person), sizeof(Person)); 
    outFile.close();

    // outFile.write((char*)&person, sizeof(Person));   // old casting method

    ///// Read binary file /////

    Person savedPerson = {};

    std::ifstream inFile;       //input stream
    inFile.open(fileName,std::ios::binary);    // default is txt file format
    
    if(!inFile.is_open()){
        return 1;
    }

    inFile.read(reinterpret_cast<char*>(&savedPerson), sizeof(Person)); 
    std::cout << savedPerson.name << ", " << savedPerson.age << std::endl;

    outFile.close();

    return 0;
}