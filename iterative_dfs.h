#pragma once
#include <vector>
#include "graph.h"
#include "dfs.h"
#include <stack>

class IterativeDFS : public DFS {
public:
    IterativeDFS(const Graph & graph) : DFS{graph} {}

    bool solve(unsigned starting_point, unsigned expected) override;
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

