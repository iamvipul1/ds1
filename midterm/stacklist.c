#include <stdio.h>
#include <stdlib.h>
struct node {
  int data;
  struct node *next;
};
struct node *top = 0;
void push();
void pop();
void display();
void peek();
int main() {
  int n;
  while (1) {
    printf("1(push), 2(pop), 3(exit): ");
    scanf("%d", &n);
    switch (n) {
    case 1:
      push();
      peek();
      display();
      break;
    case 2:
      pop();
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
void push() {
  int data;
  printf("enter data to push:");
  scanf("%d", &data);
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data = data;
  newnode->next = top;
  top = newnode;
}

void pop() {
  struct node *temp = top;
  if (top == 0) {
    printf("stack empty");
  } else {
    printf("top element is %d\n", top->data);
    top = top->next;
    free(temp);
  }
}

void peek() {
  if (top == 0) {
    printf("stack empty\n");
  } else {
    printf("top element is:%d\n", top->data);
  }
}
void display() {
  struct node *temp = top;
  if (top == NULL) {
    printf("stack underflow!!\n");
  } else {
    printf("stack elements:");
    while (temp != 0) {
      printf(" %d  ", temp->data);
      temp = temp->next;
    }
  }
}