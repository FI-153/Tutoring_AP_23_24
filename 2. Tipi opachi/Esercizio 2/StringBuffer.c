/*
  File dove implementiamo lo stringBuffer definita nel relativo header file
*/

/*
  Osservazioni:
  La traccia richiede che l'array usato per immagazzinare la stringa nello stringBuffer possa crescere tuttavia in C non possiamo creare un array dinamico. Una possibile soluzione sarebbe implementare noi un array dinamico che raddoppi di dimensione ogni volta che viene riempito. Steven Skiena presenta una trattazione degli array dinamici nel suo libro "Algorithm Design Manual", nel caso foste interessati ad approfondire trovate le slide qui: https://www3.cs.stonybrook.edu/~algorith/video-lectures/2007/lecture4.pdf dove dimostra come la complessità (ammortizzata) dell'inserimento in un array dinamico sia comunque costante.

  Se invece avessimo a dispozione Java potremmo usare un'ArrayList: https://www.javatpoint.com/dynamic-array-in-java.

  Nel nostro caso creiamo una terza stringa in cui copiamo il contenuto della prima e della seconda per poi salvarla come contenuto della prima.
*/

#include <stdio.h>
#include <stdlib.h>
#include "StringBuffer.h"

// Definiamo il tipo che rappresenta lo stringBuffer
struct bufferType
{
  // Stringa salvata nel buffer
  char *str;

  // Lunghezza della stringa
  int dimensione;
};

stringBuffer make_buffer(char *in, int len)
{

  // Allochiamo lo spazio per il buffer e poi per la stringa che contiene
  stringBuffer newBuffer = (stringBuffer)malloc(sizeof(stringBuffer));
  newBuffer->str = malloc(sizeof(char) * len);

  // Popoliamo la stirnga (anche qui volendo si poteva usane strcpy di string.h)
  for (int i = 0; i < len; i++)
    newBuffer->str[i] = in[i];

  // Popoliamo il campo mancante
  newBuffer->dimensione = len;

  return newBuffer;
}

void accoda(stringBuffer b1, stringBuffer b2)
{
  // Calcoliamo la dimensione della nuova stringa che ci serve
  int finalDim = b1->dimensione + b2->dimensione;

  // Allochiamo spazio per la nuova stringa
  char *strNew = malloc(sizeof(char) * finalDim);

  // Copiamo il contenuto del primo stringBuffer
  for (int i = 0; i < b1->dimensione; i++)
    strNew[i] = b1->str[i];

  // Copiamo il contenuto del secondo stringBuffers che seguirà il contenuto del primo
  for (int i = 0; i < b2->dimensione; i++)
    strNew[b1->dimensione + i] = b2->str[i];

  // Liberiamo lo spazio allocato per la precendete stringa del primo stringBuffer
  free(b1->str);

  // Salviamo come contenuto del primo stringBuffer la nuova stringa
  b1->str = strNew;

  // Poi ne aggiorniamo la dimensione
  b1->dimensione = finalDim;
}

char *toString(stringBuffer b)
{
  // Allochiamo lo spazio per la stringa di output riservando 3 byte aggiuntivi per gli apici e il terminatore
  char *out = malloc(sizeof(char) * b->dimensione + 3);

  // Primo apice
  out[0] = '"';

  // Copiamo contenuto della stringa
  for (int i = 0; i < b->dimensione; i++)
    out[i + 1] = b->str[i];

  // Secondo apice
  out[b->dimensione + 1] = '"';

  // Terminatore
  out[b->dimensione + 2] = '\0';

  return out;
}

void cancella(stringBuffer b)
{
  // Liberiamo il contenuto della stringa
  free(b->str);

  // Liberiamo lo spazio allocato per lo stringBuffer
  free(b);
}