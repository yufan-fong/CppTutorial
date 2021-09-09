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
6. [Template Classes & Functions](#6)<br>
    6.1 [Template Classes](#6.1)<br>
    6.2 [Template Functions](#6.2)<br>
7. [Passing Functions to Functions](#7)<br>
    7.1 [Function Pointers](#7.1)<br>


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

`std::vector<std::string> strings;` <br>
`std::vector<int> numbers {4,2,55,2};`

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

### 7.2 Abstract Class

Contains methods without implementation (i.e. pure virtual functions) <br>
OR does not implement all the virtual classes from the parent class.

Once all the virtual functions has been implemented, the class is a concrete class. <br>
Objects of a concrete class can be instantiated. <br>
Abstract classes cannot be instantiated.

```c++
class Animal{   //abstract class
public:
    virtual void speak() = 0; // =0 means no implementation
};
```

### 7.3 Functors

Passing blocks of code, alternative to function pointers. <br>
It is an object (?). <br>
Functors are classes/structs that overloads at least 1 operator.

```c++
struct MatchTest {       // functor
  bool operator()(std::string &text){
      return text == "lion";
  }
};
```

## Section 8: C++ 11 Features

### 8.1 Decltype, Typeid & Name Mangling

`#include <typeinfo>` to use Typeid

`typeid(value).name()` to get the name of the data type.

*Name Mangling:* <br>
Name mangling is the encoding of function and variable names into unique names so that linkers can separate common names in the language. Type names may also be mangled. Name mangling is commonly used to facilitate the overloading feature and visibility within different scopes

e.g. `NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE`

`decltype` to declare variables of an existing type. <br>
e.g. `decltype(value) name = "Bob";`

### 8.2 *Auto*

For variables, <br>
`auto` will look at the value that is used to initialised the variable, and use that data type. <br>
Comes in handy when the variable declaration is lengthy. <br>
e.g. `auto number = 7;`

For functions, <br>
Should use the `->` to indicate the trailing return type

```c++
auto test(value) -> int {
    return value;
}
```

OR use template classes

```c++
template <class T>
auto test(T value) -> decltype(value) {
    return value;
}
```

### 8.3 Range-based Loops

`for(auto name: animals){}` where animals is an iterable item (e.g. string, array, vector), and name is the iterator. 

```c++
auto animals = {"dog", "cat", "lion"};
for(auto name: animals){
    std::cout << name << std::endl;
}

std::vector<int> numbers{4,2,251}; 
for(int number: numbers){
        std::cout << number << std::endl;
    }
```

### 8.4 Nested Template Classes

A class that is defined within a class.

```c++
class ring{             // outer class
public:
    class iterator;     // nested class
};

class ring::iterator{   // inner nested class
public:
    void print(){
        std::cout << "Hello from iterator" << std::endl;
    }
};
```

### 8.5 Iterable Classes

For example, create a `ring` class as a ring buffer. <br>
Define the methods and variables needed for iteration.

```c++
for(ring<std::string>::iterator it=textring.begin(); it != textring.end(); it++){
        std::cout << *it << std::endl;
    }
```
__For ring class,__ <br>
`.begin()` returns an interator. <br>
`.end()` returns an interator. <br>

__For iterator nested class__, <br>
`it++` returns the ring object. <br>
`!=` overloads the operator, returns bool. <br>
`*it` returns the value at the iterator's position. <br>

The iterable class has `m_pos` and `m_ring` members. <br>
Iterator class is friendly, but it cannot access the private members (e.g. m_size, m_pos, m_values). <br>
So, need to pass a reference to the ring object

### 8.6 Initialisation

In C++11, can use {} inline to initialise.

| C++ 98 | C++ 11|
| :--- | :--- |
|`int value = 5;` | `int value{5};`|
|`int value;` | `int value{};`|
|`int numbers[] = {4,2,3,1};` | `int numbers[]{4,2,3,1};` |
|`int *pInts = new int[4];` | `int *pInts = new int[4]{33,2,1,44};` |

### 8.7 Initialisation List

The constructor takes in a list `{}` for initialisation.

```c++
class Test{
    Test(std::initializer_list<std::string> texts){
            for(auto value: texts){
                std::cout << value << std::endl;
            }
        }
}

Test fruits{"orange", "banana","apple"};    
```

### 8.8 Object Initialisation, Default, Delete

When a custom constructor is defined (e.g. with paramters), the default constructor (with no paramaters) is lost. <br>
So, if you would like to keep the default constructor, `Person() = default;`

`delete` will remove the default implementation. <br>
e.g. `Person &operator=(const Person &other) = delete;`

### 8.9 Lambda Expressions

Anonymous function. Can be passed around like a function pointer. <br>
Return type can be infered by C++11.

`[](){};` <br>
- `{}` contains the code implementation.
- `()` contains the parameters
- `[]` to capture variables into the lambda scope.

```c++
std::string time = "Morning";
auto pGreet = [time](std::string name){std::cout << time << ", " << name << std::endl;};
pGreet("Mike");
```

To change the captured variable, include the keyword mutable.
```c++
int cats = 5;
[cats]() mutable {      // capture cats by value
    cats = 8;           // mutable allows cats value to change
    std::cout << cats << std::endl;
}();
```

### 8.10 Standard Function Type

Takes in anything that is callable with the specified return type and parameter type. <br>
It will then use that function inside the implementation.

```c++
// standard function
void run(std::function<bool(std::string&)> check){
    // any function that has bool return type, string parameter
    std::string test = "dog";
    std::cout << check(test) << std::endl;
    // in this case, check contains the implementation of check1
}

run(check1); // check can be functor, function pointer or lambda expression
```

### 8.11 Constructors & Memory

Allocate memory for new *int* array that contains `SIZE` elements. <br>
The `{}` initialises each element to 0. <br> 
`_pBuffer = new int[SIZE]{};`

To copy memory from one array to another, <br>
`memcpy(_pBuffer, other._pBuffer, SIZE*sizeof(int));`

It is possible to have a constructor call another constructor to minimise the amount of code.

Remember to `delete [] _pBuffer` in the destructor to free up memory.

### 8.12 LValues and RValues

`int value1 = 7;` <br>
value1 is the LValue, 7 is the RValue.
LValues are typically (normal) references. <br>
RValues are typically temporary values. <br>
LValue references cannot take addresses of RValues. `int *pValue1 = 7;` <br>
LValue references can take addresses of LValues. `int *pValue1 = &value1;`
Note that functions return temporary values, can be considered as RValues.

Commented lines give errors.
```c++
int *pValue1 = &value1;
// int *pValue1 = &7;

Test *pTest1 = &test1;
// Test *pTest1 = &getTest();
// functions return temp values

int *pValue2 = &++value1;
// int *pValue2 = &value1++;
// int *s = &(7+value1);
```

*const* LValue references can bind to RValues, <br>
because the lifetime of RValue returned from function is extended until the reference is destroyed.

`const Test &rTest2 = getTest();`

__RValue References__ <br>
Identify temporary variables and handle them differently from non-temporary variables, to reduce inefficiency and optimise the code.

RValue references can point to RValues. <br>

__Overload Functions__ <br>
Can overload functions based on the whether the parameter is L or R Value.

```c++
void check(const Test &value){
    std::cout << "LValue function" << std::endl;
}

void check(Test &&value){
    std::cout << "RValue function" << std::endl;
}
```

### 8.13 Move Constructors/Assignment

Copy constructors
- works with LValue references, copy semantics
- copies the actual data of the object to another object instead of making another object to point to the already existing objet in the heap.

Move constructors
- works with RValue references, move semantics
- points to the already existing object in the memory
- nulls out the pointer to the temp objects
- executed when a new object is constructed

__Task: Declaring new object and assigning it with RValue__ <br>
Copy
1. Copy the data of the existing object
2. Assign to the new object

Move
1. Makes pointer of the declared object point to the data of the temp object
2. Nulls out the pointer to the temp object
3. Thus, unnecessary copying of data in the memory is avoided.

```c++
std::vector<Test> vec;
vec.push_back(Test());  //move constructor
```

Move assignment
- executed on a previously constructed object

```c++
Test &operator=(Test &&other){
    std::cout << "Move assignment" << std::endl;
    delete [] _pBuffer;
    _pBuffer = other._pBuffer;
    other._pBuffer = nullptr;
    return *this;
}

Test test;
test = getTest();
```

### 8.14 Casting

By polymorphism, a parent pointer can point to a child object. <br>
A child pointer, by default, cannot point to a parent object. <br>

__static_const__ <br>
`static_cast<>`, helps make the variable types correct at compile time. <br>
But, this is prone to error (if super class does not have all of the sub class methods). <br>
Use static_cast to allow child pointer to have a parent pointer value.

```c++
Parent parent;
Brother brother;

Parent *ppb = &brother;                         // Parent pointer to child object (downcast)
Brother *pbb = static_cast<Brother *>(ppb);     // Child pointer to parent pointer (upcast)
std::cout << pbb << std::endl;
```
Enter the desired data type inside the arrow brackets `<>`, then `()` the value.

__dynamic_cast__<br>
`dynamic_cast` helps make the variable types correct at run time. 

Returns nullptr if the code is casting a parent object to a child pointer.
```c++
Parent *pp = &parent;
Brother *pb = dynamic_cast<Brother *>(pp);

if(pb == nullptr){
    std::cout << "Invalid cast" << std::endl;
    // occurs when parent object is casted to a child pointer (downcast)
} else {
std::cout << pb << std::endl;
}
```

__reinterpret_cast__<br>
If dynamic or static cast does not work. This operation involves less checking. <br>
`Sister *ps3 = reinterpret_cast<Sister *>(pp);`

### 8.15 Perfect Forwarding

To obtain the correct inferred reference type.

If the auto evaluates to a LValue reference, the reference will collapse and just become a LValue reference. (like `t = test;`)
```c++
Test test;
auto &&t = test;    // reference collapsing
```

- If LValue is passed in the parameter, the inferred type will be T reference.
- `&&arg` will be LValue due to reference collapsing.

- If RValue is passed in the parameter, the inferred type will be LValue.
- `&&arg` will be RValue.

```c++
template<typename T>
void call(T &&arg){
    //check(static_cast<T>(arg));
    check(std::forward<T>(arg));
}
```

### 8.16 Bind

`#include <functional>`

In `std::bind()`, the parameters are `(function_ptr, param1, param2, param3, ... )`. <br>
The bind operator creates an alias of the function, possibly with placeholders for greater convenience. <br>
Each time the binded function is called, it will run the function with the specified parameters.

```c++
int add(int a, int b, int c){
    std::cout << a << ", " << b << ", " << c << std::endl;
    return a+b+c;
}

auto sum = std::bind(add,3,4,5);
sum();
```

```c++
auto sum3 = std::bind(add, std::placeholders::_2, std::placeholders::_1, 10);
sum3(20,30);
```

`std::placeholders::_2` will take the 2nd parameter of sum2 and pass it as 1st parameter of add. <br>
`std::placeholders::_1` will take the 1st parameter of sum2 and pass it as 2nd parameter of add. <br>
`10` will always be used as the 3rd parameter of add whenever sum3 is called.

### 8.17 Unique Pointers

`#include <memory>`

```c++
std::unique_ptr<int> pTest(new int);
```

Unique pointers will automatically clean up memory when the associated variable goes out of scope.

Can use `{}` to define the scope in the code.

### 8.18 Shared Pointers

Memory will not be deleted until all the variables using that pointer have gone out of the scope.

```c++
std::shared_ptr<Test> pTest1(nullptr);
std::shared_ptr<Test> pTest2 = std::make_shared<Test>();
pTest1 = pTest2;
```

## Section 9: Miscellaneous

valgrind to help check for memory leaks and other stuff.

### Multiple Inheritance

If the parent classes have the same method functions, need to disambiguate the desired method function from which parent class. <br>
e.g. `MusicalInstrument::reset()`

This requires knowledge of child and parent class implementations.

Diamond problem: multiple inheritance from classes that share a base class.

```c++
class Synthesizer: public Machine, public MusicalInstrument{
public:
    virtual ~Synthesizer(){};
};

int main(){
    Synthesizer *pSynth = new Synthesizer();

    pSynth->play();
    pSynth->start();
    pSynth->MusicalInstrument::reset();
    pSynth->Machine::reset();

    delete pSynth;
    return 0;
}
```