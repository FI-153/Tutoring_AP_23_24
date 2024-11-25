/*
 * corso.h
 *
 *  Created on: Oct 26, 2011
 *      Author: garganti
 */

#ifndef CORSO_H_
#define CORSO_H_

#include "studente.h"

typedef struct corso *corsoRef;

// Costrittore
corsoRef mkCorso(char *n);

// Aggiunge uno studente s al corso c
void addStudent(corsoRef c, studenteRef s);

#endif /* CORSO_H_ */
