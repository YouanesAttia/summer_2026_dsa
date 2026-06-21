#include <iostream>
#include <string>

// Recurrence:
// T(n) = n * T(n - 1) + O(n)
// There are n recursive calls, each solving a subproblem of size (n-1).
// Total complexity: O(n * n!)

void permutations(std::string s, int idx = 0)
{
    if (idx == s.size())
    {
        std::cout << s << std::endl;
        return;
    }

    for (int i = idx; i < s.size(); i++)
    {
        std::swap(s[idx], s[i]);
        permutations(s, idx + 1);
    }
}