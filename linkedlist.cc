#include "node.h"
// For now, this just creates a linked list

int main() {
    Node* head = new Node;
    head->setVal(1);
    Node* n = new Node;
    n->setVal(2);
    head->setNext(n);

    // Free everything
    while (head) {
        Node* free = head;
        head = head->getNext();
        delete free;
    }
}