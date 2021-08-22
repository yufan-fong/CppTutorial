#include <iostream>
#include <vector>
#include <algorithm>

class Test {
    int id;
    std::string name;

public:
    Test(int id, std::string name): id(id), name(name){}

    void print() const {
        // has to be a const method
        std::cout << id << ": "<< name << std::endl;
    }

    bool operator<(const Test &other) const {
        return id < other.id;
    }

    friend bool comp(const Test &a, const Test &b);
    // friend prototype contained in class definition
    // so that the function can access private members 

};

bool comp(const Test &a, const Test &b){
    return a.name < b.name;
}

int main(){

    std::vector<Test> tests;
    tests.push_back(Test(5,"Mike"));
    tests.push_back(Test(2,"Sue"));
    tests.push_back(Test(8,"Joe"));
    tests.push_back(Test(10,"Raj"));

    //std::sort(tests.begin(),tests.end());
    std::sort(tests.begin(), tests.end(), comp);

    for(int i=0; i<tests.size(); i++){
        tests[i].print();
    }

    return 0;
}