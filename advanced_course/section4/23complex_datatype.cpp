#include <iostream>
#include <map>
#include <vector>

int main(){

    std::map<std::string, std::vector<int>> scores;

    scores["Mike"].push_back(10);
    scores["Mike"].push_back(15);
    scores["Joe"].push_back(6);
    scores["Sue"].push_back(11);
    scores["Sue"].push_back(17);
    scores["Sue"].push_back(7);

    // iterate through the names
    for(std::map<std::string,std::vector<int>>::iterator it=scores.begin();it!=scores.end();it++){
        std::string name = it->first;
        std::vector<int> scoreList = it->second;
        std::cout << name << ": " << std::flush;
        
        // iterate through the scores
        for(int i=0;i<scoreList.size();i++){
            std::cout << scoreList[i] << " " << std::flush; 
        }

        std::cout << std::endl;
    }

}