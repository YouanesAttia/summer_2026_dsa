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

int searchRotatedArray(std::vector<int> &arr, int target)
{
    int l = 0;
    int r = arr.size() - 1;
    while (l < r)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[l] <= target && arr[l] <= arr[mid])
        {
            if (target < arr[mid])
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        else if (arr[r] > arr[mid])
        {
            if (target > arr[mid] && target <= arr[r])
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
    }
}
