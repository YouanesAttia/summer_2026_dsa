#include <iostream>
#include <vector>

// Recurrence:
// T(n) = 2T(n-1) + O(1)
// Each element creates two recursive branches:
//   - take it
//   - skip it
// Total complexity: O(n * 2^n)

std::vector<std::vector<int>> subsets(std::vector<int> &nums)
{
    std::vector<std::vector<int>> result;
    std::vector<int> current;

    backtrack(nums, 0, current, result);

    return result;
}

void backtrack(const std::vector<int> &nums, int idx, std::vector<int> &current, std::vector<std::vector<int>> &result)
{
    if (idx == nums.size())
    {
        result.push_back(current);
        return;
    }

    backtrack(nums, idx + 1, current, result);

    current.push_back(nums[idx]);
    backtrack(nums, idx + 1, current, result);
    current.pop_back();
}