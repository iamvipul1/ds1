// int data, *prev, *next
// pointers - head,tail,current
// initially all are null
// after adding first node, ptr1=head / tail / current
// ptr1->next = ptr2

#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
  struct node *prev;
};

struct node *head = NULL;
struct node *tail = NULL;

void addNode(int data) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->next = NULL;
  newNode->prev = tail;
  if (head == NULL) {
    head = newNode;
    tail = newNode;
  } else {
    tail->next = newNode;
    tail = newNode;
  }
}
void display() {
  struct node *current = head;
  if (head == NULL) {
    return;
  }
  printf("Nodes of doubly linked list: \n");
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

int countNodes() {
  int count = 0;
  struct node *current = head;

  while (current != NULL) {
    count++;
    current = current->next;
  }
  return count;
}

int main() {
  int no_nodes, i = 0, ll_data;
  printf("Enter the number of nodes you want in the linked list: ");
  scanf("%d", &no_nodes);
  while (i < no_nodes) {
    printf("Enter the data for Node %d: ", i + 1);
    scanf("%d", &ll_data);
    addNode(ll_data);
    i++;
  }
  display();
  printf("Count of nodes present in the list: %d", countNodes());
  return 0;
}
