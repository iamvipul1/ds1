#include<stdio.h>
#include<stdlib.h>
struct tnode{
char data;
struct node *lnode;
struct node *rnode;
};
typedef struct tnode tnode;
struct node *create(int val){
  tnode *tn=(tnode*)malloc(sizeof(tnode));
  tn->data=val;
  tn->lnode=NULL;
  tn->rnode=NULL;
  return tn;
}
struct node *insert(tnode *p, int val){
  if(p==NULL)
  {  p = create(val);}
  else if(val<p->data)
  {p->lnode=insert(p->lnode, val);}
   else if(val>p->data)
  {p->rnode=insert(p->rnode, val);}
  else
    printf("element already exist");
  return p;
}
void search(tnode *p, int key){
  if(p==NULL)
    printf("not found");
  else if(key<p->data)
    search(p->lnode,key);
  else if(key>p->data)
    search(p->rnode,key);
  else 
    printf("found");
}
int main(){
  int key, input;
  tnode *root=NULL;
  scanf("%d", &key);
  scanf("&d", &input);
  while(input!=-1){
    root=insert(root,input);
    scanf("%d", &input);
  }
  search(root, key);
}