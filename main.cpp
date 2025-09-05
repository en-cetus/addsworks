// main.cpp
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "BubbleSort.h"
#include "QuickSort.h"
#include "RecursiveBinarySearch.h"

using namespace std;

int main() {
    // 1) Read a line of integers
    string line;
    if (!getline(cin, line)) {
        // No input: by spec we can just print false and exit
        cout << "false" << endl;
        return 0;
    }

    vector<int> nums;
    {
        istringstream iss(line);
        int x;
        while (iss >> x) {
            nums.push_back(x);
        }
    }

    // 2) Sort using QuickSort (as required by the practical)
    QuickSort sorter;
    vector<int> sorted = sorter.sort(nums);

    // 3) Search for value 1 using RecursiveBinarySearch
    RecursiveBinarySearch bs;
    bool found = bs.search(sorted, 1);

    // 4) Output: true/false + sorted sequence
    cout << (found ? "true" : "false");
    if (!sorted.empty()) {
        cout << " ";
        for (size_t i = 0; i < sorted.size(); ++i) {
            cout << sorted[i];
            if (i + 1 < sorted.size()) cout << " ";
        }
    }
    cout << endl;

    return 0;
}
