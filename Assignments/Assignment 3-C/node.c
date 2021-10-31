//Implementation of single linled list
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
	
}NODE;
NODE *st=NULL;

NODE* createnode(int d)
{
	NODE *a=(NODE*)malloc(sizeof(NODE));
	
	a->data=d;
	a->next=NULL;
	return a;	
}
NODE* getlastnode()
{
	NODE *a=st;
	while(a->next!=NULL)
	    a=a->next;
	return a;
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
void addend(int d)
{
	NODE *a,*b;
	a=createnode(d);
	if(st==NULL)
	    st=a;
	else
	{
		b=getlastnode();
		b->next=a;
	}
}
void addbegin(int d)
{
	NODE *a=st;
	a=createnode(d);
	a->next=st;
	st=a;
}
void delfirst()
{
    if(st==NULL)
	   printf("\n empty list");
	else
	{
		NODE *a=st;
		st=a->next;
		free(a);
	}	
	
}

void addafter(int c)
{
	NODE *a=st;
	NODE *temp=createnode(c);	
	int i;
	for(i=1;i<c;i++)
	{
		a=a->next;
		   if(a==NULL)
		      printf("list is empty");		    
	}
	temp->next=a->next;
	a->next=temp;	
}
void dellast()
{
	if(st==NULL)
	    printf("list is empty");
	else
	{
		NODE *a=st;
	     	while(a->next->next!=NULL)
		         a=a->next;
		NODE *temp;
		temp=a->next;
		a->next=NULL;
		free(temp);
		         
		
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
	int opt;
	int d;
	while(1)
	{
		printf("\n menu\n1.Add at end\n 2.Add at begin\n 3.delfist\n 4.display\n 5.addafter\n 6.dellast\n 7.search\n 8.Exit\n");
		printf("enter option\n");
		scanf("%d",&opt);
		if(opt>7)
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
				delfirst();break;
			case 4:
				display();break;
			case 5:
				printf("\n enter data which you have to insert");
				scanf("%d",&d);
				int c;
				printf("enter position you have to insert\n");
            	scanf("%d",&c);
				addafter(c);break;
			case 6:
				dellast();break;
			case 7:
				printf("enter value which u have to search\n");
				scanf("%d",&d);
				search(d);
				
		}
		
	}
}
