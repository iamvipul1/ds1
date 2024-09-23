#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void addNodeAtBeginning(int data) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->next = head;
  head = newNode;
}

void addNodeAtMiddle(int data, int position) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = data;
  struct node *current = head;
  int i = 1;
  while (i < position && current != NULL) {
    current = current->next;
    i++;
  }
  if (current == NULL) {
    printf("Position does not exist\n");
    return;
  }
  newNode->next = current->next;
  current->next = newNode;
}

void addNodeAtEnd(int data) {
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

void display() {
  struct node *current = head;
  if (head == NULL) {
    printf("List is empty\n");
    return;
  }
  printf("Nodes of singly linked list: \n");
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
  int choice, data, position, count;
  while (1) {
    printf("Menu:\n");
    printf("1. Insert node at beginning\n");
    printf("2. Insert node at middle\n");
    printf("3. Insert node at end\n");
    printf("4. Display list\n");
    printf("5. Count number of nodes\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        printf("Enter data to insert at beginning: ");
        scanf("%d", &data);
        addNodeAtBeginning(data);
        break;
      case 2:
        printf("Enter data to insert: ");
        scanf("%d", &data);
        printf("Enter position to insert at: ");
        scanf("%d", &position);
        addNodeAtMiddle(data, position);
        break;
      case 3:
        printf("Enter data to insert at end: ");
        scanf("%d", &data);
        addNodeAtEnd(data);
        break;
      case 4:
        display();
        break;
      case 5:
        count = countNodes();
        printf("Count of nodes present in the list: %d\n", count);
        break;
      case 6:
        exit(0);
        break;
      default:
        printf("Invalid choice\n");
        break;
    }
  }
  return 0;
}
