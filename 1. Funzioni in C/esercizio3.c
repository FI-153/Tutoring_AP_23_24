#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Funzioni Richieste
int *sort_iterativo(int *, int);
int *sort_ricorsivo_non_TL(int *, int);
int *sort_ricorsivo_TL(int *, int);

// Funzioni ausiliarie

// Scambia gli elementi in posizione i e j nell'array a
void swap(int *, int, int);

// Stampa array poi vai a capo
void printArray(int *, int);

// Copia l'array 'src' nell'array 'dst'
void copy(int *, int *, int);

/*
Osservazoni:

- Si è scelto ordinamento crescente non essendo specificato altrimenti.

- Non viene specificato che algoritmo di sorting implementare, per questo siamo liberi di usare quello che preferiamo. Consiglio di prioritizzare la velocità di implementazione piuttosto che del codice in sé (non si tratta di un corso di algoritmi!)

- La traccia richiede di restituire una copia dell'array ordinato, tuttavia in C non è possibile passare un array by-value (cioè una sua copia esatta), infatti stiamo sempre passando il puntatore alla sua prima cella.

    void func (int* x);   qui passo il puntatore
    void func(int x[]);   qui passo una copia DEL PUNTATORE
    void func(int x[10]); qui passo una copia del puntatore all'undicesimo elemento

  Un workaorund per passare una copia dell'array è di incapsularlo in una struct del tipo:

    typedef struct {
      int arr[4];
    } ArrayWrapper;

  Tuttavia questo cambierebbe la signature delle funzioni quindi lo lasciamo perdere.
  Ci accontentiamo di definire una nostra funzione 'copy' che copia l'array di input in un secondo per poi passare la copia affinché sia ordinata. Per rendere la copia totalmente trasparente all'utente finale si può chiamare copy() all'interno della funzione di sort o in un suo wrapper.

  - La consegna chiede esplicitamente di "restituire" l'array ordinato quindi dobbiamo definire funzioni che non ritornino void (nonstante ciò possa essere ridonandante!).
*/

// Implementazione classica di Bubblesort
int *sort_iterativo(int *a, int size)
{
  bool swapped = true;
  while (swapped)
  {
    swapped = false;
    for (int i = 0, j = 1; j < size; i++, j++)
    {
      // Attenzione a non mettere '>=' o '<=' altrimenti si rischia un loop infinito se si incontrano elementi uguali
      if (a[i] > a[j])
      {
        swap(a, i, j);
        swapped = true;
      }
    }
  }

  return a;
}

// Bubblesort iterativo che ordina una porzione sempre più piccola dell'array sino a ridurlo a un sotto-array di 1 elemento
int *sort_ricorsivo_non_TL(int *a, int size)
{
  if (size == 1)
    return a;

  int count = 0;
  for (int i = 0, j = 1; j < size; i++, j++)
    if (a[i] > a[j])
    {
      swap(a, i, j);
      count++;
    }

  if (count == 0)
    return a;

  a = sort_ricorsivo_non_TL(a, --size); // In questo modo il nostro Bubblesort non è più TL

  // Possiamo inferire sulla cosa quanto vogliamo!
  //  int b = 1;
  //  b++;

  return a;
}

// Bubblesort iterativo TR che ordina una porzione sempre più piccola dell'array sino a ridurlo a un sotto-array di 1 elemento
int *sort_ricorsivo_TL(int *arr, int n)
{
  if (n == 1)
    return arr;

  int count = 0;
  for (int i = 0; i < n - 1; i++)
    if (arr[i] > arr[i + 1])
    {
      swap(arr, i, i + 1);
      count++;
    }

  if (count == 0)
    return arr;

  return sort_ricorsivo_TL(arr, --n); // Non essendoci altre operazioni dopo la chiamata ricorsiva questa funzione è TL
}

void swap(int *a, int i, int j)
{
  int tmp = a[i];
  a[i] = a[j];
  a[j] = tmp;
}

void printArray(int *a, int size)
{
  for (int i = 0; i < size; i++)
    printf("%d ", a[i]);

  printf("\n");
}

void copy(int *src, int *dst, int size)
{
  // Attenzione a non creare l'array 'dst' all'interno della funzione in quanto si avrebbe un dangling pointer una volta restituito.
  // Se proprio si vuole dichiarare 'dst' all'interno usare malloc e gestire poi la memoria.
  for (int i = 0; i < size; i++)
    dst[i] = src[i];
}

int main(int argc, char const *argv[])
{
  // Ordinato diventa: 0 1 2 3 4 5 6 7 8 9
  int a[] = {7, 3, 1, 0, 9, 8, 2, 5, 4, 6};
  int size = sizeof(a) / sizeof(int);
  int aCopy[size];

  copy(a, aCopy, size);
  int *sortedIt = sort_iterativo(aCopy, size);
  printArray(sortedIt, size);

  copy(a, aCopy, size);
  int *sortedRec = sort_ricorsivo_non_TL(aCopy, size);
  printArray(sortedRec, size);

  copy(a, aCopy, size);
  int *sortedRecTR = sort_ricorsivo_TL(aCopy, size);
  printArray(sortedRecTR, size);

  return 0;
}
