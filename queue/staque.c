#include <stdio.h>
#define size 5
void enqueue();
void dequeue();
void display();
int integer;
char character;
struct queue {
  int integer;
  char character;
};
struct queue elements[size];
int front = -1, rear = -1;
int main() {
  int choice;
  int integer;
  char character;
  while (1) {
    printf("The following operations are available: \n");
    printf("1(enqueue), 2(dequeue), 3(display), 4(exit))\n");

    scanf("%d", &choice);
    if (choice == 1) {
      printf("Enter");
      scanf("%d", &integer);
      printf("Enter character value: ");
      scanf(" %c", &character);
      enqueue(integer, character);
    } else if (choice == 2) {
      dequeue();
    } else if (choice == 3) {
      display();
    } else if (choice == 4) {
      exit(0);
    }
  }
}

void enqueue() {
  if (rear == size - 1) {
    printf("Queue is full!\n");
  } else {
    if (front == -1) {
      front = 0;
      rear++;
      elements[rear].integer = integer;
      elements[rear].character = character;
    } else {
      rear++;
      elements[rear].integer = integer;
      elements[rear].character = character;
    }
  }
  printf("The queue after pushing the elements is: \n");
  for (int i = 0; i <= rear; i++) {
    printf("(%d, %c) ", elements[i].integer, elements[i].character);
  }
}

void dequeue() {
  if (front == -1 || front > rear) {
    printf("Queue is empty!\n");
    front = -1;
    rear = -1;
  } else {
    printf("The deleted elements are: (%d, %c)\n", elements[front].integer,
           elements[front].character);
    front++;
  }
}
void display() {
  if (front == -1 || front > rear) {
    printf("Queue is empty\n");
  } else {
    printf("Queue contents: ");
    for (int i = front; i <= rear; i++) {
      printf("(%d, %c) ", elements[i].integer, elements[i].character);
    }
    printf("\n");
  }
}