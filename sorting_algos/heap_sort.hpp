#pragma once

#include <iterator>

namespace {
    template <typename iterator_t>
    inline void heapify(iterator_t beginIt, iterator_t endIt) {
        auto lastIt = std::prev(endIt);

        while (beginIt != endIt) {
            if (*lastIt < *beginIt)
                std::iter_swap(lastIt, beginIt);
            beginIt++;
        }
    }

    template <typename container_t>
    inline void heapify(container_t & container) {
        heapify(container.rbegin(), container.rend());
    }
}

namespace sorting {
    template <typename container_t>
    void heapSort(container_t & container) {
        auto rBeginIt = container.rbegin();
        auto rEndIt = container.rend();

        auto rLastIt = std::prev(rEndIt);

        while (rBeginIt != rEndIt) {
            heapify(rBeginIt, rEndIt);
            std::iter_swap(rBeginIt, rLastIt);
            rBeginIt++;
        }
    }
}

