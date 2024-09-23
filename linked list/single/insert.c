#include <stdio.h>
#include <stdlib.h>

void addNode(int data, int index);
int countNodes();
void display();

struct node {
  int data;
  struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void addNode(int data, int index) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->next = NULL;
  if (head == NULL || index == 0) {
    newNode->next = head;
    head = newNode;
    if (tail == NULL) {
      tail = head;
    }
  } else {
    struct node *current = head;
    for (int i = 0; i < index - 1 && current->next != NULL; i++) {
      current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    if (newNode->next == NULL) {
      tail = newNode;
    }
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

int main() {
  int no_nodes, i = 0, ll_data;
  printf("Enter the number of nodes you want in the linked list: ");
  scanf("%d", &no_nodes);
  while (i < no_nodes) {
    printf("Enter the data for Node %d: ", i + 1);
    scanf("%d", &ll_data);
    addNode(ll_data, i);
    i++;
  }
  display();
  printf("Count of nodes present in the list: %d\n", countNodes());
  int n, data;
  printf("Enter index to be inserted (0-%d): ", no_nodes);
  scanf("%d", &n);
  printf("Enter data for new node: ");
  scanf("%d", &data);
  addNode(data, n);
  display();
  printf("Count of nodes present in the list: %d\n", countNodes());
  return 0;
}
