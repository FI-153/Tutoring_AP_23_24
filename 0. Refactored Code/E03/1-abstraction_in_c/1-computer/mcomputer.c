/*
 * mcomputer.c
 *
 *  Created on: 12/nov/2014
 *      Author: garganti
 */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "mcomputer.h"

#define N_COMPUTER 10

// data about computers
// names: N_COMPUTER strings
static char *names[N_COMPUTER];

void setComputerData(char *name, int code)
{
	if (names[code] == NULL)
	{
		names[code] = malloc(sizeof(char) * (strlen(name) + 1));
		strcpy(names[code], name);
	}
}

void printComputer(int code)
{
	printf("computer w/ code %d is named: %s \n", code, names[code]);
}
