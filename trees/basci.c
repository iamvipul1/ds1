#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
    struct node* parent;
};

struct node* create_tree(struct node* parent, char* direction) {
    int data;
    printf("Enter the data for the %s child of node %d (or enter -1 to skip): ", direction, parent->data);
    scanf("%d", &data);
    if (data == -1) {
        return NULL;
    }
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = create_tree(newnode, "left");
    newnode->right = create_tree(newnode, "right");
    newnode->parent = parent;
    return newnode;
}

void print_tree(struct node* root) {
    if (root == NULL) {
        return;
    }
    print_tree(root->left);
    printf("%d ", root->data);
    print_tree(root->right);
}

int main() {
    int data;
    printf("Enter the data for the root node: ");
    scanf("%d", &data);
    struct node* root = (struct node*) malloc(sizeof(struct node));
    root->data = data;
    root->left = create_tree(root, "left");
    root->right = create_tree(root, "right");
    root->parent = NULL;
    print_tree(root);
    return 0;
}
