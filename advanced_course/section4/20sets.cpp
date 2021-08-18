#include <iostream>
#include <set>

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
        return name < other.name;
    }
};

int main(){

    std::set<int> numbers;

    numbers.insert(50);
    numbers.insert(10);
    numbers.insert(30);
    numbers.insert(20);
    
    for(std::set<int>::iterator it = numbers.begin();it!=numbers.end();it++){
        std::cout<<*it<<std::endl;
    }

    std::set<int>::iterator itFind = numbers.find(30);
    if(itFind != numbers.end()){
        std::cout << "Found: "<< *itFind << std::endl;
    }


    if(numbers.count(30)){
        std::cout << "Found!" << std::endl;
    }

    std::set<Test> tests;
    tests.insert(Test(10,"Mike"));
    tests.insert(Test(35,"Sue"));
    tests.insert(Test(20,"Joe"));

    for(std::set<Test>::iterator it = tests.begin();it!=tests.end();it++){
        it->print();
    }

    return 0;
}