#include <iostream>
#include <unordered_map>
#include <vector>

class Graph
{
private:
    std::unordered_map<int, std::vector<int>> g;

public:
    Graph() = default;
};

void FillGraph()
{
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
}