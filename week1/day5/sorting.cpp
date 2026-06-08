// KEY DIFFERENCE:
// - std::sort: Fast, uses Introsort, but UNSTABLE (may reorder equal elements).
// - std::stable_sort: Uses Merge Sort, STABLE (guarantees original order for ties).
// COMPLEXITY: Both are O(N log N). Stable sort may require extra memory.

#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <string_view>

int main()
{
    std::array<int, 10> s{5, 7, 4, 2, 8, 6, 1, 9, 0, 3};

    auto print = [&s](std::string_view const rem)
    {
        for (auto a : s)
            std::cout << a << ' ';
        std::cout << ": " << rem << '\n';
    };

    std::sort(s.begin(), s.end());        // Unstable_sorting technique
    std::stable_sort(s.begin(), s.end()); // Unstable_sorting technique
    print("sorted with the default operator<");

    std::sort(s.begin(), s.end(), std::greater<int>());
    print("sorted with the standard library compare function object");

    struct
    {
        bool operator()(int a, int b) const { return a < b; }
    } customLess;

    std::sort(s.begin(), s.end(), customLess);
    print("sorted with a custom function object");

    std::sort(s.begin(), s.end(), [](int a, int b)
              { return a > b; });
    print("sorted with a lambda expression");
}