#include <stdlib.h>
#include <stdio.h>
#include "CircularString.c"

int main(int argc, char const *argv[])
{

  char s[] = "ciao";
  circularString cs = costruttore(s, sizeof(s) - 1);
  printf("Originale: %s\n", toString(cs));

  gira(cs);
  printf("%s, girata per %d volta\n", toString(cs), nGira(cs));

  gira(cs);
  printf("%s, girata per %d volte\n", toString(cs), nGira(cs));

  gira(cs);
  printf("%s, girata per %d volte\n", toString(cs), nGira(cs));

  gira(cs);
  printf("%s, girata per %d volte\n", toString(cs), nGira(cs));

  cancella(cs);
  return 0;
}
