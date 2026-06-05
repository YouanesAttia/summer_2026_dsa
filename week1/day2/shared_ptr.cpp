#include <iostream>
#include <memory>
using namespace std;

class Gadget
{
public:
    Gadget() {}
    ~Gadget() {}

    void performTask() { cout << "Gadget is working...\n"; }
};

int main()
{
    shared_ptr<Gadget> p1 = make_shared<Gadget>();
    cout << "Initial use_count: " << p1.use_count() << "\n";

    {
        cout << "\n--- Stage 2: Making Copies ---\n";

        shared_ptr<Gadget> p2 = p1;
        cout << "After p2 = p1, use_count: " << p1.use_count() << "\n";

        shared_ptr<Gadget> p3 = p2;
        cout << "After p3 = p2, use_count: " << p1.use_count() << "\n";

        shared_ptr<Gadget> p4 = p1;
        cout << "After p4 = p1, use_count: " << p1.use_count() << "\n";

        p4->performTask();

        cout << "\n--- Stage 3: Copies going out of scope ---\n";
    }

    cout << "Back in main scope, use_count: " << p1.use_count() << "\n";

    cout << "\n--- Stage 4: Final destruction ---\n";
    p1.reset();

    return 0;
}