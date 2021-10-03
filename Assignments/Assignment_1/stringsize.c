//Program that finds the length of the string using pointer

#include<stdio.h>

int main()
{
    int size=0;
    char str[30];
    gets(str);
    char *ptr = str;

    int i=0,t=1;
    while(t)
    {
        if(*ptr=='\0')
        {
            break;
        }
        size++;
        ptr++;
    }
    printf("The size of the string is %d",size);
}