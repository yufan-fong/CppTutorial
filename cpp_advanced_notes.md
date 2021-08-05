# C++ Advanced

Author: __*yufanana*__

This documentation was produced from the Advanced C++ Programming course by John Purcell available on caveofprogramming.com and udemy.com. :)
</br>
____

## Section 1: Introduction

Source code for all the projects can be found at this GitHub [wiki])https://github.com/caveofprogramming/advanced-cplusplus/wiki).

## Section 2: Exceptions

### 2.1 Basics
Error handling function. Different application scenarios: <br>
- Errors that the program cannot recover from
- Errors that are likely to occur
- Error conditions that are really serious

1. `try` to run a function that may go wrong.<br>
2. If something went wrong, `throw` an error code and exit the function. <br>
3. In the main function, `catch` the error code to allow the program to continue running.

Can have multiple catches the catch the specific predined error type (e.g. int, char).

Errors thrown will go through the call stack until they are caught.

```c++
#include <iostream>

void mightGoWrong(){
    bool error = true;
    if(error){
        throw 8;
    }
}

int main(){
    try{
    mightGoWrong();
    }
    catch(int e){
        std::cout<<"Error code: " << e << std::endl;
    }
    return 0;
}
```

### 2.2 Standard

There are built-in/common error types that can be used to catch exceptions.  

```c++
int main(){
    try{
        CanGoWrong wrong;
    }
    catch(std::bad_alloc &e){
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    return 0;
}
```

### 2.4 Custom

Inherit from the C++ built-in class if possible. Documentation [here](https://en.cppreference.com/w/cpp/error/exception).

`throw()` will define the function to not throw any error.

``` c++
class MyException: public std::exception{    // inherit from built-in class
public:
    virtual const char* what() const throw(){ 
        // throw() >> doesn't throw any exceptions  
        return "Something bad happened";
    }
};
```

### 2.5 Catching Order

Sub-class errors can be caught be parent-class errors. <br>
So, catch errors from the sub-class first, before catching errors from the parent class. <br>
e.g. `std::bad_alloc` is a sub-class error of `std::exceptions`

## Section 3: Files

### 3.1 Writing


### 3.2 Reading


### 3.3 Parsing


### 3.4 Structs & Padding


### 3.5 Reading & Writing Binary Files