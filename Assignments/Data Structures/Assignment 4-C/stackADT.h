#include<stdio.h>
#define M 5


int stack[M];
int top=-1;
int isfull()
{
    return (top==M-1);
}
int isempty()
{
    return (top==-1);
}
void push()
{
    int d;
    printf("\n enter data");
    scanf("%d",&d);
    if(top==M-1)
        printf("\n stack overflow");
    else{
        top++;
        stack[top]=d;
    }
}
void pop()
{
    int d;
    if(top==-1)
        printf("\n stack underflow");
    else{
        d=stack[top];
        top--;

    }

}
void peek()
{
    if(top==-1)
        printf("\n empty");
    else
        printf("%d",stack[top]);
}
void display()
{
    int i;
    for(i=top;i>=0;i--)
    {
        printf("%4d",stack[i]);
    }
}


