#include <iostream>
#include <unordered_map>
#include <vector>
#include "../../week2/day7/stl-lite/include/queue.hpp"
class Graph
{
private:
    std::unordered_map<int, std::vector<int>> g;

public:
    Graph() = default;
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