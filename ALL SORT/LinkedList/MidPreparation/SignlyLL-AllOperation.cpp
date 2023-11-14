#include <iostream>
#include <cassert>
using namespace std;

struct Node {
    int data;
    Node *next = nullptr;
    // Constructor
    Node(int val) {
        data = val;
    }
};
typedef struct Node Node;

Node* insertTail(Node* head, int val) {
    if(head == nullptr) return new Node(val);
    head->next = insertTail(head->next, val);
    return head;
}

Node* insertHead(Node* head, int val) {
    Node *node = new Node(val);
    if(head == nullptr) return node;
    else {
        node->next = head;
        return node;
    }
}

Node* insertAt(Node* head, int index, int val) {
    int count = 0;
    Node *prev = nullptr;
    Node *curr = head;
    while(curr != nullptr && count < index)  {
        prev = curr;
        curr = curr->next;
        count++;
    }
    if(count < index) return head;  // out of range
    
    Node *node = new Node(val);
    if(prev == nullptr) {           // add to head
        node->next = head;
        return node;
    }
    else if(curr == nullptr ) {     // add to tail
        prev->next = node;
    }
    else {                          // add in the between
        prev->next = node;
        node->next = curr;
    }
    return head;
}

Node* removeHead(Node *head) {
    if(head == nullptr) return head;
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* removeTail(Node *head) {
    if(head == nullptr) return head;
    Node *curr = head;
    while(curr->next != nullptr) curr = curr->next;
    delete curr->next;
    curr->next = nullptr;
    return head;
}

Node* removeAt(Node *head, int index) {
    assert(index >= 0);     // used for debugging, interrupts the program when the assertion is false
    if(head == nullptr) return head;
    if(index == 0) {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    int count = 0;
    Node *prev = nullptr;
    Node *curr = head;
    while(curr != nullptr && count < index) {
        prev = curr;
        curr = curr->next;
        count++;
    }
    
    if(count < index) {     // out of range
        return head;
    }
    
    if(curr != nullptr) {
        prev->next = curr->next;
        delete curr;
    }
    return head;
}

int length(Node *head) {
    int count = 0;
    Node *curr = head;
    while(curr != nullptr) {
        curr = curr->next;
        count++;
    }
    return count;
}

void printList(Node* node) {
    cout << "Printing Linked List:" << endl;
    while(node != nullptr) {
        cout << node->data << ' ';
        node = node->next;
    }
    cout << endl;
}

int main() {
    Node *head = nullptr;
    
    head = insertTail(head, 100);
    head = insertTail(head, 200);
    head = insertTail(head, 300);
    head = insertAt(head, 0, 1000);
    head = insertAt(head, 4, 2000);
    head = insertAt(head, 2, 3000);

    
    printList(head);
    cout << "Length: " << length(head) << endl;
    return 0;
}