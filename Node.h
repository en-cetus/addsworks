#ifndef NODE
#define NODE

class Node{
    private:
        int data;
        Node* link;
    public:
        Node(int val = 0, Node* next = nullptr);
        int getData();
        void setData(int n);

        Node* getLink();
        void setLink(Node* p);
};

#endif