#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Dog
{
    string name;

public:
    Dog(string n) : name(n) {}

    void bark()
    {
        cout << name << " says: Woof! Woof!\n";
    }

    ~Dog() {}
};

int main()
{
    unique_ptr<Dog> p1 = make_unique<Dog>("Buddy");

    cout << "p1 is pointing to Buddy.\n";
    p1->bark();

    unique_ptr<Dog> p2 = move(p1);

    cout << "Ownership Transferred \n";

    if (p1 == nullptr)
    {
        cout << "Verification: p1 is now NULL.\n";
    }
    else
    {
        cout << "Verification: p1 still has ownership (This shouldn't happen).\n";
    }

    if (p2 != nullptr)
    {
        cout << "Verification: p2 now owns Buddy.\n";
        p2->bark();
    }

    return 0;
} // Buddy is automatically destroyed here when p2 goes out of scope.