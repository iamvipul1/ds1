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
  if (head == NULL) {
    head = newNode;
    tail = newNode;
    newNode->prev = tail;
    newNode->next = head;
  } else {
    newNode->prev = tail;
    newNode->next = head;
    tail->next = newNode;
    head->prev = newNode;
    head = newNode;
  }
}

void addNodeAtEnd(int data) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = data;
  if (head == NULL) {
    head = newNode;
    tail = newNode;
    newNode->prev = tail;
    newNode->next = head;
  } else {
    newNode->prev = tail;
    newNode->next = head;
    tail->next = newNode;
    head->prev = newNode;
    tail = newNode;
  }
}

void addNodeAtMiddle(int data, int position) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = data;
  struct node *current = head;
  int i;
  for (i = 1; i < position && current->next != head; i++) {
    current = current->next;
  }
  if (current->next == head && i != position) {
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
  printf("Nodes of circular doubly linked list: \n");
  do {
    printf("%d ", current->data);
    current = current->next;
  } while (current != head);
  printf("\n");
}

int countNodes() {
  int count = 0;
  struct node *current = head;

  do {
    count++;
    current = current->next;
  } while (current != head);
  return count;
}

int delete(int index) {
  if (head == NULL) {
    printf("List is empty.\n");
    return 0;
  }

  int i;
  struct node *current = head;
  for (i = 1; i <= index && current->next != head; i++) {
    current = current->next;
  }

  if (current->next == head && i <= index) {
    printf("Index out of range.\n");
    return 0;
  }

  if (current == head) {
    head = head->next;
    tail->next = head;
    head->prev = tail;
  } else if (current == tail) {
    tail = tail->prev;
    head->prev = tail;
    tail->next = head;
  } else {
    current->prev->next = current->next;
    current->next->prev = current->prev;
  }

  free(current);
  printf("Node deleted successfully.\n");
  return 1;
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
    printf("6. delete node at index:");
    printf("7. Exit.\n");
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
  printf("Enter the index of the node to delete: \n");
  scanf("%d", &position);
  delete(position);
  break;

      case 7:
      exit(0);
      default:
      printf("Invalid choice.\n");
    }
  }
}
