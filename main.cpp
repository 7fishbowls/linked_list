#include "./headers/node.h"
#include "./headers/list.h"
#include <iostream>
#include <fstream>

using namespace std;

enum Actions{
    RETRIVE,
    ADD,
    DELETE
};

void fectchData(List &list, fstream& file_){

    string line;
    int value;
    while(file_ >> value){
        list.pushNode(value);
    }
    list.printNodes();

}

void addNode(List &list, fstream& file){
        int value = 0;
        // cout << "Enter the value: ";
        // cin >> value;

        // if(value == 100) return;
        while(value < 1000000){
            list.pushNode(value);
            file << value << endl;
            value++;
        }
        cout << "Nodes added!" << endl;

}

int main(){

    List list;
    int action = 0;

    fstream file("C:\\Users\\Baki Hanma\\Documents\\lazy_cat\\data.txt", ios::in | ios::app);
    if(!file.is_open()) perror("Error opening file");

    cout << "1. Fetch Data\n" <<
            "2. Add Data\n" <<
            "3. Delete Entire Database: ";

    cin >> action;

    switch (action) {
    case 1:
        fectchData(list, file);
        break;
    case 2:
        addNode(list, file);
        break;
    case 3:
        cout << "Cannot delete, permission denied" << endl;
        return 1;
    default:
        break;
    }

    file.close();

    return 0;
}