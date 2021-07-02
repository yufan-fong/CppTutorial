#include <iostream>
using namespace std;

// .h header file
class Test {
private:
    int id;
    static int count;
    // static variables are created for all objs
    // associated with class, not obj
    // obj can change static variables

public:
    static int const MAX = 99;
    // for const, values must be declared in same line

public:
    Test() {
        id = ++count;
        // increment count, then assign to ID (prefix increment operator)
    }
    int getID() {
        return id;
    }
    static void showInfo() {
        // can only access static variables
        cout << "Count: " << count << endl;
    }
};

//.cpp source
int Test::count = 0;
// initialise non-const static variables

int main() {

    Test::showInfo();

    cout << Test::MAX << endl;

    Test test1;
    test1.showInfo();
    cout << "ID: " << test1.getID() << endl;

    Test test2;
    test2.showInfo();
    cout << "ID: " << test2.getID() << endl;
 
    return 0;
}