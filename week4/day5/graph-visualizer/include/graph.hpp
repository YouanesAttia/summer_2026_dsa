#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <utility>

#include "../../../../week2/day7/stl-lite/include/queue.hpp"
#include "../../../../week2/day7/stl-lite/include/stack.hpp"

class Graph
{
private:
    std::unordered_map<int,
                       std::vector<std::pair<int, int>>>
        g;

    std::unordered_set<int> vertices;

    void DFS_Recursive(
        int start,
        std::unordered_map<int, bool> &visited,
        std::vector<int> &order);

    bool hasCycleDFS(
        int node,
        std::unordered_map<int, bool> &visited,
        std::unordered_map<int, bool> &recStack);

public:
    Graph() = default;

    explicit Graph(
        const std::unordered_map<
            int,
            std::vector<std::pair<int, int>>> &graph);

    // Graph construction
    void addVertex(int vertex);

    void addEdgeDirected(
        int u,
        int v,
        int weight = 1);

    void addEdgeUndirected(
        int u,
        int v,
        int weight = 1);

    void readGraph(
        bool directed = true,
        bool weighted = true);

    void printGraph() const;

    // Traversals
    std::vector<int> BFS(int start);

    std::vector<int> DFS(int start);

    std::vector<int> DFS_iterative(int start);

    // Graph properties
    bool hasCycle();

    bool isConnected();

    // Getters
    const std::unordered_set<int> &getVertices() const;

    const std::unordered_map<
        int,
        std::vector<std::pair<int, int>>> &
    getMap() const;
};

#endif