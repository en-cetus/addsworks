#include "LinkedList.h"
#include <iostream>
#include <limits>

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::LinkedList(int* array, int len) : head(nullptr) {
    if (!array || len <= 0) return;

    head = new Node(array[0], nullptr);
    Node* cur = head;
    for (int i = 1; i < len; ++i) {
        cur->setLink(new Node(array[i], nullptr));
        cur = cur->getLink();
    }
}

LinkedList::~LinkedList() {
    Node* cur = head;
    while (cur) {
        Node* nxt = cur->getLink();
        delete cur;
        cur = nxt;
    }
    head = nullptr;
}

void LinkedList::insertPosition(int pos, int newNum) {

    if (pos <= 1 || head == nullptr) {
        head = new Node(newNum, head);
        return;
    }

    Node* cur = head;
    int idx = 1;
    while (cur->getLink() != nullptr && idx < pos - 1) {
        cur = cur->getLink();
        ++idx;
    }
    // insert after cur
    Node* node = new Node(newNum, cur->getLink());
    cur->setLink(node);
}

bool LinkedList::deletePosition(int pos) {
    if (pos < 1 || head == nullptr) return false;

    if (pos == 1) {
        Node* tmp = head;
        head = head->getLink();
        delete tmp;
        return true;
    }
    Node* cur = head;
    int idx = 1;
    while (cur && cur->getLink() && idx < pos - 1) {
        cur = cur->getLink();
        ++idx;
    }
    if (!cur || !cur->getLink()) return false;

    Node* target = cur->getLink();
    cur->setLink(target->getLink());
    delete target;
    return true;
}

int LinkedList::get(int pos) {
    if (pos < 1) return std::numeric_limits<int>::max();
    Node* cur = head;
    int idx = 1;
    while (cur && idx < pos) {
        cur = cur->getLink();
        ++idx;
    }
    if (!cur) return std::numeric_limits<int>::max();
    return cur->getData();
}

int LinkedList::search(int target) {
    Node* cur = head;
    int idx = 1;
    while (cur) {
        if (cur->getData() == target) return idx;
        cur = cur->getLink();
        ++idx;
    }
    return -1;
}

void LinkedList::printList() {
    if (!head) {

        return;
    }
    std::cout << "[";
    Node* cur = head;
    bool first = true;
    while (cur) {
        if (!first) std::cout << " ";
        std::cout << cur->getData();
        first = false;
        cur = cur->getLink();
    }
    std::cout << "]";
}