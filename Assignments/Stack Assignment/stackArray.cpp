#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Stack{

public:
    int size;
    int top;
    int* arrStack;

    Stack(int size){
        this->size = size;
        top = -1;
        arrStack = new int[size];
    }
};

// Push
void Push(Stack* stack, int data){
    // Check if stack is full
    if(stack->top == stack->size - 1) cout<<"Stack Overflow \n";
    else{
        stack->arrStack[++stack->top] = data;
    }
}

// Pop
void Pop(Stack* stack){
    // Check if stack is empty
    if(stack->top == -1) cout<<"Stack Underflow \n";
    else{
        stack->top--;
        cout<<"Popped element is "<<stack->arrStack[stack->top+1]<<"\n";
    }
}

// Peek
void Peek(Stack* stack, int index){
    // Check if indez is valid or not
    if(index > stack->top + 1 || index < 0) cout<<"Invalid index \n";
    else{
        cout<<"Element at index "<<index<<" is "<<stack->arrStack[stack->top + 1 - index]<<"\n";
    }
}

// isEmpty
bool isEmpty(Stack* stack){
    return stack->top == -1;
}

// isFull
bool isFull(Stack* stack){
    return stack->top == stack->size - 1;
}

// Stack Top
int StackTop(Stack* stack){
    if(!isEmpty(stack)) return stack->arrStack[stack->top];
    else return -1;
}

//Print the stack
void Display(Stack* stack){
    if(stack->top == -1) cout<<"Stack is empty. \n";
    else{
        cout<<"Stack is: ";
        for(int i = stack->top; i >= 0; i--){
            cout<<stack->arrStack[i]<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    int n;
    cout<<"Enter the size of the stack: ";
    cin>>n;

    // Create a stack of size n
    Stack* stack = new Stack(n);

    // Menu for stack operations
    int choice;
    do{
        cout<<"\n1. Push \n2. Pop \n3. Peek \n4. Display \n5. Exit \nEnter your choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                int data;
                cout<<"Enter the data to be pushed: ";
                cin>>data;
                Push(stack, data);
                break;
            case 2:
                Pop(stack);
                break;
            case 3:
                int index;
                cout<<"Enter the index of the element to be peeked: ";
                cin>>index;
                Peek(stack, index);
                break;
            case 4:
                Display(stack);
                break;
            case 5:
                cout<<"Exiting... \n";
                break;
            default:
                cout<<"Invalid choice. \n";
        }
    }while(choice != 5);

    return 0;
}