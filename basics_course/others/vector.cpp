#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

void func(vector<vector<double>> &data, string fileName){

    ifstream myFile;
    string line;
    vector<double> targetData;
    myFile.open(fileName);

    getline(myFile,line);
    while (getline(myFile,line)) {
        //cout << line << endl;
        stringstream ss(line);
        string value;
        targetData.clear();
        
        while(getline(ss,value,',')){
            //cout << value << endl;
            double temp = stod(value);
            targetData.push_back(temp);
        }
        data.push_back(targetData);
    }

    myFile.close();
}

int main(){
    
    vector<vector<double>> data;
    string fileName = "data.csv";
    func(data, fileName);

    for(int i=0; i<data.size();i++){
        for(int j=0; j<data[i].size();j++){
            cout << data[i][j] << ", ";
        }
        cout << endl;
    }
    //cout << data.size() << endl;
    //cout << data[1][1] << endl;

    return 0;
}