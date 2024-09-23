#include <stdio.h>
#include <stdlib.h>
int r, n, c;
struct node {
  int data;
  struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void addnode(int data);
int countNodes();
int display();
int del(int r);
int add();

int main() {
  int n;
  printf("Enter number of nodes: ");
  scanf("%d", &n);

  int d;
  for (int i = 0; i < n; i++) {
    printf("Enter data for node %d: ", i + 1);
    scanf("%d", &d);
    addnode(d);
  }

  display();
  printf("Count of nodes present in the list: %d\n", countNodes());

  int r;
  printf("enter index(0-%d) to delete element:", n - 1);
  scanf("%d", &r);
  del(r);
  int s;
  printf("enter index(0-%d) to insert element:", n - 1);
  scanf("%d", &s);
  add();

  return 0;
}

void addnode(int data) {
  struct node *a = (struct node *)malloc(sizeof(struct node));
  a->data = data;
  a->next = NULL;
  if (head == NULL) {
    head = a;
    tail = a;
  } else {
    tail->next = a;
    tail = a;
  }
}

int display() {
  struct node *cu = head;
  if (head == NULL) {
    printf("The list is empty.\n");
    return 0;
  } else {
    printf("Nodes of singly linked list: ");
    while (cu != NULL) {
      printf("%d ", cu->data);
      cu = cu->next;
    }
    printf("\n");
    return 1;
  }
}

int countNodes() {
  int c = 0;
  struct node *cur = head;
  while (cur != NULL) {
    c++;
    cur = cur->next;
  }
  return c;
}

int del(int r) {
  if (head == NULL) {
    printf("The list is empty.\n");
    return 0;
  }
  int size = countNodes();
  if (r >= size) {
    printf("Invalid index.\n");
    return 0;
  }
  struct node *current = head;
  struct node *temp;
  if (r == 0) {
    head = head->next;
    temp = current;
  } else {
    int i = 0;
    while (i < r - 1) {
      current = current->next;
      i++;
    }
    temp = current->next;
    current->next = temp->next;
  }
  free(temp);
  printf("Node at index %d deleted.\n", r);
  display();
  return 1;
}

int add() {
  int data, pos;
  printf("Enter data for the new node: ");
  scanf("%d", &data);

  int size = countNodes();
  printf("Enter position to insert the new node (0-%d): ", size);
  scanf("%d", &pos);

  if (pos < 0 || pos > size) {
    printf("Invalid position.\n");
    return 0;
  }

  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = NULL;

  if (pos == 0) {
    new_node->next = head;
    head = new_node;
  } else {
    struct node *current = head;
    for (int i = 0; i < pos - 1; i++) {
      current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
  }

  printf("Node with data %d inserted at position %d.\n", data, pos);
  display();
  return 1;
}
