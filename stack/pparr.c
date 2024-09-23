#include <stdio.h>
#define size 2
int a[size];
int top = -1; // stack is empty.
int push();
int pop();
int peek();
int main() 
{
    int n, data;
  while(1)
    {
printf("Enter operation (1=push, 2=pop, 3=peek, 4=exit): ");
        scanf("%d", &n);
        switch (n) 
        {
            case 1:
                push();
               printf("Stack elements: ");
                for (int i = top; i >= 0; i--)
                  {
                    printf("%d ", a[i]);
                }
                 printf("\n");
                break;
            case 2:
                data = pop();
                if (data != -1)
                {
                    printf("Popped element: %d\n", data);
                }
              printf("Stack elements: ");
                for (int i = top; i >= 0; i--)
                  {
                    printf("%d ", a[i]);
                }
                printf("\n");
                break;
            case 3:
                peek();
              printf("Stack elements: ");
                for (int i = top; i >= 0; i--)
                  {
                    printf("%d ", a[i]);
                }
                printf("\n");
                break;
            case 4:
                 printf("Stack elements: ");
                for (int i = top; i >= 0; i--) 
                {
                    printf("%d ", a[i]);
                }
                printf("\n");
                return 0;
            default:
                printf("Invalid operation\n");
        }
    }
}

int push() 
{
    int item;
    printf("Enter value to push: ");
    scanf("%d", &item);
    if (top == size - 1) {
        printf("Stack overflow\n");
    }
    top = top + 1;
    a[top] = item;
}

int pop()
{
    int value;
    if (top == -1)
    {
        printf("Stack underflow\n");
        return -1;
    }
    value = a[top];
    top = top - 1;
    return value;
}

int peek() 
{
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Top element: %d\n", a[top]);
    }
}