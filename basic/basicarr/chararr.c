#include<stdio.h>
int main()
{
  int n;
  printf("enter n  ::");
  scanf("%d", &n);
  char a[n];
  for(int i=0;i<n;i++)
    {
      scanf("%s", &a[i]);
    }
  printf("array entered is:");
  for(int i=0;i<n;i++)
    {
      printf("%c ", a[i]);
    }
  return 0;
}
