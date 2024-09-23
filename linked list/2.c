#include <stdio.h>
struct node {
  int data;
  struct node *next;
};
void print_linked_list(struct node *n);
int main() {
  int nu;
  printf("enter num of nodes:");
  scanf("%d", &nu);
  struct node *ab[nu];
  for (int i = 0; i < nu; i++) {
    ab[i] = (struct node *)malloc(sizeof(struct node));
    ab[i]->next = NULL;
  }
  printf("enter %d elements:\n", nu);
  for (int i = 0; i < nu; i++) {
    scanf("%d", &ab[i]->data);
    if (i < nu - 1) {
      ab[i]->next = ab[i + 1];
    }
  }
  printf("linked list:\n");
  print_linked_list(ab[0]);
  for (int i = 0; i < nu; i++) {
    free(ab[i]);
  }
  return 0;
}
void print_linked_list(struct node *n) {
  while (n != NULL) {
    printf("data is: %d\n", n->data);
    n = n->next;
  }
}
