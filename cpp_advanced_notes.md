# C++ Advanced

Author: __*yufanana*__

This documentation was produced from the Advanced C++ Programming course by John Purcell available on caveofprogramming.com and udemy.com. :)
</br>
____

## Table of Contents <a name="top"></a>

1. [Introduction](#1)<br>
2. [Exceptions](#2)<br>
    2.1 [Basics](#2.1)<br>
    2.2 [Standard](#2.2)<br>
    2.3 [Custom](#2.3)<br>
    2.4 [Catching Order](#2.4)<br>
3. [Files](#3)<br>
    3.1 [Writing](#3.1)<br>
    3.2 [Reading](#3.2)<br>
    3.3 [Parsing](#3.3)<br>
    3.4 [Structs & Padding](#3.4)<br>
    3.5 [Binary Files](#3.5)<br>
4. [Standard Template Library](#4)<br>
    4.1 [Vectors](#4.1)<br>
    4.2 [Vectors & Memory](#4.2)<br>
    4.3 [2D Vectors](#4.3)<br>
    4.4 [Lists](#4.4)<br>
    4.5 [Maps](#4.5)<br>
    4.6 [Custom Objects as Map Values](#4.6)<br>
    4.7 [Custom Objects as Map Keys](#4.7)<br>
    4.8 [Multimaps](#4.8)<br>
    4.9 [Stacks](#4.9)<br>
    4.10 [Queues](#4.10)<br>
    4.11 [Deque & Friend](#4.11)<br>
5. [Operator Overloading](#5)<br>
    5.1 [= Assignment Operator](#5.1)<br>
    5.2 [<< Left Bit Shift Operator](#5.2)<br>
    5.3 [+ Plus Operator](#5.3)<br>
    5.4 [== Eqaulity Operator](#5.4)<br>
    5.5 [* Dereference Operator](#5.5)<br>


## Section 1: Introduction<a name="1"></a>
[Go to top](#top)

Source code for all the projects can be found at this GitHub [wiki])https://github.com/caveofprogramming/advanced-cplusplus/wiki).

## Section 2: Exceptions<a name="2"></a>
[Go to top](#top)

### 2.1 Basics<a name="2.1"></a>
[Go to top](#top)

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

### 2.2 Standard<a name="2.2"></a>
[Go to top](#top)

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

### 2.3 Custom<a name="2.3"></a>
[Go to top](#top)


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

### 2.4 Catching Order<a name="2.4"></a>
[Go to top](#top)

Sub-class errors can be caught be parent-class errors. <br>
So, catch errors from the sub-class first, before catching errors from the parent class. <br>
e.g. `std::bad_alloc` is a sub-class error of `std::exceptions`

## Section 3: Files<a name="3"></a>
[Go to top](#top)

Header files may differ for different IDEs.
```c++
#include <iostream>
#include <fstream>  // filestream
```

### 3.1 Writing<a name="3.1"></a>
[Go to top](#top)

Open the file using `fstream` or `ofstream`. <br>
Good to check whether file was opened. <br>
Remember to close the file.

```c++
int main(){

    std::string outFileName = "text7.txt";

    std::ofstream outFile;
    outFile.open(outFileName);

    // std::fstream outFile;
    // outFile.open(outFileName, std::ios::out);    // set as write out

    if(outFile.is_open()){
        outFile << "Hello there" << std::endl;       // similar mechanics to cout
        outFile.close();
    }
    else{
        std::cout << "Failed to create file: " << outFileName << std::endl;
    }

    return 0;
}
```

### 3.2 Reading<a name="3.2"></a>
[Go to top](#top)

Open file as an input file. <br>
Use the `getline()` function together with a loop to iterate through each line in the file. <br>

``` c++
int main(){

    std::string inFileName = "text8.txt";
    // can use relative path directory as filename
    // else, default is to search in working directory

    std::ifstream inFile;
    inFile.open(inFileName);

    if(inFile.is_open()){
        std::string line;

        while(!inFile.eof()){   //eof: end of file
            getline(inFile,line);
            std::cout << line << std::endl;
        }
        // Or, while(inFile)
        inFile.close();
    }
    else{
        return 1;
    }
    return 0;
}
```

### 3.3 Parsing<a name="3.3"></a>
[Go to top](#top)

Open file as input file. <br>
Delimiters (e.g. `,`,`:`) are like markers to split up/parse the lines. <br>
Newline characters are usually included at the end of a line.

```c++
int main(){

    std::string inFileName = "text9.txt";

    std::ifstream inFile; 
    inFile.open(inFileName);

    if(!inFile.is_open()){
        return 1;
    }

    while(inFile){
        std::string line;
        getline(inFile,line, ':');     // : is the delimiter
        // line now contains the string "<country> Population"

        int population;
        inFile >> population;

        inFile.get();      // extracts a single character from the stream
        // removes the newline character

        std::cout << "'" << line << "' --- '" << population << "'" << std::endl;
    }

    inFile.close();
    
    return 0;
}
```

### 3.4 Structs & Padding<a name="3.4"></a>
[Go to top](#top)

Structs are used to map binary data to struct members. <br>
Padding is implemented to make the processing more efficient. <br>
Can read more from [GeeksforGeeks](https://www.geeksforgeeks.org/structure-member-alignment-padding-and-data-packing/)

### 3.5 Binary Files<a name="3.5"></a>
[Go to top](#top)

`.bin` are binary files.


## Section 4: Standard Template Library<a name="4"></a>
[Go to top](#top)

### 4.1 Vectors<a name="4.1"></a>
[Go to top](#top)

Header file: `#include <vector>`

`std::vector<std::string> strings;`

Vector is a template class. <br>
Vectors can be presized in its instantiation, e.g. `vector<int> ages[4];` <br>
Resizeable using `.push_back()` and `.pop()`. 

Calling a non-existent index of a vector is an undefined behaviour. Careful that it will not result in any error thrown.

`it++` to increment

`.size()` to get number of elements in vector

`myVector[3]` to refer to the specified index

`.push_back(element)` to add element to the end of the vector

`.pop()` to remove the last element

`.begin()` to get pointer to first element

`.end()` to get pointer to last element

### 4.2 Vectors & Memory<a name="4.2"></a>
[Go to top](#top)

Vectors are stored as continuous lists.

Capacity is the size of the internal array (memory) that has been allocated to the vector.

To minimise delays in the program, operations like insertion should be relatively constant. So, whenever the vector has reached its size limit, all the elements are copied over to a new array that is double the size of the original array.

`.clear()` clears all the elements. Size becomes zero but capacity remains unchanged.

`.reserve(1000)` increases the vector's capacity to specified capacity if the current capacity is smaller.

`.resize()` does not change the vector's capacity.

### 4.3 2D Vectors<a name="4.3"></a>
[Go to top](#top)

Vector of vectors. <br>
Can create jagged arrays in which member arrays are have different lengths.

`vector<vector<int>> grid(3, vector<int>(4,1));` <br>
Creates a 2D vector with 3 rows, 4 cols, and each element is intialised with `1`.

### 4.4 Lists<a name="4.4"></a>
[Go to top](#top)

Header file: `#include <list>`

Stored as doubly-linked lists in C++. <br>
<img src=".notes_images/linked_list1.png" height=150>

Use pointers to traverse the list instead of index. <br>
`std::list<int>::iterator it;`

`.push_back()` adds element to back of list

`.push_front()` adds element to front of list

`.begin()` returns the pointer to the first element

`.end()` returns the pointer to the last element

`.insert(it,25)`inserts element before specified iterator/pointer position.

`.erase(it)` invalidates the iterator used and returns a pointer to the next element.

### 4.5 Maps<a name="4.5"></a>
[Go to top](#top)

Header file: `#include <map>`

Maps will always be sorted in order of its keys. <br>
Stores key-value pairs. <br>
Keys are always unique. <br>
Can store custom class objects as map values.

`ages["Raj"]` returns the value associated with the specified key.

#### Instantiation

`std::map<std::string,int> ages;` <br>
- keys are strings
- values are integers
- map is called namelist

#### Initialisation
`ages["Mike"] = 40;` OR <br>
```c++
std::pair<std::string,int> newPerson("Peter",100);
ages.insert(newPerson);
```
OR <br>
Use a built-in handy function in C++. <br>
`ages.insert(std::make_pair("Peter",142));`

#### Iteration
`it->first` points to the first object in the struct. <br>
`it->second` points to the second object in the struct. <br>
Iterators return *const* values, so only *const* methods can be used.
`std::cout << it->first << ": " << it->second << std::endl;`

Or, use `std::pairs` to access key-value pairs. <br>
```c++
std::pair<std::string, int> age = *it;
std::cout << age.first << ": " << age.second << std::endl;
```

#### Searching
Searching for a non-existent key will add a new key-value pair to the map. <br>
`cout << ages["Sue"] << endl;`

Instead, should use an if-loop and `.find()`. <br>
`.find()` will return the end pointer if search is unsuccessful. <br>
e.g.
```c++
if(ages.find("Raj") != ages.end()){
        std::cout << "Key is found" << std::endl;
    }
```

### 4.6 Custom Objects as Map Values<a name="4.6"></a>
[Go to top](#top)

When constructors are overloaded with custom constructors, the default constructor without parameters is removed. So, the default constructor without parameters should be defined again in the class.

Maps will always be sorted in order of its keys.

```c++
std::map<int, Person> people;
people[0] = Person("Mike", 40);
```
1. `Person("Mike",40)` calls the Person constructor with parameters.
2. `people[0]` calls the Person constructor without parameters
3. Values from `Person("Mike",40)` are then assigned to the Person object in the map using the `=` assignment operator. By default, this creates a shallow copy.

`people.insert(std::make_pair(19, Person("Ali",24)));` <br>
1. `Person("Ali",24)` calls the Person constructor with parameters.
2. Copy constructor is then called twice (not sure why)

### 4.7 Custom Objects as Map Keys<a name="4.7"></a>
[Go to top](#top)

Since maps are sorted in an order, the comparison operator (<) has to be overloaded (custom definition).
```c++
bool operator<(const Person &other) const{
        return name < other.name;
    }
```
e.g. when `bool test = test1 < test2` is called, it can be interpreted as the `<` method is called on test1, and test2 is passed as a parameter.

If a new key is added, and the new key is evaluated to be the same as an existing key, the new key will not be added onto the map. However, the value of the existing key will be changed to the new value.

So, the object __comparison operator should be carefully defined__ to suit the case needs. <br>
e.g. in a `Person` object, compare both the names and ages, return boolean.
```c++
bool operator<(const Person &other) const{
    if(name == other.name){
        return age < other.age;
    } else{
        return name < other.name;
    }
}
```
or just compare names only.
```c++
bool operator<(const Person &other) const{
        return name < other.name;
    }
```

### 4.8 Multimaps<a name="4.8"></a>
[Go to top](#top)

Multimaps allows for duplicate keys to exist.

#### Instantiation

`std::multimap<int,std::string> namelist;` <br>
- keys are integers
- values are strings
- multimap is called namelist

#### Initialisation
```c++
namelist.insert(std::make_pair(30, "Mike"));
namelist.insert(std::make_pair(30, "Kai"));   // duplicate key
```

#### Searching
`find()` is not reliable. Use `equal_range()` instead.

```c++
// create a pair of iterators for that multimap
std::pair<std::multimap<int,std::string>::iterator, std::multimap<int, std::string>::iterator> its;
its = namelist.equal_range(30);     // pass the desired key

for(std::multimap<int, std::string>::iterator it=its.first; it!=its.second; it++){
    std::cout << it->first << ": " << it->second << std::endl;
    // first gives iterator to start of the range
    // second gives iterator to +1 of end of the range
    // therefore, stop before it points to its.second
}
```

Or, simpler way is to use `auto its = namelist.equal_range(30);`

### 4.9 Sets<a name="4.9"></a>
[Go to top](#top)

`#include <set>`

Stores unique elements, repeated elements will not be included again. <br>
Elements are stored in an increasing order.

#### Instantiation
`std::set<int> numbers;`

#### Initialisation
`.insert()` to insert elements into the set.

#### Iteration
Use iterator pointer, similar to vectors. <br>
`std::set<int>::iterator it = numbers.begin()`

#### Searching
`.find()` can be used to search for elements. <br>
e.g. 
```c++
std::set<int>::iterator itFind = numbers.find(30);
if(itFind != numbers.end()){
    std::cout << "Found: "<< *itFind << std::endl;
}
```

`.count()` returns 0 or 1 if the element is not found or found respectively. <br>
e.g.
```c++
if(numbers.count(30)){
    std::cout << "Found!" << std::endl;
}
```

#### Custom objects as set elements
Similar to maps, `<` operator has to be overloaded to define a way to sort the elements. <br>
The operator has to be *const*, takes in a reference to the object as no modification intended. <br>
e.g. 
```c++
bool operator<(const Test &other) const {
    return name < other.name;
}
```
### 4.10 Stacks<a name="4.10"></a>
[Go to top](#top)

Data structure, last in first out (LIFO).

#### Methods

`.push()` to add element to top of stack.

`.pop()` returns and removes the element from top of stack.

`.top()` returns a shallow copy of the top element .

### 4.11 Queues<a name="4.11"></a>
[Go to top](#top)

Data strucutre, first in first out (FIFO).

#### Methods

`.push()` to add element to end of queue.

`.pop()` to remove element from front of queue.

`.front()` returns a shallow copy of the element at the front of queue.

### 4.12 Deque & Friend<a name="4.12"></a>
[Go to top](#top)

`friend` functions are functions that do not belong to a class, but it can access the class' private members. <br>

friend prototypes are contained in class definition


```c++
class Test{
    friend bool comp(const Test &a, const Test &b);
    // friend function prototype
};

bool comp(const Test &a, const Test &b){
    // friend function definition
    return a.name < b.name;
}

```

## Section 5: Operator Overloading<a name="5"></a>
[Go to top](#top)

### 5.1 Assignment Operator<a name="5.1"></a>
[Go to top](#top)

`=` is the assignment operator. <br>
e.g.    `test2 = test1` , `test2.operator=(test1);`

In `test2 = test1;`, the assignment operator is called by test2, with test1 passed as a parameter.

Methods receive an implicit first argument, that is the reference to the object that calls the method. Thus, the assignment method is a binary operator with 2 arguments.

`test3 = test2 = test1;` method chaining <br>
Thus, it should return a *const* reference to the object that calls the method.

`Test test4 = test1;` does not run the assignment operator, but the copy constructor instead.

#### Implementation
1. *const* method that does not change the objects (`this` and `other`). 
2. Takes in references to objects (`&other`) as this is more efficient. 
3. Returns a reference to the object that calls the method (`this`).

```c++
const Test &operator=(const Test &other){
    std::cout << "Assignment running" << std::endl;
    this->id = other.id;
    this->name = other.name;
    return *this;
}
```

C++ Rule of 3: assignment operator, copy constructor, destructor. <br>
If any one of the above is defined, the other 2 should be defined as well.

### 5.2 Left Bit Shift Operator<a name="5.2"></a>
[Go to top](#top)

`cout << endl;`, it has left-right associativity. <br>
i.e., executes from left to right

`cout` is an object from the `ostream` class.

```c++
friend std::ostream &operator<<(std::ostream &out, const Test &test){
    out << test.id << ": " << test.name;
    // endl not needed here since it's present in the main code
    return out;
}
```

For non-friend implementation, the get methods have to be public and const.
```c++
std::ostream &operator<<(std::ostream &out, const Complex &c){
    out << "(" << c.getReal() << "," << c.getImaginary() << ")";
    return out;
}
```

### 5.3 Plus Operator<a name="5.3"></a>
[Go to top](#top)

`+` is the plus operator. Non-binary operator. <br>
e.g. `c1 + c2`

It takes in *const* objects, and returns a new object that is not *const*. <br>
Consider the different data types and combinations.

```c++
// header file
Complex operator+(const Complex &c1, const Complex &c2);
Complex operator+(const Complex &c1, double d);
Complex operator+(double d, const Complex &c1);

// implementation
Complex operator+(const Complex &c1, const Complex &c2){
    // complex as both parameters
    return Complex(c1.getReal() + c2.getReal(), c1.getImaginary() + c2.getImaginary());
}

Complex operator+(const Complex &c1, double d){
    // double as 2nd parameter
    return Complex(c1.getReal()+d, c1.getImaginary());
}

Complex operator+(double d, const Complex &c1){
    // double as 1st parameter
    return Complex(c1.getReal()+d, c1.getImaginary());
};
```

### 5.4 Equality Operator<a name="5.4"></a>
[Go to top](#top)

`==` is the equality operator. Binary operator. <br>
The operator should be defined in the class definition. <br>
Returns a boolean value.

```c++
// header file
bool operator==(const Complex &other);

// implementation
bool Complex::operator==(const Complex &other){
    return (real == other.real) && (imaginary == other.imaginary);
}
```

Separate definition should be done for `!=` as well.

### 5.5 Dereference Operator<a name="5.5"></a>
[Go to top](#top)

`*` is the dereference operator. <br>
The operator should be defined in the class definition. <br>
Returns a new complex number object.

```c++
// header file
Complex operator*() const;

// implementation
Complex Complex::operator*() const{
    return Complex(real, -imaginary);
}
```

## Section 6: Template Classes & Functions<a name="6"></a>
[Go to top](#top)

### 6.1 Template Classes<a name="6.1"></a>
[Go to top](#top)

`template<class T>` <br>
Classes that work with types of variables specified by the user. <br>
Convention to name the variable type with a single letter.

`T` can be treated as a generic data type like int, string, etc. <br>
The data type is specified by the user in the main code. `Test<std::string> test1("Hello");`

The methods defined in `class Test` assumes that they will work for the data type defined by the user.

```c++
template<class T>
class Test{
private:
    T obj;
public:
    Test(T obj){
        this->obj = obj;
    }

    void print(){
        std::cout << obj << std::endl;
    }
};
```

Possible to have `template<class T, class K>`

It is bad practice for the methods to enquire the variable type and then execute the methods accordingly, because this defeats the purpose of template classes. 

### 6.2 Template Functions<a name="6.2"></a>
[Go to top](#top)

Creates a function that works with the specified type. <br>
The variable type is specified by the user in the main code. `print<int>(5);`

```c++
template<class T> // or template<typename T>
void print(T n){
    std::cout << n << std::endl;
}
```

## Section 7: Passing Functions to Functions<a name="7"></a>
[Go to top](#top)

### 7.1 Function Pointers<a name="7.1"></a>
[Go to top](#top)

Create a pointer to a function, and call the function via the pointer.

Pointer should have the same return type and the parameter list (number and type). <br>
The variable is essentially a pointer. <br>
Use round brackets `()` to call the function.

```c++
void (*pTest)();    // creates function pointer that takes no parameters, returns void
pTest = &test;      // set pTest to the defined function
(*pTest)();         // dereference the pointer, call the function with ()
```

```c++
void (*pTest)() = test;
pTest();
```