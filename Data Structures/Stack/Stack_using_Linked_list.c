#include<limits.h>
#include <stdio.h>
#include <stdlib.h>
 

struct StackNode {
    int data;
    struct StackNode* next;
};
 
struct StackNode* newNode(int data)
{
    struct StackNode* stackNode =
      (struct StackNode*)
      malloc(sizeof(struct StackNode));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}
 
int isEmpty(struct StackNode* root)
{
    return !root;
}
 
void push(struct StackNode** root, int data)
{
    struct StackNode* stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
    printf("%d pushed to stack\n", data);
}
 
int pop(struct StackNode** root)
{
    if (isEmpty(*root))
        return INT_MIN;
    struct StackNode* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
 
    return popped;
}
 
int peek(struct StackNode* root)
{
    if (isEmpty(root))
        return INT_MIN;
    return root->data;
}
 
int main()
{
    struct StackNode* root = NULL;
 
    push(&root, 5);
    push(&root, 14);
    push(&root, 23);
 
    printf("%d popped from stack\n", pop(&root));
 
    printf("Top element is %d\n", peek(root));
 
    return 0;
}
