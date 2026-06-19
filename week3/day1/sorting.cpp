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
    for (int i = 0; i < n; i++)
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
        for (int j = i; j < n; j++)
        {
            if (v[j] < v[i])
                minindex = j;
        }
        swap(v[minindex], v[i]);
    }
}

int main()
{
    std::vector<int> v = {2, 5, 6, 3, 4, 6, 76, 8};
    selectionSort(v);
    for (int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
}