//Implementation of queue using array
#include<stdio.h>
#define N 5
int queue[N];
int front=-1;
int rear=-1;
void insert(int d)
{
    if(rear==-1)
	{
		front++;
		rear++;
	}
	else if((front==0 && rear==N-1) || (front==rear+1))
	{
		printf("\n Queue is full");
	}
	else if(rear==N-1 && front>0)
	{
		rear=0;
	}
	else
	{
		rear++;
	}
	queue[rear]=d;
}
void delete()
{
	if(front==-1)
	{
		printf("Empty");
	}
	else if(front==rear)
	{
		front=rear=-1;
	}
	else
	{
		printf("%d",queue[front]);
		front++;
	}
}
void display()
{
	int i;
	if(front==-1)
	{
		printf("empty queue");
	}
	if(front>rear)
	{
		for(i=front;i<N;i++)
		{
			printf("%4d",queue[i]);
		}
		for(i=0;i<=rear;i++)
		{
			printf("%4d",queue[i]);
		}
	}
	else
	{
		for(i=front;i<=rear;i++)
			printf("%4d",queue[i]);
	}
	
}
void peek()
{
	if(front==-1 && rear==-1)
	{
		printf("empty queue");
	}
	else
	{
		printf("%d",queue[front]);
	}
}
void main()
{
	int opt,d;
	while(1)
	{
		printf("\n Menu\n 1.insert\n 2.delete\n 3.display\n 4.peek\n 5.Exit\n");
		printf("\n Enter option");
		scanf("%d",&opt);
		if(opt>4)
			break;
		switch(opt)
		{
			case 1:
				printf("\n enter data");
				scanf("%d",&d);
				insert(d);break;
			case 2:
				 delete();break;
			case 3:
				 display();break;
			case 4:
				 peek();
				
		}
	}
}
