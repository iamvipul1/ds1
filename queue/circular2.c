#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#define SIZE 20
int stack[SIZE];
int top = -1;
char expression[SIZE];
void push(char sym) {
  top = top + 1;
  printf("\n Top is %d", top);
  int num = sym - '0';
  printf(" \n converted to num %d", num);
  stack[top] = num;
  printf("\n Stack Top is %d", stack[top]);

} // end push

int pop() {
  int deleted;
  deleted = pop();
  top--;
  return deleted;
} // end pop

int Evaluate(int operand1, int operand2, char exp) {
  int result = 0;
  switch (exp) {
  case '+': {
    result = operand1 + operand2;
    break;
  }
  case '-': {
    result = operand1 - operand2;
    break;
  }
  case '*': {
    result = operand1 * operand2;
    break;
  }
  case '/': {
    result = operand1 / operand2;
    break;
  }
  case '$': {
    result = pow(operand1, operand2);
    break;
  }
  case '^': {
    result = pow(operand1, operand2);
    break;
  }

  } // end switch
  return result;

} // end evaluate

int main() {
  int i = 0, result, operand1, operand2;
  char symbol;
  printf("Enter a valid postfix expression");
  scanf("%s", expression);

  int len = strlen(expression);
  printf("\n Length is %d", len);
  for (int j = 0; j <= len; j++)
    printf("\n %c", expression[j]);

  for (i = 0; i <= len; i++) {
    if (isdigit(expression[i])) {
      printf("\n %c is a digit", expression[i]);

      push(expression[i]);
    } else {
      operand1 = pop();
      operand1 = operand1 - '0';
      operand2 = pop();
      operand2 = operand2 - '0';
      result = Evaluate(operand1, operand2, expression[i]);
      push(result);

    } // end else
  }   // end for

  result = pop();
  printf("\n Evaluation Result is %d", result);
}