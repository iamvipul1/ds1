#include<stdio.h>
int total=0;
int n=4;
int howmany(int n, int tot){
  if(n==0){
    printf("\n base condition");
    return tot;
  }
  else{
    tot=tot+1;
    return howmany(n-1, tot);
  }
}
int main(){
  total=howmany(n,total);
  printf(" people in Q is %d", total);
  printf("\n");
  printf(" people in front of last person in Q is %d", total-1);
}