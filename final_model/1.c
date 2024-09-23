/*
Write a program that reverses a given list of characters.

Store the characters choosing a suitable data structure and perform the reversal
of the input stored in the data structure.

Input:
Each character will be input in a new (separate) line.
When the input character is a '.', you can ignore the '.' and stop scanning for
more input (i.e.) you have reached the end of the list of characters.

Output:
Display the characters, each in a new line, in reverse order.
*/
#include <stdio.h>
#include <stdlib.h>

struct node {
  char data;
  struct node *next;
};

struct node *head = NULL;

void display() {
  struct node *current = head;
  while (current != NULL) {
    printf("%c\n", current->data);
    current = current->next;
  }
}

void addnode(char data) {
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data = data;
  newnode->next = NULL;

  if (head == NULL) {
    head = newnode;
  } else {
    newnode->next = head;
    head = newnode;
  }
}

int main() {
  char data;
  printf("Enter characters (enter '.' to end):\n");
  while (1) {
    scanf(" %c", &data);
    if (data != '.') {
      addnode(data);
    } else {
      break;
    }
  }
  printf("\nReversed List:\n");
  display();

  return 0;
}
