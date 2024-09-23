#include <stdio.h>
#include <stdlib.h>

// define the structure of a node in a circular singly linked list
struct node {
  int data;
  struct node *next; // pointer to the next node in the list
};

// initialize the head pointer to NULL
struct node *head = NULL;

// declare function prototypes
int addbeg();
int addmid();
int addend();
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
    printf("Enter 1(add-beg), 2(add-mid), 3(add-end), "
           "5(count),6(exit), 7(del-beg), 8(del-mid), 9(del-end)\n"); // display menu
    scanf("%d", &choice);         // read user's choice
    switch (choice)               // perform action based on user's choice
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

// function to add a node to the beginning of the circular singly linked list
int addbeg() {
  int data;
  
  printf("Enter data to add in the beginning of circular single linked list: ");
  scanf("%d", &data);
  
  struct node *newnode = (struct node *)malloc(
      sizeof(struct node)); // allocate memory for new node
  
  newnode->data = data;     // set data of new node
  if (head == NULL)         // check if the list is empty
  {
    newnode->next = newnode; // set the next pointer of new node to itself
    head = newnode;       // set the head pointer to the new node
  } else {
    newnode->next = head; // set the next pointer of new node to the current head
    struct node *current = head; // Initialize a pointer to the current node as the head
    while (current->next != head) { // Traverse the list until the end of the list is reached
        current = current->next;
    }
    current->next = newnode; // Set the next pointer of the last node to the new node
  }
  head = newnode; // set the head pointer to the new node
  printf("%d added at the beginning of the circular singly linked list\n", data);
return 0; // exit the function
}

// function to add a node to the middle of the circular singly linked list
int addmid() {
int data, pos, i;

printf("Enter data to add in the middle of circular single linked list: ");
scanf("%d", &data);
printf("Enter the position at which to add the node: ");
scanf("%d", &pos);

int n = count(); // get the length of the list


struct node *newnode = (struct node *)malloc(
sizeof(struct node)); // allocate memory for new node

newnode->data = data; // set data of new node

struct node *current = head; // Initialize a pointer to the current node as the head
for (i = 1; i < pos - 1; i++) { // Traverse the list until the node before the desired position is reached
current = current->next;
}
newnode->next = current->next; // Set the next pointer of the new node to the node at the desired position
current->next = newnode; // Set the next pointer of the node before the desired position to the new node

printf("%d added at position %d of the circular single linked list\n", data, pos);
return 0; // exit the function
}

// function to add a node to the end of the circular singly linked list
int addend() {
int data;

printf("Enter data to add in the end of circular single linked list: ");
scanf("%d", &data);

struct node *newnode = (struct node *)malloc(
sizeof(struct node)); // allocate memory for new node

newnode->data = data; // set data of new node
if (head == NULL) // check if the list is empty
{
newnode->next = newnode; // set the next pointer of new node to itself
head = newnode; // set the head pointer to the new node
} else {
newnode->next = head; // set the next pointer of new node to the current head
struct node *current = head; // Initialize a pointer to the current node as the head
while (current->next != head) { // Traverse the list until the end of the list is reached
current = current->next;
}
current->next = newnode; // Set the next pointer of the last node to the new node
}

printf("%d added at the end of the circular single linked list\n", data);
return 0; // exit the function
}
// function to display the elements of the circular singly linked list
int display() {
if (head == NULL) // check if the list is empty
{
printf("List is empty!\n"); // display error message for empty list
return 0; // exit the function
}
struct node *current = head; // Initialize a pointer to the current node as the head
printf("Circular Single Linked List: ");
do {
printf("%d ", current->data); // print the data of current node
current = current->next; // move to the next node in the list
} while (current != head); // stop when the end of the list is reached
printf("\n");
return 0; // exit the function
}

// function to count the number of elements in the circular singly linked list
int count() {
if (head == NULL) // check if the list is empty
{
printf("List is empty!\n"); // display error message for empty list
return 0; // exit the function
}
int count = 0;
struct node *current = head; // Initialize a pointer to the current node as the head
do {
count++; // increment count for each node
current = current->next; // move to the next node in the list
} while (current != head); // stop when the end of the list is reached
printf("The number of elements in the circular singly linked list is %d\n", count);
return 0; // exit the function
}

// function to delete the first node of the circular singly linked list
int delbeg() {
if (head == NULL) // check if the list is empty
{
printf("List is empty!\n"); // display error message for empty list
return 0; // exit the function
}
struct node *current = head; // Initialize a pointer to the current node as the head
while (current->next != head) { // Traverse the list until the end of the list is reached
current = current->next;
}
if (head == current) { // If there is only one node in the list
head = NULL; // set the head pointer to NULL
free(current); // free memory of the current node
} else {
current->next = head->next; // Set the next pointer of the last node to the second node
free(head); // free memory of the first node
head = current->next; // set the head pointer to the second node
}
printf("The first node of the circular singly linked list has been deleted\n");
return 0; // exit the function
}
// function to delete a node from the middle of the circular singly linked list
// function to delete a node from the middle of the circular singly linked list
int delmid() {
  int pos, i;
  
  printf("Enter the position of the node to be deleted: ");
  scanf("%d", &pos);

  int n = count(); // get the length of the list
  if (pos <= 0 || pos > n) // check if position is valid
  {
    printf("Invalid position!\n"); // display error message for invalid position
    return 0; // exit the function
  }

  if (pos == 1) // special case if the node to be deleted is the head node
  {
    delbeg(); // call delbeg function to delete the head node
    return 0; // exit the function
  }

  struct node *current = head; // Initialize a pointer to the current node as the head
  struct node *prev; // Declare a pointer to the previous node
  for (i = 1; i < pos; i++) { // Traverse the list until the desired position is reached
    prev = current; // set the previous pointer to the current node
    current = current->next; // set the current pointer to the next node
  }
  prev->next = current->next; // Set the next pointer of the previous node to the next node after the current node
  free(current); // free the memory allocated for the current node

  printf("Node at position %d deleted from the circular singly linked list\n", pos);
  return 0; // exit the function
}

// function to delete a node from the end of the circular singly linked list
int delend() {
  if (head == NULL) // check if the list is empty
  {
    printf("List is empty!\n");
    return 0; // exit the function
  }

  struct node *current = head; // Initialize a pointer to the current node as the head
  struct node *prev = NULL; // Initialize a pointer to the previous node as NULL
  while (current->next != head) { // Traverse the list until the end of the list is reached
    prev = current;
    current = current->next;
  }
  if (prev != NULL) // Check if the list has more than one node
  {
    prev->next = head; // Set the next pointer of the previous node to the head node
  }
  else // If there is only one node, set head to NULL
  {
    head = NULL;
  }
  free(current); // Deallocate memory for the deleted node

  printf("Last node has been deleted from the circular singly linked list\n");
  return 0; // exit the function
}