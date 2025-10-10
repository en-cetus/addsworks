#ifndef PREFIX_MATCHER_H
#define PREFIX_MATCHER_H

#include <string>

class RouterNode {
public:
    int bestRouterHere;
    RouterNode* zero;
    RouterNode* one;

    RouterNode();
};

class PrefixMatcher {
public:
    PrefixMatcher();
    ~PrefixMatcher();

    void insert(const std::string& address, int routerNumber);
    int selectRouter(const std::string& networkAddress) const;

private:
    RouterNode* root;
    void freeAll();
};

#endif // PREFIX_MATCHER_H