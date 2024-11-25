/*
 ============================================================================
 Name        : bitvector.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "bitvector.h"
#include "bitvector.c"

// main di prova per testare il programma
int main(void)
{

	bitvector v = make_vector(3);
	printf("Stampo il dato appena creato %s \n", tostring(v));

	// not -> creo un vettore, poi lo converto subito a not e lo stampo
	bitvector vNot = not(make_vector(3));
	printf("Provo il not. not(000) = %s \n", tostring(vNot));

	// provo and e or
	printf("Provo con and: and(111, 000) = %s \n", tostring(and(vNot, v)));
	printf("Provo con or: or(111, 000) = %s \n", tostring(or (vNot, v)));

	// provo con dimensioni diverse
	printf("Errore AND = %s \n", tostring(and(make_vector(5), v))); // stampa 5 zeri
	printf("Errore OR = %s \n", tostring(or (make_vector(5), v)));	// stampa 5 zeri

	delete_vector(vNot);
	delete_vector(v);

	return EXIT_SUCCESS;
}
