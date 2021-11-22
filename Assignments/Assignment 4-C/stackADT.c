#include<stdio.h>
#include"stackADT.h"
int main() 
{
    int opt;
    while(1)
    {
        printf("\n Menu\n 1.push\n 2. pop\n 3. top\n 4.display\n 5.exit\n");
        printf("\n enter option");
        scanf("%d",&opt);
        if(opt>4)
            break;
        switch(opt)
        {
            case 1:
               push();break;
            case 2:
               pop();break;
            case 3:
               peek();break;
            case 4:
               display();
             
        }
    }
    return 0;
}

