/*
Vowel shooter, using a queue implemented as an array.

Store the input characters choosing a suitable data structure such that when the input character is a vowel, remove the first of the currently remaining input characters from the data structure.

Do not add the vowel itself to the data structure. 

When the input character is a ‘.’, display the elements in the data structure and end the game (program).

If there are no elements at all in the data structure at the time of display, display EMPTY. Implement the data structure using an array.

Input:
Each character will be input in a new (separate) line.

Output:
Display the characters, each in a new line. If there are no characters at all in the data structure, display EMPTY
*/
#include<stdio.h>
#include<stdlib.h>
#define size 10
char queue[size];
int front = -1;
int rear = -1;

void enqueue(char ele)
{
    if(front == -1)
        front = 0;
    queue[++rear]= ele;
}

void dequeue()
{
    if(front == -1)
    {
        //do nothing
    }
    else
        front++;
}

void display()
{
    if(front == -1|| front>rear)
        printf("EMPTY\n");
    else
    {
        for(int i = front; i <= rear; i++)
        printf("%c\n",queue[i]);
    }
}

int main()
{
    char ele;
    scanf(" %c",&ele);
    while(ele!='.')
    {
        if(ele == 'A'||ele == 'E'||ele == 'I'||ele == 'O'||ele == 'U')
            dequeue();
        else
            enqueue(ele);
        scanf(" %c",&ele);
    }
    display();
}