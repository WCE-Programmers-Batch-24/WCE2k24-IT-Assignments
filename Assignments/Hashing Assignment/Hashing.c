#include<stdio.h>

#define size 7

int arr[size];


void init()
{   
    int i;
    for(i = 0; i < size; i++)
        arr[i] = -1;
}

void insert(int value)
{   
    int key = value % size;
    
    if(arr[key] == -1)
    {   
        arr[key] = value;
        printf("%d inserted at arr[%d]\n", value,key);
    }
    else
    {   
        printf("Collision : arr[%d] has element %d already!\n",key,arr[key]);
        printf("Unable to insert %d\n",value);
    }
}

void del(int value)
{
    int key = value % size;
    if(arr[key] == value)
        arr[key] = -1;
    else
        printf("%d not present in the hash table\n",value);
}

void search(int value)
{
    int key = value % size;
    if(arr[key] == value)
        printf("Search Found\n");
    else
        printf("Search Not Found\n");
}

void print()
{
    int i;
    for(i = 0; i < size; i++)
        printf("arr[%d] = %d\n",i,arr[i]);
}

int main()
{
    init();
    int n,x;
    while(1){
    	printf("1.Insert\n2.Delete\n3.Search\n4.Print\n");
    	scanf("%d",&n);
    	switch(n)
    	{
    	case 1: 
  	   	 printf("Enter the Value:\n");
	   	 scanf("%d",&x);
	   	 insert(x);
	   	 break;
  	    
   	 case 2: 
	   	 printf("Enter the Value:\n");
	   	 scanf("%d",&x);
	   	 del(x);
	   	 break;

   	 case 3: 
	    	printf("Enter the Value:\n");
	    	scanf("%d",&x);
	    	search(x);
	    	break;

    	case 4:	 
		 print();
	    	 break;

    	default: 
		 printf("Invalid Output");
	         break;	    
        }
    }

    return 0;
}
