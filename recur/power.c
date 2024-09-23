#include <stdio.h>
#include <stdlib.h>

int power(int num, int pow) 
{
  if (pow == 0) {
    return 1;
  } else {
    int result = num * power(num, pow-1);
    return result;
  }
}
int main() 
{
  int num = 3, pow = 2;
  int result = power(num, pow);
  printf("ans is %d", result);
  return 0;
}
