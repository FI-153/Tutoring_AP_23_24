/*
 * corso.c
 *
 *  Created on: Oct 26, 2011
 *      Author: garganti
 */
#include "stdlib.h"
#include <string.h>

#include "corso.h"

#define MAX_CHAR_CORSO 40

struct nodo
{
	studenteRef s;
	struct nodo *next;
};

struct corso
{
	char nome[MAX_CHAR_CORSO];
	//
	struct nodo *lista;
	// alternativa (chiaro che avrò un numero massimo di studenti VS un numero indefinito con la lista)
	// studenteRef classe[100];
};

corsoRef mkCorso(char *n)
{
	corsoRef c = malloc(sizeof(struct corso));
	strncpy(c->nome, n, MAX_CHAR_CORSO);
	c->lista = NULL;

	// Avendo usato l'alternativa avrei inizializzato "classe" a NULL per tutti i suoi 100 valori
	return c;
}

void addStudent(corsoRef c, studenteRef s)
{
	// Creo nuovo nodo
	struct nodo *n = malloc(sizeof(struct nodo));
	n->s = s;

	// Inserisco in testa per velocità (O(1) VS O(N) dove N è il numero di studenti già nella lista). Inserimento in coda comunque valido!
	n->next = c->lista;
	c->lista = n;
}
