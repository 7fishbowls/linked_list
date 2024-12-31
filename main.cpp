#include <iostream>
using namespace std;

class Node{
    int data;
    Node * nextNode;

    public:
    Node(int data){
        this->data = data;
        nextNode = nullptr;
    }

    void setNode(Node * node){
        nextNode = node;
    }

    Node* getNext(){
        return nextNode;
    }

    int getData(){
        return data;
    }

};

class List{

    Node * head = nullptr;
    Node * tail = nullptr;

    public:

        void addNode(int data){

            Node * newNode = new Node(data);

            if(head == nullptr){
                head = tail = newNode;
            }
            else {
                newNode->setNode(head);
                head = newNode;
            }
        }

        void pushNode(int data){
            Node * newNode = new Node(data);

            if(head == nullptr){
                head = tail = newNode;
                return;
            }

            tail->setNode(newNode);
            tail = newNode;

        }

        void printNodes(){
            Node * temp = head;
            while(temp != nullptr){

                cout << temp->getData() << " -> ";
                temp = temp->getNext();

            }
        }

        void getHead(){
            cout << "\nHead: " << head->getData();
        }

        void getTail(){
            cout << "\nTail: " << tail->getData();
        }

};

int main(){
    List list;

    for(int i = 0; i < 10000; i++){
        list.pushNode(i);
    }

    list.printNodes();
    list.getHead();
    list.getTail();
    return 0;
}