#include "BubbleSort.h"
#include <iostream>
#include <vector>
using namespace std;

vector<int> BubbleSort::sort(vector<int> list) {
    int n = list.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // 如果前面的大于后面，就交换
            if (list[j] > list[j + 1]) {
                swap(list[j], list[j + 1]);
            }
        }
    }
    return list;
}
