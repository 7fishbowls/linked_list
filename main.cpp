#include <iostream>
using namespace std;

class Node{
    int data;
    Node * nextNode;

    Node(int data){
        this->data = data;
        nextNode = nullptr;
    }

    void setNode(Node * node){
        nextNode = node;
    }

    int getData(){
        return data;
    }

};

class List{
    Node * head = nullptr;
    Node * tail = nullptr;
};

int main(){
    return 0;
}