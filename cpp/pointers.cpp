#include <iostream>
using namespace std;

int main() {
    int a = 10;

    int *p = &a; 
    // p is a pointer to int
    // &a means "address of a"
    // so p now stores the memory address of a

    cout << "Value of a: " << a << endl;

    cout << "Address of a: " << &a << endl; 
    // prints the memory address of a

    cout << "Value inside *p: " << *p << endl; 
    // *p means "go to the address stored in p"
    // so this prints the value at that address (which is a)

    cout << "Value inside p: " << p << endl; 
    // this prints the address stored in p
    // which is the same as &a

    return 0;
}
