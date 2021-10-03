//c program to Increment and Decrement Operations Using Pointer
#include<stdio.h>
int main(){
    int a, *ptr;
    ptr = &a;
    printf("Enter integer:");
    scanf("%d", &a);
    printf("Value after increment operation is %d \n", ++(*ptr));
    printf("Value after decrement operation is %d \n", --(*ptr));
}
