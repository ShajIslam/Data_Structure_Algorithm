#include <iostream>
using namespace std;


struct node{
    int data;
    node *next;
};

void printList(struct node* node) {
    cout << "Printing Linked List:" << endl;
    while(node != nullptr) {
        cout << node->data << ' ';
        node = node->next;
    }
    cout << endl;
}


int main(){
    node *n;
    node *temp;
    node *head;

    //create a new node
    n = new node;
    n->data = 1;
    temp = n;
    head = n;


    //creating another node
    n = new node;
    n->data = 2;
    temp->next = n;
    temp= temp->next;
    n->next = nullptr;

    printList(head);


}