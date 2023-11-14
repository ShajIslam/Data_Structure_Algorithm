#include <iostream>
using namespace std;


struct node{
    int data;
    node* next;
    node* prev;
};

void printList(struct node* head){
    node* temp = head;

    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout <<endl;
}


int main(){
     node* n;
     node* head;
     node* tail;



     n = new node;
     n->data = 1;
     n->prev = nullptr;
     head =n;
     tail =n;

     //creating another node
     n = new node;
     n->data = 2;
     n->prev = tail;
     tail = n;

     n = new node;
     n->data = 3;
     n->prev = tail;
     tail = n;

     n = new node;
     n->data = 4;
     n->prev = tail;
     tail = n;
     tail->next = nullptr;


     printList(head);

     return 0;
}