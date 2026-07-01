#include "../include/visualizer.hpp"
#include "../include/algorithms.hpp"

#include <chrono>
#include <cstdlib>
#include <iostream>
#include <thread>
#include <climits>

void clearScreen()
{
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

void pause(int milliseconds)
{
    std::this_thread::sleep_for(
        std::chrono::milliseconds(milliseconds));
}

void printQueue(std::queue<int> q)
{
    std::cout << "Queue: ";

    while (!q.empty())
    {
        std::cout << q.front() << ' ';
        q.pop();
    }

    std::cout << '\n';
}

void printStack(std::stack<int> s)
{
    std::cout << "Stack: ";

    while (!s.empty())
    {
        std::cout << s.top() << ' ';
        s.pop();
    }

    std::cout << '\n';
}

void printStack(Stack<int> s)
{
    std::cout << "Stack: ";

    while (!s.isEmpty())
        std::cout << s.pop() << ' ';

    std::cout << '\n';
}

void printVisited(
    const std::unordered_set<int> &visited,
    const Graph &graph)
{
    std::cout << "Visited: ";

    for (int vertex : graph.getVertices())
    {
        if (visited.count(vertex))
            std::cout << Color::GREEN << vertex << Color::RESET << " ";
        else
            std::cout << vertex << " ";
    }

    std::cout << '\n';
}

void printDistances(
    const std::unordered_map<int, int> &dist)
{
    std::cout << "\nDistances\n";

    for (const auto &[vertex, distance] : dist)
    {
        std::cout << vertex << " : ";

        if (distance == INT_MAX)
            std::cout << "INF";
        else
            std::cout << distance;

        std::cout << '\n';
    }
}

void visualizeBFS(
    const Graph &graph,
    int start)
{
    std::queue<int> q;
    std::unordered_set<int> visited;

    const auto &adj = graph.getMap();

    q.push(start);
    visited.insert(start);

    while (!q.empty())
    {
        clearScreen();

        int current = q.front();
        q.pop();

        std::cout
            << Color::CYAN
            << "Current Node: "
            << current
            << Color::RESET
            << "\n\n";

        for (const auto &edge : adj.at(current))
        {
            int neighbor = edge.first;

            if (!visited.count(neighbor))
            {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }

        printQueue(q);
        std::cout << '\n';
        printVisited(visited, graph);

        std::cout << "\nNeighbors\n";

        for (const auto &edge : adj.at(current))
        {
            std::cout
                << edge.first
                << " (weight "
                << edge.second
                << ")\n";
        }

        pause();
    }
}

void visualizeDFS(
    const Graph &graph,
    int start)
{
    Stack<int> st;
    std::unordered_set<int> visited;

    const auto &adj = graph.getMap();

    st.push(start);

    while (!st.isEmpty())
    {
        clearScreen();

        int current = st.pop();

        if (visited.count(current))
            continue;

        visited.insert(current);

        for (auto it = adj.at(current).rbegin();
             it != adj.at(current).rend();
             ++it)
        {
            if (!visited.count(it->first))
                st.push(it->first);
        }

        std::cout
            << Color::YELLOW
            << "Current Node: "
            << current
            << Color::RESET
            << "\n\n";

        printStack(st);

        std::cout << '\n';

        printVisited(visited, graph);

        pause();
    }
}

void visualizeDijkstra(
    const Graph &graph,
    int source)
{
    const auto &adj = graph.getMap();

    std::unordered_map<int, int> dist;

    for (int vertex : graph.getVertices())
        dist[vertex] = INT_MAX;

    using Node = std::pair<int, int>;

    std::priority_queue<
        Node,
        std::vector<Node>,
        std::greater<Node>>
        pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty())
    {
        auto [currentDistance, current] = pq.top();
        pq.pop();

        if (currentDistance > dist[current])
            continue;

        clearScreen();

        std::cout
            << Color::BLUE
            << "Processing Node: "
            << current
            << Color::RESET
            << "\n";

        for (const auto &edge : adj.at(current))
        {
            int neighbor = edge.first;
            int weight = edge.second;

            if (dist[neighbor] > dist[current] + weight)
            {
                dist[neighbor] = dist[current] + weight;

                pq.push({dist[neighbor], neighbor});

                std::cout
                    << "\nRelaxed Edge: "
                    << current
                    << " -> "
                    << neighbor
                    << "\n";
            }
        }

        printDistances(dist);

        pause();
    }
}