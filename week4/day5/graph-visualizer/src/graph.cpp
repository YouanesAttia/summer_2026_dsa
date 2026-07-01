#include "../include/graph.hpp"

#include <iostream>

Graph::Graph(
    const std::unordered_map<
        int,
        std::vector<std::pair<int, int>>> &graph)
    : g(graph)
{
    for (const auto &[node, edges] : g)
    {
        vertices.insert(node);

        for (const auto &edge : edges)
            vertices.insert(edge.first);
    }
}

void Graph::addVertex(int vertex)
{
    vertices.insert(vertex);

    if (g.find(vertex) == g.end())
        g[vertex] = {};
}

void Graph::addEdgeDirected(
    int u,
    int v,
    int weight)
{
    addVertex(u);
    addVertex(v);

    g[u].push_back({v, weight});
}

void Graph::addEdgeUndirected(
    int u,
    int v,
    int weight)
{
    addEdgeDirected(u, v, weight);
    addEdgeDirected(v, u, weight);
}

void Graph::readGraph(
    bool directed,
    bool weighted)
{
    int nodes;

    std::cout << "Number of vertices: ";
    std::cin >> nodes;

    for (int i = 0; i < nodes; i++)
    {
        int node;
        int neighbors;

        std::cout
            << "\nVertex "
            << i + 1
            << ": ";

        std::cin >> node;

        addVertex(node);

        std::cout
            << "Neighbors: ";

        std::cin >> neighbors;

        for (int j = 0; j < neighbors; j++)
        {
            int neighbor;
            int weight = 1;

            std::cout
                << "Neighbor "
                << j + 1
                << ": ";

            std::cin >> neighbor;

            if (weighted)
            {
                std::cout
                    << "Weight: ";

                std::cin >> weight;
            }

            if (directed)
                addEdgeDirected(node,
                                neighbor,
                                weight);
            else
                addEdgeUndirected(node,
                                  neighbor,
                                  weight);
        }
    }
}

void Graph::printGraph() const
{
    std::cout << "\n===== GRAPH =====\n\n";

    for (const auto &[node, edges] : g)
    {
        std::cout << node << " -> ";

        if (edges.empty())
        {
            std::cout << "(none)";
        }

        for (const auto &edge : edges)
        {
            std::cout
                << "("
                << edge.first
                << ", "
                << edge.second
                << ") ";
        }

        std::cout << '\n';
    }

    std::cout << "\n=================\n";
}

const std::unordered_set<int> &
Graph::getVertices() const
{
    return vertices;
}

const std::unordered_map<
    int,
    std::vector<std::pair<int, int>>> &
Graph::getMap() const
{
    return g;
}

std::vector<int> Graph::BFS(int start)
{
    Queue<int> q;
    std::vector<int> order;
    std::unordered_map<int, bool> visited;

    q.enqueue(start);
    visited[start] = true;

    while (!q.isempty())
    {
        int current = q.dequeue();
        order.push_back(current);

        for (const auto &edge : g[current])
        {
            int neighbor = edge.first;

            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.enqueue(neighbor);
            }
        }
    }

    return order;
}

std::vector<int> Graph::DFS(int start)
{
    std::unordered_map<int, bool> visited;
    std::vector<int> order;

    DFS_Recursive(start, visited, order);

    return order;
}

void Graph::DFS_Recursive(
    int start,
    std::unordered_map<int, bool> &visited,
    std::vector<int> &order)
{
    visited[start] = true;
    order.push_back(start);

    for (const auto &edge : g[start])
    {
        int neighbor = edge.first;

        if (!visited[neighbor])
            DFS_Recursive(neighbor, visited, order);
    }
}

std::vector<int> Graph::DFS_iterative(int start)
{
    Stack<int> st;

    std::unordered_map<int, bool> visited;
    std::vector<int> order;

    st.push(start);

    while (!st.isEmpty())
    {
        int current = st.pop();

        if (visited[current])
            continue;

        visited[current] = true;
        order.push_back(current);

        for (auto it = g[current].rbegin();
             it != g[current].rend();
             ++it)
        {
            if (!visited[it->first])
                st.push(it->first);
        }
    }

    return order;
}

bool Graph::hasCycle()
{
    std::unordered_map<int, bool> visited;
    std::unordered_map<int, bool> recursionStack;

    for (const auto &[node, _] : g)
    {
        if (!visited[node])
        {
            if (hasCycleDFS(node,
                            visited,
                            recursionStack))
                return true;
        }
    }

    return false;
}

bool Graph::hasCycleDFS(
    int node,
    std::unordered_map<int, bool> &visited,
    std::unordered_map<int, bool> &recursionStack)
{
    visited[node] = true;
    recursionStack[node] = true;

    for (const auto &edge : g[node])
    {
        int neighbor = edge.first;

        if (!visited[neighbor])
        {
            if (hasCycleDFS(neighbor,
                            visited,
                            recursionStack))
                return true;
        }
        else if (recursionStack[neighbor])
        {
            return true;
        }
    }

    recursionStack[node] = false;

    return false;
}
bool Graph::isConnected()
{
    if (vertices.empty())
        return true;

    int start = *vertices.begin();

    std::vector<int> reachable = DFS(start);

    return reachable.size() == vertices.size();
}