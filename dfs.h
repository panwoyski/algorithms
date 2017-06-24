#pragma once
#include <vector>
#include "graph.h"

class DFS {
    std::vector<bool> m_visited;
    const Graph & m_graph;

public:
    DFS(const Graph & graph)
        : m_visited(graph.verticesAmount(), false)
        , m_graph{graph} {}

    bool solve(unsigned starting_point, unsigned expected);
private:
    bool recur(unsigned vertex, unsigned expected);
};

bool DFS::solve(unsigned starting_point, unsigned expected) {
    return recur(starting_point, expected);
}

bool DFS::recur(unsigned vertex, unsigned expected) {
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

