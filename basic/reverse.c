/*
Write a program that reverses a given list of characters. Store the characters choosing a suitable data structure and perform the reversal of the input stored in the data structure.
Input:
Each character will be input in a new (separate) line.
When the input character is a '.', you can ignore the '.' and stop scanning for more input (i.e.) you have reached the end of the list of characters.
Output:
Display the characters, each in a new line, in reverse order.
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

void display(list *llist)
{
    if(llist->num_ele == 0)
        printf("Error:Linked list is empty\n");
    else
        {
            node *curr;
            curr = llist->head;//node *curr = llist->head;
            while(curr != NULL)
            {
                printf("%c\n",curr->data);//do NOT give space before %c
                curr = curr->next;
            }
        }
}

int main()
{
    list *x = create_list();
    char input;
    scanf(" %c",&input);//give space before %c
    while(input != '.')
    {
        add_front(x,input);
        scanf(" %c",&input);//give space before %c
    }
    display(x);
}