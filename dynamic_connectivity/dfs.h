#pragma once
#include <vector>
#include "graph.h"

class DFS {
protected:
    std::vector<bool> m_visited;
    const Graph & m_graph;

public:
    DFS(const Graph & graph)
        : m_visited(graph.verticesAmount(), false)
        , m_graph{graph} {}

    virtual bool solve(unsigned starting_point, unsigned expected) = 0;
    virtual ~DFS() = default;
};

