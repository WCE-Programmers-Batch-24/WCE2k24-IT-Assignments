//Implementation of queue using linked list
#include <stdio.h>
#include <stdlib.h>

struct QNode {
    int key;
    struct QNode* next;
};
struct Queue {
    struct QNode *front, *rear;
};
struct QNode* newNode(int k)
{
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->key = k;
    temp->next = NULL;
    return temp;
}
struct Queue* createQueue()
{
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}
void enQueue(struct Queue* q, int k)
{
    struct QNode* temp = newNode(k);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}
void deQueue(struct Queue* q)
{
    if (q->front == NULL)
        return;
    struct QNode* temp = q->front;
 
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
 
    free(temp);
}
void display(struct Queue* q)  
{  
    struct QNode* temp=q->front;  
         
    if(q->front == NULL)  
    {  
        printf("\nEmpty queue\n");  
    }  
    else  
    {   printf("\nprinting values:\n");  
        while(temp!= NULL)   
        {  
            printf("%4d",temp->key); 
			temp=temp->next; 
            
        }  
    }  
}
int main()
{
    struct Queue* q = createQueue();
    int choice,d;   
    while(choice != 4)   
    {     
        
        printf("\nMenu\n 1.insert \n2.Delete \n3.Display the queue\n4.Exit\n");  
        printf("\nEnter your choice ");  
        scanf("%d",& choice);  
        switch(choice)  
         {  
            case 1: 
			printf("\n Enter data");
			scanf("%d",&d);
			enQueue(q,d); 
            break;  
            case 2: 
			deQueue(q); 
            break;  
            case 3:  
            display(q);  
            break;  
            case 4:  
            exit(0);  
            break;  
            default:   
            printf("\nEnter valid choice\n");  
         }  
    }   
    return 0;
}
