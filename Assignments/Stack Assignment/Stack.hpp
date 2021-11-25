#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(){
        this->data = 0;
        this->next = NULL;
    }

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

// template

template <class stack>
class Stack{
private:
    Node* top = NULL;
    int count = 0;
public:
    // Constructor
    Stack(){
        this->top = NULL;
        this->count = 0;
    };

    // Destructor
    ~Stack(){
        Node* temp = this->top;
        while(temp != NULL){
            Node* temp2 = temp->next;
            delete temp;
            temp = temp2;
        }
    };

    void Push(int data);
    int Pop();
    void Display();
};

// Push
template<>
void Stack<Node>::Push(int data){

    // Create a new node and store the data
    Node* newNode = new Node(data);

    // If stack is empty, then newNode will be the head
    if(this->top == NULL){
        top = newNode;
    }

    // If stack is not empty, then add the newNode to the top
    else{
        newNode->next = this->top;
        this->top = newNode;
    }

    // Increment the count
    count++;
}

// Pop
template<>
int Stack<Node>::Pop(){
    // If stack is empty, then return -1
    if(top == NULL){
        cout<<"Stack Underflow\n";
        return -1;
    }

    // If stack is not empty, then return the top and delete the top
    else{
        // Store the top data
        int data = top->data;
        
        // Store the top's next node
        Node* temp = top;

        // move the top to the next node
        top = top->next;

        // Delete the top
        delete temp;

        // Decrement the count
        count--;

        // Return the top data
        return data;
    }
}

// Display
template<>
void Stack<Node>::Display(){
    // If stack is empty, then print "Stack is empty"
    if(top == NULL){
        cout<<"Stack is empty\n";
    }

    // If stack is not empty, then print the stack
    else{
        // Create a new node and store the top
        Node* temp = top;

        // Print the stack
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
}