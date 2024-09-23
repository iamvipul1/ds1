// rear = -1 - insertion,,,,,enqueue - r++
// front = -1 - deletion ,,,,dequeue - f++
// f=r = -1 - queue is empty
#include <stdio.h>
#define size 5

int re = -1;
int fr = -1;
int a[size];

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
  if (re == size - 1) {
    printf("Queue full\n");
    return -1;
  }
  if (fr == -1) {
    fr = 0;
  }
  printf("Enter: ");
  scanf("%d", &data);
  re++;
  a[re] = data;
  return 0;
}

int dequeue() {
  if (fr == -1 || fr > re) {
    printf("Queue empty\n");
    return -1;
  }
  printf("Dequeued element: %d\n", a[fr]);
  fr++;
  return 0;
}

int peek() {
  if (fr == -1 || fr > re) {
    printf("Queue empty\n");
  }
  return a[fr];
}
int display() {
  printf("queue elements:");
  for (int i = fr; i <= re; i++) {
    printf("%d", a[i]);
  }
  printf("\n");
}
