#pragma once
#define NODE_TYPE int

class Node{

    NODE_TYPE data;
    Node * nextNode;

    public:
    Node(NODE_TYPE data);

    Node* getNext();

    void setNode(Node * node);

    NODE_TYPE getData();

};