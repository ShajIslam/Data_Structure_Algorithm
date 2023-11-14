#include <iostream>
#define MAX 10

using namespace std;

int Q[MAX], front = -1, rear = -1;

void insert(int value) {
    if (rear == MAX - 1) {
        cout << "OVERFLOW" << endl;
        return;
    }
    if (front == -1 && rear == -1) {
        front = rear = 0;
        Q[rear] = value;
    } else {
        rear++;
        Q[rear] = value;
    }
}

void display() {
    if(front ==-1){
        cout<<"QUEUE IS EMPTY"<<endl;
    }
    cout << "Current Status" << endl;
    for (int i = front; i <= rear; i++) {
        cout << Q[i] << " ";
    }
    cout << endl;
}

int remove() {
   if(front == -1){
    cout<<"UNDERFLOW"<<endl;
   }
   int item;
   if(front == rear){
    item = Q[front];
    front=rear= -1;
   }else{
    item = Q[front];
    front++;
   }
   return item;
}

int main() {
    insert(10);
    display();
    insert(7);
    insert(15);
    display();
    remove();
    display();
    
    
    return 0;
}
