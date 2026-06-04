#include <iostream>
using namespace std;

int main()
{
    int *ptr = new int(3);
    cout << "The value on the heap is: " << *ptr << endl;
    cout << "The memory address is:    " << ptr << endl;
    delete ptr;
}