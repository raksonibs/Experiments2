#include <stdio.h>
#define MAXSIZE 50

int stack[MAXSIZE];
int top = 0;
void push(int i);

int main() {
  char input[1];
  while(1) {
    scanf("%s", input);
    int val = atoi(input);
    if (input[0] == 'q') {
      break;
    } else if (input[0] == 'p') {
      printf("%10d\n", stack[top]);
    } else if(input[0] == '+') {
      int j = pop();
      int k = pop();
      push(j + k);
    } else if (input[0] == '-') {
      int j = pop();
      int k = pop();
      push(k - j);
    } else if(input[0] == '*') {
      int j = pop();
      int k = pop();
      push(k * j);
    } else if(input[0] == '/') {
      int j = pop();
      int k = pop();
      push(k / j);
    } else {
      push(val);
    }
  }
  return 0; 
}

void push(int i) {
  if (top > MAXSIZE) {
    printf("Stack is already full!\n");
    return;
  } else {
    top++;
    stack[top] = i;
    return;
  } 
}

int pop() {
  int i;
  if(top <= 0) {
    printf("Stack is empty!\n");
    return 0;
  } else {
    i = stack[top];
    top--;
  }
  return i;
}