/*
Search for the given key (target) element in the given list of positive integers that are stored using a singly linked list in which elements are added to the front of the list.
Input:
The first line of input will contain the key element.
The subsequent lines will each contain one integer of the list.
The end of the list will be indicated through an input of -1. Do not add the -1 itself to the list.
Output:
Display the position of the given element, if found. If not found, display 0.
Note:
Position of the first element in the list is 1 and not 0.
*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node node;

struct list
{
    int num_ele;
    struct node *head;
};

typedef struct list list;

list *create_list()
{
    list *llist = (list *)malloc(sizeof(list));
    llist->head = NULL;
    llist->num_ele = 0;
    return llist;
}

void add_front(list *llist, int val)
{
    node *n = (node *)malloc(sizeof(node));
    n->data = val;
    n->next = llist->head;
    llist->head = n;
    llist->num_ele++;
}

int check_fn(list *llist,int key)
{
    int pos = 0;
    if(llist->num_ele == 0)
        printf("Error:Linked list is empty\n");
    else
        {
            node *curr;
            curr = llist->head;//node *curr = llist->head
            for(int i = 1; i <= llist->num_ele; i++)
            {
                if(curr->data == key)
                {
                    pos = i;
                    break;
                }
                else
                    curr = curr->next;
            }
        }
        
    return pos;
}

int main()
{
    list *x = create_list();
    int key, input;
    scanf("%d",&key);
    scanf("%d",&input);
    while(input != -1)
    {
        add_front(x,input);
        scanf("%d",&input);
    }
    printf("%d",check_fn(x, key));
}