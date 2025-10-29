#include "sort_algorithms.h"
#include <vector>
#include <algorithm>
#include <iterator>

template<typename T>
void StrandSort<T>::sort(std::vector<T>& data) {
    if (data.empty()) return;

    std::vector<T> result;
    result.reserve(data.size());

    while (!data.empty()) {
        std::vector<T> strand;
        strand.reserve(data.size());
        strand.push_back(data.front());
        data.erase(data.begin());

        for (auto it = data.begin(); it != data.end();) {
            if (*it >= strand.back()) {
                strand.push_back(*it);
                it = data.erase(it);
            }
            else {
                ++it;
            }
        }

        std::vector<T> merged;
        merged.reserve(result.size() + strand.size());
        std::merge(result.begin(), result.end(),
            strand.begin(), strand.end(),
            std::back_inserter(merged));

        result.swap(merged);
    }

    data.swap(result);
}

template class StrandSort<int>;
template class StrandSort<std::string>;
