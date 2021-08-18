#include <iostream>
#include <list>

int main(){
    std::list<int> numbers;

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_back(4);
    // [1,2,3,4]
    numbers.push_front(0);
    // [0,1,2,3,4]

    std::list<int>::iterator it=numbers.begin();
    it++;
    numbers.insert(it,25);  // inserts element at current pointer position
    // [0,25,1,2,3,4]

    std::list<int>::iterator eraseIt=numbers.begin();
    eraseIt = numbers.erase(eraseIt);
    // [25,1,2,3,4]
    std::cout << "eraseIt: " << *eraseIt << std::endl;

    // iterator in the for loop is local
    for(std::list<int>::iterator it=numbers.begin(); it!=numbers.end(); it++){
        std::cout << *it << std::endl;
    }


    // insert & erase in a loop
    std::cout << "insert & erase in a loop" << std::endl;
    for(std::list<int>::iterator it=numbers.begin(); it!=numbers.end(); it++){
        if(*it==2){
            numbers.insert(it,1234);
        }
        if(*it==3){
            it = numbers.erase(it);   
            // it now points to the next element
            it--;
        }
    }

    for(std::list<int>::iterator it=numbers.begin(); it!=numbers.end(); it++){
        std::cout << *it << std::endl;
    }

    return 0;
}