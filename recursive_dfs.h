#pragma once
#include <vector>
#include "graph.h"

#include <iostream>

class RecursiveDFS {
    std::vector<bool> m_visited;
    const Graph & m_graph;

public:
    RecursiveDFS(const Graph & graph)
        : m_visited(graph.verticesAmount(), false)
        , m_graph{graph} {}

    bool solve(unsigned starting_point, unsigned expected);
private:
    bool recur(unsigned vertex, unsigned expected);
};

bool RecursiveDFS::solve(unsigned starting_point, unsigned expected) {
    return recur(starting_point, expected);
}

bool RecursiveDFS::recur(unsigned vertex, unsigned expected) {
    std::cout << "Testing vertex: " << vertex << std::endl;
    if (vertex == expected)
        return true;

    m_visited[vertex] = true;
    for (const auto & curr_vert : m_graph.getNeighbours(vertex)) {
        if (m_visited[curr_vert])
            continue;

        bool ret = recur(curr_vert, expected);

        if (true == ret)
            return ret;
    }

    return false;
}

