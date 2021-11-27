//Implementation of stack ADT
#include<stdio.h>
#include"stackImplement.h"
#include<stdlib.h>

int main()
{
    STACK* stack;
    stack=createStack();
    int* data;
    data=(int*)malloc(sizeof(int));
    int opt;
    while(1)
    {
        printf("\n Menu\n 1.push\n 2. pop\n 3.top\n 4.stackcount\n 5.display\n 6.Exit\n");
        printf("Enter option");
        scanf("%d",&opt);
        if(opt>5)
            break;
        switch(opt)
        {
            case 1:
                printf("\n enter data");
                scanf("%d",&data);
                pushStack(stack,data);break;
            case 2:
                popStack(stack);break;
            case 3:
                printf("%d",stackTop(stack));break;
            case 4:
                printf("%d",stackCount(stack));break;
             case 5:
             	display(stack);

        }

    }
    return 0;


}
