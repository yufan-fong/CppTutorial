#include <iostream>
#include <vector>

int main(){

    // std::vector<std::string> strings(3);
    // strings[1] = "dog";
    std::vector<std::string> strings;
    strings.push_back("cat");
    strings.push_back("dog");
    strings.push_back("horse");

    // std::cout << strings[3] << std::endl;
    // std::cout << strings.size() << std::endl;

    // // Method 1
    // for(int i=0; i<strings.size();i++){
    //     std::cout << strings[i] << std::endl;
    // }

    // Method 2
    std::vector<std::string>::iterator it = strings.begin();
    // get an iterator point from vector<string> that points to first index

    // it++;
    // std::cout << *it << std::endl;  // dereference the iterator pointer

    for(it; it!= strings.end();it++){
        std::cout << *it << std::endl;
    }
    return 0;
}
