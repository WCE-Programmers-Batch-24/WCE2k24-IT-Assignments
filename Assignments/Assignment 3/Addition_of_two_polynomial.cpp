//Addition of two polynomial
//2020BTEIT00069 Nidhish Chauhan
//Batch: S4

#include <iostream>
#include <math.h>

struct Node
{

    int Coeff;

    int E;

    Node *Next;
};

void Create_First(Node **p)
{
    int N;
    Node *Last, *t;
    printf("Enter the no of terms for first polynomial: \n");
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        t = new Node;
        printf("Enter the polynomial terms for first polynomial : \n");
        scanf("%d %d", &t->Coeff, &t->E);
        t->Next = NULL;
        if (!*p)
        {
            *p = Last = t;
        }
        else
        {
            Last->Next = t;
            Last = t;
        }
    }
}

void Create_Second(Node **q)

{

    int N;

    Node *Last, *t;

    printf("Enter the no of terms for second polynomial: \n");

    scanf("%d", &N);

    for (int i = 0; i < N; i++)

    {

        t = new Node;

        printf("Enter the polynomial terms for second polynomial: \n ");

        scanf("%d %d", &t->Coeff, &t->E);

        t->Next = NULL;

        if (!*q)

        {

            *q = Last = t;
        }

        else

        {

            Last->Next = t;

            Last = t;
        }
    }
}

Node *Add(Node *p, Node *q)

{

    Node *A = NULL, *Last, *t;

    while (p != NULL && q != NULL)

    {

        if (p->E == q->E)

        {

            t = new Node;

            t->Coeff = p->Coeff + q->Coeff;

            t->E = p->E;

            t->Next = NULL;
            p = p->Next;
            q = q->Next;

            if (A == NULL)

            {

                A = Last = t;
            }

            else

            {

                Last->Next = t;

                Last = t;
            }
        }

        else if (p->E > q->E)

        {

            t = new Node;

            t->Coeff = p->Coeff;

            t->E = p->E;

            t->Next = NULL;

            p = p->Next;

            if (A == NULL)
            {

                A = Last = t;
            }

            else

            {

                Last->Next = t;

                Last = t;
            }
        }

        else if (p->E < q->E)

        {

            t = new Node;

            t->Coeff = q->Coeff;

            t->E = q->E;

            t->Next = NULL;

            q = q->Next;

            if (A == NULL)
            {

                A = Last = t;
            }

            else

            {

                Last->Next = t;

                Last = t;
            }
        }
    }

    while (q != NULL)

    {

        t = new Node;

        t->Coeff = q->Coeff;

        t->E = q->E;

        t->Next = NULL;

        q = q->Next;

        if (A == NULL)
        {

            A = Last = t;
        }

        else

        {

            Last->Next = t;

            Last = t;
        }
    }

    while (p != NULL)

    {

        t = new Node;

        t->Coeff = p->Coeff;

        t->E = p->E;

        t->Next = NULL;

        p = p->Next;

        if (A == NULL)
        {

            A = Last = t;
        }

        else

        {

            Last->Next = t;

            Last = t;
        }
    }

    return A;
}

void Display(Node *A)

{

    while (A->Next)

    {

        printf("%dx^%d+", A->Coeff, A->E);

        A = A->Next;
    }

    printf("%dx^%d\n", A->Coeff, A->E);
}

int main()
{
    Node *A, *First = NULL, *Second = NULL;

    Create_First(&First);

    Create_Second(&Second);
    A = Add(First, Second);
    printf("Displaying the first polynomial: \n");

    Display(First);

    printf("Displaying the second polynomial: \n");
    Display(Second);

    printf("\nDisplaying the addition of two polynomial: \n");
    Display(A);

    return 0;
}