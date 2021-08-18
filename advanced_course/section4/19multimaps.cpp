#include <iostream>
#include <map>

int main(){
    std::multimap<int, std::string> namelist;

    namelist.insert(std::make_pair(30, "Mike"));
    namelist.insert(std::make_pair(10, "Bob"));
    namelist.insert(std::make_pair(20, "Raj"));
    namelist.insert(std::make_pair(30, "Kai"));   // duplicate key
    namelist.insert(std::make_pair(30, "Joe"));   // duplicate key

    for(std::multimap<int, std::string>::iterator it=namelist.begin(); it!=namelist.end(); it++){
        std::cout << it->first << ": " << it->second << std::endl;
    }

    std::cout << "Search Demo " << std::endl;
    // create a pair of iterators for that multimap
    std::pair<std::multimap<int,std::string>::iterator, std::multimap<int, std::string>::iterator> its;
    its = namelist.equal_range(30);     // pass the desired key

    for(std::multimap<int, std::string>::iterator it=its.first; it!=its.second; it++){
        std::cout << it->first << ": " << it->second << std::endl;
        // first gives iterator to start of the range
        // second gives iterator to +1 of end of the range
        // therefore, stop before it points to its.second
    }

    auto its2 = namelist.equal_range(30);

    return 0;
}