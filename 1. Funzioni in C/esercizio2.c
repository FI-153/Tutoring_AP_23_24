#include <stdlib.h>
#include <stdio.h>

// Funzioni Richieste
char *mixStrings(char *, int, char *, int);
char *mixStrings_rec(char *, int, char *, int, int, int, char *);
char *mixStrings_rec_TR(char *, int, char *, int, int, int, char *);

// Macro Ausiliarie
#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]));
#define MIN(a, b) (a < b ? a : b)

int main(int argc, char const *argv[])
{
  char s1[] = "cane";
  char s2[] = "nero";
  int sizeS1 = ARRAY_SIZE(s1);
  int sizeS2 = ARRAY_SIZE(s2);

  printf("%s\n", mixStrings(s1, sizeS1, s2, sizeS2));

  char *out1 = (char *)malloc(sizeof(char) * MIN(sizeS1, sizeS2));
  out1 = mixStrings_rec(s1, sizeS1, s2, sizeS2, 0, 0, out1);
  printf("%s\n", out1);
  free(out1);

  char *out2 = (char *)malloc(sizeof(char) * MIN(sizeS1, sizeS2));
  printf("%s\n", mixStrings_rec_TR(s1, sizeS1, s2, sizeS2, 0, 0, out2));
  free(out2);

  char s3[] = "ciao";
  char s4[] = "marianna";
  int sizeS3 = ARRAY_SIZE(s3);
  int sizeS4 = ARRAY_SIZE(s4);

  printf("%s\n", mixStrings(s3, sizeS3, s4, sizeS4));

  char *out3 = (char *)malloc(sizeof(char) * MIN(sizeS3, sizeS4));
  mixStrings_rec(s3, sizeS3, s4, sizeS4, 0, 0, out3);
  printf("%s\n", out3);
  free(out3);

  char *out4 = (char *)malloc(sizeof(char) * MIN(sizeS3, sizeS4));
  printf("%s\n", mixStrings_rec_TR(s3, sizeS3, s4, sizeS4, 0, 0, out4));
  free(out4);

  return 0;
}

char *mixStrings(char *s1, int len1, char *s2, int len2)
{
  // Alloco lo spazio per la stringa in uscita ricordando di aggiungere il terminatore
  int sizeOut = (2 * MIN(len1, len2)) + 1;
  char *out = (char *)malloc(sizeof(char) * sizeOut);

  // Dichiaro 'i' fuori dal ciclo per poter aggiungere il terminatore
  int i = 0;
  for (int j = 0; j < MIN(len1, len2); j++)
  {
    // Primo carattere da s1
    out[i] = s1[j];
    i += 1;

    // Secondo carattere da s2
    out[i] = s2[j];
    i += 1;
  }

  // Terminatore
  out[i] = '\0';
  return out;
}

char *mixStrings_rec(char *s1, int len1, char *s2, int len2, int idxOut, int idxStrs, char *out)
{
  // Passo base: mi fermo quando incontro la fine della stringa più corta
  if (idxStrs > MIN(len1, len2))
  {
    // Terminatore
    out[idxOut] = '\0';
    return out;
  }

  // Chiamata ricorsiva
  out = mixStrings_rec(s1, len1, s2, len2, idxOut + 2, idxStrs + 1, out);

  // Popolo la stringa quando "riemergo" dalla ricorsione, in questo modo rendo esplicito che la funzione non è tail-recursive
  out[idxOut] = s1[idxStrs];
  out[idxOut + 1] = s2[idxStrs];

  return out;
}

char *mixStrings_rec_TR(char *s1, int len1, char *s2, int len2, int idxOut, int idxStrs, char *out)
{

  // Passo base: mi fermo quando incontro la fine della stringa più corta
  if (idxStrs > MIN(len1, len2))
  {
    out[idxOut] = '\0';
    return out;
  }

  // Passo iterativo: popolo la stringa
  out[idxOut] = s1[idxStrs];
  out[idxOut + 1] = s2[idxStrs];

  // Chiamata ricorsiva tail recursive
  return mixStrings_rec_TR(s1, len1, s2, len2, idxOut + 2, idxStrs + 1, out);
}