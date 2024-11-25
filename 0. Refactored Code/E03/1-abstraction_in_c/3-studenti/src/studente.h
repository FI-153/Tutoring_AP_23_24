/*
 * studente.h
 *
 *  Created on: Oct 26, 2011
 *      Author: garganti
 */

#ifndef STUDENTE_H_
#define STUDENTE_H_

typedef struct studente *studenteRef;

// Costruttore
studenteRef mkStudente(char *n, char *g);

// Print
void printStudente(studenteRef s);

// Distruttore
void deleteStudente(studenteRef *s);

#endif /* STUDENTE_H_ */
