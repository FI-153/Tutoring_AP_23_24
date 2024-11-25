/*
 ============================================================================
 Name        : CENTURELLI_VALENTINA_OPACHI.h
 Author      : Valentina Centurelli
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * In questo file definisco:
 *
 * - il tipo di dato opaco (con typedef)
 * - costruttore
 * - distruttore
 * - funzioni ausiliarie al bitvector (and, or, not, tostring)
 */

// Tipo opaco descrivente il vettore di bit
typedef struct vettore *bitvector;

// Costruttore di un bitvector inizializzato a 0
bitvector make_vector(int);

// Distruttore del bitvector passato in input
void delete_vector(bitvector);

// Converti bitvector in stringa
char *tostring(bitvector);

// And di due bitvector di eguale dimensione, altrimenti ritornano uno di 0 della dimensione del più lungo
bitvector and (bitvector, bitvector);

// Or di due bitvector di eguale dimensione, altrimenti ritornano uno di 0 della dimensione del più lungo
bitvector or (bitvector, bitvector);

// Not di un bitvector
bitvector not(bitvector);
