#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include <string>
#include <vector>

class Node {
public:
    bool isEnd;
    Node* next[26];
    std::vector<std::string> words;

    Node();
};

class Autocomplete {
public:
    Autocomplete();
    ~Autocomplete();

    void insert(const std::string& word);
    std::vector<std::string> getSuggestions(const std::string& prefix) const;

private:
    Node* root;
    void freeAll();
};

#endif // AUTOCOMPLETE_H