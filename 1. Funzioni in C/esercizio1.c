#include <stdio.h>
#include <stdlib.h>

/*
  ASSUNZIONI:
    - Negli array non possano esserci numeri negativi;
    - Due elementi uguali non vengono contati.
*/

// Funzioni Richieste
int COUNT_GT_Iterativo(int a1[], int dimA1, int a2[], int dimA2);
int COUNT_GT_RicorsivoNoTailCall(int a1[], int dimA1, int a2[], int dimA2, int i);
int COUNT_GT_RicorsivoTailCall(int a1[], int dimA1, int a2[], int dimA2, int i, int numElem);

// Funzioni Ausiliarie
int MIN(int a, int b);
#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))

int main(int argc, char const *argv[])
{

  int a1[] = {2, 3, 4};
  int sizeA1 = ARRAY_SIZE(a1);
  int a2[] = {3, 1};
  int sizeA2 = ARRAY_SIZE(a2);
  // 2<3, 3>1, 4>0 --> 2
  printf("Iterativo: %d\n", COUNT_GT_Iterativo(a1, sizeA1, a2, sizeA2));
  printf("Iterativo no tail call: %d\n", COUNT_GT_RicorsivoNoTailCall(a1, sizeA1, a2, sizeA2, 0));
  printf("Iterativo tail call: %d\n", COUNT_GT_RicorsivoTailCall(a1, sizeA1, a2, sizeA2, 0, 0));

  int a3[] = {1, 4, 2, 6};
  int sizeA3 = ARRAY_SIZE(a3);
  int a4[] = {2, 6, 3, 5, 7};
  int sizeA4 = ARRAY_SIZE(a4);
  // 1<2, 4<6, 2<3, 6>5, 0<7 --> 1
  printf("Iterativo: %d\n", COUNT_GT_Iterativo(a3, sizeof(a3) / sizeof(a3[0]), a4, sizeof(a4) / sizeof(a4[0])));
  printf("Iterativo no tail call: %d\n", COUNT_GT_RicorsivoNoTailCall(a3, sizeof(a3) / sizeof(a3[0]), a4, sizeof(a4) / sizeof(a4[0]), 0));
  printf("Iterativo tail call: %d\n", COUNT_GT_RicorsivoTailCall(a3, sizeof(a3) / sizeof(a3[0]), a4, sizeof(a4) / sizeof(a4[0]), 0, 0));

  return 0;
}

int MIN(int a, int b)
{
  return (a < b) ? a : b;
}

int COUNT_GT_Iterativo(int a1[], int dimA1, int a2[], int dimA2)
{
  int numMaggiori = 0;

  // Trova elementi nel primo array che siano maggiori rispetto al corrispettivo nel secondo
  for (int i = 0; i < MIN(dimA1, dimA2); i++)
  {
    if (a1[i] > a2[i])
      numMaggiori++;
  }

  // Se il primo array è più lungo del secondo allora tutti gli elementi mancanti del secondo saranno 0.
  // Non serve fare controlli e possiamo calcolare direttamente l'incremento
  if (dimA1 > dimA2)
    numMaggiori += dimA1 - dimA2;

  return numMaggiori;
}

int COUNT_GT_RicorsivoNoTailCall(int a1[], int dimA1, int a2[], int dimA2, int i)
{

  // Passo base: mi fermo quando incontro l'ultimo elemento dell'array più corto
  if (i == MIN(dimA1, dimA2))
  {
    if (dimA1 > dimA2)
      // Quindi se il primo è più lungo del secondo restituisco la differnza (vedi funzione iterativa)
      return dimA1 - dimA2;
    else
      // Altrimenti restituisco 0
      return 0;
  }

  // Passo ricorsivo: quando il l'i-esimo elemento del primo array è maggiore dell'i-esimo del secondo incrementa risultato
  if (a1[i] > a2[i])
    return 1 + COUNT_GT_RicorsivoNoTailCall(a1, dimA1, a2, dimA2, ++i);
  else
    return 0 + COUNT_GT_RicorsivoNoTailCall(a1, dimA1, a2, dimA2, ++i);
  /*
    Se nell'else avessi scritto

      return COUNT_GT_RicorsivoNoTailCall(a1, dimA1, a2, dimA2, ++i);

    sarebbe diventata tail-recursive? No, perché non tutti i possibili path in cui chiamiamo la funzione sarebbero stati TR
  */
}

int COUNT_GT_RicorsivoTailCall(int a1[], int dimA1, int a2[], int dimA2, int i, int numElem)
{

  // Passo base: mi fermo quando incontro l'ultimo elemento dell'array più corto
  if (i == MIN(dimA1, dimA2))
  {
    if (dimA1 > dimA2)
      return numElem + (dimA1 - dimA2);
    else
      return numElem;
  }

  if (a1[i] > a2[i])
    return COUNT_GT_RicorsivoTailCall(a1, dimA1, a2, dimA2, ++i, ++numElem);
  else
    return COUNT_GT_RicorsivoTailCall(a1, dimA1, a2, dimA2, ++i, numElem);
}