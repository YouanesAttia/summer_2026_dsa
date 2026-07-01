#include "../include/algorithms.hpp"

#include <climits>
#include <functional>
#include <queue>

std::unordered_map<int, int>
dijkstra(const Graph &graph,
         int source)
{
    std::unordered_map<int, int> dist;

    using Node = std::pair<int, int>;

    std::priority_queue<
        Node,
        std::vector<Node>,
        std::greater<Node>>
        pq;

    for (int vertex : graph.getVertices())
        dist[vertex] = INT_MAX;

    dist[source] = 0;

    pq.push({0, source});

    const auto &adj = graph.getMap();

    while (!pq.empty())
    {
        auto [currentDistance,
              currentNode] = pq.top();

        pq.pop();

        if (currentDistance > dist[currentNode])
            continue;

        for (const auto &edge : adj.at(currentNode))
        {
            int neighbor = edge.first;
            int weight = edge.second;

            if (dist[neighbor] >
                dist[currentNode] + weight)
            {
                dist[neighbor] =
                    dist[currentNode] + weight;

                pq.push(
                    {dist[neighbor],
                     neighbor});
            }
        }
    }

    return dist;
}