#pragma once

#include <map>
#include <vector>
#include <iterator>

class UnionFind {
    std::map<unsigned, unsigned> m_assocs;
    std::map<unsigned, unsigned> m_treeLens;
public:
    UnionFind() = default;
    UnionFind(std::istream & is);

    void addUnion(unsigned a, unsigned b);
    bool areConnected(unsigned a, unsigned b);

    friend std::ostream & operator<<(std::ostream &, const UnionFind&);
private:
    unsigned root(unsigned index);
};

std::ostream & operator<<(std::ostream & os, const UnionFind& uf) {
    os << "{";
    for (const auto & token : uf.m_assocs)
        os << token.first << ": " << token.second << ", ";
    os << "}";
    return os;
}

UnionFind::UnionFind(std::istream & is) {
    auto it = std::istream_iterator<unsigned>{is};
    while (it != std::istream_iterator<unsigned>()) {
        unsigned vertexA = *it;
        ++it;
        unsigned vertexB = *it;
        this->addUnion(vertexA, vertexB);
        ++it;
    }
}

unsigned UnionFind::root(unsigned index) {
    while (index != m_assocs[index]) {
        index = m_assocs[index];
    }

    return index;
}
void UnionFind::addUnion(unsigned a, unsigned b) {
    if (a == b)
        return;
    
    if (m_assocs.count(b) < 1) {
        m_assocs[b] = b;
        m_treeLens[b] = 1;
    }
    
    if (m_assocs.count(a) < 1) {
        m_assocs[a] = a;
        m_treeLens[a] = 1;
    }

    auto rootA = this->root(a);
    auto rootB = this->root(b);

    auto lenA = m_treeLens[a];
    auto lenB = m_treeLens[b];

    if (lenA < lenB) {
        m_assocs[rootA] = rootB;
        m_treeLens[b] += lenA;
    } else {
        m_assocs[rootB] = rootA;
        m_treeLens[a] += lenB;
    }
}

bool UnionFind::areConnected(unsigned a, unsigned b) {
    return root(a) == root(b);
}

