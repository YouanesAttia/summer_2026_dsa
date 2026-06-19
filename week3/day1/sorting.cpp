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

int main()
{
    std::vector<int> v = {2, 5, 6, 3, 4, 6, 76, 8};

    mergeSort(v);

    for (int x : v)
    {
        std::cout << x << " ";
    }
}