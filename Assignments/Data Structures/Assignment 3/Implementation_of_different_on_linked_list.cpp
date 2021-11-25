#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

void create(int A[], int n)
{
    int i;

    struct Node *t, *last;

    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void create2(int A[], int n)
{
    int i;

    struct Node *t, *last;

    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    last = second;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void create3(int A[], int n)
{
    int i;

    struct Node *t, *last;

    third = new Node;
    third->data = A[0];
    third->next = NULL;
    last = third;

    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
int count(Node *p)
{
    int c = 0;
    while (p)
    {
        c++;
        p = p->next;
    }
    return c;
}
void display(Node *p)
{
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

void concat(Node *p, Node *q)
{
    third = p;
    while (p->next)
    {
        p = p->next;
    }
    p->next = q;
}
void reverse(Node *p)
{
    int *A;
    A = (int *)malloc(sizeof(int) * count(p));

    Node *q = p;
    int i = 0;
    while (q)
    {
        A[i] = q->data;
        q = q->next;
        i++;
    }
    q = p;
    i--;
    while (q)
    {
        q->data = A[i];
        q = q->next;
        i--;
    }
}
void merge(Node *p, Node *q)
{
    Node *last;

    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }

    while (p && q)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }

    if (p)
    {
        last->next = q;
    }
    if (q)
    {
        last->next = p;
    }
}

int main()
{
    int A[] = {10, 20, 40, 50, 60};
    int B[] = {15, 18, 25, 30, 55};
    create(A, 5);
    create2(B, 5);

    int choice;
    cout << "Enter your choice for doing operation on linked list\n" << endl;
    cout << "Enter interger '1' for concatenating two linked list" << endl;
    cout << "Enter interger '2' for Merging(or sorting) two linked list" << endl;
    cout << "Enter interger '3' for reversing each linked list\n" << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
        concat(first, second);
        cout << "Displaying the concatenated Linked list" << endl;
        display(third);
        break;

    case 2:
        merge(first, second);
        cout << "Displaying the merged(or sorted) Linked list" << endl;
        display(third);
        break;
    case 3:
        reverse(first);
        cout << "Displaying the reversed Linked list" << endl;
        display(first);
        cout << "\n";

        reverse(second);
        cout << "Displaying the reversed Linked list" << endl;
        display(first);
        break;
    }
    return 0;
}
