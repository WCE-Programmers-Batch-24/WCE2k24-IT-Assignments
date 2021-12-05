#include <iostream>

using namespace std;

class Node
{
public:
    Node *lChild;
    int data;
    Node *rChild;
};

class Queue
{
    int front;
    int rear;
    int size;
    Node **Q;

public:
    Queue()
    {
        front = rear = -1;
        size = 10;
        Q = new Node *[size];
    }
    Queue(int size)
    {
        front = rear = -1;
        this->size = size;
        Q = new Node *[size];
    }
    void enqueue(Node *p);
    Node *dequeue();
    int isEmpty()
    {
        if (front == rear)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};

void Queue::enqueue(Node *p)
{

    if (rear == size - 1)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        rear++;
        Q[rear] = p;
    }
}
Node *Queue::dequeue()
{
    Node *p = nullptr;
    if (front == rear)
    {
        printf("Queue is empty \n");
    }
    else
    {
        front++;
        p = Q[front];
    }
    return p;
}

class Tree
{
    Node *root;

public:
    Tree() { root = nullptr; }
    void createTree();
    void preOrder()
    {
        preOrder(root);
    }
    void preOrder(Node *p);

    void inOrder()
    {
        inOrder(root);
    }
    void inOrder(Node *p);

    void postOrder()
    {
        postOrder(root);
    }
    void postOrder(Node *p);
    void levelOrder()
    {
        levelOrder(root);
    }
    void levelOrder(Node *p);
    int Height()
    {
        return Height(root);
    }
    int Height(Node *p);
};

void Tree::createTree()
{
    Node *p, *t = nullptr;
    int x;
    Queue q(100);
    printf("Enter root value: \n");
    scanf("%d", &x);

    root = new Node;
    root->data = x;
    root->lChild = root->rChild = nullptr;
    q.enqueue(root);
    while (!q.isEmpty())
    {
        p = q.dequeue();
        printf("Enter left child of %d: \n", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lChild = t->rChild = nullptr;
            p->lChild = t;
            q.enqueue(t);
        }

        printf("Enter right child of %d: \n", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lChild = t->rChild = nullptr;
            p->rChild = t;
            q.enqueue(t);
        }
    }
}

void Tree::preOrder(Node *p)
{

    if (p)
    {
        printf("%d ", p->data);
        preOrder(p->lChild);
        preOrder(p->rChild);
    }
}
void Tree::inOrder(Node *p)
{

    if (p)
    {
        preOrder(p->lChild);
        printf("%d ", p->data);
        preOrder(p->rChild);
    }
}
void Tree::postOrder(Node *p)
{

    if (p)
    {
        preOrder(p->lChild);
        preOrder(p->rChild);
        printf("%d ", p->data);
    }
}

void Tree::levelOrder(Node *p)
{
    Queue q(100);
    printf("%d ", p->data);
    q.enqueue(p);
    while (!q.isEmpty())
    {
        p = q.dequeue();
        if (p->lChild)
        {
            printf("%d ", p->lChild->data);
            q.enqueue(p->lChild);
        }
        if (p->rChild)
        {
            printf("%d ", p->rChild->data);
            q.enqueue(p->rChild);
        }
    }
}

int Tree::Height(Node *p)
{
    int l = 0;
    int r = 0;
    if (p == nullptr)
    {
        return 0;
    }
    l = Height(p->lChild);
    r = Height(p->rChild);
    if (l > r)
    {
        return l + 1;
    }
    else
    {
        return r + 1;
    }
}

int main()
{
    Tree t;
    t.createTree();
    int ch;
    while (ch != 0)
    {
        printf("\nEnter your choice: \n 1. Preorder\n 2. Inorder\n 3. Postorder\n 4.Levelorder\n 5. Height of the tree\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Preorder: ");
            t.preOrder();
            printf("\n");
            break;
        case 2:
            printf("Inorder:");
            t.inOrder();
            printf("\n");
            break;
        case 3:
            printf("Postorder:");
            t.postOrder();
            printf("\n");
            break;
        case 4:
            printf("Levelorder:");
            t.levelOrder();
            printf("\n");
            break;
        case 5:
            printf("Height of the tree:");
            printf("%d", t.Height());
            printf("\n");
            break;

        case 0:
            break;
        }
    }

    return 0;
}