//Implementation of circular linked list
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}NODE;
NODE *last=NULL;

void addbegin(int d)
{
	NODE *a=(NODE*)malloc(sizeof(NODE));
	a->data=d;
	  if(last==NULL)
	  {
	  	a->next=a;
	  	last=a;
	  	return;
	  }
	a->next=last->next;
	last->next=a;
	
}
void addend(int d)
{
	if(last==NULL)
	{
		addbegin(d);
		return;
	}
	else
	{
	
	NODE *a=(NODE*)malloc(sizeof(NODE));
	a->data=d;
	a->next=last->next;
	last->next=a;
	last=a;
    }
}
void display()
{
	if(last==NULL)
	   printf("\n list is empty");
	else
	{
		NODE *temp;
		temp=last->next;
		do
		{
			printf("%4d",temp->data);
			temp=temp->next;
		}while(temp!=last->next);
	}
}
void addafter(int d)
{
	NODE *temp,*a;
	temp=last->next;
	int x;
	printf("\n enter data which to serach");
	scanf("%d",&x);
	do
	{
		if(temp->data==x)
		{
			a=(NODE*)malloc(sizeof(NODE));
			a->data=d;
			a->next=temp->next;
			temp->next=a;
			if(temp==last)
			  last=a;
			temp=temp->next;
		}
		temp=temp->next;		
	}while(temp!=last->next);
		
}
void search(int d)
{
	NODE *temp;
	temp=last->next;
	do
	{
		if(temp->data==d){
			printf("\n found");
			return;
		}
		 temp=temp->next;   		
	}while(temp!=last->next);
	printf("not found\n");
	return;
}
void delfirst()
{
	NODE *temp;
	temp=last->next;
	if(last==NULL)
	    printf("\n empty list");
    else if(temp->next==temp)
	{
		last=NULL;
		free(temp);
		return;
	}
	else
    {
		last->next=temp->next;
		free(temp);
		return;
	}		
}
void dellast()
{
	NODE *a,*b;
	if(last==NULL)
	  printf("\n empty list");
	else if(a->next==a)
	{
		last=NULL;
		free(a);
	}
	else
	{
		while(a->next!=last->next)
		{
			b=a;
			a=a->next;
		}
		b->next=last->next;
		last=b;
		free(a);
	}
}
void delafter(int c)
{
	NODE *a,*b;
	int i=1;
	a=last->next;
	if(c==1)
	  delfirst();
	else
	{
		while(i<c-1)
		{
			a=a->next;
			i++;
		}
		b=a->next;
		a->next=b->next;
		free(b);
	}
	
}

void main()
{
	int opt;
	int d,c;
	while(1)
	{
		printf("\n menu\n1.Add at end\n 2.Add at begin\n 3.display\n 4.search\n 5.addafter\n 6.delfirst\n 7.dellast\n 8.delafter\n 9.Exit\n");
		printf("enter option\n");
		scanf("%d",&opt);
		if(opt>8)
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
				addbegin(d);break;
		
			case 3:
				display();break;			
			case 4:
				printf("enter value which u have to search\n");
				scanf("%d",&d);
				search(d);break;
			case 5:
				printf("\n enter data after which you have to insert");
				scanf("%d",&d);
				addafter(d);
			case 6:
			    delfirst();break;
			case 7:
			    dellast();break;
			case 8:
			    printf("enter position you have to delete\n");
            	scanf("%d",&c);
				delafter(c);				
		}
		
	}
}


	
	
	



