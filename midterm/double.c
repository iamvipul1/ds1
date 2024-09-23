#include <stdio.h>
#include <stdlib.h>

// define the structure of a node in a doubly linked list
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

  printf("Enter data to add in the beginning of double linked list: ");
  scanf("%d", &data);

  struct node *newnode = (struct node *)malloc(
      sizeof(struct node)); // allocate memory for new node

  newnode->data = data; // set data of new node
  newnode->prev = NULL; // set the previous pointer of new node to NULL
  if (head == NULL)     // check if the list is empty
  {
    newnode->next = NULL; // set the next pointer of new node to NULL
    tail = newnode;       // set the tail pointer to the new node
  } else {
    newnode->next = head; // set the next pointer of new node to the current head
    head->prev = newnode; // set the previous pointer of the current head to the new node
  }
  head = newnode; // set the head pointer to the new node
  printf("%d added at the beginning of the list.\n", data); // display message
  return 0; // return 0 to indicate success
}

int addmid() {
int data, position, i;

printf("Enter data to add in the middle of the double linked list: ");
scanf("%d", &data);

printf("Enter the position to add the node: ");
scanf("%d", &position);

if (position == 0) // check if the position is 1
{
addbeg(); // call addbeg function to add node at beginning
return 0;
}

struct node *newnode = (struct node *)malloc(
sizeof(struct node)); // allocate memory for new node
newnode->data = data; // set data of new node
struct node *temp = head;

for (i = 0; i < position - 1 && temp != NULL; i++) // loop through the list until the desired position is reached
{
temp = temp->next;
}

if (temp == NULL) // check if the desired position is out of range
{
printf("Position out of range.\n");
return 0;
}

newnode->prev = temp; // set the previous pointer of the new node to the previous node
newnode->next = temp->next; // set the next pointer of the new node to the next node
temp->next->prev = newnode; // set the previous pointer of the next node to the new node
temp->next = newnode; // set the next pointer of the previous node to the new node
printf("%d added at position %d of the list.\n", data, position);
return 0;
}

// function to add a node to the end of the list
int addend() {
int data;

printf("Enter data to add at the end of the double linked list: ");
scanf("%d", &data);

struct node *newnode = (struct node *)malloc(
sizeof(struct node)); // allocate memory for new node

newnode->data = data; // set data of new node
newnode->next = NULL; // set the next pointer of new node to NULL
if (head == NULL) // check if the list is empty
{
newnode->prev = NULL; // set the previous pointer of new node to NULL
head = newnode; // set the head pointer to the new node
} else {
newnode->prev = tail; // set the previous pointer of new node to the current tail
tail->next = newnode; // set the next pointer of the current tail to the new node
}
tail = newnode; // set the tail pointer to the new node
printf("%d added at the end of the list.\n",
data); // display
return 0;
}

// function to display the contents of the list
int display() {
  struct node *temp = head; // create a temporary pointer to traverse the list

  printf("Contents of the list: ");
  while (temp != NULL) // loop through the list until the end is reached
  {
    printf("%d ", temp->data); // display the data of the current node
    temp = temp->next;        // move to the next node
  }
  printf("\n");
}

// function to count the number of nodes in the list
int count() {
  int count = 0;
  struct node *temp = head; // create a temporary pointer to traverse the list

  while (temp != NULL) // loop through the list until the end is reached
  {
    count++;          // increment the counter
    temp = temp->next; // move to the next node
  }
  printf("Number of nodes in the list: %d\n", count);
}

// function to search for a node with a given value
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
// function to delete the node at the beginning of the list
int delbeg() {
  if (head == NULL) // check if the list is empty
  {
    printf("List is empty!\n"); // display error message
    return 0;
  } else if (head == tail) // check if the list has only one node
  {
    printf("%d deleted from the beginning of the list.\n", head->data); // display message
    free(head);                                                         // deallocate memory for head node
    head = NULL;                                                         // set the head pointer to NULL
    tail = NULL;                                                         // set the tail pointer to NULL
  } else {
    printf("%d deleted from the beginning of the list.\n", head->data); // display message
    struct node *temp = head;                                            // create a temporary pointer to the head node
    head = head->next;                                                   // set the head pointer to the next node
    head->prev = NULL;                                                   // set the previous pointer of the new head node to NULL
    free(temp);                                                          // deallocate memory for the old head node
  }
  return 0;
}

// function to delete the node at the middle of the list
int delmid() {
  if (head == NULL) // check if the list is empty
  {
    printf("List is empty!\n"); // display error message
    return 0;
  } else {
    int pos;
    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > count()) // check if the position is invalid
    {
      printf("Invalid position!\n"); // display error message
      return 0;
    } else if (pos == 1) // check if the node to be deleted is the first node
    {
      delbeg(); // call delbeg function to delete the first node
      return 0;
    } else if (pos == count()) // check if the node to be deleted is the last node
    {
      delend(); // call delend function to delete the last node
      return 0;
    } else {
      int i = 1;
      struct node *temp = head; // create a temporary pointer to the head node

      while (i < pos) // loop through the list
      {
        temp = temp->next; // move to the next node
        i++;
      }
      printf("%d deleted from the list.\n", temp->data); // display message
      temp->prev->next = temp->next;                     // set the next pointer of the previous node to the next node
      temp->next->prev = temp->prev;                     // set the previous pointer of the next node to the previous node
      free(temp);                                        // deallocate memory for the node to be deleted
      return 0;
    }
  }
}

int delend() {
  if (head == NULL) {
    printf("The list is empty.\n");
    return 0;
  } else if (head == tail) { // if there's only one node in the list
    printf("%d deleted from the list.\n", tail->data);
    free(tail);
    head = NULL;
    tail = NULL;
    return 0;
  }

  struct node *temp = tail; // temporary pointer to the last node
  tail = tail->prev;        // move tail to the previous node
  tail->next = NULL;        // set the next pointer of the new tail to NULL
  printf("%d deleted from the end of the list.\n", temp->data);
  free(temp); // free memory of the deleted node
  return 1;
}


