/*
  Header file dove definiamo lo stringBuffer e i relativi metodi
*/

#ifndef StringBuffer
#define StringBuffer

// Definiamo il tipo opaco "stringBuffer"
typedef struct bufferType *stringBuffer;

// Costruttore dello stringBuffer
stringBuffer make_buffer(char *in, int len);

// Accoda il primo stringBuffer al secondo
void accoda(stringBuffer b1, stringBuffer b2);

// Restituisce la stringa rappresetante lo stringBuffer aggiungengo apici all'inizio e alla fine
char *toString(stringBuffer b);

// Cancella lo stringBuffer liberando la memoria ad esso dedicata
void cancella(stringBuffer b);

#endif