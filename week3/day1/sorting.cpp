#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include "MinHeap.hpp"

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(std::vector<int> &v)
{
    int n = v.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (v[j] > v[j + 1])
            {
                swap(v[j], v[j + 1]);
            }
        }
    }
}

void selectionSort(std::vector<int> &v)
{
    int n = v.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minindex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (v[j] < v[minindex])
                minindex = j;
        }
        swap(v[minindex], v[i]);
    }
}

void insertionSort(std::vector<int> &v)
{
    int n = v.size();
    for (int i = 1; i < n; i++)
    {
        int x = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > x)
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = x;
    }
}

void merge(int l, int mid, int h, std::vector<int> &v)
{
    int i = l;
    int j = mid + 1;
    std::vector<int> temp;
    while (i <= mid && j <= h)
    {
        if (v[i] <= v[j])
        {
            temp.push_back(v[i]);
            i++;
        }
        else
        {
            temp.push_back(v[j]);
            j++;
        }
    }
    while (i <= mid)
    {
        temp.push_back(v[i]);
        i++;
    }
    while (j <= h)
    {
        temp.push_back(v[j]);
        j++;
    }
    for (int index = 0; index < temp.size(); index++)
    {
        v[l + index] = temp[index];
    }
}

void mergeSort(int l, int h, std::vector<int> &v)
{
    if (h > l)
    {
        int mid = (h + l) / 2;
        mergeSort(l, mid, v);
        mergeSort(mid + 1, h, v);
        merge(l, mid, h, v);
    }
}

void mergeSort(std::vector<int> &v)
{
    mergeSort(0, v.size() - 1, v);
}

void medianOfThree(std::vector<int> &v, int l, int h)
{
    int mid = l + (h - l) / 2;

    if (v[mid] < v[l])
        swap(v[l], v[mid]);
    if (v[h] < v[l])
        swap(v[l], v[h]);
    if (v[h] < v[mid])
        swap(v[mid], v[h]);

    swap(v[l], v[mid]);
}

int partition(std::vector<int> &v, int l, int h)
{
    medianOfThree(v, l, h);

    int pivot = v[l];
    int i = l;
    int j = h;

    while (i < j)
    {
        do
        {
            i++;
        } while (i <= h && v[i] <= pivot);

        do
        {
            j--;
        } while (v[j] > pivot);

        if (i < j)
        {
            swap(v[i], v[j]);
        }
    }

    swap(v[l], v[j]);
    return j;
}

void quickSortRecursive(std::vector<int> &v, int l, int h)
{
    if (l < h)
    {
        int p = partition(v, l, h);
        quickSortRecursive(v, l, p - 1);
        quickSortRecursive(v, p + 1, h);
    }
}

void quickSort(std::vector<int> &v)
{
    if (v.size() < 2)
        return;
    quickSortRecursive(v, 0, v.size() - 1);
}

int main()
{
    std::vector<int> sizes = {1000, 10000, 100000};

    std::cout << "Algorithm\t1,000\t\t10,000\t\t100,000\n";
    std::cout << "------------------------------------------------------------\n";

    const char *names[] = {"Bubble", "Selection", "Insertion", "Merge", "Quick", "Heap"};
    for (int i = 0; i < 6; i++)
    {
        std::cout << names[i] << (i > 2 ? "\t\t" : "\t"); // Formatting alignment

        for (int n : sizes)
        {
            std::vector<int> v;
            for (int k = 0; k < n; k++)
            {
                v.push_back(rand() % 1000000);
            }

            auto start = std::chrono::high_resolution_clock::now();

            if (i == 0)
                bubbleSort(v);
            else if (i == 1)
                selectionSort(v);
            else if (i == 2)
                insertionSort(v);
            else if (i == 3)
                mergeSort(v);
            else if (i == 4)
                quickSort(v);
            else if (i == 5)
            {
                MinHeap<int> heap(n);
                heap.heapSort(v);
            }

            auto end = std::chrono::high_resolution_clock::now();
            auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

            std::cout << diff.count() << " ms\t\t";
            std::cout.flush();
        }
        std::cout << "\n";
    }

    return 0;
}