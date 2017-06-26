#pragma once

#include <algorithm>

namespace sorting {
    template <typename container_t>
    void bubbleSort(container_t & container) {
        bool changed{ false };
        auto end_it = container.end();

        do {
            changed = false;

            auto it1 = container.begin();
            auto it2 = std::next(it1);

            while (it2 != end_it) {
                if (*it1 > *it2) {
                    std::iter_swap(it1, it2);
                    changed = true;
                }
                it1++;
                it2++;
            }
            end_it = it1;
        } while (changed); 
    }
}
