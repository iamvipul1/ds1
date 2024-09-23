#include <stdio.h>
int main()
{
    int size;
    printf("Enter size  :: ");
    scanf("%d", &size);
    int a[size];
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }
    int len;
    len = sizeof(int);
    printf("Size of integer: %d bytes\n", len);
    printf("Size of array: %d", len * size);
    return 0;
}