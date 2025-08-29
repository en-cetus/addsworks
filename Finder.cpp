#include "Finder.h"
#include <vector>
#include <string>
using namespace std;

// Build the prefix function (pi array) for KMP algorithm
static vector<int> buildPi(const string& p) {
    int m = (int)p.size();
    vector<int> pi(m, 0);
    for (int i = 1, j = 0; i < m; ++i) {
        while (j > 0 && p[i] != p[j]) j = pi[j - 1];
        if (p[i] == p[j]) ++j;
        pi[i] = j;
    }
    return pi;
}

vector<int> Finder::findSubstrings(const string s1, const string s2) {
    int n = (int)s1.size(), m = (int)s2.size();
    vector<int> ans(m, -1);
    if (m == 0) return ans;

    // Preprocess pattern s2
    vector<int> pi = buildPi(s2);
    int L = 0; // Current matched prefix length

    for (int j = 0; j < n; ++j) {
        // Backtrack until characters match
        while (L > 0 && s1[j] != s2[L]) L = pi[L - 1];
        if (s1[j] == s2[L]) ++L;

        // First time reaching prefix length L → store the index
        if (L > 0 && ans[L - 1] == -1) {
            ans[L - 1] = j - (L - 1);
        }

        // If we matched the full pattern, roll back according to pi
        if (L == m) L = pi[L - 1];
    }
    return ans;
}
