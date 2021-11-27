#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
 

struct StackNode {
    int data;
    struct StackNode* next;
};
 
struct StackNode* createNode(int data)
{
    struct StackNode* stackNode =(struct StackNode*)malloc(sizeof(struct StackNode));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}
 
int isEmpty(struct StackNode* a)
{
    return !a;
}
 
void push(struct StackNode** a, int data)
{
    struct StackNode* stackNode = createNode(data);
    stackNode->next = *a;
    *a = stackNode;
    printf("%d pushed to stack\n", data);
}
 
int pop(struct StackNode** a)
{
    if (isEmpty(*a))
    {
    	 printf("\n empty stack");
    	 return 0;
	}
	else{
	
    struct StackNode* temp = *a;
    *a= (*a)->next;
    int popdata = temp->data;
    free(temp); 
    return popdata;
}
}
void display(struct StackNode* a)
{
	printf("\n data\n");
	while(a!=NULL)
	{
		printf("%d\n",a->data);
		a=a->next;
		
	}
}
 
int top(struct StackNode* a)
{
    if (isEmpty(a))
        return -1;
    return a->data;
}
 

