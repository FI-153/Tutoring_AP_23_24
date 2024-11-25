#include <stdio.h>
#include <stdlib.h>

int *foo(int y)
{
  int *h = malloc(sizeof(int));
  *h = y;

  printf("Inside before free: %p\n", *h);
  free(h);
  printf("Inside after free: %p\n", *h);
  return h;
}

int main(void)
{
  int *p = foo(3);

  printf("Outside for 3: %d\n", *p);
  foo(4);

  int b = *p;
  printf("%d\n", *p);
  printf("%d\n", b);

  return 0;
}
