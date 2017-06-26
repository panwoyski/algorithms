#pragma once
#include <map>
#include <set>
#include <vector>
#include <istream>
#include <iterator>

class Graph {
    std::map<unsigned, std::set<unsigned>> m_adj;
    using adj_list_t = decltype(m_adj)::mapped_type;
    adj_list_t m_empty_adj_list;
public:
    Graph() = default;
    Graph(std::istream & is);

    void addEdge(unsigned a, unsigned b);

    const adj_list_t & getNeighbours(unsigned vertex) const;

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
        ++it;
    }
}

void Graph::addEdge(unsigned a, unsigned b) {
    this->failsafe_add(a, b);
    this->failsafe_add(b, a);
}

const Graph::adj_list_t & Graph::getNeighbours(unsigned vertex) const {
    try {
        return m_adj.at(vertex);
    }
    catch (std::out_of_range &) {
        return m_empty_adj_list;
    }
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

