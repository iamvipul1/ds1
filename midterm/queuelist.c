#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue();
void dequeue();
void display();
void peek();

int main() {
  int n;

  while (1) {
    printf("1(enqueue), 2(dequeue), 3(exit): ");
    scanf("%d", &n);

    switch (n) {
    case 1:
      enqueue();
      peek();
      display();
      break;
    case 2:
      dequeue();
      peek();
      display();
      break;
    case 3:
      exit(0);
      break;
    default:
      printf("invalid option /!!");
      break;
    }
  }

  return 0;
}

void enqueue() {
  int data;
  printf("enter data: ");
  scanf("%d", &data);

  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data = data;
  newnode->next = NULL;

  if (front == NULL && rear == NULL) {
    front = rear = newnode;
  } else {
    rear->next = newnode;
    rear = newnode;
  }
}

void dequeue() {
  struct node *temp = front;

  if (front == NULL && rear == NULL) {
    printf("queue empty \n");
  } else {
    front = front->next;
    free(temp);
  }
}

void peek() {
  if (front == NULL && rear == NULL) {
    printf("queue empty \n");
  } else {
    printf("top element: %d \n", front->data);
  }
}

void display() {
  struct node *temp = front;

  if (front == NULL && rear == NULL) {
    printf("queue empty \n");
  } else {
    printf("queue: ");

    while (temp != NULL) {
      printf("%d ", temp->data);
      temp = temp->next;
    }

    printf("\n");
  }
}
