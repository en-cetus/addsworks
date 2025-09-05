#include "QuickSort.h"
#include <vector>
#include <algorithm>
using namespace std;

// Public interface
vector<int> QuickSort::sort(vector<int> list) {
    if (!list.empty()) {
        quickSort(list, 0, (int)list.size() - 1);
    }
    return list;
}

// QuickSort recursive helper
void QuickSort::quickSort(vector<int>& list, int left, int right) {
    if (left < right) {
        int pivotIndex = partition(list, left, right);
        quickSort(list, left, pivotIndex - 1);
        quickSort(list, pivotIndex + 1, right);
    }
}

// Partition with pivot selection: third element if possible
int QuickSort::partition(vector<int>& list, int left, int right) {
    int pivotIndex;
    if (right - left + 1 >= 3) {
        pivotIndex = left + 2; // third element
    } else {
        pivotIndex = right;    // fallback: last element
    }

    int pivot = list[pivotIndex];
    swap(list[pivotIndex], list[right]); // move pivot to end
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (list[j] <= pivot) {
            i++;
            swap(list[i], list[j]);
        }
    }
    swap(list[i + 1], list[right]);
    return i + 1;
}
