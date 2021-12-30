//I think mam told us to only make insert function so you can omit the delete function from the program

#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int A[], int n)
{
    int temp, i;
    i = n;
    temp = A[i];

    while (temp > A[i / 2] && i > 1)
    {
        A[i] = A[i / 2];
        i = i / 2;
    }
    A[i] = temp;
}

void Delete(int A[], int n)
{
    int val, i, temp, j, x;

    val = A[1];
    // x = A[1];
    A[1] = A[n];
    A[n] = val;
    i = 1;
    j = 2 * i;

    while (j <= n - 1)
    {
        if (j < n - 1 && (A[j + 1] > A[j]))
        {
            j = j + 1;
        }

        if (A[i] < A[j])
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i = j;
            j = 2 * i;
        }
        else
        {
            break;
        }
    }

    printf("\n The deleted element is: %d ", val);
}

int main()
{

    int size, choice;
    printf("Enter the size of an array: ");
    scanf("%d", &size);
    int B[size];
    printf("\n\nNote: Enter the the first element of array as '0' because the heap DS will start from 1st index\n");
    printf("\nInsert the elements into the array: \n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &B[i]);
    }

    while (choice != 0)
    {
        printf("\nEnter your choice: \n");
        printf("1. Creation of a heap\n2. Deleting a element from a heap\n3. Displaying a heap\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nCreating a heap...\n");
            for (int i = 2; i <= sizeof(B) / sizeof(B[0]) - 1; i++)
            {
                insert(B, i);
            }

            break;

        case 2:

            printf("Deleting...\n");
            Delete(B, sizeof(B) / sizeof(B[0]) - 1);
            printf("The deleted element will be stored at the free space of given array.");
            break;

        case 3:

            printf("Heap: [ ");
            for (int i = 1; i <= sizeof(B) / sizeof(B[0]) - 1; i++)
            {
                printf("%d ", B[i]);
            }
            printf("]\n");

            break;
        case 0:

            break;
        }
    }

    return 0;
}