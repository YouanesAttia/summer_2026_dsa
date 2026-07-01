#include "../include/graph.hpp"
#include "../include/visualizer.hpp"
#include "../include/algorithms.hpp"

#include <iostream>
#include <limits>

void printMenu()
{
    std::cout << "\n=====================================\n";
    std::cout << "         GRAPH VISUALIZER\n";
    std::cout << "=====================================\n";
    std::cout << "1. Read Directed Graph\n";
    std::cout << "2. Read Undirected Graph\n";
    std::cout << "3. Print Graph\n";
    std::cout << "4. BFS\n";
    std::cout << "5. DFS\n";
    std::cout << "6. Dijkstra\n";
    std::cout << "7. Check Connectivity\n";
    std::cout << "8. Check Cycle\n";
    std::cout << "9. Exit\n";
    std::cout << "=====================================\n";
    std::cout << "Choice: ";
}

int main()
{
    Graph graph;

    while (true)
    {
        printMenu();

        int choice;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            graph = Graph();
            graph.readGraph(true, true);
            break;
        }

        case 2:
        {
            graph = Graph();
            graph.readGraph(false, true);
            break;
        }

        case 3:
        {
            graph.printGraph();
            break;
        }

        case 4:
        {
            int start;

            std::cout << "Start Vertex: ";
            std::cin >> start;

            visualizeBFS(graph, start);

            break;
        }

        case 5:
        {
            int start;

            std::cout << "Start Vertex: ";
            std::cin >> start;

            visualizeDFS(graph, start);

            break;
        }

        case 6:
        {
            int start;

            std::cout << "Source Vertex: ";
            std::cin >> start;

            visualizeDijkstra(graph, start);

            break;
        }

        case 7:
        {
            if (graph.isConnected())
                std::cout << "\nGraph is connected.\n";
            else
                std::cout << "\nGraph is NOT connected.\n";

            break;
        }

        case 8:
        {
            if (graph.hasCycle())
                std::cout << "\nGraph contains a cycle.\n";
            else
                std::cout << "\nGraph does NOT contain a cycle.\n";

            break;
        }

        case 9:
        {
            return 0;
        }

        default:
        {
            std::cout << "\nInvalid option.\n";
        }
        }

        std::cout << "\nPress ENTER to continue...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
    }

    return 0;
}