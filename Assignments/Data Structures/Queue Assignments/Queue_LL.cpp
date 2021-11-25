/*
    Queue using Linked List implementation
*/

#include <bits/stdc++.h>
using namespace std;

// Node class
class Node{
public:
    int data;
    Node *next;

    Node(){
        this->data = 0;
        this->next = NULL;
    }

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

// Queue class
class Queue{
public:
    Node* front;
    Node* rear;

    Queue(){
        this->front = NULL;
        this->rear = NULL;
    }

    void enqueue(int data);
    int dequeue();
};

// Function to enqueue an element in the queue using LL implementation of Queue
void Queue::enqueue(int data){
    // Create a new node
    Node* new_node = new Node(data);

    // If queue is empty
    if(this->front == NULL){
        // Make the new node as the front and rear
        this->front = new_node;
        this->rear = new_node;
    }
    else{
        // Make the new node as the rear
        this->rear->next = new_node;
        this->rear = new_node;
    }
}

// Function to dequeue an element from the queue using LL implementation of Queue
int Queue::dequeue(){
    // if queue is empty
    if(this->front == NULL){
        cout<<"Queue is empty"<<endl;
        return -1;
    }
    else{
        // Store the data of the front node
        int data = this->front->data;

        // Make the next node as the front
        this->front = this->front->next;

        // If queue is empty
        if(this->front == NULL){
            this->rear = NULL;
        }

        return data;
    }
}

int main(){
    Queue q;

    // Menu driven program to perform operations on the queue using LL implementation of Queue
    int choice;
    do{
        cout<<"---------------------Menu---------------------\n";
        cout<<"1. Enqueue"<<endl;
        cout<<"2. Dequeue"<<endl;
        cout<<"3. Exit"<<endl;

        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                int data;
                cout<<"Enter the data to be enqueued: ";
                cin>>data;
                q.enqueue(data);
                break;
            case 2:
                cout<<"Dequeued element: "<<q.dequeue()<<endl;
                break;
            case 3:
                cout<<"Exiting..."<<endl;
                break;
            default:
                cout<<"Invalid choice"<<endl;
        }
    }while(choice != 3);

    return 0;
}