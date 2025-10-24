#include "DocumentManager.h"
#include <utility>   // for std::move

void DocumentManager::addDocument(const std::string& name, int id, int license_limit) {
    Doc d;
    d.name = name;
    d.id = id;
    d.license_limit = license_limit;
    nameToId[name] = id;
    docsById[id] = d;
}

void DocumentManager::addPatron(int patronID) {
    patrons.insert(patronID);
}

int DocumentManager::search(const std::string& name) {
    auto it = nameToId.find(name);
    return (it == nameToId.end()) ? 0 : it->second;
}

bool DocumentManager::borrowDocument(int docid, int patronID) {
    auto dit = docsById.find(docid);
    if (dit == docsById.end()) return false;
    if (!patrons.count(patronID)) return false;

    Doc& doc = dit->second;

    // already borrowed the same book.
    if (doc.borrowers.count(patronID)) return true;

    // remained licenses.
    if ((int)doc.borrowers.size() < doc.license_limit) {
        doc.borrowers.insert(patronID);
        return true;
    }

    return false;
}

void DocumentManager::returnDocument(int docid, int patronID) {
    auto dit = docsById.find(docid);
    if (dit == docsById.end()) return;

    Doc& doc = dit->second;

    auto it = doc.borrowers.find(patronID);
    if (it == doc.borrowers.end()) return; // Never borrowed

    doc.borrowers.erase(it);

}