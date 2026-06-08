#include <algorithm>
#include <array>
#include <cassert>
#include <complex>
#include <initializer_list>
#include <iostream>
#include <vector>

bool is_even(int i)
{
    return i % 2 == 0;
}

void example_contains()
{
    const auto haystack = {1, 2, 3, 4};

    for (const int needle : {3, 5})
        if (std::find(haystack.begin(), haystack.end(), needle) == haystack.end())
            std::cout << "haystack does not contain " << needle << '\n';
        else
            std::cout << "haystack contains " << needle << '\n';
}

void example_predicate()
{
    for (const auto &haystack : {std::array{3, 1, 4}, {1, 3, 5}})
    {
        const auto it = std::find_if(haystack.begin(), haystack.end(), is_even);
        if (it != haystack.end())
            std::cout << "haystack contains an even number " << *it << '\n';
        else
            std::cout << "haystack does not contain even numbers\n";
    }
}

void example_list_init()
{
    std::vector<std::complex<double>> haystack{{4.0, 2.0}};
#ifdef __cpp_lib_algorithm_default_value_type
    // T gets deduced making list-initialization possible
    const auto it = std::find(haystack.begin(), haystack.end(), {4.0, 2.0});
#else
    const auto it = std::find(haystack.begin(), haystack.end(), std::complex{4.0, 2.0});
#endif
    assert(it == haystack.begin());
}

int main()
{
    example_contains();
    example_predicate();
    example_list_init();
}