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

int main()
{
    Stack<int> st(5);

    std::cout << std::boolalpha;

    std::cout << "===== Initial State =====\n";
    std::cout << "Empty: " << st.isEmpty() << '\n';
    std::cout << "Full : " << st.isFull() << '\n';

    std::cout << "\n===== Push Elements =====\n";
    st.push(10);
    st.push(20);
    st.push(30);

    std::cout << "Top = " << st.stackTop() << '\n';

    std::cout << "\n===== Peek =====\n";
    std::cout << "Peek(1): " << st.peek(1) << '\n';
    std::cout << "Peek(2): " << st.peek(2) << '\n';
    std::cout << "Peek(3): " << st.peek(3) << '\n';

    std::cout << "\n===== Pop =====\n";
    std::cout << st.pop() << '\n';
    std::cout << "Top = " << st.stackTop() << '\n';

    std::cout << "\n===== Fill Stack =====\n";
    st.push(40);
    st.push(50);
    st.push(60);

    std::cout << "Full : " << st.isFull() << '\n';
    std::cout << "Top  : " << st.stackTop() << '\n';

    std::cout << "\n===== Overflow Test =====\n";
    try
    {
        st.push(70);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
    }

    std::cout << "\n===== Pop Everything =====\n";
    while (!st.isEmpty())
    {
        std::cout << st.pop() << ' ';
    }
    std::cout << '\n';

    std::cout << "\n===== Underflow Test =====\n";
    try
    {
        st.pop();
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
    }

    std::cout << "\n===== Peek Empty Stack =====\n";
    try
    {
        std::cout << st.peek(1) << '\n';
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
    }

    return 0;
}