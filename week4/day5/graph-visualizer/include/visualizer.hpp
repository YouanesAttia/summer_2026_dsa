#ifndef VISUALIZER_HPP
#define VISUALIZER_HPP

#include "graph.hpp"

#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>

namespace Color
{
    constexpr const char *RESET = "\033[0m";
    constexpr const char *RED = "\033[31m";
    constexpr const char *GREEN = "\033[32m";
    constexpr const char *YELLOW = "\033[33m";
    constexpr const char *BLUE = "\033[34m";
    constexpr const char *CYAN = "\033[36m";
}

void visualizeBFS(
    const Graph &graph,
    int start);

void visualizeDFS(
    const Graph &graph,
    int start);

void visualizeDijkstra(
    const Graph &graph,
    int source);

void clearScreen();

void pause(int milliseconds = 700);

void printQueue(std::queue<int> q);

void printStack(std::stack<int> s);
void printStack(Stack<int> s);

void printVisited(
    const std::unordered_set<int> &visited,
    const Graph &graph);

void printDistances(
    const std::unordered_map<int, int> &dist);

#endif