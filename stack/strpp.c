#include <stdio.h>

#define SIZE 2

struct stack {
    int top;
    int data[SIZE];
};

struct stack s;

void push() {
    int item;
    printf("Enter value to push: ");
    scanf("%d", &item);
    if (s.top == SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    s.top = s.top + 1;
    s.data[s.top] = item;
}

void pop() {
    int value;
    if (s.top == -1) {
        printf("Stack underflow\n");
        return;
    }
    value = s.data[s.top];
    s.top = s.top - 1;
    printf("Popped element: %d\n", value);
}

void peek() {
    if (s.top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element: %d\n", s.data[s.top]);
}

int main() {
    s.top = -1;
    int n;
    while (1) {
        printf("Enter operation (1=push, 2=pop, 3=peek, 4=exit): ");
        scanf("%d", &n);
        switch (n) {
            case 1:
                push();
                printf("Stack elements: ");
                for (int i = s.top; i >= 0; i--) {
                    printf("%d ", s.data[i]);
                }
                printf("\n");
                break;
            case 2:
                pop();
                printf("Stack elements: ");
                for (int i = s.top; i >= 0; i--) {
                    printf("%d ", s.data[i]);
                }
                printf("\n");
                break;
            case 3:
                peek();
                break;
            case 4:
                printf("Stack elements: ");
                for (int i = s.top; i >= 0; i--) {
                    printf("%d ", s.data[i]);
                }
                printf("\n");
                return 0;
            default:
                printf("Invalid operation\n");
        }
    }
}
