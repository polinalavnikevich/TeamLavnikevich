#ifndef SORT_ALGORITHMS_H
#define SORT_ALGORITHMS_H

#include <vector>
#include <string>

template<typename T>
class SortAlgorithm {
public:
    virtual void sort(std::vector<T>& data) = 0;
    virtual ~SortAlgorithm() = default;
};

// Алгоритмы "последовательного" типа
template<typename T> class NaturalMergeSort : public SortAlgorithm<T> {
public: void sort(std::vector<T>& data) override;
};

template<typename T> class ListInsertionSort : public SortAlgorithm<T> {
public: void sort(std::vector<T>& data) override;
};

template<typename T> class StrandSort : public SortAlgorithm<T> {
public: void sort(std::vector<T>& data) override;
};

template<typename T> class PolyphaseMergeSort : public SortAlgorithm<T> {
public: void sort(std::vector<T>& data) override;
};

#endif

