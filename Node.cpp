#include "Node.h"

Node::Node(int val, Node* next) : data(val), link(next) {}

int Node::getData() { return data; }
void Node::setData(int v) { data = v; }

Node* Node::getLink() { return link; }
void Node::setLink(Node* p) { link = p; }