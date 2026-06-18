#include <iostream>
#include <stdexcept>

template <class T>
class Queue
{
private:
    int size;
    T *arr;
    int frontIndex;
    int rearIndex;
    int count;

public:
    Queue(int n = 10) : size(n), arr(new T[size]), frontIndex(-1), rearIndex(-1), count(0) {}

    ~Queue() { delete[] arr; }

    bool isempty() const
    {
        return count == 0;
    }

    bool isfull() const
    {
        return count == size;
    }

    int getcapacity() const
    {
        return size;
    }

    int getsize() const
    {
        return count;
    }

    void enqueue(const T &val)
    {
        if (!isfull())
        {
            rearIndex = ++rearIndex % size;
            arr[rearIndex] = val;
            count++;
        }
        else
        {
            throw std::runtime_error("Queue is full");
        }
    }

    T dequeue()
    {
        if (isempty())
        {
            throw std::runtime_error("Queue is empty");
        }
        else
        {
            count--;
            frontIndex = ++frontIndex % size;
            return (arr[frontIndex]);
        }
    }

    T &front()
    {
        if (isempty())
            throw std::runtime_error("Queue is empty");

        return arr[(frontIndex + 1) % size];
    }

    void print() const
    {
        for (int i = 1; i <= count; ++i)
        {
            int index = (frontIndex + i) % size;
            std::cout << arr[index] << ' ';
        }

        std::cout << '\n';
    }
};