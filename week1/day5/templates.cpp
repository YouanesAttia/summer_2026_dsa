#include <iostream>
#include <string>

template <class T>
T myMax(T a, T b)
{
    return (a > b) ? a : b;
}

template <class T>
class Pair
{
private:
    T first, second;

public:
    Pair(T first, T second) : first(first), second(second) {}
    void swap()
    {
        T temp = first;
        first = second;
        second = temp;
    }
    void print() const
    {
        std::cout << "(" << first << ", " << second << ")\n";
    }
};

int main()
{
    std::cout << myMax(10, 20) << '\n';
    std::cout << myMax(3.14, 2.71) << '\n';
    std::cout << myMax(std::string("apple"), std::string("banana")) << '\n';

    Pair<int> p1(10, 20);
    p1.print();

    p1.swap();
    p1.print();
    return 0;
}