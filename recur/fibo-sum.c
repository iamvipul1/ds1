#include <stdio.h>

int fibo(int num, int a, int b)
{
    if (num == 0)
    {
        return a;
    }
    else
    {
        int c = a + b;
        return c + fibo(num-1, b, c);
    }
}

int main()
{
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    int sum = fibo(n-1, 0, 1);
    printf(" sum is %d", sum);

    return 0;
}
