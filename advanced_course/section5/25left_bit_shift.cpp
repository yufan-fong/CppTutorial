#include <iostream>

class Test {
private:
    int id;
    std::string name;

public:
    Test(): id(0), name(""){}

    Test(int id, std::string name): id(id), name(name){}

    void print() const {
        std::cout << id << ": "<< name << std::endl;
    }

    // assignment operator
    const Test &operator=(const Test &other){
        this->id = other.id;
        this->name = other.name;
        return *this;
    }

    // copy constructor
    Test(const Test &other){
        *this = other;
    }

    friend std::ostream &operator<<(std::ostream &out, const Test &test){
        out << test.id << ": " << test.name;
        return out;
    }
};

int main(){
    Test test1(10, "Mike");
    //test1.print();
    std::cout << test1 << std::endl;

    return 0;
}