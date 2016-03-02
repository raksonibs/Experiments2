#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
  struct {
    int len;
    int height;
  } tmp, *p =&tmp;

  tmp.len = 10;
  tmp.height =20;
  // printf("111 %d \n", tmp.len);
  // same as
  printf("111 %d \n", p->len);

  struct dimension {
    float width;
    float height;
  };

  struct dimension chairs[2];

  struct dimension *tables;

  tables = (struct dimension*)malloc(20*sizeof(struct dimension));

  struct dimension table = tables[0];
  table.width = 2.0;
  printf("%f\n", table.width);

  char *str;

   /* Initial memory allocation */
   str = (char *) malloc(15);
   strcpy(str, "tutorialspoint");
   printf("String = %s,  Address = %u\n", str, str);

   /* Reallocating memory */
   str = (char *) realloc(str, 25);
   strcat(str, ".com");
   printf("String = %s,  Address = %u\n", str, str);

   free(str);
   
  return 0;
}