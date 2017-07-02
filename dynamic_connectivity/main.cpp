#include <iostream>
#include "graph.h"
#ifndef RECURSIVE
#include "iterative_dfs.h"
#else
#include "recursive_dfs.h"
#endif
#include "union_find.h"
#include <chrono>

template <typename function_t>
void timedExecution(function_t func) {
    using std::chrono::high_resolution_clock;

    auto t1 = high_resolution_clock::now();
    func();
    auto t2 = high_resolution_clock::now();
    
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

    std::cout << "Execution took: " << duration << "ms\n";
}

void unionFindTest() {
    std::cout << __func__ << std::endl;
    auto it = std::istream_iterator<unsigned>{std::cin};
    unsigned room1 = *it;
    unsigned room2 = *(++it);
    
    auto unionFind = UnionFind{std::cin};
    auto result = unionFind.areConnected(room1, room2);

    std::cout << (result ? "yes" : "no") << std::endl;
}

void dfsTest() {
    std::cout << __func__ << std::endl;
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
}

int main() {
#ifdef USE_DFS
    timedExecution(dfsTest);
#else
    timedExecution(unionFindTest);
#endif
    return 0;
}

