#pragma once
#include <map>
#include <set>
#include <vector>
#include <istream>
#include <iterator>

class Graph {
    std::map<unsigned, std::set<unsigned>> m_adj;
public:
    Graph() = default;
    Graph(std::istream & is);

    void addEdge(unsigned a, unsigned b);

    decltype(m_adj)::mapped_type const & getNeighbours(unsigned vertex) const;

    std::size_t verticesAmount() const { return m_adj.size(); }

    friend std::ostream & operator<<(std::ostream &, const Graph&);
private:
    void failsafe_add(unsigned a, unsigned b);
};

Graph::Graph(std::istream & is) {
    auto it = std::istream_iterator<unsigned>{is};
    while (it != std::istream_iterator<unsigned>()) {
        unsigned vertexA = *it;
        ++it;
        unsigned vertexB = *it;
        addEdge(vertexA, vertexB);
    }
}

void Graph::addEdge(unsigned a, unsigned b) {
    this->failsafe_add(a, b);
    this->failsafe_add(b, a);
}

decltype(Graph::m_adj)::mapped_type const &
Graph::getNeighbours(unsigned vertex) const {
    return m_adj.at(vertex);
}

void Graph::failsafe_add(unsigned a, unsigned b) {
    if (m_adj.count(a) < 1)
        m_adj[a] = std::set<unsigned>{b};
    else
        m_adj[a].insert(b);
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

