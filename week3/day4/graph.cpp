#include <iostream>
#include <unordered_map>
#include <vector>
#include "../../week2/day7/stl-lite/include/queue.hpp"
#include "../../week2/day7/stl-lite/include/stack.hpp"
class Graph
{
private:
    std::unordered_map<int, std::vector<int>> g;

public:
    Graph() = default;
    Graph(std::unordered_map<int, std::vector<int>> g_) : g(g_) {}

    void addEdgeDirected(int u, int v)
    {
        g[u].push_back(v);
    }
    void addEdgeUndirected(int u, int v)
    {
        g[u].push_back(v);
        g[v].push_back(u);
    }

    std::vector<int> BFS(int start)
    {
        Queue<int> q;
        std::vector<int> result;
        std::unordered_map<int, bool> isvisited;
        q.enqueue(start);
        result.push_back(start);
        isvisited[start] = 1;
        while (!q.isempty())
        {
            int val = q.dequeue();
            for (int i = 0; i < g[val].size(); i++)
            {
                if (!isvisited[g[val][i]])
                {
                    q.enqueue(g[val][i]);
                    result.push_back(g[val][i]);
                    isvisited[g[val][i]] = 1;
                }
            }
        }
        return result;
    }

    std::vector<int> DFS(int start)
    {
        std::unordered_map<int, bool> isvisited;
        std::vector<int> result;
        DFS(start, isvisited, result);
        return result;
    }

    void DFS(int start, std::unordered_map<int, bool> &check, std::vector<int> &v)
    {
        if (check[start] == 0)
        {
            v.push_back(start);
            check[start] = 1;
            for (int i = 0; i < g[start].size(); i++)
            {
                if (!check[g[start][i]])
                    DFS(g[start][i], check, v);
            }
        }
    }

    std::vector<int> DFS_iterative(int start)
    {
        std::unordered_map<int, bool> isvisited;
        std::vector<int> result;
        Stack<int> st;

        st.push(start);
        isvisited[start] = true;

        while (!st.isEmpty())
        {
            int val = st.pop();
            result.push_back(val);

            for (int neighbor : g[val])
            {
                if (!isvisited[neighbor])
                {
                    st.push(neighbor);
                    isvisited[neighbor] = true;
                }
            }
        }

        return result;
    }

    // visited = node has been seen before
    // recStack = node is currently in the active DFS path
    // If we reach a node already in recStack, we found a back edge => cycle
    bool hasCycle()
    {
        std::unordered_map<int, bool> visited;
        std::unordered_map<int, bool> recStack;

        for (auto &[node, neighbors] : g)
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

        for (int neighbor : g[node])
        {
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
};

std::unordered_map<int, std::vector<int>> FillGraph()
{
    std::unordered_map<int, std::vector<int>> g;
    int nodes;
    std::cout << "Enter the number of nodes: ";
    std::cin >> nodes;
    for (int i = 1; i <= nodes; i++)
    {
        int nodeVal;
        int connectedNodes;
        std::vector<int> v;
        std::cout << "Enter the value of the node number " << i << ": ";
        std::cin >> nodeVal;
        std::cout << "Enter the number of connected nodes to the node number " << i << ": ";
        std::cin >> connectedNodes;
        for (int j = 1; j <= connectedNodes; j++)
        {
            int connectedVal;
            std::cout << "Enter the value of the connected node number " << j << ": ";
            std::cin >> connectedVal;
            v.push_back(connectedVal);
        }
        g[nodeVal] = v;
    }
    return g;
}