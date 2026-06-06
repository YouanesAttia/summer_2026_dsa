// Build a class BigBuffer that holds a vector<int> with 1 million ints. Implement the Rule of Five:
// default constructor, destructor, copy constructor, copy assignment, move constructor, move assignment
// operator. Time copying vs moving using std::chrono.

#include <iostream>
#include <utility>
#include <vector>
#include <chrono>
using namespace std;

class BigBuffer
{
private:
    vector<int> v;

public:
    BigBuffer()
    {
        v.assign(1000000, 0);
    }

    BigBuffer(int n)
    {
        v.assign(1000000, n);
    }

    ~BigBuffer() = default;

    BigBuffer(const BigBuffer &a)
    {
        v = a.v;
    }

    BigBuffer &operator=(const BigBuffer &other)
    {
        if (this != &other)
        {
            v = other.v;
        }
        return *this;
    }

    BigBuffer(BigBuffer &&a) noexcept
    {
        v = std::move(a.v);
    }

    BigBuffer &operator=(BigBuffer &&other) noexcept
    {
        if (this != &other)
        {
            v = std::move(other.v);
        }
        return *this;
    }
    size_t size() const { return v.size(); }
};

int main()
{
    BigBuffer source(42);
    cout << "Source size: " << source.size() << " elements.\n";

    // --- TIMING THE COPY ---
    auto startCopy = std::chrono::high_resolution_clock::now();
    BigBuffer copyDest = source;
    auto endCopy = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> copyTime = endCopy - startCopy;

    // --- TIMING THE MOVE ---
    auto startMove = std::chrono::high_resolution_clock::now();
    BigBuffer moveDest = std::move(source);
    auto endMove = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> moveTime = endMove - startMove;

    cout << "Copying 1,000,000 ints took: " << copyTime.count() << " ms\n";
    cout << "Moving 1,000,000 ints took:  " << moveTime.count() << " ms\n";

    cout << "Dest size after move:   " << moveDest.size() << "\n";
    cout << "Source size after move: " << source.size() << "\n";

    return 0;
}