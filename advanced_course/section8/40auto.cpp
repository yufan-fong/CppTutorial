#include <iostream>

template <class T>
auto test(T value) -> decltype(value) {
    return value;
}

int get(){
    return 43;
}

auto test2() -> decltype(get()){
    return get();
}

int main(){

    auto number = 7;
    auto string = "Hello";
    
    std::cout << test("Hello") << std::endl;
    std::cout << test2() << std::endl;
    
    return 0;
}