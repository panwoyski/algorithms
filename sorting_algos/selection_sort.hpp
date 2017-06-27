#pragma once
#include <algorithm>

namespace sorting {
    template <typename container_t>
    void selectionSort(container_t & container) {
        auto beginIt = container.begin();
        auto endIt = container.end();

        while (beginIt != endIt) {
            auto foundIt = std::min_element(beginIt, endIt);
            if (foundIt != endIt && *foundIt < *beginIt)
                std::iter_swap(foundIt, beginIt);
            beginIt++;
        }
    }
}
