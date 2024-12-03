/*
  File dove implementiamo la circularString definita nel relativo header file
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "CircularString.h"

// Definiamo il tipo che rappresenta la circularString
struct circularStringType
{
  // Spazio dedicato alla stringa
  char *stringa;

  // Lunghezza della stringa salvata
  int lenStringa;

  // Numero di volte che la stringa è stata girata
  int numGiri;
};

circularString costruttore(char *s, int len)
{
  // Allochiamo lo spazio per la circularString
  circularString cs = malloc(sizeof(circularString));

  // Allochiamo lo spazio per la stringa
  cs->stringa = (char *)malloc(sizeof(char) * len);

  // Popoliamo la stringa dall'input
  for (int i = 0; i < len; i++)
    cs->stringa[i] = s[i];

  // Alternativa usando la funzione dedicata da string.h
  // strcpy(cs->stringa, s);

  // Inizializziamo gli altri campi
  cs->numGiri = 0;
  cs->lenStringa = len;

  return cs;
}

void gira(circularString s)
{

  // Salviamo l'ultimo carattere
  char lastChar = s->stringa[s->lenStringa - 1];

  // Salviamo una copia della stringa
  char *tmp = (char *)malloc(sizeof(char) * s->lenStringa);
  strcpy(tmp, s->stringa);

  // Scaliamo avanti le lettere della stringa
  for (int i = 0, j = 1; i < s->lenStringa - 1; i++, j++)
    s->stringa[j] = tmp[i];

  // Liberiamo la stringa temporanea che non ci serve più
  free(tmp);

  // L'ultimo carattere diventa il primo
  s->stringa[0] = lastChar;

  // Incrementiamo il numero di giri
  s->numGiri = s->numGiri + 1;
}

char *toString(circularString s)
{
  return s->stringa;
}

int nGira(circularString s)
{
  return s->numGiri;
}

void cancella(circularString s)
{
  // Liberiamo SEMPRE per primo lo spazio allocato per i field della struct
  free(s->stringa);

  // Poi liberiamo lo spazio allocato per la struct che rappresenta la circularString
  free(s);
}
