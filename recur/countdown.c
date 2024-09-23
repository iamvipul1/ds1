#include <stdio.h>

void countdown(int n) {
    if (n == 0) {
        printf("Countdown complete.\n");
    } else {
        printf("%d ", n);
        countdown(n - 1);
    }
}

int main() {
    int num;
    printf("Enter a number to start countdown:\n ");
    scanf("%d", &num);
    countdown(num);
    return 0;
}
