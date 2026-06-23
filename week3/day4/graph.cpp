#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
#include "../../week2/day7/stl-lite/include/queue.hpp"
#include "../../week2/day7/stl-lite/include/stack.hpp"

class Graph
{
private:
    std::unordered_map<int, std::vector<std::pair<int, int>>> g;

public:
    Graph() = default;

    Graph(std::unordered_map<int, std::vector<std::pair<int, int>>> g_) : g(g_) {}

    void addEdgeDirected(int u, int v, int weight = 0)
    {
        g[u].push_back({v, weight});
    }

    void addEdgeUndirected(int u, int v, int weight = 0)
    {
        g[u].push_back({v, weight});
        g[v].push_back({u, weight});
    }

    std::vector<int> BFS(int start)
    {
        Queue<int> q;
        std::vector<int> result;
        std::unordered_map<int, bool> isvisited;

        q.enqueue(start);
        isvisited[start] = true;

        while (!q.isempty())
        {
            int val = q.dequeue();
            result.push_back(val);

            for (auto &edge : g[val])
            {
                int neighbor = edge.first;
                if (!isvisited[neighbor])
                {
                    q.enqueue(neighbor);
                    isvisited[neighbor] = true;
                }
            }
        }
        return result;
    }

    std::vector<int> DFS(int start)
    {
        std::unordered_map<int, bool> isvisited;
        std::vector<int> result;
        DFS_Recursive(start, isvisited, result);
        return result;
    }

    void DFS_Recursive(int start, std::unordered_map<int, bool> &check, std::vector<int> &v)
    {
        if (!check[start])
        {
            v.push_back(start);
            check[start] = true;
            for (auto &edge : g[start])
            {
                int neighbor = edge.first;
                if (!check[neighbor])
                    DFS_Recursive(neighbor, check, v);
            }
        }
    }

    std::vector<int> DFS_iterative(int start)
    {
        std::unordered_map<int, bool> isvisited;
        std::vector<int> result;
        Stack<int> st;

        st.push(start);

        while (!st.isEmpty())
        {
            int val = st.pop();

            if (!isvisited[val])
            {
                isvisited[val] = true;
                result.push_back(val);

                for (auto &edge : g[val])
                {
                    int neighbor = edge.first;
                    if (!isvisited[neighbor])
                    {
                        st.push(neighbor);
                    }
                }
            }
        }
        return result;
    }

    bool hasCycle()
    {
        std::unordered_map<int, bool> visited;
        std::unordered_map<int, bool> recStack;

        for (auto const &[node, neighbors] : g)
        {
            if (!visited[node])
            {
                if (hasCycleDFS(node, visited, recStack))
                    return true;
            }
        }
        return false;
    }

    bool hasCycleDFS(int node, std::unordered_map<int, bool> &visited, std::unordered_map<int, bool> &recStack)
    {
        visited[node] = true;
        recStack[node] = true;

        for (auto &edge : g[node])
        {
            int neighbor = edge.first;
            if (!visited[neighbor])
            {
                if (hasCycleDFS(neighbor, visited, recStack))
                    return true;
            }
            else if (recStack[neighbor])
            {
                return true;
            }
        }

        recStack[node] = false;
        return false;
    }

    bool isConnected()
    {
        if (g.empty())
            return true;
        std::vector<int> reachable = DFS(g.begin()->first);
        return reachable.size() == g.size();
    }
};

std::unordered_map<int, std::vector<std::pair<int, int>>> FillGraph()
{
    std::unordered_map<int, std::vector<std::pair<int, int>>> g;
    int nodes;
    std::cout << "Enter the number of nodes: ";
    std::cin >> nodes;

    for (int i = 0; i < nodes; i++)
    {
        int nodeVal, connectedNodes;
        std::cout << "Enter the value of the node: ";
        std::cin >> nodeVal;

        // Ensure node exists in map even if it has 0 connections
        if (g.find(nodeVal) == g.end())
            g[nodeVal] = {};

        std::cout << "Number of neighbors for node " << nodeVal << ": ";
        std::cin >> connectedNodes;

        for (int j = 0; j < connectedNodes; j++)
        {
            int neighbor, weight;
            std::cout << "  Enter neighbor node ID: ";
            std::cin >> neighbor;
            std::cout << "  Enter weight for edge (" << nodeVal << "->" << neighbor << "): ";
            std::cin >> weight;
            g[nodeVal].push_back({neighbor, weight});
        }
    }
    return g;
}