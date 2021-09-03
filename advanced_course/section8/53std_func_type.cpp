#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

bool check(std::string &test){
    return test.size()==3;
}

class Check{
public:
    bool operator()(std::string &test){
        return test.size() == 5;
    }
} check1;       // functor called check1, object of Check class

// standard function
void run(std::function<bool(std::string&)> check){
    // any function that has bool return type, string parameter
    std::string test = "dog";
    std::cout << check(test) << std::endl;
}

int main(){
    int size = 5;
    std::vector<std::string> vec{"one","two","three"};

    // lambda expression
    auto lambda = [size](std::string test){return test.size() == size;};
    int count = std::count_if(vec.begin(),vec.end(), lambda);
    std::cout << count << std::endl;

    // function pointer
    count = std::count_if(vec.begin(),vec.end(), check);
    std::cout << count << std::endl;

    // functor
    count = std::count_if(vec.begin(),vec.end(), check1);
    std::cout << count << std::endl;

    run(lambda);
    run(check1);
    run(check);



    return 0;
}