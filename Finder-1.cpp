#include "Finder-1-1.h"
#include <vector>
#include <string>
using namespace std;

vector<int> Finder::findSubstrings(const string s1, const string s2) {
    vector<int> res;
    res.reserve(s2.size());

    for (size_t len = 1; len <= s2.size(); ++len) {
        // Search for the first 'len' characters of s2 inside s1
        size_t pos = s1.find(s2.c_str(), 0, len);

        // If found, store the starting index; otherwise store -1
        res.push_back(pos == string::npos ? -1 : static_cast<int>(pos));
    }
    return res;
}