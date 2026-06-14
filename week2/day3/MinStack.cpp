#include <stack>
#include <algorithm>

class MinStack
{
private:
    std::stack<int> dataStack;
    std::stack<int> minStack;

public:
    MinStack() {}

    void push(int val)
    {
        dataStack.push(val);

        // Push to minStack if it's empty or val is <= current minimum
        if (minStack.empty() || val <= minStack.top())
        {
            minStack.push(val);
        }
    }

    void pop()
    {
        // If the value we are removing is the current minimum, pop from minStack too
        if (dataStack.top() == minStack.top())
        {
            minStack.pop();
        }
        dataStack.pop();
    }

    int top()
    {
        return dataStack.top();
    }

    int getMin()
    {
        return minStack.top();
    }
};