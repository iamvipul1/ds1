#include <stdio.h>
int main()
{
    int n;
    printf("Enter the number of items:\n ");
    scanf("%d", &n);

    int *a = (int*)malloc(sizeof(int) * n);
    int *b = (int*)malloc(sizeof(int) * n);
        int *c = (int*)malloc(sizeof(int) * n);
printf("enter elements in 1\n");
    for(int i = 0; i < n; i++)
    {
        printf("Enter item %d:\n ", i+1);
        scanf("%d", &a[i]);
    }

printf("enter elements in 2\n");
    for(int i = 0; i < n; i++)
    {
        printf("Enter item %d:\n ", i+1);
        scanf("%d", &b[i]);
    }
    printf("added are:\n ");
    for(int i = 0; i < n; i++)
    {
       c[i]=a[i]+b[i];
    }
    for(int i = 0; i < n; i++)
    {
       printf("%d", c[i]);
    }
    printf("\n");

      printf("memory are:\n ");
for(int i = 0; i < n; i++)
    {
        printf("%d ", &c[i]);
    }    
  printf("\n");
  free(a);
  free(b);
   printf("added  after are:\n ");
    for(int i = 0; i < n; i++)
    {
       a[i]=a[i]+b[i];
    }
    for(int i = 0; i < n; i++)
    {
       printf("%d\n", a[i]);
    }
    printf("\n");

      printf("memory are:\n ");
for(int i = 0; i < n; i++)
    {
        printf("%d \n", &a[i]);
    }    
}