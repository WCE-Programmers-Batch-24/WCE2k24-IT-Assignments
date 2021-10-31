#include <iostream>
#include <math.h>

using namespace std;

class Node
{
public:
    int coeff;
    int exp;
    Node *next;
};

class linkedList
{
public:
    Node *first = NULL;

    linkedList();
    ~linkedList();
    void display();
    double evaluate(int x);
};

linkedList::linkedList()
{
    Node *last = NULL, *t;
    int n;
    cout << "Enter the numbers of terms" << endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        t = new Node;

        cout << "Enter the coeff and exp" << endl;
        cin >> t->coeff >> t->exp;
        t->next = NULL;
        if (!first)
        {
            first = last = t;
        }
        else
        {
            last->next = t;
            last = t;
        }
    }
};

linkedList::~linkedList()
{
    Node *p = first;
    while (first)
    {
        first = first->next;
        delete p;
        p = first;
    }
}
void linkedList::display()
{
    Node *p = first;
    while (p)
    {
        cout << p->coeff << "x^" << p->exp << " + ";
        p = p->next;
    }
    cout << endl;
}
double linkedList ::evaluate(int x)
{

    int sum = 0;
    Node *p = first;

    while (p)
    {
        sum += p->coeff * pow(x, p->exp);
        p = p->next;
    }
    return sum;
}

int main()
{

    linkedList l;

    cout << "Displaying the polynomial\n";
    l.display();

    cout << "\nEvaluating the polynomial by adding the value of x variable\n";
    cout << l.evaluate(2);

    return 0;
}
