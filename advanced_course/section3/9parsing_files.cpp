#include <iostream>
#include <fstream>  // filestream

int main(){

    std::string inFileName = "text9.txt";

    std::ifstream inFile;      //input filestream
    inFile.open(inFileName);

    if(!inFile.is_open()){
        return 1;
    }

    while(inFile){
        std::string line;
        getline(inFile,line, ':');     // : is the delimiter
        // line now contains the string "<country> Population"

        int population;
        inFile >> population;

        inFile.get();       // extracts a single character from the stream
        // removes the newline character

        std::cout << "'" << line << "' --- '" << population << "'" << std::endl;
    }

    inFile.close();
    
    return 0;
}