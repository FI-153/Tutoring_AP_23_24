/*
 * studente.c
 *
 *  Created on: Oct 26, 2011
 *      Author: garganti
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "studente.h"

#define MAX_CHAR_NOME 10

static int numero_studenti = 0;

struct studente
{
	char nome[MAX_CHAR_NOME]; // La lunghezza del nome è vincolata a 10 caratteri
	char *cognome;						// Non abbiamo vincoli sulla lunghezza del cognome
	int matricola;
};

studenteRef mkStudente(char *n, char *c)
{
	// Alloco lo spazio per la struct che contiene i dati dello studente
	studenteRef ris = malloc(sizeof(struct studente));

	// inizializzo i field di studente
	int cLen = strlen(c) + 1; // Ricordo di aggiungere un carattere in più per il terminatore
	ris->cognome = malloc(sizeof(char) * cLen);
	strcpy(ris->cognome, c);

	strncpy(ris->nome, n, MAX_CHAR_NOME);

	ris->matricola = ++numero_studenti; // Usare "++i" indica di incrementare il valore di i prima di usarlo

	return ris;
}

void printStudente(studenteRef s)
{
	printf("Matricola: %d, Nome: %s, Cognome: %s\n", s->matricola, s->nome, s->cognome);
}

void deleteStudente(studenteRef *s)
{
	// Anzitutto liberiamo lo spazio allocato per i field all'interno della struct
	free((*s)->cognome);

	// Successivamente liberiamo lo spazio allocato per la struct in sé
	free(*s);
}