#include <iostream>
#include <vector>

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
            if (v[j] < v[i])
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

#include <iostream>
#include <vector>
#include <algorithm>

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
    std::vector<int> v = {2, 5, 6, 3, 4, 6, 76, 8};

    mergeSort(v);

    for (int x : v)
    {
        std::cout << x << " ";
    }
}