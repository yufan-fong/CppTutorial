#include <iostream>
#include <map>

int main(){
    // key: string, value: int
    std::map<std::string,int> ages;

    ages["Mike"] = 40;
    ages["Sarah"] = 32;
    ages["Raj"] = 25;
    std::pair<std::string,int> newPerson("Peter",100);
    ages.insert(newPerson);

    ages.insert(std::make_pair("Peter",142));

    std::cout << ages["Raj"] << std::endl;

    // iterate through the map
    for(std::map<std::string, int>::iterator it=ages.begin(); it!= ages.end(); it++){
        std::cout << it->first << ": " << it->second << std::endl;
    }

    // another way to iterate
    for(std::map<std::string, int>::iterator it=ages.begin(); it!= ages.end(); it++){
        std::pair<std::string, int> age = *it;
        std::cout << age.first << ": " << age.second << std::endl;
    }

    // search for key
    if(ages.find("Raj") != ages.end()){
        std::cout << "Key is found" << std::endl;
    }
    else {
        std::cout << "Key not found" << std::endl;
    }

    return 0;
}