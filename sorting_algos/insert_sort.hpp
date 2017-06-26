#pragma once

#include <algorithm>

namespace sorting {
    template <typename container_t>
    void insertionSort(container_t & container) {
        auto it = std::next(container.begin());

        for (it = std::next(container.begin());
             it != container.end();
             ++it) {
            auto inner_it = it;
            while (*inner_it < *std::prev(inner_it)
                   && inner_it != container.begin()) {
                std::iter_swap(inner_it, std::prev(inner_it));
                inner_it--;
            }
        }
    }
}
