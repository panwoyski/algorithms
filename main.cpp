#include <iostream>
#include <set>
#include <sstream>
#include <memory>
#include <map>
#include <vector>
#include <iterator>
#include <unistd.h>

std::string generateTestStream(); 

class Graph {
    std::map<unsigned, std::set<unsigned>> m_adj; 
public:
    void addEdge(unsigned a, unsigned b) {
        this->failsafe_add(a, b);
        this->failsafe_add(b, a);
    }

    bool areVerticesConnected(unsigned, unsigned) const;

    friend std::ostream & operator<<(std::ostream &, const Graph&);
private:
    void failsafe_add(unsigned a, unsigned b) {
        if (m_adj.count(a) < 1)
            m_adj[a] = std::set<unsigned>{b};
        else
            m_adj[a].insert(b);
    }
};

bool Graph::areVerticesConnected(unsigned vertexA, unsigned vertexB) const {
    auto visited = std::vector<bool>(false, m_adj.size());

    return false;
}

std::ostream & operator<<(std::ostream& os, const Graph & graph) {
    for (const auto & pair : graph.m_adj) {
        os << pair.first << ':';
        for (const auto & vertex : pair.second) {
            os << vertex << " ";
        }
        os << std::endl;
    }
        
    return os;
}

void parseInput(std::vector<std::string> tokens) {
    auto graph = Graph();
    bool sig1_present = false;
    bool sig2_present = false;
    int significant1 = std::stoi(tokens[0]);
    int significant2 = std::stoi(tokens[1]);

    std::cout << significant1 << std::endl;
    std::cout << significant2 << std::endl;

    for (std::size_t i = 2; i < tokens.size(); i += 2) {
        int vertex_a = std::stoi(tokens[i]);
        int vertex_b = std::stoi(tokens[i+1]);
        sig1_present |= significant1 == vertex_a || significant1 == vertex_b;
        sig2_present |= significant2 == vertex_a || significant2 == vertex_b;
        graph.addEdge(vertex_a, vertex_b); 
    }
    std::cout << "Significant1 is " << (sig1_present ? "present" : "absent") << std::endl;
    std::cout << "Significant2 is " << (sig2_present ? "present" : "absent") << std::endl;
    std::cout << graph;
}

int main(int argc, const char * argv[]) {
    (void)argc;
    (void)argv;
    auto str = generateTestStream();

    auto stream = std::istringstream(str);
    std::vector<std::string> tokens{std::istream_iterator<std::string>{stream},
                                    std::istream_iterator<std::string>()};

    parseInput(tokens);
    

    //for (const auto& token : tokens) {
    //    std::cout << token << std::endl;
    //}
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

