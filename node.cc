class Node {
    int val_;
    Node* next_;

    public:
        Node() {
            val_ = 0;
            next_ = nullptr;
        }

        ~Node(){}

        void setVal(int val) {
            val_ = val;
        }

        void setNext(Node* next) {
            next_ = next;
        }

        int getVal() {
            return val_;
        }

        Node* getNext() {
            return next_;
        }
};

int main() {
    // Create using new/delete, but also create things on the stack
    Node* n = new Node;
    n->setVal(5);
    delete n;
}