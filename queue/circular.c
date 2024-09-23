#include <stdio.h>
#define size 5

int rear = -1;
int front = -1;
int queue[size];

int enqueue();
int dequeue();
int peek();
int display();

int main() {
  int n;
  while (1) {
    printf("Enter 1 (enqueue), 2 (dequeue), 3 (peek), 4(exit): ");
    scanf("%d", &n);
    switch (n) {
    case 1:
      enqueue();
      display();
      break;
    case 2:
      dequeue();
      display();
      break;
    case 3:
      printf("Front element : %d\n", peek());
      printf("\n");
      display();
      break;
    case 4:
      display();
      return 0;
      break;
    default:
      printf("Invalid option!\n");
      break;
    }
  }
  return 0;
}

int enqueue() {
  int data;
  if ((rear == size - 1) && front == 0) {
    printf("Queue full\n");
    return -1;
  }
  if (front == -1) {
    front = 0;
  }
  printf("Enter: ");
  scanf("%d", &data);
  if (rear == size - 1 && front != 0) {
    rear = -1;
  }
  rear++;
  queue[rear] = data;
  return 0;
}
int dequeue() {
  if (front == -1) {
    printf("Queue empty\n");
    return -1;
  }
  int data = queue[front];
  if (front == rear) {
    front = -1;
    rear = -1;
  } else if (front == size - 1) {
    front = 0;
  } else {
    front++;
  }
  printf("Dequeued element: %d\n", data);
  return 0;
}
int peek() {
  if (front == -1) {
    printf("Queue empty\n");
  }
  return queue[front];
}
int display() {
  if (front == -1) {
    printf("Queue empty\n");
    return -1;
  }
  printf("Queue elements: ");
  int i;
  if (rear >= front) {
    for (i = front; i <= rear; i++) {
      printf("%d ", queue[i]);
    }
  } else {
    for (i = front; i < size; i++) {
      printf("%d ", queue[i]);
    }
    for (i = 0; i <= rear; i++) {
      printf("%d ", queue[i]);
    }
  }
  printf("\n");
  return 0;
}