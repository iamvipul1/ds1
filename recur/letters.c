#include <stdio.h>
#include <stdlib.h>
int i=0;
void letter(char name[], int i) 
{
  if (name[i] == '\0') 
  {
    printf("\n over:");
    exit(0);
  } 
  else {
    printf("%c\n ", name[i]);
    letter(name, i + 1);
  }
}

int main() {
  char name[] = "vipul";
  letter(name,i);
  return 0;
}
