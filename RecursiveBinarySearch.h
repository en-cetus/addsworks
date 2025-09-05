#ifndef RECURSIVEBINARYSEARCH_H
#define RECURSIVEBINARYSEARCH_H

#include <vector>

class RecursiveBinarySearch {
public:
    // Public interface
    bool search(const std::vector<int>& data, int target);

private:
    // Helper function for recursion
    bool searchHelper(const std::vector<int>& data, int target, int left, int right);
};

#endif
