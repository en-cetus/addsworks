#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "Sort.h"
#include <vector>

class QuickSort : public Sort {
public:
    std::vector<int> sort(std::vector<int> list) override;

private:
    void quickSort(std::vector<int>& list, int left, int right);
    int partition(std::vector<int>& list, int left, int right);
};

#endif
