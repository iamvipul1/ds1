#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node *createNode(int data);
struct node *insert(struct node *root, int data);

void preorder(struct node *root);
void postorder(struct node *root);
void inorder(struct node *root);
int min(struct node *root);
int max(struct node *root);
void search(struct node *root);

int main() {
  struct node *root = NULL;
  root = insert(root, 70);
  root = insert(root, 55);
  root = insert(root, 88);
  root = insert(root, 34);
  root = insert(root, 60);
  root = insert(root, 74);
  root = insert(root, 90);
  root = insert(root, 75);

  printf("pre-order: ");
  preorder(root);
  printf("\n");

  printf("post-order: ");
  postorder(root);
  printf("\n");

  printf("in-order: ");
  inorder(root);
  printf("\n");

  int minimum = min(root);
  printf("Minimum value of inorder: %d\n", minimum);

  int maximum = max(root);
  printf("Maximum value of inorder: %d\n", maximum);

  search(root);

  return 0;
}

struct node *createNode(int data) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

struct node *insert(struct node *root, int data) {
  if (root == NULL) {
    return createNode(data);
  }

  if (data < root->data) {
    root->left = insert(root->left, data);
  } else if (data > root->data) {
    root->right = insert(root->right, data);
  }

  return root;
}

void preorder(struct node *root) {
  if (root == NULL) {
    return;
  }
  printf("%d ", root->data);
  preorder(root->left);
  preorder(root->right);
}

void postorder(struct node *root) {
  if (root == NULL) {
    return;
  }
  postorder(root->left);
  postorder(root->right);
  printf("%d ", root->data);
}

void inorder(struct node *root) {
  if (root == NULL) {
    return;
  }
  inorder(root->left);
  printf("%d ", root->data);
  inorder(root->right);
}

int min(struct node *root) {
  struct node *temp = root;
  while (temp != NULL && temp->left != NULL) {
    temp = temp->left;
  }
  if (temp != NULL) {
    return temp->data;
  }
  return 0;
}

int max(struct node *root) {
  struct node *temp = root;
  while (temp != NULL && temp->right != NULL) {
    temp = temp->right;
  }
  if (temp != NULL) {
    return temp->data;
  }
  return 0;
}

void search(struct node *root) {
  int key;
  printf("Enter data to search in the tree: ");
  scanf("%d", &key);

  struct node *temp = root;
  while (temp != NULL) {
    if (key == temp->data) {
      printf("Data %d found in the tree.\n", key);
      return;
    } else if (key < temp->data) {
      temp = temp->left;  // Traverse to the left subtree
    } else {
      temp = temp->right; // Traverse to the right subtree
    }
  }
  printf("Data %d not found in the tree.\n", key);
}
