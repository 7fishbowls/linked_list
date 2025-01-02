#include "../headers/list.h"
#include <iostream>

using namespace std;

void List::addNode(NODE_TYPE data){

    Node * newNode = new Node(data);

    if(head == nullptr){
        head = tail = newNode;
    } else {
        newNode->setNode(head);
        head = newNode;
    }
}

void List::pushNode(NODE_TYPE data){
    Node * newNode = new Node(data);

    if(head == nullptr){
        head = tail = newNode;
        return;
    }

    tail->setNode(newNode);
    tail = newNode;

}

void List::printNodes(){
    if(head != nullptr){
        Node * temp = head;
        while(temp != nullptr){
            cout << temp->getData();
            if(temp->getNext() != nullptr) {
                cout << " -> ";
            }
            temp = temp->getNext();
        }
    } else {
        cout << "-> No nodes found to print." << endl;
    }
}

void List::getHead(){
    if(head != nullptr) cout << "\n-> Head: " << head->getData();
}

void List::getTail(){
    if(head != nullptr) cout << "\n-> Tail: " << tail->getData();
}

void List::searchNode(NODE_TYPE value){
    Node * temp = head;
    int tries = 0;
    bool found = false;

    while(temp != nullptr){
        if(temp->getData() == value) { found = true; break; };
            temp = temp->getNext();
            tries++;
        }

    if(found){
        cout << endl;
        cout << "\n-> Found: " << value << " At " << tries << endl;
    } else {
        cout << endl;
        cout << "\n-> Can't find " << value << endl;
    }
}

void List::deleteNode(int value){

    if(!head){
        cout << "No node found to delete";
        return;
    }

    if(head->getData() == value){
        deleteHead();
        return;
    }

    if(tail->getData() == value){
        deleteTail();
        return;
    }

    Node * temp = head;
    while(temp->getNext() != nullptr && temp->getNext()->getData() != value){
        temp = temp->getNext();
    }

    if(temp->getNext() == nullptr){
        cout << "-> No node found to delete." << endl;
        return;
    }

    Node * nodeDelete = temp->getNext();
    temp->setNode(nodeDelete->getNext());
    delete nodeDelete;

}

void List::deleteHead(){

    if(head != nullptr){

        Node * temp = head;
        head = temp->getNext();
        delete temp;

    }

}
void List::deleteTail(){

    if(head != nullptr){

        Node * temp = head;
        while(temp->getNext()->getNext() != nullptr){
            temp = temp->getNext();
        }
        tail = temp;
        tail->setNode(nullptr);
        delete temp->getNext();
    } else {
        cout << "-> No nodes found." << endl;
    }

}

List::~List(){

    Node * temp = head;
    while(temp != nullptr){
        Node * node = temp->getNext();
        // cout << temp->getData() << " been deleted" << endl;
        delete temp;
        temp = node;
    }

}