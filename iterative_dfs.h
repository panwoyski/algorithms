#pragma once
#include <vector>
#include "graph.h"
#include <stack>

class IterativeDFS {
    std::vector<bool> m_visited;
    const Graph & m_graph;

public:
    IterativeDFS(const Graph & graph)
        : m_visited(graph.verticesAmount(), false)
        , m_graph{graph} {}

    bool solve(unsigned starting_point, unsigned expected);
private:
    bool recur(unsigned vertex, unsigned expected);
};

bool IterativeDFS::solve(unsigned starting_point, unsigned expected) {
    std::deque<unsigned> dfs;
    
    bool found = false;
    dfs.push_front(starting_point);
    do {
        auto top = dfs[0];
        if (top == expected) {
            found = true;
            break;
        }
        dfs.pop_front();

        if (m_visited[top])
            continue;
        m_visited[top] = true;

        auto vertices = m_graph.getNeighbours(top);

        dfs.insert(dfs.begin(), vertices.begin(), vertices.end());
    } while (!dfs.empty());

    return found;
}

bool IterativeDFS::recur(unsigned vertex, unsigned expected) {
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

