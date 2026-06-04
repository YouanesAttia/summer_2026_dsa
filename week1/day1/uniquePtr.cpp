#include <iostream>
#include <memory>
using namespace std;

int main()
{
    unique_ptr<int> ptr = make_unique<int>(42);
    cout << "Value: " << *ptr << std::endl;
    // Don't have to delete the pointer
}