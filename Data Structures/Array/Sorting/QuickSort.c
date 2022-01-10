// Quick Sort Program in C
// Best case Time Complexity: O(n logn)
// Average case Time Complexity: O(n logn)
// Worst case time complexity: O(n^2)
#include<stdio.h>

void quicksort(int number[100],int first,int last){
    int i, j, pivot, temp;
    if(first<last){
        pivot=first;
        i=first;
        j=last;
    while(i<j){
        while(number[i]<=number[pivot]&&i<last)
            i++;
        while(number[j]>number[pivot])
            j--;
        if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
        }
    }
    temp=number[pivot];
    number[pivot]=number[j];
    number[j]=temp;
    quicksort(number,first,j-1);
    quicksort(number,j+1,last);
    }
}

int main(){
    int i, count, number[25];
    printf("Enter no. of elements : \n");
    scanf("%d",&count);
    printf("Enter %d elements:\n ", count);
    for(i=0;i<count;i++)
        scanf("%d",&number[i]);
    quicksort(number,0,count-1);
    printf("The Sorted Order is: ");
    for(i=0;i<count;i++)
        printf(" %d\n",number[i]);
    return 0;
    }
