#include <stdio.h>
#include <string.h>

int main() {
  struct list {
    int len;
    struct list *next;
  } *head, *p, *last;

  head = (struct list *)malloc(sizeof(list));
  head -> len = 1;
  head -> next = NULL;
  last = head;
  int i;
  scanf("%d", &i);


}