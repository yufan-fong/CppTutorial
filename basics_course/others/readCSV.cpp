#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <utility> // std::pair
#include <stdexcept> // std::runtime_error
#include <sstream> // std::stringstream

std::vector<std::pair<std::string, std::vector<double>>> read_csv(std::string filename) {
    // Reads a CSV file into a vector of <string, vector<int>> pairs where
    // each pair represents <column name, column values>

    // Create a vector of <string, int vector> pairs to store the result
    std::vector<std::pair<std::string, std::vector<double>>> result;

    // Create an input filestream
    std::ifstream myFile(filename);
    myFile.open("data.csv");

    // Helper vars
    std::string line;
    std::string colname;
    double val;

    
    std::cout << myFile.good() << std::endl;
    // Read the column names
    if (myFile.good())
    {
        // Extract the first line in the file
        std::getline(myFile, line);

        // Create a stringstream from line
        std::stringstream ss(line);

        // Extract each column name
        while (std::getline(ss, colname, ',')) {

            // Initialize and add <colname, int vector> pairs to result
            result.push_back({ colname, std::vector<double> {} });
        }

        std::cout << ss.str() << std::endl;
        std::cout << "Here" << std::endl;
    }


    // Read data, line by line
    while (std::getline(myFile, line))
    {
        // Create a stringstream of the current line
        std::stringstream ss(line);

        // Keep track of the current column index
        int colIdx = 0;

        // Extract each integer
        while (ss >> val) {

            // Add the current integer to the 'colIdx' column's values vector
            result.at(colIdx).second.push_back(val);

            // If the next token is a comma, ignore it and move on
            if (ss.peek() == ',') ss.ignore();

            // Increment the column index
            colIdx++;
        }
    }
    std::cout << result.size() << std::endl;
    // Close file
    myFile.close();

    return result;
}

int main() {
    // Read three_cols.csv and ones.csv
    std::vector<std::pair<std::string, std::vector<double>>> values = read_csv("data.csv");

    //std::cout << values.size() << std::endl;

    //for (int i = 0; i < values.size(); i++) {
     //   std::cout << "hello" << std::endl;
    //}
    // Write to another file to check that this was successful
    //write_csv("three_cols_copy.csv", three_cols);
    //write_csv("ones_copy.csv", ones);

    return 0;
}
