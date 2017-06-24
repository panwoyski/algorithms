#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>
#include "graph.h"
#include "dfs.h"

std::string generateTestStream(); 

void solve(std::vector<std::string> tokens) {
    auto graph = Graph();
    bool sig1_present = false;
    bool sig2_present = false;
    int significant1 = std::stoi(tokens[0]);
    int significant2 = std::stoi(tokens[1]);

    for (std::size_t i = 2; i < tokens.size(); i += 2) {
        int vertex_a = std::stoi(tokens[i]);
        int vertex_b = std::stoi(tokens[i+1]);
        sig1_present |= significant1 == vertex_a || significant1 == vertex_b;
        sig2_present |= significant2 == vertex_a || significant2 == vertex_b;
        graph.addEdge(vertex_a, vertex_b); 
    }

    if (!(sig1_present && sig2_present)) {
        std::cout << "no\n";
        return;
    }
 
    auto dfs = DFS(graph);
    auto result = dfs.solve(significant1, significant2);
    std::cout << (result ? "yes" : "no") << std::endl;
}

int main() {
    auto str = generateTestStream();

    auto stream = std::istringstream(str);
    std::vector<std::string> tokens{std::istream_iterator<std::string>{stream},
                                    std::istream_iterator<std::string>()};

    solve(tokens);

    return 0;
}

std::string generateTestStream() {
   auto ss = std::stringstream();
   ss << "1 5\n";
   ss << "1 2\n";
   ss << "2 3\n";
   ss << "3 4\n";
   ss << "4 2\n";
   ss << "4 5\n";

   return ss.str();
}

