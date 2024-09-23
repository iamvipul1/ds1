#include <stdio.h>
int top = -1;
int main() {
    int num[10], div[10], choice = 0, peek_ele;
    printf("Enter 10 array elements: ");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &num[i]);
    }
    for (int i = 0; i < 10; i++) {
        if (num[i] % 5 == 0) {
            top++;
            div[top] = num[i];
            printf("\n\nPopped element is %d", div[top]);
            printf("\nStack elements: ");
            for (int j = 0; j <= top; j++)
                printf("%d ", div[j]);
            if (div[top] == 5 || div[top] == 25)
                top--;
        }
    }
}