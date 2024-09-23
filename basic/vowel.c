#include<stdio.h>
#include<stdio.h>
#define size 10
char queue[size];
int front=-1;
int rear=-1;
void enqueue(char ele){
  if(front==-1){front=0;}
  queue[++rear]=ele;
}
void dequeue(){
  if(front==-1){
    /*do nothing*/}
else
    front++;
    }
void display(){
  if(front==-1||front>rear){
    printf("empty");
  }else{
    for(int i=front;i<=rear;i++)
      printf("%c", queue[i]);
  }
    }
int main(){
char ele;
scanf("%c", &ele);
while(ele!='.'){
if(ele == 'A'||ele == 'E'||ele == 'I'||ele == 'O'||ele == 'U')
  dequeue();
  else
    enqueue(ele);
  scanf("%c", &ele);
  }
  display();
}