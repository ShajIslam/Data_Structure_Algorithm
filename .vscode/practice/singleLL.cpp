#include <iostream>
using namespace std;


struct node{
    int data;
    node* next;
};

//insert at first
node* insertAtFirst(struct node* head, int value){
    node* n = new node;
    n->data = value;
    if(head ==nullptr) {
        return n;
    }
    else{
        n->next = head;
        head = n;
        return n;
    }
   
}

//insert at last

void insertAtLast(struct node* head, int value){
    node* n = new node;
    n->data = value;

    node* temp = head;
    n->next = nullptr;

    if(head == nullptr){
        head = n;
        return;
    }
    
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = n; 
}


//delete from first

node* deleteFromFirst(struct node* head){

    if(head == nullptr){
        return nullptr;
    }

    node* temp = head;
    head = head->next;

    delete temp;
    return head;
}

//delete from last

node* deleteFromLast (struct node* head){
    if(head == nullptr){
        return nullptr;
    }

    if(head->next ==nullptr){
        delete head;
        return nullptr;
    }

    node* temp = head;

    while(temp->next->next !=nullptr){
        temp = temp->next;
    }

    temp->next = nullptr;

}

node* removeLast (struct node* head){
    if(head == nullptr){
        return nullptr;
    }
    if(head->next == nullptr){
        delete head;
        return nullptr;
    }
    node* second_last = head;

    while(second_last->next->next != nullptr){
        second_last = second_last->next;
    } 
    second_last->next = nullptr;

}



void printList(struct node* node){
    while(node != nullptr){
        cout<<node->data<<" ";
        node = node->next;
    }
}

int main(){
    node* n;
    node* temp;
    node* head;


    //creating a new node
    n = new node;
    n->data = 4;
    temp =n;
    head = n;

    //add another node

    n = new node;
    n->data = 5;
    temp->next = n;
    temp = temp->next;
    n->next = nullptr ;

   
    head = insertAtFirst(head, 10);
    head = insertAtFirst(head, 0);
    insertAtLast(head, 20);
    head = deleteFromFirst(head);
    head = insertAtFirst(head, 70);
    head = insertAtFirst(head, 50);
    head = deleteFromFirst(head);
    head = removeLast(head);
    head = insertAtFirst(head, 50);
    
    printList(head);
    

}