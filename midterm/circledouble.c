#include <stdio.h>
#include <stdlib.h>

// define the structure of a node in a circular doubly linked list
struct node {
  int data;
  struct node *prev; // pointer to the previous node in the list
  struct node *next; // pointer to the next node in the list
};

// initialize the head and tail pointers to NULL
struct node *head = NULL;
struct node *tail = NULL;

// declare function prototypes
int addbeg();
int addmid();
int addend();
int search();
int display();
int count();
int delbeg();
int delmid();
int delend();
int choice;

// main function
int main() {
  while (1) // loop indefinitely
  {
    printf("Enter 1(add-beg), 2(add-mid), 3(add-end), 4(search), "
           "5(count),6(exit), 7(del-beg), 8(del-mid), 9(del-end)\n"); // display
                                                                      // menu
    scanf("%d", &choice); // read user's choice
    switch (choice)       // perform action based on user's choice
    {
    case 1:
      addbeg();  // call addbeg function
      display(); // call display function to show updated list
      break;
    case 2:
      addmid();  // call addmid function
      display(); // call display function to show updated list
      break;
    case 3:
      addend();  // call addend function
      display(); // call display function to show updated list
      break;
    case 4:
      search();
      display();
      break;
    case 5:
      count(); // call count function
      break;
    case 6:
      exit(0); // exit the program
      break;
    case 7:
      delbeg();
      display();
      break;
    case 8:
      delmid();
      display();
      break;
    case 9:
      delend();
      display();
      break;
    default:
      printf("Invalid choice!\n"); // display error message for invalid choice
      break;
    }
  }
  return 0; // exit the program
}

// function to add a node to the beginning of the list
int addbeg() {
  int data;

  printf("Enter data to add in the beginning of circular double linked list: ");
  scanf("%d", &data);

  struct node *newnode = (struct node *)malloc(
      sizeof(struct node)); // allocate memory for new node

  newnode->data = data; // set data of new node
  if (head == NULL) { // check if the list is empty
    newnode->prev = newnode; // set the previous pointer of new node to itself
    newnode->next = newnode; // set the next pointer of new node to itself
    tail = newnode; // set the tail pointer to the new node
  } else {
    newnode->prev = tail; // set the previous pointer of new node to tail
    newnode->next = head; // set the next pointer of new node to head
    head->prev = newnode; // set the previous pointer of the current head to new node
    tail->next = newnode; // set the next pointer of the tail to new node
  }
  head = newnode; // set the head pointer to the new node
  return 0; // return 0 to indicate success
}
// function to add a node at a specified position in the list
int addmid() {
  int pos, data, i;
  printf("Enter position at which you want to add a node: ");
  scanf("%d", &pos);

  printf("Enter data to add at position %d: ", pos);
  scanf("%d", &data);

  struct node *newnode = (struct node *)malloc(sizeof(struct node)); // allocate memory for new node
  newnode->data = data; // set data of new node

  if (head == NULL) { // check if the list is empty
    printf("List is empty, cannot add at specified position\n");
    return 0;
  }

  struct node *temp = head; // set a temporary pointer to traverse the list
  for (i = 1; i < pos - 1; i++) { // traverse the list to the specified position
    temp = temp->next; // move the pointer to the next node
    if (temp == head) { // check if the end of the list has been reached
      printf("Specified position is out of range, cannot add at position %d\n", pos);
      return 0;
    }
  }

  newnode->prev = temp; // set the previous pointer of new node to the previous node
  newnode->next = temp->next; // set the next pointer of new node to the next node
  temp->next->prev = newnode; // set the previous pointer of the next node to the new node
  temp->next = newnode; // set the next pointer of the previous node to the new node

  printf("Node with data %d added at position %d\n", data, pos);
  return 1;
}

// function to add a node at the end of the list
int addend() {
  int data;
  printf("Enter data to add at the end of circular double linked list: ");
  scanf("%d", &data);

  struct node *newnode = (struct node *)malloc(sizeof(struct node)); // allocate memory for new node
  newnode->data = data; // set data of new node

  if (head == NULL) { // check if the list is empty
    newnode->prev = newnode; // set the previous pointer of new node to itself
    newnode->next = newnode; // set the next pointer of new node to itself
    head = newnode; // set the head pointer to the new node
    tail = newnode; // set the tail pointer to the new node
  } else {
    newnode->prev = tail; // set the previous pointer of new node to the tail node
    newnode->next = head; // set the next pointer of new node to the head node
    tail->next = newnode; // set the next pointer of the tail node to the new node
    head->prev = newnode; // set the previous pointer of the head node to the new node
    tail = newnode; // set the tail pointer to the new node
  }

  printf("Node with data %d added at the end\n", data);
  return 1;
}
// function to display the contents of the list
int display() {
  struct node *current; // declare a pointer to traverse the list

  if (head == NULL) { // check if the list is empty
    printf("List is empty!\n");
    return 0;
  }

  printf("The contents of the list are: ");

  current = head; // start from the head of the list
  do {
    printf("%d ", current->data); // print the data of the current node
    current = current->next; // move to the next node
  } while (current != head); // loop until we reach the head again

  printf("\n");

  return 0;
}

// function to count the number of nodes in the list
int count() {
  int count = 0; // initialize count to zero
  struct node *current; // declare a pointer to traverse the list

  if (head == NULL) { // check if the list is empty
    printf("List is empty!\n");
    return 0;
  }

  current = head; // start from the head of the list
  do {
    count++; // increment the count
    current = current->next; // move to the next node
  } while (current != head); // loop until we reach the head again

  printf("The number of nodes in the list is: %d\n", count);

  return 0;
}

// function to search for a node in the list
int search() {
  int data; // declare a variable to hold the data to search for
  int position = 1; // initialize position to 1
  struct node *current; // declare a pointer to traverse the list

  if (head == NULL) { // check if the list is empty
    printf("List is empty!\n");
    return 0;
  }

  printf("Enter the data to search for: ");
  scanf("%d", &data); // read the data to search for from the user

  current = head; // start from the head of the list
  do {
    if (current->data == data) { // check if the data matches
      printf("Data found at position %d\n", position);
      return position;
    }
    position++; // increment the position
    current = current->next; // move to the next node
  } while (current != head); // loop until we reach the head again

  printf("Data not found in the list!\n");

  return 0;
}
// function to delete the first node from the list
int delbeg() {
  if (head == NULL) { // check if the list is empty
    printf("List is empty!\n");
    return 0;
  }
  else if (head == tail) { // check if there is only one node in the list
    free(head); // free the memory allocated for the node
    head = NULL; // set the head pointer to NULL
    tail = NULL; // set the tail pointer to NULL
  }
  else { // there are more than one node in the list
    struct node *temp = head; // create a temporary pointer to the first node
    head = head->next; // update the head pointer to the second node
    head->prev = tail; // set the previous pointer of the new head to the tail
    tail->next = head; // set the next pointer of the tail to the new head
    free(temp); // free the memory allocated for the first node
  }
  printf("Deleted the first node from the list.\n");
  return 1;
}
// function to delete a node from the middle of the list
int delmid() {
  int pos, i;
  struct node *temp, *prev, *cur;

  if (head == NULL) { // check if the list is empty
    printf("List is empty!\n");
    return 0;
  }

  printf("Enter position of node to delete from the middle: ");
  scanf("%d", &pos);

  if (pos == 1) { // if position is 1, call delbeg function to delete first node
    delbeg();
    return 0;
  }

  cur = head;
  for (i = 1; i < pos; i++) { // traverse the list to find the node to delete
    prev = cur;
    cur = cur->next;
    if (cur == head) { // if end of list is reached before finding the node, display error message and return
      printf("Invalid position!\n");
      return 0;
    }
  }

  prev->next = cur->next; // set the next pointer of the previous node to the next node of the node to be deleted
  cur->next->prev = prev; // set the previous pointer of the next node to the previous node of the node to be deleted
  if (cur == tail) { // if the node to be deleted is the tail node, update the tail pointer to the previous node
    tail = prev;
  }
  free(cur); // free the memory occupied by the node to be deleted

  printf("Node deleted successfully from the middle!\n");
  return 1;
}

// function to delete a node from the end of the list
int delend() {
  struct node *temp;

  if (head == NULL) { // check if the list is empty
    printf("List is empty!\n");
    return 0;
  }

  if (head->next == head) { // if list contains only one node, delete the node and set head and tail pointers to NULL
    temp = head;
    head = NULL;
    tail = NULL;
    free(temp);
    printf("Node deleted successfully from the end!\n");
    return 1;
  }

  temp = tail; // set temp pointer to the tail node
  tail = tail->prev; // update the tail pointer to the previous node
  tail->next = head; // set the next pointer of the new tail node to the head node
  head->prev = tail; // set the previous pointer of the head node to the new tail node
  free(temp); // free the memory occupied by the tail node

  printf("Node deleted successfully from the end!\n");
  return 1;
}
