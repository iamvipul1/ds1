#include <stdio.h>
int tot =0;
void sum(int n) {
  if (n == 10) {
    printf("\nmax num is 10, it is set by vip,,,,so - ");
  } else {
    tot = tot+ n;
    sum(n+1);
  }
}
int main() {
  int num;
  printf("Enter a starting number: ");
  scanf("%d", &num);
  sum(num);
          printf("Sum is %d", tot);
  return 0;
}
