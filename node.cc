#include "node.h"

Node::Node() {
    val_ = 0;
    next_ = nullptr;
};

Node::~Node(){};

void Node::setVal(int val) {
    val_ = val;
};

void Node::setNext(Node* next) {
    next_ = next;
};

int Node::getVal() {
    return val_;
};

Node* Node::getNext() {
    return next_;
};