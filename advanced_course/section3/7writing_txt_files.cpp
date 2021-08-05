#include <iostream>
#include <fstream>  // filestream

int main(){

    std::string outFileName = "text7.txt";

    std::ofstream outFile;      //output filestream
    outFile.open(outFileName);

    // std::fstream outFile;
    // outFile.open(outFileName, std::ios::out);    // set as write out

    if(outFile.is_open()){
        outFile << "Hello there" << std::endl;       // similar mechanics to cout
        outFile << "41231";
        outFile.close();
    }
    else{
        std::cout << "Failed to create file: " << outFileName << std::endl;
    }

    return 0;
}