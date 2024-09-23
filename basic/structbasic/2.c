#include<stdio.h>
struct myshoparray{
char name[100];
float quan;
float upri;
float tpri;
}a[5];
int main()
{
  printf("enter name, quantity, unit-price:::");
  for(int i=0;i<5;i++)
    {
     scanf("%s %f %f", &a[i].name,&a[i].quan,&a[i].upri); 
    }
  printf("you entered:");
    for(int i=0;i<5;i++)
      {
  printf("%s %f %f \n",a[i].name,a[i].quan,a[i].upri);
      }
  for(int i=0;i<5;i++)
    {
        a[i].tpri=a[i].quan*a[i].upri;
        printf("total_price of item %d:%.2f\n",i+1, a[i].tpri);
    }
}