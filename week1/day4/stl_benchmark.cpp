// Deques are the most efficient considering insertion at the beganing
// Vectors are the most efficient considering insertion at the end
// The unordered_map is more effecient than the map considering looking up the data

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <chrono>
#include <map>
#include <unordered_map>
#include <string>
#include <queue>

int main()
{
    // Insert at the begin
    std::vector<int> v1;
    auto vstarttime = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 100000; i++)
        v1.insert(v1.begin(), i);
    auto vendtime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> binsertintime = vendtime - vstarttime;
    std::cout << "Time taken to insert at the begining of a vector is: " << binsertintime.count() << " microseconds\n"; // 466.062

    std::list<int> l1;
    auto lstarttime = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 100000; i++)
        l1.push_front(i);
    auto lendtime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> linsertintime = lendtime - lstarttime;
    std::cout << "Time taken to insert at the begining of a list is: " << linsertintime.count() << " microseconds\n"; // 8.4383

    std::deque<int> q1;
    auto qstarttime = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 100000; i++)
        q1.push_front(i);
    auto qendtime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> qinsertintime = qendtime - qstarttime;
    std::cout << "Time taken to insert at the begining of a deque is: " << qinsertintime.count() << " microseconds\n"; // 0.7297

    // Insert at the end
    std::vector<int> v2;
    auto evstarttime = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 100000; i++)
        v2.push_back(i);
    auto evendtime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> evinsertintime = evendtime - evstarttime;
    std::cout << "Time taken to insert at the end of a vector is: " << evinsertintime.count() << " microseconds\n"; // 0.6909

    std::list<int> l2;
    auto elstarttime = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 100000; i++)
        l2.push_back(i);
    auto elendtime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elinsertintime = elendtime - elstarttime;
    std::cout << "Time taken to insert at the end of a list is: " << elinsertintime.count() << " microseconds\n"; // 10.9229

    std::deque<int> q2;
    auto eqstarttime = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 100000; i++)
        q2.push_back(i);
    auto eqendtime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> eqinsertintime = eqendtime - eqstarttime;
    std::cout << "Time taken to insert at the end of a deque is: " << eqinsertintime.count() << " microseconds\n"; // 1.1501

    // Time needed to lookup a map vs. unordered_map
    std::map<int, std::string> orderedMap;
    std::unordered_map<int, std::string> unorderedMap;

    for (int i = 0; i < 100000; ++i)
    {
        std::string value = "Value_" + std::to_string(i);
        orderedMap[i] = value;
        unorderedMap[i] = value;
    }

    auto startMap = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 100000; ++i)
    {
        auto it = orderedMap.find(i);
    }
    auto endMap = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> mapTime = endMap - startMap;
    std::cout << "Map lookup time: " << mapTime.count() << " microseconds\n"; // 41.7921

    auto startumap = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 100000; ++i)
    {
        auto it = unorderedMap.find(i);
    }
    auto endumap = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> umapTime = endumap - startumap;
    std::cout << "Unordered_map lookup time: " << umapTime.count() << " microseconds\n"; // 4.3118

    // Uses std::priority_queue to sort a random vector of integers

    std::vector<int> v3{1, 2, 5, 6, 2342, 235, 55, 664, 7467, 86, 45, 345};
    std::priority_queue<int> pq1;
    int n = v3.size();
    for (int i = 0; i < n; i++)
    {
        int value = v3.back();
        pq1.push(value);
        v3.pop_back();
    }

    while (!pq1.empty())
    {
        int val = pq1.top();
        v3.push_back(val);
        pq1.pop();
    }

    for (auto a : v3)
        std::cout << a << " ";
}