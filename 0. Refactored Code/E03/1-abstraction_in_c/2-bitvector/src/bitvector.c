/*
 ============================================================================
 Name        : CENTURELLI_VALENTINA_OPACHI.c
 Author      : Valentina Centurelli
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "bitvector.h"

/*
 * Implementazione dei dati
 */

struct vettore
{
	int dimensione;
	int *contenuto; // ho scelto int come tipo primitivo per l'array -> 0 false, 1 -> true
};

bitvector make_vector(int n)
{

	// alloco lo spazio per la struct defininte il bitvector
	bitvector newVector = (bitvector)(malloc(sizeof(struct vettore)));

	// salvo i dati della dimensione
	newVector->dimensione = n;

	// alloco lo spazio per il contenuto del bit vector (array di 0 o 1)
	newVector->contenuto = malloc(sizeof(int) * n);

	// inizializzo il contenuto del bitvector
	for (int i = 0; i < n; i++)
	{
		newVector->contenuto[i] = 0;
	}

	return newVector;
}

char *tostring(bitvector v)
{
	// Alloco lo spazio per la stringa che rappresenta il contenuto del bitvector +1 per il carattere terminatore
	char *ris = malloc((v->dimensione + 1) * sizeof(char));

	int i;
	for (i = 0; i < v->dimensione; i++)
	{
		ris[i] = v->contenuto[i] == 1 ? '1' : '0';
	}
	ris[i] = '\0';
	return ris;
}

void delete_vector(bitvector v)
{

	// Libero prima sempre tutta la memoria allocata per il contenuto di una struttura dati.
	// In questo caso si tratta solo del contenuto del bitvector
	free(v->contenuto);

	// Solo alla fine libero lo spazio allocato per la struct
	free(v);
}

bitvector and (bitvector b1, bitvector b2)
{

	bitvector ris = make_vector(b1->dimensione);

	if (b1->dimensione != b2->dimensione)
	{
		printf("AND: Dimensioni non uguali \n");
		return ris;
	}

	for (int i = 0; i < ris->dimensione; i++)
	{
		ris->contenuto[i] = b1->contenuto[i] * b2->contenuto[i];
	}

	return ris;
}

bitvector or (bitvector b1, bitvector b2)
{

	bitvector ris = make_vector(b1->dimensione);

	if (b1->dimensione != b2->dimensione)
	{
		printf("AND: Dimensioni non uguali \n");
		return ris;
	}

	for (int i = 0; i < ris->dimensione; i++)
	{
		// Con il modulo restringo il risultato a 1 e 0 (2%2=0, 3%2=1 ecc.)
		ris->contenuto[i] = (b1->contenuto[i] + b2->contenuto[i]) % 2;
	}

	return ris;
}

bitvector not(bitvector b)
{

	bitvector ris = make_vector(b->dimensione);

	// inizializzo il contenuto -> se b aveva 0 allora ris ha 1 e viceversa
	for (int i = 0; i < b->dimensione; i++)
	{
		ris->contenuto[i] = b->contenuto[i] == 1 ? 0 : 1;
	}

	return ris;
}
