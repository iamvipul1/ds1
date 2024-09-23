#include <stdio.h>
int main(void)
{
  int *n[5], s1,s2,s3,s4;
  s1=sizeof(n);
  char *c[5];
  s2=sizeof(c);
  float *f[5];
  s3=sizeof(f);
  double *d[5];
  s4=sizeof(d);
  printf("Size of int=%d\n", s1);
  printf("Size of character=%d\n", s2);
  printf("Size of float=%d\n", s3);
  printf("Size of double=%d\n", s4);
}