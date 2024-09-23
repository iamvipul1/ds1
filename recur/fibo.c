#include<stdio.h>
#include<stdlib.h>

void fibo(int num, int a, int b)
{
  if(num == 0)
  {
    printf("no sequence");
  }
  else
  {
    int c = a + b;
    printf("%d ", c);
    fibo(num-1, b, c);
  }
}

int main()
{
  int n;
  printf("Enter the number of terms: ");
  scanf("%d", &n);
  fibo(n-1, 0, 1);
  return 0;
}
