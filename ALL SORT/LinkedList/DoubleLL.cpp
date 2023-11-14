#include <iostream>
using namespace std;


struct node{
    int data;
    node* previous;
    node* next;
};

//insert at first in DLL
node* insertAtFirst (struct node* head, int value){

    node* n = new node;
    n->data = value;
    n->previous = nullptr;

    if(head ==nullptr){
        return n;
    }

    n->next = head;
    head->previous = n;
    head = n;

    return n;

}

//insert at last 

node* insertAtLast (struct node* head, int value){
    node* n = new node;
    n->data = value;
    n->previous = nullptr;
    n->next =nullptr;

    if(head == nullptr){
        return n;
    }
    node* temp = head;

    while(temp->next !=nullptr){
        temp = temp->next;
    }
    temp->next = n;
    n->previous = temp;
}


void printList(struct node* head){

    node* temp = head;

    while(temp !=nullptr){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
   cout<<endl;

}

int main(){
    node* n;
    node* head;
    node* tail;

     n = new node;
     n->data = 1;
     n->previous = nullptr;
     head = n;
     tail = n;

     //creating another node
     n = new node;
     n->data = 2;
     tail->next = n;
     n->previous = tail;
     tail = n;

    head = insertAtFirst(head, 87);
    head = insertAtLast(head, 0);
     printList(head);

}