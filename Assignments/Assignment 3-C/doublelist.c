//Implementation of double linked list
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
	struct node *prev;
}NODE;
NODE *st=NULL;

NODE* createnode(int d)
{
	NODE *a=(NODE*)malloc(sizeof(NODE));
	
	a->data=d;
	a->prev=NULL;
	a->next=NULL;
	return a;	
}
void addbeg(int d)
{
	NODE *a=st;
	a=createnode(d);
	if(st==NULL)
	   st=a;
	else
	{
	   
	   a->next=st;
	   st->prev=a;
	   st=a;	    	
	}
}
void addend(int d)
{
	NODE *a=st;
	a=createnode(d);
	if(st==NULL)
	   st=a;
	else
	{
		NODE *b;
		b=st;
		while(b->next!=NULL)
		{
			b=b->next;
		}
		b->next=a;
		a->prev=b;
	}
}
void addafter(int c)
{
	NODE *a;
	NODE *temp=st;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	a->next=temp->next;
	temp->next->prev=a;
	temp->next=a;
	a->prev=temp;
}
void delbeg()
{
	NODE *a=st;
	st=st->next;
	st->prev=NULL;
	free(a);
}
void delat(int c)
{
	if(c==1){
		delbeg();
		return;
	}
	NODE *temp=st;
	int i=1;
	for(i=1;i<c-1;i++)
	{
		temp=temp->next;
	}
	NODE *a=temp->next;
	temp->next=a->next;
	if(temp->next!=NULL)
	{
		a->next->prev=temp;
	}
	free(a);
	
}
void display()
{
	NODE *a=st;
	if(st==NULL)
	   printf("\n empty list");
	else
	{
		printf("\n data");
	
	while(a!=NULL)
	{
		printf("%4d",a->data);
		a=a->next;
	}
     }
}
void search(int d)
{
	NODE *a=st;
	while(a!=NULL)
	{
		if(a->data==d){
			printf("\n found");
			return;
		}
		 a=a->next;   		
	}
	printf("not found\n");
	return;
}
void main()
{
	int opt,c;
	int d;
	while(1)
	{
		printf("\n menu\n1.Add at end\n 2.Add at begin\n 3.delat\n 4.display\n 5.addafter\n 6.search\n 7.Exit\n");
		printf("enter option\n");
		scanf("%d",&opt);
		if(opt>6)
		   break;
		switch(opt)
		{
			case 1:
				printf("\n add data at end\n");
				scanf("%d",&d);
				addend(d);break;
			case 2:
				printf("\n add data at begin\n");
				scanf("%d",&d);
				addbeg(d);break;
			case 3:
				printf("enter position you have to delete\n");
            	scanf("%d",&c);
				delat(c);break;
			case 4:
				display();break;
			case 5:
				printf("\n enter data which you have to insert");
				scanf("%d",&d);
				printf("enter position you have to insert\n");
            	scanf("%d",&c);
				addafter(c);break;
			
			case 6:
				printf("enter value which u have to search\n");
				scanf("%d",&d);
				search(d);				
		}
		
	}
}
