#include <stdio.h>
int main() 
{
    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr = &arr[0];
    
    for(int i = 0; i < 5; i++) 
    {
        printf("arr[%d] = %d \t Memory= %p\n", i, arr[i], &arr[i]);
    }
  }

