#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

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

int main() {
  while (1) {
    printf("Enter 1(add-beg), 2(add-mid), 3(add-end),4(search), 5(count), 6(exit), 7(del-beg), 8(del-mid), 9(del-end)\n");
    scanf("%d", &choice);         
    switch (choice) {               
      case 1:
        addbeg();  
        display(); 
        break;
      case 2:
        addmid();  
        display(); 
        break;
      case 3:
        addend();  
        display(); 
        break;
      case 4:
          search();
        display(); 
        break;
      case 5:
count();
        break;
      case 6:
        exit(0); 
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
        printf("Invalid choice!\n"); 
        break;
    }
  }
  return 0; 
}

int addbeg() {
  int data;
    printf("Enter data: ");
        scanf("%d", &data);
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = data;
  if (head == NULL) {
    new_node->next = new_node;
    head = new_node;
    tail = new_node;
  } else {
    new_node->next = head;
    head = new_node;
    tail->next = head;
  }
  return 0;
}

int addmid() {
  int pos,data;
  printf("Enter position: ");
        scanf("%d", &pos);
        printf("Enter data: ");
        scanf("%d", &data);
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = data;
  if (head == NULL) {
    printf("List is empty!\n");
  }
  struct node *current = head;
  for (int i = 1; i < pos - 1; i++) {
    if (current->next == head) {
      printf("Position out of range!\n");
    }
    current = current->next;
  }
  new_node->next = current->next;
  current->next = new_node;
  if (current == tail) {
    tail = new_node;
  }
  return 0;
}

int addend() {
  int data;
          printf("Enter data: ");
        scanf("%d", &data);
struct node *new_node = (struct node *)malloc(sizeof(struct node));
new_node->data = data;
if (head == NULL) {
new_node->next = new_node;
head = new_node;
tail = new_node;
} else {
tail->next = new_node;
new_node->next = head;
tail = new_node;
}
return 0;
}

int display() {
if (head == NULL) {
printf("List is empty!\n");
}
struct node *current = head;
printf("List: ");
do {
printf("%d ", current->data);
current = current->next;
} while (current != head);
printf("\n");
return 0;
}

int count() {
int count = 0;
if (head == NULL) {
return count;
}
struct node *current = head;
 while (current != head){
  count++;
current = current->next;
}
return count;
}

int delbeg() {
  if (head == NULL) {
    printf("List is empty!\n");
    return 0;  // Add a return statement
  }
  struct node *temp = head;
  head = head->next;
  tail->next = head;
  free(temp);
  return 0;
}

int delmid() {
  int pos;
      printf("Enter position: ");
        scanf("%d", &pos);
  if (head == NULL) {
    printf("List is empty!\n");
    return 0;  // Add a return statement
  }
  struct node *current = head;
  for (int i = 0; i < pos - 1; i++) {
    if (current->next == head) {
      printf("Position out of range!\n");
      return 0;  // Add a return statement
    }
    current = current->next;
  }
  if (current->next == tail) {
    tail = current;
  }
  struct node *temp = current->next;
  current->next = temp->next;
  free(temp);
  return 0;
}

int delend() {
  if (head == NULL) {
    printf("List is empty!\n");
    return 0;  // Add a return statement
  }
  struct node *current = head;
  while (current->next != tail) {
    current = current->next;
  }
  current->next = head;
  free(tail);
  tail = current;
  return 0;
}

int search(){
  struct node *temp = head;
  int pos = 0;
  int key;
  printf("Enter the data you want to search: ");
  scanf("%d", &key);
  while (temp != tail) {
    if (temp->data == key) {
      printf("Data found at position %d.\n", pos);
      return 0;
    }
    temp = temp->next;
    pos++;
  }
  if (temp->data == key) {  // check last node
    printf("Data found at position %d.\n", pos);
    return 0;
  }
  printf("Data not found.\n");
  return 0;
}
