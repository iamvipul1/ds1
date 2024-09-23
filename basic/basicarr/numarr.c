#include<stdio.h>
int main()
{
  int n;
  printf("enter n:");
  scanf("%d", &n);
  int a[n];
  for(int i=0;i<n;i++)
    {
      scanf("%d", &a[i]);
    }
  printf("array entered is:");
  for(int i=0;i<n;i++)
    {
      printf("%d ", a[i]);
    }
  return 0;
}