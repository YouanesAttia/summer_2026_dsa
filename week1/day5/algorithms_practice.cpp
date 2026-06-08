#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>

int main()
{
    // Given a vector<string> of names, use std::sort to sort alphabetically,
    // then std::sort with a custom comparator to sort by string length.

    std::vector<std::string> a{"Youanes", "Ahmed", "Omar", "Ali", "Mohamed", "Ahmed", "Khalid"};
    std::sort(a.begin(), a.end());
    std::cout
        << "Vector sorted alphabetically" << std::endl;
    for (int i = 0; i < a.size(); i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;

    std::sort(a.begin(), a.end(), [](std::string a, std::string b)
              { return a.length() > b.length(); });
    std::cout << "\n Vector sorted using length()" << std::endl;
    for (int i = 0; i < a.size(); i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;

    // Use std::transform to convert a vector<int> to a vector<string> (each int becomes "item_N").
    std::vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<std::string> items(v1.size());
    std::transform(v1.begin(), v1.end(), items.begin(), [](int n)
                   { return "item_" + std::to_string(n); });
    for (const auto &item : items)
    {
        std::cout << item << ' ';
    }
    std::cout << std::endl;

    // Use the erase-remove idiom to remove all even numbers from a vector in-place.
    v1.erase(std::remove_if(v1.begin(), v1.end(), [](int n)
                            { return n % 2 == 0; }),
             v1.end());
    for (const auto &num : v1)
    {
        std::cout << num << ' ';
    }
    std::cout << std::endl;

    // Use std::accumulate with a custom binary operation to find the product of all elements in a vector.
    std::vector<int> v2{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int product = std::accumulate(v2.begin(), v2.end(), 1, [](int a, int b)
                                  { return a * b; });
    std::cout << "Product = " << product << '\n';
}