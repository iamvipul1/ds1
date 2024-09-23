#include <stdio.h>
int main()
{
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int *a = (int*)calloc(sizeof(int) * n);

    for(int i = 0; i < n; i++)
    {
        printf("Enter item %d: ", i+1);
        scanf("%d", &a[i]);
    }

    printf("Items are: ");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
      printf("memory are: ");

for(int i = 0; i < n; i++)
    {
        printf("%d ", &a[i]);
    }  
  free(a);
  return 0;
}