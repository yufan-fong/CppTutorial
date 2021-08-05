#include <iostream>
#include <fstream>  // filestream

int main(){

    std::string inFileName = "text8.txt";
    // can use relative path directory as filename
    // else, default is to search in working directory

    std::ifstream inFile;      //input filestream
    inFile.open(inFileName);

    // std::fstream inFile;
    // outFile.open(inFileName, std::ios::in);    // set as read in

    if(inFile.is_open()){
        std::string line;

        while(!inFile.eof()){   //eof: end of file
            getline(inFile,line);
            std::cout << line << std::endl;
        }
        // Or, while(inFile)

        // // this will only get the first word before a white space
        // inFile >> line;
        // std::cout << line << std::endl;

        inFile.close();
    }
    else{
        std::cout << "Failed to open file: " << inFileName << std::endl;
    }

    return 0;
}