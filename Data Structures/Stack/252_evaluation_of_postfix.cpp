#include <iostream>
#include <algorithm>
#include <string.h>
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
    ~Stack();
    void push(int x);
    int pop();
    void display();
    // int isPre(char x);
    // int isOperand(char x);
    // char (*inToPost)(char *infix);
    char stackTop();
    int isEmpty();
    int isFull();
};

Stack::~Stack()
{
    Node *p = new Node;
    while (top)
    {
        top = top->next;
        delete p;
        p = top;
    }
}
char Stack::stackTop()

{

    if (top)

        return top->data;

    return -1;
}

int Stack::isEmpty()

{

    return top ? 0 : 1;
}

int Stack::isFull()

{

    Node *t = new Node;

    int r = t ? 0 : 1;

    delete t;

    return r;
}
int isPre(char x)
{
    if (x == '+' || x == '-')
    {
        return 1;
    }
    else if (x == '*' || x == '/')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

char *inToPost(char *infix)
{
    Stack st;
    char *postfix;
    long len = strlen(infix) + 2;
    postfix = new char[len];
    int i = 0, j = 0;
    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else
        {
            if (isPre(infix[i]) > isPre(st.stackTop()))
            {
                st.push(infix[i++]);
            }
            else
            {
                postfix[j++] = st.pop();
            }
        }
    }
    while (!st.isEmpty())
    {
        postfix[j++] = st.pop();
    }
    postfix[j] = '\0';
    return postfix;
}
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

int Evaluate(char *postfix)
{
    Stack st;
    int x1, x2, r;
    for (int i = 0; postfix[i] != '\0'; i++)
    {
        if (isOperand(postfix[i]))
        {
            st.push(postfix[i] - '0');
        }
        else
        {
            x1 = st.pop();
            x2 = st.pop();
            switch (postfix[i])
            {
            case '+':
                r = x2 + x1;
                break;
            case '-':
                r = x2 - x1;
                break;
            case '*':
                r = x2 * x1;
                break;
            case '/':
                r = x2 / x1;
                break;

            default:
                break;
            }
            st.push(r);
        }
    }
    int res = st.pop();
    // st.pop();
    return res;
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

    Stack st;
    char *infix = "3*5+6/2-4";
    st.push('#');
    char *postfix = inToPost(infix);
    cout << postfix << endl;
    // char *postfix = "35*62/+4-";
    cout << Evaluate(postfix);
    return 0;
}