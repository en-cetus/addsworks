#include "RecursiveBinarySearch.h"
using namespace std;

// Public interface
bool RecursiveBinarySearch::search(const vector<int>& data, int target) {
    return searchHelper(data, target, 0, (int)data.size() - 1);
}

// Recursive helper
bool RecursiveBinarySearch::searchHelper(const vector<int>& data, int target, int left, int right) {
    // Base case: not found
    if (left > right){
        return false;
    }
    int mid = left + (right - left)/2;
    if(data[mid] == target){
        return true;
    }
    if(target < data[mid]){
        return searchHelper(data, target, left, mid - 1);
    } else{
        return searchHelper(data, target, mid + 1, right);
    }
}
