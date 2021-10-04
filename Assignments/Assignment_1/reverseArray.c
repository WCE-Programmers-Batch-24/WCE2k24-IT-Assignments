//Q4: Write c program to reverse Array Using Pointers
#include <stdio.h>

void reverseArray(int A[], int n){
    int *left = A;
    int *right = A + n - 1;

    while (left < right) {
        *left    ^= *right;
        *right   ^= *left;
        *left    ^= *right;

        left++;
        right--;
    }
}

int main(){
    int n;
    printf("Enter the length of array: ");
    scanf("%d", &n);

    int A[n];
    printf("\nEnter the array elemnts to be reversed: ");
    for(int i=0; i<n; i++) {scanf("%d", &A[i]);}

    reverseArray(A, n);
     printf("\nThe reversed array is: ");
    for(int i=0; i<n; i++) {printf("%d ", A[i]);}

    return 0;
}