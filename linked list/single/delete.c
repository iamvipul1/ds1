#include <stdio.h>
#include <stdlib.h>

void addNode(int data);
int countNodes();
void display();
void deleteNode(int n);

struct node {
  int data;
  struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void addNode(int data) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->next = NULL;
  if (head == NULL) {
    head = newNode;
    tail = newNode;
  } else {
    tail->next = newNode;
    tail = newNode;
  }
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
void display() {
  struct node *current = head;
  if (head == NULL) {
    return;
  }
  printf("Nodes of singly linked list: \n");
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}
void deleteNode(int n) {
  if (head == NULL) {
    return;
  }
  struct node *current = head;
  if (n == 0) {
    head = head->next;
    free(current);
    return;
  }
  int i = 0;
  while (current != NULL && i < n - 1) {
    current = current->next;
    i++;
  }
  if (current == NULL || current->next == NULL) {
    return;
  }
  struct node *temp = current->next;
  current->next = temp->next;
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
  printf("Count of nodes present in the list: %d\n", countNodes());
  int n;
  printf("Enter the index of the node to be deleted (0-%d): ", no_nodes - 1);
  scanf("%d", &n);
  deleteNode(n);
  printf("Linked list after deleting node %d:\n", n);
  display();
  printf("Count of nodes present in the list: %d\n", countNodes());
  return 0;
}
