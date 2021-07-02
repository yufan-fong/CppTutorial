#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <utility> // std::pair

int main(){
    std::vector<std::pair<std::string, std::vector<double>>> result;
    std::ifstream myFile;
    std::string line;
    std::string colname;
    double val;

    myFile.open("data.csv");

    while (getline(myFile,line)){  // read until end of document

        std::stringstream ss(line);

        while (std::getline(ss, colname, ',')) {

            result.push_back({ colname, std::vector<double> {} });
        }
    }

    // Read data, line by line
    while (std::getline(myFile, line))
    {
        std::stringstream ss(line);

        int colIdx = 0;

        // Extract each integer
        while (ss >> val) {

            // Add the current integer to the 'colIdx' column's values vector
            result.at(colIdx).second.push_back(val);

            // If the next token is a comma, ignore it and move on
            if (ss.peek() == ',') ss.ignore();

            colIdx++;
        }
    }

    //std::copy(result.begin(), result.end(), std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << result[1][3] << std::endl;
    std::cout << result.size() << std::endl;
    myFile.close();

    return 0;
}