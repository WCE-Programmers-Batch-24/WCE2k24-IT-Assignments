#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Stack
{
    Node *top;

public:
    Stack()
    {
        top = NULL;
    }
    void push(int x);
    int pop();
    void display();
};

void Stack::display()
{
    Node *p = top;
    while (p)
    {
        cout << p->data << " | ";
        p = p->next;
    }
    cout << "\n";
}

void Stack::push(int x)
{

    Node *p = new Node;
    if (p == NULL)
    {
        cout << "Stack Overflow" << endl;
    }
    else
    {
        p->data = x;
        p->next = top;
        top = p;
    }
}

int Stack::pop()
{

    int x = -1;

    if (top == NULL)
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        Node *p = top;
        x = p->data;
        top = top->next;
        delete p;
    }
    return x;
}

int main()
{

    Stack stk;
    int arr[] = {7, 14, 21, 28, 35, 42, 49};
    char choice;

    cout << "Enter 'Y'(i.e., Yes) to push the elements into stack." << endl;
    cin >> choice;
    switch (choice)
    {
    case 'Y':
        for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        {
            stk.push(arr[i]);
        }
        cout << "\nDisplaying the stack: " << endl;
        stk.display();
        break;

    default:
        cout << "It is recommended to enter an input" << endl;
        break;
    }

    cout << "\nEnter 'Y'(i.e., Yes) to pop out an elements from stack or else enter 'N' (i.e., No)." << endl;
    cin >> choice;

    switch (choice)
    {
    case 'Y':
        stk.pop();
        cout << "\nDisplaying the stack after popping out an element: " << endl;
        stk.display();
        break;

    case 'N':
        break;
    }

    return 0;
}