#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
  struct node *prev;
};

struct node *head = NULL;
struct node *tail = NULL;

void addNodeAtBeginning(int data) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->next = head;
  newNode->prev = NULL;
  if (head == NULL) {
    head = newNode;
    tail = newNode;
  } else {
    head->prev = newNode;
    head = newNode;
  }
}

void addNodeAtEnd(int data) {
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

void addNodeAtMiddle(int data, int position) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = data;
  struct node *current = head;
  int i;
  for (i = 1; i < position && current != NULL; i++) {
    current = current->next;
  }
  if (current == NULL) {
    printf("Invalid position.\n");
    return;
  }
  newNode->next = current;
  newNode->prev = current->prev;
  current->prev->next = newNode;
  current->prev = newNode;
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
  int choice, ll_data, position;
  while (1) {
    printf("Choose an option:\n");
    printf("1. Insert at beginning.\n");
    printf("2. Insert at end.\n");
    printf("3. Insert at middle.\n");
    printf("4. Display.\n");
    printf("5. Count nodes.\n");
    printf("6. Exit.\n");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Enter the data to be inserted: ");
      scanf("%d", &ll_data);
      addNodeAtBeginning(ll_data);
      break;
    case 2:
      printf("Enter the data to be inserted: ");
      scanf("%d", &ll_data);
      addNodeAtEnd(ll_data);
      break;
    case 3:
      printf("Enter the data to be inserted: ");
      scanf("%d", &ll_data);
      printf("Enter the position to insert at: ");
      scanf("%d", &position);
      addNodeAtMiddle(ll_data, position);
      break;
    case 4:
      display();
      break;
    case 5:
      printf("Count of nodes present in the list: %d\n", countNodes());
      break;
    case 6:
      exit(0);
    default:
      printf("Invalid choice.\n");
    }
  }
}
