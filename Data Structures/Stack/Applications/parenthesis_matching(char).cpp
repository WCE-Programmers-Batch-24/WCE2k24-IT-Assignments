#include <iostream>
#include <cstring>

using namespace std;

class Node
{
public:
    char data;
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
    void push(char x);
    int pop();
    void display();
    int isBalanced(char *exp);
    int isEmpty();
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

void Stack::push(char x)
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

    char x = -1;

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

int Stack::isBalanced(char *exp)
{

    Stack st;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '('||exp[i]=='{'||exp[i]=='[')
        {
            st.push(exp[i]);
        }
        else if (exp[i] <=125)
        {
            if (st.isEmpty())
            {
                return 0;
            }
            else if(exp[i]==41)
            {
                st.pop();
            }
            else if(exp[i]==93)
            {
                st.pop();
            }
            else if(exp[i]==125)
            {
                st.pop();
            }
        }
    }
    return st.isEmpty() ? 1 : 0;
}
int Stack::isEmpty()
{
    return top ? 0 : 1;
}

Stack::~Stack(){
    Node *p=new Node;
    while (top)
    {
        top=top->next;
        delete p;
        p=top;
    }
    
}

int main()
{
    char exp[] = "{([a+b]*[c-d])}";
    Stack st;
    cout << st.isBalanced(exp);

    return 0;
}
