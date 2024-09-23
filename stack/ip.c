#include <ctype.h>
#include <stdio.h>
#define size 50
char ch[size], ex[size], stack[size], pf[size];
int top = -1, Index = 0;
int push(char);
int pop();
int isOperand(char);
int precedence(char);
void InfixToPostfix();
int main() {
  printf("infix:");
  scanf("%s", ex);
  InfixToPostfix();
  printf("postfix:%s\n", pf);
}
void InfixToPostfix() {
  int len = 0;
  while (ex[len] != '\0') {
    len++;
  }
  for (int i = 0; i <= len; i++) {
    if (isOperand(ex[i])) {
      pf[Index] = ex[i];
      Index++;
    } else if (ex[i] == '(') {
      push(ex[i]);
    } else if (ex[i] == ')') {
      while (top != -1 && stack[top] != '(') {
        pf[Index] = pop();
        Index = Index + 1;
      }
      pop();
    } else {
      while (top != -1 && precedence(stack[top]) >= precedence(ex[i])) {
        pf[Index] = pop();
        Index = Index + 1;
      }
      push(ex[i]);
    }
  }
  while (top != -1) {
    pf[Index] = pop();
    Index = Index + 1;
  }
}

int isOperand(char ch) {
  if (isalnum(ch))
    return 1;
  else
    return 0;
}
int push(char ch) {
  if (size == top - 1)
    printf("stack overflow");
  else {
    top = top + 1;
    stack[top] = ch;
  }
}
int pop() {
  if (top == -1)
    printf("stack underflow");
  else {
    int c = stack[top];
    top = top - 1;
    return c;
  }
  return 0;
}
int precedence(char ch) {
  if ((ch == '+') || (ch == '-'))
    return 1;
  else if ((ch == '*') || (ch == '/'))
    return 2;
  else if (ch == '^')
    return 3;
  else
    return 0;
}