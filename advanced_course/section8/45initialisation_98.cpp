#include <iostream>

struct S{
    std::string text;
    int id;
};

int main(){
    int values[] = {1,2,3,5,1};
    std::cout << values[0] << std::endl;

    class C{
    public:
        std::string text;
        int id;
    };

    C c1 = {"Hello", 7};
    std::cout << c1.text << std::endl;

    struct {       // no struct name if the struct is not reused
    std::string text;
    int id;
    } s1 = {"Struct", 44}, s2 = {"#two", 2};
    
    std::cout << s1.id << std::endl;
    std::cout << s2.text << std::endl;

    return 0;
}