#include <iostream>
using namespace std;

class Stack
{
private:
    int size;
    int top;
    int *S;

public:
    Stack(int size);
    ~Stack();

    void push(int x);
    int pop();
    void display();

    int isFull();
    int isEmpty();
    int stackTop();
};

Stack::Stack(int size)
{
    this->size = size;
    top = -1;
    S = new int[size];
}

Stack::~Stack()
{
    delete[] S;
}

void Stack::push(int x)
{
    if (isFull())
    {
        cout << "Stack Overflow!" << endl;
    }
    else
    {
        top++;
        S[top] = x;
    }
}

int Stack::pop()
{
    int x = 1;
    if (isEmpty())
    {
        cout << "Stack Underflow!" << endl;
    }
    else
    {
        x = S[top];
        top--;
    }
    return x;
}

int Stack::isFull()
{
    if (top == size - 1)
    {
        return 1;
    }
    return 0;
}

int Stack::isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    return 0;
}

void Stack::display()
{
    for (int i = top; i >= 0; i--)
    {
        cout << S[i] << " | " << flush;
    }
    cout << endl;
}

int Stack::stackTop()
{
    if (isEmpty())
    {
        return -1;
    }
    return S[top];
}

int main()
{

    int A[] = {1, 3, 5, 7, 9};

    Stack stk(sizeof(A) / sizeof(A[0]));

    // Populate stack with array elements
    cout << "Pushing the elements" << endl;
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
    {
        stk.push(A[i]);
    }
    stk.push(11); // -->expected output is Stack Overflow!

    // Display stack;
    cout << "Stack: " << flush;
    stk.display();

    // Pop out elements from stack

    cout << "Popped out elements: " << flush;
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
    {
        cout << stk.pop() << ", " << flush;
    }

    cout << endl;
    stk.pop();

    return 0;
}