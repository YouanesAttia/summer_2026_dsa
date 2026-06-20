#include <iostream>
#include <vector>

int IbinarySearch(std::vector<int> &arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return -1;
}

int RbinarySearch(std::vector<int> &arr, int l, int h, int target)
{
    if (h < l)
        return -1;

    int mid = l + (h - l) / 2;

    if (arr[mid] == target)
        return mid;
    else if (arr[mid] > target)
        return RbinarySearch(arr, l, mid - 1, target);
    else
        return RbinarySearch(arr, mid + 1, h, target);
}

int RbinarySearch(std::vector<int> &arr, int target)
{
    return RbinarySearch(arr, 0, arr.size() - 1, target);
}
