#include "Autocomplete.h"
#include <vector>

//Initialization
Node::Node() : isEnd(false) {
    for (int i = 0; i < 26; ++i){
        next[i] = nullptr;
    } 
}

Autocomplete::Autocomplete() {
    root = new Node();
}

Autocomplete::~Autocomplete() {
    freeAll();
}

//Release all nodes
void Autocomplete::freeAll() {
    if (!root) return;
    std::vector<Node*> stack{root};
    while (!stack.empty()) {
        Node* cur = stack.back(); stack.pop_back();
        for (int i = 0; i < 26; ++i){
            if (cur->next[i]){
                stack.push_back(cur->next[i]);
            }
        }
        delete cur;
    }
    root = nullptr;
}

// Insert a word into the Trie tree
void Autocomplete::insert(const std::string& word) {
    Node* cur = root;
    cur->words.push_back(word);
    // Convert letters to indices
    for (char c : word) {
        int k = c - 'a';
        if (k < 0 || k >= 26){
            return;
        }
        if (!cur->next[k]){
            cur->next[k] = new Node();
        }
        cur = cur->next[k];
        cur->words.push_back(word);
    }
    cur->isEnd = true;
}

// Return a list of suggested words based on the prefix
std::vector<std::string> Autocomplete::getSuggestions(const std::string& prefix) const {
    const Node* cur = root;
    // Traverse the Trie by prefix
    for (char c : prefix) {
        int k = c - 'a';
        if (k < 0 || k >= 26 || !cur->next[k]) {
            return;
        }
        cur = cur->next[k];
    }
    return cur->words;
}