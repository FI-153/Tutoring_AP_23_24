/*
  Header file dove definiamo la circularString e i relativi metodi
*/

/*
  Osservazioni:
  La traccia è ambigua se la stringa debba essere un puntatore a caratteri o una string (dalla libreria string.h).
  Tuttavia a un certo punto richiede che la stringa sia restituita come un array di caratteri quindi si è deciso di
  non usare string.h.
*/

#ifndef CircularString
#define CircularString

// Definiamo il tipo opaco "circularString"
typedef struct circularStringType *circularString;

// Costruisce una circularString
circularString costruttore(char *s, int len);

// Gira la stringa rappresentata dalla circularString di una posizione vs destra
void gira(circularString s);

// Restituisce la stringa che rappresenta la circularString. Attenzione a non restituire "String"
char *toString(circularString s);

// Restituisce il numero di volte che la circularString è stata girata
int nGira(circularString s);

// Cancella la circularString liberando la memoria ad essa allocata
void cancella(circularString s);

#endif