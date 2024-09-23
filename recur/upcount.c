#include <stdio.h>
void upcount(int n) {
  if (n == 11) {
    printf("\nCountup complete.\n");
  } else {
    printf("%d ", n);
    upcount(n + 1);
  }
}
int main() {
  int num;
  printf("Enter a number to start countup: ");
  scanf("%d", &num);
  printf("\n");
  upcount(num);
  return 0;
}