#include <iostream>
#include <string>
#include <utility>

class Widget
{
private:
    int i{0};
    std::string s{};
    int *pi{nullptr};

public:
    Widget(int val, std::string text) : i(val), s(text)
    {
        pi = new int(val);
        std::cout << "Constructing Widget: " << s << "\n";
    }

    Widget(Widget &&w) noexcept
        : i(std::move(w.i)), s(std::move(w.s)), pi(std::exchange(w.pi, nullptr))
    {
        std::cout << "Moving Widget: " << s << "\n";
    }

    Widget &operator=(Widget &&w) noexcept
    {
        if (this == &w)
            return *this;
        delete pi;

        i = std::move(w.i);
        s = std::move(w.s);
        pi = std::exchange(w.pi, nullptr);

        return *this;
    }

    ~Widget()
    {
        if (pi)
        {
            std::cout << "Deleting pointer for: " << s << "\n";
            delete pi;
        }
        else
        {
            std::cout << "Destructor for empty/moved Widget\n";
        }
    }

    void printStatus()
    {
        std::cout << "String: " << s << ", Int: " << i
                  << ", Pointer addr: " << pi << "\n";
    }
};

int main()
{
    std::cout << "--- Creating w1 ---\n";
    Widget w1(42, "Original Data");
    w1.printStatus();

    std::cout << "\n--- Creating w2 by moving w1 ---\n";
    Widget w2(std::move(w1)); // This triggers the Move Constructor

    std::cout << "\n--- Current Status ---\n";
    std::cout << "w1 (after move): ";
    w1.printStatus(); // Should be empty/null

    std::cout << "w2 (after move): ";
    w2.printStatus(); // Should have the original data

    std::cout << "\n--- Program End ---\n";
    return 0;
}