#define NODE_TYPE int
#include "../headers/node.h"

Node::Node(NODE_TYPE data){
    this->data = data;
    nextNode = nullptr;
}

void Node::setNode(Node * node){
    nextNode = node;
}

Node* Node::getNext(){
    return nextNode;
}

NODE_TYPE Node::getData(){
    return data;
}
