class Node {
    int val_;
    Node* next_;

    public:
        Node();

        ~Node();

        void setVal(int val);

        void setNext(Node* next);

        int getVal();

        Node* getNext();
};