#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
    std::vector<int> source = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::vector<int> all_items;
    // We use back_inserter so 'all_items' grows automatically
    std::copy(source.begin(), source.end(), std::back_inserter(all_items));

    // --- 2. std::copy_if ---
    std::vector<int> only_even;
    std::copy_if(source.begin(), source.end(), std::back_inserter(only_even),
                 [](int x)
                 {
                     return x % 2 == 0; // The "Filter" condition
                 });

    // --- Output Results ---
    std::cout << "All items: ";
    for (int x : all_items)
        std::cout << x << " ";

    std::cout << "\nOnly even: ";
    for (int x : only_even)
        std::cout << x << " ";

    return 0;
}