#include <stdio.h>
struct node {
  int data;
  struct node *next;
};
void print_linked_list(struct node *n);
int main() {
  struct node *first = NULL;
  struct node *second = NULL;
  struct node *third = NULL;
  first = (struct node *)malloc(sizeof(struct node));
  second = (struct node *)malloc(sizeof(struct node));
  third = (struct node *)malloc(sizeof(struct node));

  int a[3];
  printf("enter 3 elements:");
  for (int i = 0; i < 3; i++) {
    scanf("%d", &a[i]);
  }
  printf("\n");

  first->data = a[0];
  first->next = second;
  second->data = a[1];
  second->next = third;
  third->data = a[2];
  third->next = NULL;
  print_linked_list(first);
  return 0;
}
void print_linked_list(struct node *n) {
  while (n != NULL) {
    printf("data is: %d\n", n->data);
    n = n->next;
  }
}
