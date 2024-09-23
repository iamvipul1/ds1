/*
Count how many times ‘e’ is present among the input characters that are stored
using a singly linked list.

Input:
Each character will be input in a new (separate) line.
When the input character is a space, you can ignore the space and stop scanning
for more input (i.e.) you have reached the end of the list of input characters.
Output:
An integer
*/
#include <stdio.h>
#include <stdlib.h>

struct node {
  char data;
  struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void count() {
  int count = 0;
  struct node *current = head;
  while (current != NULL) {
    if (current->data == 'e') {
      count++;
    }
    current = current->next;
  }
  printf("%d\n", count);
}

void addnode(char data) {
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data = data;
  newnode->next = NULL;

  if (head == NULL) {
    head = newnode;
    tail = newnode;
  } else {
    newnode->next = head;
    head = newnode;
  }
}

int main() {
  char data;

  printf("Enter characters (end with space):\n");
  while (1) {
    scanf(" %c", &data);
    if (data != 's') {
      addnode(data);
    } else {
      break;
    }
  }
  
  count();

  return 0;
}

