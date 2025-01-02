#pragma once
#include "./node.h"

class List{

    Node * head = nullptr;
    Node * tail = nullptr;

    public:

    void addNode(NODE_TYPE data);
    void pushNode(NODE_TYPE data);
    void printNodes();
    void getHead();
    void getTail();
    void searchNode(NODE_TYPE value);
    void deleteNode(int value);
    void deleteHead();
    void deleteTail();

    ~List();


};