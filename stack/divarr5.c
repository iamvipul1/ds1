#include<stdio.h>
int top=-1;
int main()
{
    int num[10],div[10] ;
   printf("\nenter 10 array elements:");
    for(int i=0; i<10; i++)
    {
        scanf("%d ",&num[i]);
    }
    for(int i=0; i<10; i++)
    {
        if(num[i]%5==0)
        {
            top++;
            div[top]=num[i];
            printf("\n\n peek element is%d",div[top]);
            if(div[top]==5 || div[top]==25)
            top--;
           printf("\nstCK ELEMENTS:");
            for(int i=0; i<=top; i++)
            printf("%d ",div[i]);
        }
    }
}