/*
 ============================================================================
 Name        : adt_studentcorso2.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style

  Scrivi la definizione di un tipo di dato astratto "Studente" che rappresenta uno studente con un nome (max 30 caratteri), cognome e matricola.
  Scrivi le seguenti funzioni:
  - mkStudente(char *n, char *c) --> restituisce uno studente con nome n, cognome c e matricola pari a un numero progressivo che dipende dal numero di studenti esistenti
  - printStudente(studenteRef s) --> stampa cognome nome e matricola
  - deleteStudente(studenteRef* s) --> cancella uno studente

  Definire anche un tipo di dato astratto "Corso" che rappresenta un corso con nome (max 40 caratteri) e un elenco di studenti che frequentano il corso.
  Scrivi le seguenti funzioni:
  - mkCorso(char *n) --> restituisce un corso con lista studenti pari a NULL
  - addStudent(corsoRef c, studenteRef s) --> dato un corso e uno studente, aggiunge lo studente alla lista dei partecipanti al corso (il nuovo studente viene inserito in testa alla lista).

  Scrivere un main in cui si creano due studenti e un corso, si inserisce uno studente nel corso e si cancella uno studente
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "studente.h"
#include "studente.c"
#include "corso.h"
#include "corso.c"

int main(void)
{
  studenteRef s1 = mkStudente("Matteo Pasquale Mario Giovanni", "Verdi");
  printStudente(s1); // il nome viene stampato a meta' perche' la lunghezza max e' 10
  deleteStudente(&s1);
  s1 = mkStudente("Matteo", "Verdi");

  studenteRef s2 = mkStudente("Mario", "Bianchi");
  printStudente(s2);
  deleteStudente(&s2);

  corsoRef c = mkCorso("Advanced Programming");
  addStudent(c, s1);
  addStudent(c, s2);

  return EXIT_SUCCESS;
}
