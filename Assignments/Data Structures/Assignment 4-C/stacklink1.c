//Implementation of stack using linked list
#include<stdio.h>
#include<stdlib.h>
#include"stacklink.h"

int main()
{
	struct StackNode* stack = NULL;
	int opt,d;
	while(1)
	{
		printf("\n Menu\n 1.push\n 2.pop\n 3.top\n 4.display\n 5.Exit\n");
		printf("\n enter option");
		scanf("%d",&opt);
		if(opt>4)
			break;
		switch(opt)
		{
			case 1:
				printf("\n enter data");
				scanf("%d",&d);
				push(&stack,d);break;
			case 2:
				printf("%d",pop(&stack));break;
			case 3:
				printf("%d",top(stack));break;
			case 4:
				display(stack);
		}
	}
 
}
