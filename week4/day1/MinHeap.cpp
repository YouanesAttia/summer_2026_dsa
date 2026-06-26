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

    void insert(const T &val) // O(log n)
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

    T extractMin()
    {
        if (size == 0)
            throw std::range_error("Heap is impty");
        if (size == 1)
        {
            T val = arr[1];
            size--;
            return val;
        }
        T val = arr[1];
        arr[1] = arr[size];
        size--;
        int idx = 1;
        while (2 * idx <= size)
        {
            if (2 * idx == size)
            {
                if (arr[idx] > arr[2 * idx])
                    swap(idx, 2 * idx);
                break;
            }
            if (arr[2 * idx] < arr[2 * idx + 1] && arr[idx] > arr[2 * idx])
            {
                swap(idx, 2 * idx);
                idx *= 2;
            }
            else if (arr[2 * idx] > arr[2 * idx + 1] && arr[idx] > arr[2 * idx + 1])
            {
                swap(idx, 2 * idx + 1);
                idx = idx * 2 + 1;
            }
            else
            {
                break;
            }
        }
        return val;
    }
};