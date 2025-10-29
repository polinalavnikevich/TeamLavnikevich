#include "sort_algorithms.h"
#include <vector>
#include <algorithm>

template<typename T>
void NaturalMergeSort<T>::sort(std::vector<T>& data) {
    if (data.size() <= 1) return;

    std::vector<T> temp(data.size());
    bool sorted = false;

    while (!sorted) {
        sorted = true;
        size_t i = 0;
        while (i < data.size()) {
            size_t left = i;
            while (i + 1 < data.size() && data[i] <= data[i + 1]) i++;
            size_t mid = i++;
            if (i >= data.size()) break;
            while (i + 1 < data.size() && data[i] <= data[i + 1]) i++;
            size_t right = ++i;

            std::merge(data.begin() + left, data.begin() + mid + 1,
                data.begin() + mid + 1, data.begin() + right,
                temp.begin() + left);
            for (size_t j = left; j < right; j++)
                data[j] = temp[j];
            sorted = false;
        }
    }
}

template class NaturalMergeSort<int>;
template class NaturalMergeSort<std::string>;
