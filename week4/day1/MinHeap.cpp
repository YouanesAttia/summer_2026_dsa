#include <iostream>
#include <stdexcept>

template <class T>
class MinHeap
{
private:
    T *arr;
    int capacity;
    int size;

public:
    MinHeap(int c) : size(0), capacity(c), arr(new T[capacity + 1]) {}

    ~MinHeap()
    {
        delete[] arr;
    }

    void swap(int a, int b)
    {
        T temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }

    void insert(const T &val)
    {
        if (size == capacity)
        {
            capacity *= 2;
            T *arr1 = new T[capacity + 1];
            for (int i = 1; i <= size; i++)
            {
                arr1[i] = arr[i];
            }
            delete[] arr;
            arr = arr1;
        }
        size++;
        int idx = size;
        arr[idx] = val;
        while (idx > 1)
        {
            if (arr[idx] < arr[idx / 2])
            {
                swap(idx, idx / 2);
                idx /= 2;
            }
            else
                break;
        }
    }
};