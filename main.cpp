#include <iostream>
#include <set>
#include <sstream>
#include <memory>
#include <map>

std::string generateTestStream(); 

class Graph {
    std::map<unsigned, std::set<unsigned>> m_adj; 
public:
    void addEdge(unsigned a, unsigned b) {
        this->failsafe_add(a, b);
        this->failsafe_add(b, a);
    }
private:
    void failsafe_add(unsigned a, unsigned b) {
        if (m_adj.count(a) < 1)
            m_adj[a] = std::set<unsigned>{b};
        else
            m_adj[a].insert(b);
    }
};

int main(int argc, const char * argv[]) {
    (void)argc;
    (void)argv;
    auto stream = generateTestStream();
    std::cout << stream;
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

