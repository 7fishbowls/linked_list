#include "./headers/node.h"
#include "./headers/list.h"

int main(){
    List list;

    for(int i = 1; i <= 2000; i++){
        list.pushNode(i);
    }

    list.printNodes();
    list.getHead();
    list.getTail();

    return 0;
}