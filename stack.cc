#include "node.h"

#include <iostream>
#include <unistd.h>

class Stack {
    Node* head_;
    int size_;

    public:
        Stack() {
            head_ = nullptr;
            size_ = 0;
        }

        ~Stack() {
            while (head_) {
                Node* free = head_;
                head_ = head_->getNext();
                delete free;
            }
        }

        void push(Node* n) {
            n->setNext(head_);
            head_ = n;
            size_++;
        }

        Node* pop() {
            if (!head_) {
                return nullptr;
            }
            Node* popped = head_;
            head_ = head_->getNext();
            size_--;
            return popped;
        }

        bool isEmpty() {
            return (size_ == 0);
        }
};

// The purpose of `foo()` is to verify that ASLR has been disabled.
int foo(int x) {
    x *= x;
    return x;
}

int main() {
    pid_t pid = getpid();
    printf("My PID is %d!\n", pid);

    // Create using new/delete
    // TODO: also create local vars on the stack
    Node* n = new Node;
    int nodeVal = foo(4);
    n->setVal(nodeVal);
    // Create a stack to see if the addr for `new` is different
    Stack* stack = new Stack;
    stack->push(n);
    delete stack; // will also free `n`
}