//Add two pointers
#include<stdio.h>
int main()
{
	int a,b;
	int *p=&a;
	int *q=&b;
	printf("\n enter two no");
	scanf("%d%d",&a,&b);
	int sum;
	sum=*p+*q;
	printf("sum:%d\n",sum);
}