#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void begin() {
  int data;
  printf("enter data to insert at beg:");
  scanf("%d", &data);
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data = data;
  newnode->next = head;
  head = newnode;
}

void midin() {
  struct node *current = head;
  int data, pos;
  printf("enter position to insert data:");
  scanf("%d", &pos);
  printf("enter data to insert in middle:");
  scanf("%d", &data);
  int i = 0;
  while (i < pos - 1 && current != NULL) {
    current = current->next;
    i++;
  }
  if (current == NULL && i != pos - 1) {
    printf("no position\n");
  } else {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    if (pos == 1) {
      newnode->next = head;
      head = newnode;
    } else {
      newnode->next = current->next;
      current->next = newnode;
    }
  }
}

void endin() {
  int data;
  printf("enter data to insert at end:");
  scanf("%d", &data);
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
    printf("list empty\n");
  } else {
    printf("Nodes of singly linked list: \n");
    while (current != NULL) {
      printf("%d ", current->data);
      current = current->next;
    }
    printf("\n");
  }
}

void count() {
  struct node *current = head;
  int count = 0;
  while (current != NULL) {
    count++;
    current = current->next;
  }
  printf("number of nodes in list are: %d \n", count);
}

void delbeg() {
  if (head == NULL) {
    printf("empty list\n");
  } else {
    struct node *current = head;
    head = head->next;
    free(current);
  }
}

void delmid() {
  if (head == NULL) {
    printf("empty list\n");
  } else {
    struct node *current = head, *prev = NULL;
    int pos, i = 0;
    printf("enter position to delete:");
    scanf("%d", &pos);
    while (current != NULL && i < pos - 1) {
      prev = current;
      current = current->next;
      i++;
    }
    if (current == NULL && i != pos - 1) {
      printf("no position\n");
    } else {
      if (pos == 1) {
        head = current->next;
      } else if (current == tail) {
        tail = prev;
        prev->next = NULL;
      } else {
        prev->next = current->next;
      }
      free(current);
    }
  }
}

void delend() {
  if (head == NULL) {
    printf("empty list\n");
  } else if (head->next == NULL) {
    free(head);
    head = NULL;
    tail = NULL;
  } else {
    struct node *current = head, *prev = NULL;
    while (current->next != NULL) {
      prev = current;
      current = current->next;
    }
    free(current);
    prev->next = NULL;
    tail = prev;
  }
}

int main() {
  int n;
  while (1) {
    printf("1(begin),2(midin),3(endin),\n 4(display),5(count),\n 6(delbeg), "
           "7(delmid), 8(delend)\n 9(exit) :");
    scanf("%d", &n);
    switch (n) {
    case 1:
      begin();
      break;
    case 2:
      midin();
      break;
    case 3:
      endin();
      break;
    case 4:
      display();
      break;
    case 5:
      count();
      break;
    case 6:
      delbeg();
      break;
    case 7:
      delmid();
      break;
    case 8:
      delend();
      break;
    case 9:
      exit(0);
    default:
      printf("invalid choice\n");
    }
  }
  return 0;
}
