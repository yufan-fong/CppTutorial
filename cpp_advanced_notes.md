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

Header files may differ for different IDEs.
```c++
#include <iostream>
#include <fstream>  // filestream
```

### 3.1 Writing

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

### 3.2 Reading

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

### 3.3 Parsing

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

### 3.4 Structs & Padding

Structs are used to map binary data to struct members. <br>
Padding is implemented to make the processing more efficient. <br>
Can read more from [GeeksforGeeks](https://www.geeksforgeeks.org/structure-member-alignment-padding-and-data-packing/)

### 3.5 Reading & Writing Binary Files

`.bin` are binary files.


## Section 4: Standard Template Library

### 4.1 Vectors

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

### 4.2 Vectors & Memory

Vectors are stored as continuous lists.

Capacity is the size of the internal array (memory) that has been allocated to the vector.

To minimise delays in the program, operations like insertion should be relatively constant. So, whenever the vector has reached its size limit, all the elements are copied over to a new array that is double the size of the original array.

`.clear()` clears all the elements. Size becomes zero but capacity remains unchanged.

`.reserve(1000)` increases the vector's capacity to specified capacity if the current capacity is smaller.

`.resize()` does not change the vector's capacity.

### 4.3 2D Vectors

Vector of vectors. <br>
Can create jagged arrays in which member arrays are have different lengths.

`vector<vector<int>> grid(3, vector<int>(4,1));` <br>
Creates a 2D vector with 3 rows, 4 cols, and each element is intialised with `1`.

### 4.4 Lists

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

### 4.5 Maps

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


### 4.6 Custom Objects as Map Values

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

### 4.7 Custom Objects as Map Keys

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

### 4.7 Multimaps

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

### 4.8 Sets

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