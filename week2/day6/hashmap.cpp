#include <vector>
#include <string>
#include <utility>
#include <stdexcept>
#include <chrono>
#include <cassert>
#include <iostream>

template <typename K, typename V>
class HashMap
{
private:
    std::vector<std::vector<std::pair<K, V>>> buckets;
    size_t currentSize;
    size_t capacity;

private:
    size_t hashKey(const int &key) const
    {
        return static_cast<size_t>(key);
    }

    size_t hashKey(const std::string &key) const
    {
        size_t hash = 0;

        for (char c : key)
        {
            hash = hash * 31 + c;
        }

        return hash;
    }

    size_t getBucketIndex(const K &key) const
    {
        return hashKey(key) % capacity;
    }

    double loadFactor() const
    {
        return static_cast<double>(currentSize) / capacity;
    }

    void rehash()
    {
        size_t newCapacity = capacity * 2;

        std::vector<std::vector<std::pair<K, V>>> newBuckets(newCapacity);

        for (auto &bucket : buckets)
        {
            for (auto &entry : bucket)
            {
                size_t newIndex = hashKey(entry.first) % newCapacity;
                newBuckets[newIndex].push_back(entry);
            }
        }

        buckets = std::move(newBuckets);
        capacity = newCapacity;
    }

public:
    HashMap(size_t initialCapacity = 16)
        : buckets(initialCapacity),
          currentSize(0),
          capacity(initialCapacity)
    {
    }

    void put(const K &key, const V &value)
    {
        size_t index = getBucketIndex(key);

        for (auto &entry : buckets[index])
        {
            if (entry.first == key)
            {
                entry.second = value;
                return;
            }
        }

        buckets[index].push_back({key, value});
        ++currentSize;

        if (loadFactor() > 0.75)
        {
            rehash();
        }
    }

    V &get(const K &key)
    {
        size_t index = getBucketIndex(key);

        for (auto &entry : buckets[index])
        {
            if (entry.first == key)
            {
                return entry.second;
            }
        }

        throw std::runtime_error("Key not found");
    }

    const V &get(const K &key) const
    {
        size_t index = getBucketIndex(key);

        for (const auto &entry : buckets[index])
        {
            if (entry.first == key)
            {
                return entry.second;
            }
        }

        throw std::runtime_error("Key not found");
    }

    bool contains(const K &key) const
    {
        size_t index = getBucketIndex(key);

        for (const auto &entry : buckets[index])
        {
            if (entry.first == key)
            {
                return true;
            }
        }

        return false;
    }

    bool remove(const K &key)
    {
        size_t index = getBucketIndex(key);

        auto &bucket = buckets[index];

        for (auto it = bucket.begin(); it != bucket.end(); ++it)
        {
            if (it->first == key)
            {
                bucket.erase(it);
                --currentSize;
                return true;
            }
        }

        return false;
    }

    size_t size() const
    {
        return currentSize;
    }

    bool empty() const
    {
        return currentSize == 0;
    }
};

int main()
{
    HashMap<int, int> map;

    const int N = 1000;

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < N; i++)
    {
        map.put(i, i * 10);
    }

    for (int i = 0; i < N; i++)
    {
        assert(map.contains(i));
        assert(map.get(i) == i * 10);
    }

    auto end = std::chrono::high_resolution_clock::now();

    auto duration =
        std::chrono::duration_cast<std::chrono::microseconds>(
            end - start);

    std::cout << "Inserted and verified "
              << N
              << " items\n";

    std::cout << "Time: "
              << duration.count()
              << " microseconds\n";

    for (int i = 0; i < 100; i++)
    {
        map.remove(i);
    }

    for (int i = 0; i < 100; i++)
    {
        assert(!map.contains(i));
    }

    std::cout << "Remove test passed\n";
    std::cout << "Current size = "
              << map.size()
              << '\n';

    return 0;
}
