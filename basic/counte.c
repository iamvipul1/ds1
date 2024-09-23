/*
Count how many times ‘e’ is present among the input characters that are stored using a singly linked list. 
Input:
Each character will be input in a new (separate) line.
When the input character is a space, you can ignore the space and stop scanning for more input (i.e.) you have reached the end of the list of input characters.
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    char data;
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

void add_front(list *llist, char val)
{
    node *n = (node *)malloc(sizeof(node));
    n->data = val;
    n->next = llist->head;
    llist->head = n;
    llist->num_ele++;
}

int check_fn(list *llist)
{
    int count = 0;
    if(llist->num_ele == 0)
        printf("Error:Linked list is empty\n");
    else
        {
            node *curr;
            curr = llist->head;//node *curr = llist->head
            while(curr != NULL)
            {
                if(curr->data == 'e')
                    count++;
                curr = curr ->next;
            }
        }
    return count;
}

int main()
{
    list *x = create_list();
    char input;
    scanf("%c",&input);
    while(input != ' ')
    {
        add_front(x,input);
        scanf("%c",&input);
    }
    printf("%d",check_fn(x));
}