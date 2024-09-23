#include <stdio.h>
#define size 10
struct stack {
    int top;
    int data[size];
};
struct stack s;
int element;
void push() {
    s.top = s.top + 1;
    s.data[s.top] = element;
}
int pop() {
    int item = s.data[s.top];
    s.top--;
    return item;
}
int main() {
    s.top = -1;
    printf("Enter 10 array elements: ");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &s.data[i]);
    }
    for (int i = 0; i < 10; i++) {
        if (s.data[i] % 5 == 0) {
            element = s.data[i];
            push();
            printf("\n\nPopped element is %d", s.data[s.top]);
            printf("\nStack elements: ");
            for (int j = 0; j <= s.top; j++) {
                printf("%d ", s.data[j]);
            }
            if (s.data[s.top] == 5 || s.data[s.top] == 25) {
                pop();
            }
        }
    }
}