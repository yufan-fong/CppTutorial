#include <iostream>
#include <stack>
#include <queue>

class Test{

private:
    std::string name;

public:
    Test(std::string name): name(name){}

    ~Test(){
        //std::cout << "Object destroyed" << std::endl;
    }

    void print(){
        std::cout << name << std::endl;
    }

};

int main(){

    std::stack<Test> myStack;

    // objects are destroyed after adding to the stack
    myStack.push(Test("Mike"));     // add element to top of stack
    myStack.push(Test("Sue"));
    myStack.push(Test("Joe"));
    std::cout << "Finished pushing" << std::endl;

    myStack.pop();                      // remove element from top of stack
    Test test1 = myStack.top();         // referred object is shallow copied to test1 (=)
    //Test &test1 = myStack.top();      // getting the reference is more efficient
    test1.print();

    /* This is invalid code that will not run reliably, object is destroyed.
    Test &test1 = myStack.top();
    myStack.pop();
    test1.print();
    */

   while(myStack.size()>0){
       Test &test = myStack.top();
       test.print();
       myStack.pop();
   }

   std::cout << std::endl;

    std::queue<Test> myQueue;

    // objects are destroyed after adding to the stack
    myQueue.push(Test("Mike"));     // add element to top of stack
    myQueue.push(Test("Sue"));
    myQueue.push(Test("Joe"));
    std::cout << "Finished pushing" << std::endl;

    Test test2 = myQueue.front();       // referred object is shallow copied to test1 (=)
    //Test &test1 = myQueue.top();      // getting the reference is more efficient
    test2.print();

    while(myQueue.size()>0){
        Test &test = myQueue.front();
        test.print();
        myQueue.pop();
    }

    std::cout << std::endl;

    return 0;
}