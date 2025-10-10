#include "PrefixMatcher.h"
#include <vector>

RouterNode::RouterNode() : bestRouterHere(-1), zero(nullptr), one(nullptr) {}

//Initialization
PrefixMatcher::PrefixMatcher() {
    root = new RouterNode();
}

//Release all dynamically allocated nodes
PrefixMatcher::~PrefixMatcher() {
    freeAll();
}

void PrefixMatcher::freeAll() {
    if (!root) return;
    //Store nodes in a stack
    std::vector<RouterNode*> stack{root};
    while (!stack.empty()) {
        RouterNode* cur = stack.back(); stack.pop_back();

        //// If a child node exists, push it onto the stack
        if (cur->zero){
            stack.push_back(cur->zero);
        }
        if (cur->one){
            stack.push_back(cur->one);
        }
        delete cur;
    }
    root = nullptr;
}

//Insert new route prefix
void PrefixMatcher::insert(const std::string& address, int routerNumber) {
    RouterNode* cur = root;
    for (char c : address) {
        if (c == '0') {
            if (!cur->zero){
                cur->zero = new RouterNode();
            };
            cur = cur->zero;
        } else if (c == '1') {
            if (!cur->one){
                cur->one = new RouterNode();
            };
            cur = cur->one;
        } else {
            return; // ignore invalid char
        }
        cur->bestRouterHere = routerNumber;
    }
}

//Find the best-matching route
int PrefixMatcher::selectRouter(const std::string& networkAddress) const {
    const RouterNode* cur = root;
    int best = -1;
    for (char c : networkAddress) {
        if (c == '0') {
            if (!cur->zero){
                break;
            }
            cur = cur->zero;
        } else if (c == '1') {
            if (!cur->one){
                break;
            }
            cur = cur->one;
        } else {
            break;
        }
        if (cur->bestRouterHere != -1){
            best = cur->bestRouterHere;
        }
    }
    return best;
}