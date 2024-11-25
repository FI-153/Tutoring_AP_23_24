#include <stdio.h>
#include <stdlib.h>

int main(void)
{

  long i = 0;

  long *i_prt = (long *)i;

  //  printf("%ld\n",*i_prt);

  //(*i_prt)=0x000000016fdff31c;
  // printf("%ld\n",*i_prt);

  char *p1 = NULL;

  // printf("%c\n",*p1);
  char *p2; // Wild pointer
  printf("%c\n", *p2);
  printf("%p\n", p2);

  char *p3 = malloc(10 * sizeof(char));

  p3[0] = 'a';
  free(p3);
  printf("%c\n", *p3);
}
