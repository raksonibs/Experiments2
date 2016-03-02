#include<stdio.h>
#include<stdlib.h>
main() {
  int *a, i,n,sum=0;
  printf("Input an aray size ");
  scanf("%d",&n);
  a=calloc(n, sizeof(int));
  for(i=0; i<n; i++) scanf("%d",&a[i]);
  for(i=0; i<n; i++) sum+=a[i];
  free(a);
  printf("Number of elelments = %d and the sum is %d\n",n,sum);
}