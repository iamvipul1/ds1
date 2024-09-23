#include <stdio.h>
int main() {
  int size;
  printf("enter size:");
  scanf("%d", &size);
  char a[size];
  for (int i = 0; i < size; i++) {
    scanf("%s", &a[i]);
  }
  int len;
  len = sizeof(char);
  printf("size of char:%d\n", len);
  printf("size of array:%d", len * size);
}