#include "dijkstra.cpp"

void printVector(const std::string &label, const std::vector<int> &vec)
{
    std::cout << label << ": [ ";
    for (int i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << (i == vec.size() - 1 ? "" : ", ");
    }
    std::cout << " ]" << std::endl;
}

int main()
{
    Graph myGraph;

    std::cout << "--- Building Graph ---" << std::endl;
    myGraph.addEdgeDirected(0, 1, 1);
    myGraph.addEdgeDirected(0, 2, 4);
    myGraph.addEdgeDirected(1, 2, 2);
    myGraph.addEdgeDirected(1, 3, 6);
    myGraph.addEdgeDirected(2, 3, 3);

    std::vector<int> bfsResult = myGraph.BFS(0);
    printVector("BFS starting from 0", bfsResult);

    std::vector<int> dfsRecResult = myGraph.DFS(0);
    printVector("DFS (Recursive) starting from 0", dfsRecResult);

    std::vector<int> dfsIterResult = myGraph.DFS_iterative(0);
    printVector("DFS (Iterative) starting from 0", dfsIterResult);

    std::cout << "Is graph connected? " << (myGraph.isConnected() ? "Yes" : "No") << std::endl;

    std::cout << "Does graph have cycle? " << (myGraph.hasCycle() ? "Yes" : "No") << std::endl;

    std::cout << "Adding edge (3 -> 0) to create a cycle..." << std::endl;
    myGraph.addEdgeDirected(3, 0, 1);
    std::cout << "Does graph have cycle now? " << (myGraph.hasCycle() ? "Yes" : "No") << std::endl;

    std::cout << "\n--- Testing Dijkstra (Shortest Paths from Node 0) ---" << std::endl;

    Graph dGraph;
    dGraph.addEdgeDirected(0, 1, 10);
    dGraph.addEdgeDirected(0, 2, 3);
    dGraph.addEdgeDirected(1, 2, 1);
    dGraph.addEdgeDirected(1, 3, 2);
    dGraph.addEdgeDirected(2, 1, 4);
    dGraph.addEdgeDirected(2, 3, 8);
    dGraph.addEdgeDirected(2, 4, 2);
    dGraph.addEdgeDirected(3, 4, 7);
    dGraph.addEdgeDirected(4, 3, 9);

    std::unordered_map<int, int> distances = dijkstra(dGraph, 0);

    std::cout << std::left << std::setw(10) << "Node" << "Distance from 0" << std::endl;
    for (auto const &[node, dist] : distances)
    {
        std::cout << std::left << std::setw(10) << node;
        if (dist == INT_MAX)
            std::cout << "INF" << std::endl;
        else
            std::cout << dist << std::endl;
    }

    return 0;
}