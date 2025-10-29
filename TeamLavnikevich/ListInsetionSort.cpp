#include "sort_algorithms.h"

template<typename T>
void ListInsertionSort<T>::sort(std::vector<T>& data) {
    for (size_t i = 1; i < data.size(); i++) {
        T key = data[i];
        int j = static_cast<int>(i) - 1;
        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
    }
}

template class ListInsertionSort<int>;
template class ListInsertionSort<std::string>;
