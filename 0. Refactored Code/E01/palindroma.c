#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> // intrudce i tipi booleani

// scrivere due funzioni che verificano se una string e' palindroma.
// una ricorsiva e una non ricorsiva
// disegnare il record di attivazione per l'input Anna

int GLOBAL = 0;

// funzione che restitusce true se la stringa
// passata in ingresso � palindroma
bool palindroma(char *s)
{
	char *start = s;
	char *end = s + strlen(s) - 1;
	for (; start < end; start++, end--)
	{
		if (*start != *end)
			return false;
	}
	return true;
}
// in modo ricorsivo
// s string da analizzare
// n: indice dell'ultimo carattere
bool pali_ric(char *s, int n)
{
	if (n <= 0)
		return true;
	if (s[0] != s[n])
		return false;
	else
		return pali_ric(s + 1, n - 2); // TAIL RECURSION OK
}

int main(void)
{
	char s1[] = "rianair";
	printf("%s e' palindroma? %i\n", s1, palindroma(s1));
	char s2[] = "alitalia";
	printf("%s e' palindroma? %i\n", s2, palindroma(s2));
	printf("%s e' palindroma? %i\n", s2, pali_ric(s2, 7));
	char s3[] = "anna";
	printf("%s e' palindroma? %i\n", s3, palindroma(s3));
	printf("%s e' palindroma? %i\n", s3, pali_ric(s3, 3));

	//	int h = 0;
	//	int *pi = &h;
	//	char *pc = s1;
	//	printf("%d %d\n", pi, pc);
	//	pi++;
	//	pc++;
	//	printf("%d %d", pi, pc);

	return EXIT_SUCCESS;
}
