#ifndef DOCUMENT_MANAGER_H
#define DOCUMENT_MANAGER_H

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>

class DocumentManager {
private:
    struct Doc {
        std::string name;
        int id = 0;
        int license_limit = 0;
        std::unordered_set<int> borrowers;   // Current Borrower
    };

    // Primary Index
    std::unordered_map<int, Doc> docsById;      // id -> document
    std::unordered_map<std::string, int> nameToId; // name -> id
    std::unordered_set<int> patrons;            // Registered readers

public:
    
    void addDocument(const std::string& name, int id, int license_limit);

    void addPatron(int patronID);

    int search(const std::string& name);

    bool borrowDocument(int docid, int patronID);

    void returnDocument(int docid, int patronID);
};

#endif