/*
 ============================================================================
 Name        : esercizio1_encapsulation.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "mcomputer.c"

int main(void)
{
	// using module
	setComputerData("pippo", 0);
	printComputer(0);

	setComputerData("pluto", 4);
	printComputer(4);

	setComputerData("topolino", 0);
	printComputer(0); // Unchanged by definition of the method

	return EXIT_SUCCESS;
}
