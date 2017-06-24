#pragma once
#include <vector>
#include "graph.h"
#include "dfs.h"

class RecursiveDFS : public DFS {
public:
    RecursiveDFS(const Graph & graph) : DFS{graph} {}

    bool solve(unsigned starting_point, unsigned expected) override;
private:
    bool recur(unsigned vertex, unsigned expected);
};

bool RecursiveDFS::solve(unsigned starting_point, unsigned expected) {
    return recur(starting_point, expected);
}

bool RecursiveDFS::recur(unsigned vertex, unsigned expected) {
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

