#include <stdlib.h>
#include <stdio.h>
#include "StringBuffer.c"

int main(int argc, char const *argv[])
{

  // Crato primo StringBuffer
  char ciao[] = "ciao";
  stringBuffer b1 = make_buffer(ciao, sizeof(ciao) - 1);
  printf("%s\n", toString(b1));

  // Creto secondo StringBuffer
  char mario[] = "mario";
  stringBuffer b2 = make_buffer(mario, sizeof(mario) - 1);

  // Accodato il contenuto del secondo StringBuffer al primo
  accoda(b1, b2);
  printf("%s\n", toString(b1));

  // Cancellato il primo StringBuffer
  cancella(b1);

  // Provando ad accedere al contenuto non troviamo nulla
  printf("%s", b1->str);

  return 0;
}
