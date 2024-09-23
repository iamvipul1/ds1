#include<stdio.h>
struct myshop{
char name[100];
float quan;
float upri;
float tpri;
}a;
int main()
{
  printf("enter name, quantity, unit-price:::");
scanf("%s %f %f", &a.name,&a.quan,&a.upri);
  printf("you entered:");
  printf("%s %f %f",a.name,a.quan,a.upri);
  a.tpri=a.quan*a.upri;
  printf("total_price:%.2f", a.tpri);
}