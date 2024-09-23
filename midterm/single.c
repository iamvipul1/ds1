#include <stdio.h>
#include <stdlib.h>

// define the structure of a node in a singly linked list
struct node {
  int data;
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

  printf("Enter data to add in the beginning of single linked list: ");
  scanf("%d", &data);

  struct node *newnode = (struct node *)malloc(
      sizeof(struct node)); // allocate memory for new node

  newnode->data = data; // set data of new node
  if (head == NULL)     // check if the list is empty
  {
    newnode->next = NULL; // set the next pointer of new node to NULL
    tail = newnode;       // set the tail pointer to the new node
  } else {
    newnode->next =
        head; // set the next pointer of new node to the current head
  }
  head = newnode; // set the head pointer to the new node
  printf("%d added at the beginning of the list.\n",
         data); // display success message
  return 0;
}

// Function to add a node in the middle of a singly linked list
int addmid() {
  // Declare variables to hold the data and position of the new node
  int data, position;
  printf("Enter data to add in the middle of single linked list: ");
  scanf("%d", &data);
  printf("Enter position to insert: ");
  scanf("%d", &position);

  // Allocate memory for the new node
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data = data; // Set the data of the new node

  // Initialize a pointer to the current node as the head
  struct node *current = head;

  // Traverse the list until the desired position or the end of the list is
  // reached
  int i = 0;
  while (i < position - 1 && current->next != NULL) {
    current = current->next; // Move the pointer to the next node
    i++;                     // Increment the counter
  }

  // If the current pointer is NULL, the position is invalid
  if (current == NULL) {
    printf("Invalid position!\n"); // Display error message
    free(newnode);                 // Free the memory allocated for the new node
    return 0;
  } else {
    // Set the next pointer of the new node to the next node of the current node
    newnode->next = current->next;

    // Set the next pointer of the current node to the new node
    current->next = newnode;

    // Display success message
    printf("%d added at position %d of the list.\n", data, position);

    return 0;
  }
}

// function to add a node to the end of the list
int addend() {
  int data;
  printf("Enter data to add in the end of single linked list: ");
  scanf("%d", &data);
  struct node *newnode = (struct node *)malloc(
      sizeof(struct node)); // allocate memory for new node
  newnode->data = data;     // set data of new node
  newnode->next = NULL;     // set the next pointer of new node to NULL
  if (head == NULL)         // check if the list is empty
  {
    head = newnode; // set the head pointer to the new node
    tail = newnode; // set the tail pointer to the new node
  } else {
    tail->next =
        newnode;    // set the next pointer of the current tail to the new node
    tail = newnode; // set the tail pointer to the new node
  }
  printf("%d added at the end of the list.\n", data); // display success message
  return 0;
}

int delbeg() {
  if (head == NULL) {
    printf("List is empty\n");
  }
  struct node *temp = head;
  head = head->next;
  if (head == NULL) {
    tail = NULL;
  }
  free(temp);
}

int delmid() {
  int position;
  printf("Enter position to delete at: ");
  scanf("%d", &position);
  if (head == NULL) {
    printf("List is empty\n");
  }
  struct node *current = head, *previous = NULL;
  int i = 0;
  while (i < position && current != NULL) {
    previous = current;
    current = current->next;
    i++;
  }
  if (current == NULL) {
    printf("Position does not exist\n");
  }
  if (current == head) {
    head = head->next;
  } else {
    previous->next = current->next;
  }
  if (current == tail) {
    tail = previous;
  }
  free(current);
}

int delend() {
  if (head == NULL) {
    printf("List is empty\n");
  }
  struct node *current = head, *previous = NULL;
  while (current->next != NULL) {
    previous = current;
    current = current->next;
  }
  if (current == head) {
    head = NULL;
    tail = NULL;
  } else {
    previous->next = NULL;
    tail = previous;
  }
  free(current);
}
// function to display the list
int display() {
  if (head == NULL) // check if the list is empty
  {
    printf("List is empty.\n");
    return 0;
  } else {
    struct node *current =
        head; // initialize a pointer to the current node as the head
    printf("The list is: ");
    while (current != NULL) // traverse the list until the end is reached
    {
      printf("%d ", current->data); // display the data of the current node
      current = current->next;      // move the pointer to the next node
    }
    printf("\n");
    return 0;
  }
}

// function to count the number of nodes in the list
int count() {
  int count = 0;
  struct node *current =
      head; // initialize a pointer to the current node as the head
  while (current != NULL) // traverse the list until the end is reached
  {
    count++;                 // increment the count
    current = current->next; // move the pointer to the next node
  }
  printf("The number of nodes in the list is %d.\n",
         count); // display the count
  return 0;
}

int search() {
  struct node *temp = head;
  int pos = 1;
  int key;
  printf("enter the data you want to search:");
  scanf("%d", &key);
  while (temp != NULL) {
    if (temp->data == key) {
      printf("Element found at position %d\n", pos);
      return 0;
    }

    pos++;
    temp = temp->next;
  }

  printf("Element not found in the list\n");
}