#include <iostream>
#include "graph.h"
#include "recursive_dfs.h"

int main() {
    auto it = std::istream_iterator<unsigned>{std::cin};
    unsigned room1 = *it;
    unsigned room2 = *(++it);

    // Mozna by tu sprawdzic czy oba pokoje wystepuja
    // w liscie pokoi i skrocic obliczenia
    auto graph = Graph{std::cin};
    //std::cout << "Graph structure\n";
    //std::cout << graph;
    auto dfs = RecursiveDFS{graph};
    auto result = dfs.solve(room1, room2);

    std::cout << (result ? "yes" : "no") << std::endl;

    return 0;
}

