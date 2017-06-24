#include <iostream>
#include "graph.h"
#ifndef RECURSIVE
#include "iterative_dfs.h"
#else
#include "recursive_dfs.h"
#endif

int main() {
    auto it = std::istream_iterator<unsigned>{std::cin};
    unsigned room1 = *it;
    unsigned room2 = *(++it);

    auto graph = Graph{std::cin};
#ifndef RECURSIVE
    auto dfs = IterativeDFS{graph};
#else
    auto dfs = RecursiveDFS{graph};
#endif
    auto result = dfs.solve(room1, room2);

    std::cout << (result ? "yes" : "no") << std::endl;

    return 0;
}

