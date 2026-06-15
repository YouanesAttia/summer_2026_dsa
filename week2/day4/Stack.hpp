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