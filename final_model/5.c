/* Write a program for creating a Binary Search tree(BST) that stores a set of
positive integers. Search for the specific element in the BST.

Note: First line of input contains key elements to be searched .

Input: One integer in one line. The end of the list will be indicated through an
input of -1. Do not add the -1 itself to the list.

Output: Display FOUND, if found. If not found, display NOT FOUND */

#include <stdio.h>
#include <stdlib.h>

struct tnode {
  int data;
  struct tnode *lchild;
  struct tnode *rchild;
};
typedef struct tnode tnode;

tnode *create_tree(int val) {
  tnode *tn = (tnode *)malloc(sizeof(tnode));
  tn->data = val;
  tn->lchild = NULL;
  tn->rchild = NULL;
  return tn;
}

tnode *insert_recurse(tnode *p, int val) {
  if (p == NULL)
    p = create_tree(val);
  else if (val < p->data)
    p->lchild = insert_recurse(p->lchild, val);
  else if (val > p->data)
    p->rchild = insert_recurse(p->rchild, val);
  else
    printf("Element already exists\n");
  return p;
}

void search(tnode *p, int key) {
  if (p == NULL)
    printf("NOT FOUND\n");
  else if (key < p->data)
    search(p->lchild, key);
  else if (key > p->data)
    search(p->rchild, key);
  else {
    printf("FOUND\n");
    return;
  }
}

int main() {
  tnode *root = NULL;
  int key, input;
  scanf("%d", &key);
  scanf("%d", &input);
  while (input != -1) {
    root = insert_recurse(root, input);
    scanf("%d", &input);
  }
  search(root, key);
}
