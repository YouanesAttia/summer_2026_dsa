#include <iostream>
#include "vector.hpp"

template <class T>
class Stack
{
private:
    int top;
    Vector<T> data;
    int size;

public:
    Stack(int size_ = 10) : size(size_), top(-1), data(size_) {}

    void push(const T &val)
    {
        if (!isFull())
        {
            data.push_back(val);
            top++;
        }
        else
        {
            throw std::out_of_range("Stack is full");
        }
    }

    T pop()
    {
        if (isEmpty())
        {
            throw std::out_of_range("Stack is Empty");
        }
        else
        {
            T val = data[top];
            data.pop_back();
            top--;
            return val;
        }
    }

    T stackTop()
    {
        if (isEmpty())
            throw std::out_of_range("Stack is Empty");

        return data[top];
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == size - 1;
    }

    T peek(int pos)
    {
        int index = top - pos + 1;
        if (index < 0 || index > top)
        {
            throw std::out_of_range("Invalid Position");
        }
        return data[index];
    }
};
