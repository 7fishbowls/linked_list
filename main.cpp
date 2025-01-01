#define NODE_TYPE int
#include <iostream>
using namespace std;

class Node{
    NODE_TYPE data;
    Node * nextNode;

    public:
    Node(NODE_TYPE data){
        this->data = data;
        nextNode = nullptr;
    }

    void setNode(Node * node){
        nextNode = node;
    }

    Node* getNext(){
        return nextNode;
    }

    NODE_TYPE getData(){
        return data;
    }

};

class List{

    Node * head = nullptr;
    Node * tail = nullptr;

    public:

        void addNode(NODE_TYPE data){

            Node * newNode = new Node(data);

            if(head == nullptr){
                head = tail = newNode;
            }
            else {
                newNode->setNode(head);
                head = newNode;
            }
        }

        void pushNode(NODE_TYPE data){
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
                cout << temp->getData();
                if(temp->getNext() != nullptr) {
                    cout << " -> ";
                }
                temp = temp->getNext();

            }
        }

        void getHead(){
            cout << "\nHead: " << head->getData();
        }

        void getTail(){
            cout << "\nTail: " << tail->getData() << endl;
        }

        void searchNode(NODE_TYPE value){
            Node * temp = head;
            int tries = 0;
            bool found = false;

            while(temp != nullptr){
                if(temp->getData() == value) {found = true; break;};
                temp = temp->getNext();
                tries++;
            }

            if(found){
                cout << endl;
                cout << "\nFound: " << value << " At " << tries << endl;
            } else {
                cout << endl;
                cout << "\nCan't find " << value << endl;
            }
        }

        void deleteNode(int value){
            Node * temp = head;
            bool found = false;
            while(temp != nullptr){
                if(temp->getData() == value) {
                    found = true;
                    delete temp;
                    cout << value << " has been deleted.";
                    break;
                }
                temp = temp -> getNext();
            }

            if(!found){
                cout << "Couldn't find " << value << endl;
            }
        }

        void deleteHead(){

            Node * temp = head;
            head = temp->getNext();
            delete temp;
            cout << "Head deleted." << endl;

        }

        void deleteTail(){

            Node * temp = head;
            while(temp->getNext()->getNext() != nullptr){
                temp = temp->getNext();
            }
            tail = temp;
            tail->setNode(nullptr);
            delete temp->getNext();

        }

        ~List(){

            Node * temp = head;
            while(temp != nullptr){
                Node * node = temp->getNext();
                // cout << temp->getData() << " been deleted" << endl;
                delete temp;
                temp = node;
            }

        }

};

int main(){
    List list;

    for(int i = 1; i <= 30; i++){
        list.pushNode(i);
    }

    list.printNodes();
    list.getHead();
    list.getTail();
    return 0;
}