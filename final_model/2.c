/* Search for the given key (target) element in the given list of positive
integers that are stored using a singly linked list.

Input:
The first line of input will contain the key element.
The subsequent lines will each contain one integer of the list.
The end of the list will be indicated through an input of -1.
Do not add the -1 itself to the list.

Output:
Display the position of the given element, if found.
If not found, display 0.

Note: Position of the first element in the list is 1 and not 0*/

#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void display(int key) {
  int count = 0;
  struct node *current = tail;
  while (current != NULL) {
    count++;
    if (current->data == key) {
      printf("%d\n", count);
      return;
    }
    current = current->next;
  }
  printf("0\n"); // Key not found
}


void addnode(int data) {
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
  int data;
  int key;
  printf("Enter key: ");
  scanf("%d", &key);

  printf("Enter numbers (-1 to end):\n");
  while (1) {
    scanf("%d", &data);
    if (data != -1) {
      addnode(data);
    } else {
      break;
    }
  }
  display(key);

  return 0;
}
