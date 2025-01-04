#pragma once
#define NODE_TYPE int
#include "./node.h"

class List{

    Node * head = nullptr;
    Node * tail = nullptr;

    public:

    void printNodes() const;
    void getHead() const;
    void getTail() const;
    void deleteHead();
    void deleteTail();
    void searchNode(NODE_TYPE value) const;
    void addNode(NODE_TYPE data);
    void deleteNode(int value);
    void pushNode(NODE_TYPE data);

    ~List();


};