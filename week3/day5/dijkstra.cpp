#include "../day4/graph.cpp"
#include <queue>

std::unordered_map<int, int> dijkstra(Graph g, int source)
{
    std::unordered_map<int, int> d;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

    for (int v : g.getVertices())
    {
        d[v] = INT_MAX;
    }
    d[source] = 0;

    pq.push({0, source});
    std::unordered_map<int, std::vector<std::pair<int, int>>> m = g.getMap();

    while (!pq.empty())
    {
        std::pair<int, int> Top = pq.top();
        pq.pop();
        for (auto &[neighbor, weight] : m[Top.second])
        {
            if (d[neighbor] > Top.first + weight)
            {
                d[neighbor] = Top.first + weight;
                pq.push({d[neighbor], neighbor});
            }
        }
    }

    return d;
}