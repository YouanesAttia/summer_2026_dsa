#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "graph.hpp"
#include <unordered_map>

std::unordered_map<int, int>
dijkstra(const Graph &graph, int source);

#endif