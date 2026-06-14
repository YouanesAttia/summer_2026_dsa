#include <iostream>
#include "SinglyLinkedList.hpp"

template <typename T>
class Stack
{
private:
    SinglyLinkedList<T> list;

public:
    void push(const T &value)
    {
        list.push_front(value);
    }

    T pop()
    {
        if (list.empty())
        {
            throw std::runtime_error("Stack Underflow: Cannot pop from empty stack");
        }
        return list.pop_front();
    }

    T top()
    {
        if (list.empty())
        {
            throw std::runtime_error("Stack is empty");
        }
        T val = list.pop_front();
        list.push_front(val);
        return val;
    }

    bool empty() const
    {
        return list.empty();
    }
};

int main()
{
    Stack<std::string> shelf;

    std::cout << "Pushing: 'Book A', 'Book B', 'Book C'" << std::endl;
    shelf.push("Book A");
    shelf.push("Book B");
    shelf.push("Book C");

    std::cout << "Top element is: " << shelf.top() << std::endl;

    std::cout << "Popping all elements:" << std::endl;
    while (!shelf.empty())
    {
        std::cout << "Popped: " << shelf.pop() << std::endl;
    }

    return 0;
}